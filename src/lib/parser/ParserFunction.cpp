#include <parser/ParserFunction.hpp>

#include <optional>
#include <variant>
#include <vector>
#include <string>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/Comment.hpp>
#include <parser/Identifier.hpp>
#include <parser/ParserTypeUse.hpp>
#include <parser/ParserValueType.hpp>
#include <parser/ParserBlockedInstr.hpp>
#include <parser/GetInstr.hpp>
#include <structure/Function.hpp>

struct Local{
  std::optional<std::string> id;
  std::vector<ValueType> types;
};

static std::optional<Local> parseLocal(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if((*context.cursor) == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "local")){
        context.cursor += 5;
        Comment::skip(context);
        Local result;
        Identifier id(context);
        if(id.has_value()){
          result.id = *id;
        }
        Comment::skip(context);
        for(ParserValueType valType(context); valType.has_value(); valType = ParserValueType(context)){
          result.types.push_back(*valType);
          Comment::skip(context);
        }
        if((*context.cursor) == ')'){
          ++context.cursor;
          parent_context.cursor = context.cursor;
          return std::optional<Local>(result);
        }else{
          throw Error<ErrorType::SyntaxError>("expected ')'");
        }
      }
    }
  }
  return std::optional<Local>();
}

ParserFunction::ParserFunction(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if((*context.cursor) == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "func")){
        context.cursor += 4;
        Function& func = emplace<Function>(Function());
        // Id
        Comment::skip(context);
        Identifier id(context);
        if(id.has_value()){
          func.id = *id;
        }
        // Typeuse
        Comment::skip(context);
        ParserTypeUse typeuse(context);
        if(typeuse.has_value()){
          func.typeUse = *typeuse;
        }else{
          throw Error<ErrorType::SyntaxError>("expected typeuse in function section");
        }
        // Local
        Comment::skip(context);
        for(std::optional<Local> local = parseLocal(context); local.has_value(); local = parseLocal(context)){
          uint32_t index = func.locals.size();
          if(local->id.has_value()){
            func.localMap[*(local->id)] = index;
          }
          for(auto it = local->types.begin(); it != local->types.end(); ++it){
            func.locals.push_back(*it);
          }
          Comment::skip(context);
        }
        // Body
        while (true){
          Comment::skip(context);
          InstrVariant instr(getInstruction(context));
          if(std::holds_alternative<std::monostate>(instr)){
            ParserFoldedInstr folded(context);
            if(folded.has_value()){
              for(auto it = folded->begin(); it != folded->end(); ++it){
                func.body.emplace_back(*it);
              }
            }else{
              break;
            }
          }else{
            func.body.emplace_back(instr);
          }
        }
        // Postfix
        Comment::skip(context);
        if((*context.cursor) == ')'){
          ++context.cursor;
          parent_context = context;
        }else{
          throw Error<ErrorType::SyntaxError>("expected ')'");
        }
      }
    }
  }
}
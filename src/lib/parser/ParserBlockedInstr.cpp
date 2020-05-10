#include <parser/ParserBlockedInstr.hpp>

#include <variant>
#include <optional>
#include <vector>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/Comment.hpp>
#include <parser/Identifier.hpp>
#include <parser/ParserResult.hpp>
#include <parser/ParserConstInstr.hpp>
#include <parser/ParserControlInstr.hpp>
#include <parser/ParserMemoryInstr.hpp>
#include <parser/ParserNumericInstr.hpp>
#include <parser/ParserParamInstr.hpp>
#include <parser/ParserVariableInstr.hpp>
#include <structure/Value.hpp>
#include <structure/BlockedInstr.hpp>

template <class... Args>
static InstrVariant variant_cast(const std::variant<Args...>& v){
  return std::visit([](auto&& arg) -> InstrVariant { return arg; }, v);
}

template <class... T>
static InstrVariant getInstr(ParserContext& context){
  for(InstrVariant result : std::vector<InstrVariant>({variant_cast(T(context))...})){
    if(!std::holds_alternative<std::monostate>(result)){
      return result;
    }
  }
  return InstrVariant(std::monostate());
}

ParserBlockedInstr::ParserBlockedInstr(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;

    std::optional<std::string>* idPtr = nullptr;
    std::vector<ValueType>* resultsPtr = nullptr;
    std::vector<InstrVariant>* instrsPtr = nullptr;

    if(Util::matchString(context.cursor, context.end, "block")){
      context.cursor += 5;
      BlockInstr& instr = emplace<BlockInstr>(BlockInstr());
      idPtr = &instr.id;
      resultsPtr = &instr.resultTypes;
      instrsPtr = &instr.instrs;
    }else if(Util::matchString(context.cursor, context.end, "loop")){
      context.cursor += 4;
      LoopInstr& instr = emplace<LoopInstr>(LoopInstr());
      idPtr = &instr.id;
      resultsPtr = &instr.resultTypes;
      instrsPtr = &instr.instrs;
    }else if(Util::matchString(context.cursor, context.end, "if")){
      context.cursor += 2;
      IfInstr& instr = emplace<IfInstr>(IfInstr());
      idPtr = &instr.id;
      resultsPtr = &instr.resultTypes;
      instrsPtr = &instr.instrs;
    }else{
      return;
    }
    // Id
    Comment::skip(context);
    Identifier id(context);
    *idPtr = id;

    // Return Type
    Comment::skip(context);
    for(ParserResult result(context); result.has_value(); result = ParserResult(context)){
      if(result.type() == typeid(ValueType)){
        resultsPtr->emplace_back(std::any_cast<ValueType>(result));
      }else{
        std::vector<ValueType> newResults(std::any_cast<std::vector<ValueType>>(result));
        for(auto it = newResults.begin(); it != newResults.end(); ++it){
          resultsPtr->emplace_back(*it);
        }
      }
      Comment::skip(context);
    }

    // Instructions
    for(bool hasInstr = true; hasInstr; ){
      Comment::skip(context);
      InstrVariant instr = getInstr<
        ParserConstInstr,
        ParserControlInstr,
        ParserMemoryInstr,
        ParserNumericInstr,
        ParserParamInstr,
        ParserVariableInstr,
        ParserBlockedInstr
      >(context);
      if(std::holds_alternative<std::monostate>(instr)){
        hasInstr = false;
      }else{
        instrsPtr->emplace_back(instr);
      }
    }

    // Else section in if
    Comment::skip(context);
    if(std::holds_alternative<IfInstr>(*this) && Util::matchString(context.cursor, context.end, "else")){
      context.cursor += 4;
      Comment::skip(context);
      Identifier postfix(context);
      if(postfix.has_value() && *postfix != *id){
        throw Error<ErrorType::SyntaxError>("postfix id of 'else' should match block label");
      }
      std::vector<InstrVariant>& elseInstrs = std::get<IfInstr>(*this).elseInstrs;
      for(bool hasInstr = true; hasInstr; ){
        Comment::skip(context);
        InstrVariant instr = getInstr<
          ParserConstInstr,
          ParserControlInstr,
          ParserMemoryInstr,
          ParserNumericInstr,
          ParserParamInstr,
          ParserVariableInstr,
          ParserBlockedInstr
        >(context);
        if(std::holds_alternative<std::monostate>(instr)){
          hasInstr = false;
        }else{
          elseInstrs.emplace_back(instr);
        }
      }
    }

    // Check end
    Comment::skip(context);
    if(Util::matchString(context.cursor, context.end, "end")){
      context.cursor += 3;
    }else{
      throw Error<ErrorType::SyntaxError>("expected 'end' in blocked instruction");
    }

    // Check postfix
    Comment::skip(context);
    Identifier postfix(context);
    if(postfix.has_value() && *postfix != *id){
      throw Error<ErrorType::SyntaxError>("postfix id should match block label");
    }

    parent_context.cursor = context.cursor;
  }
}
#include <parser/ParserType.hpp>

#include <Util.hpp>
#include <Error.hpp>
#include <parser/Comment.hpp>
#include <parser/Identifier.hpp>
#include <parser/ParserFuncType.hpp>
#include <structure/Type.hpp>

ParserType::ParserType(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "type")){
        context.cursor += 4;
        Type type;
        Comment::skip(context);
        Identifier id(context);
        if(id.has_value()){
          type.id = *id;
        }
        Comment::skip(context);
        ParserFuncType funcType(context);
        if(funcType.has_value()){
          Comment::skip(context);
          if(*context.cursor == ')'){
            ++context.cursor;
            type.funcType = *funcType;
            this->std::optional<Type>::operator=(type);
            parent_context.cursor = context.cursor;
          }else{
            throw Error<ErrorType::SyntaxError>("expected ')' when type section ends");
          }
        }else{
          throw Error<ErrorType::SyntaxError>("expected functype in type section");
        }
      }
    }
  }
}
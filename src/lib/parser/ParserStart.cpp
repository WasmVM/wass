#include <parser/ParserStart.hpp>

#include <optional>
#include <cstdint>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>

ParserStart::ParserStart(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "start")){
        context.cursor += 5;
        Comment::skip(context);
        IntegerLiteral index(context);
        if(!index.has_value()){
          throw Error<ErrorType::ParseError>("expect index in start description");
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::ParseError>("expected ')' after start section");
        }else{
          ++context.cursor;
        }
        this->std::optional<uint32_t>::operator=((uint32_t)*index);
        parent_context.cursor = context.cursor;
      }
    }
  }
}
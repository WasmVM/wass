#include <parser/ParserStart.hpp>

#include <optional>
#include <cstdint>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <parser/Identifier.hpp>

ParserStart::ParserStart(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "start")){
        context.cursor += 5;
        Comment::skip(context);
        Index& index = std::optional<Index>::emplace();
        IntegerLiteral intIndex(context);
        if(intIndex.has_value()){
          index.emplace<uint32_t>(*intIndex);
        }else{
          Identifier strIndex(context);
          if(strIndex.has_value()){
            index.emplace<std::string>(*strIndex);
          }else{
            throw Error<ErrorType::ParseError>("expected a function index as start function");
          }
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::ParseError>("expected ')' after start section");
        }else{
          ++context.cursor;
        }
        parent_context.cursor = context.cursor;
      }
    }
  }
}
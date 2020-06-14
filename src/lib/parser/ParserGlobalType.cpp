#include <parser/ParserGlobalType.hpp>

#include <optional>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserValueType.hpp>
#include <structure/GlobalType.hpp>

ParserGlobalType::ParserGlobalType(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    GlobalType global;
    if((*context.cursor) == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "mut")){
        context.cursor += 3;
        global.immutable = false;
      }
    }
    Comment::skip(context);
    ParserValueType type(context);
    if(type.has_value()){
      global.type = *type;
      if(global.immutable == false){
        Comment::skip(context);
        if((*context.cursor) != ')'){
          throw Error<ErrorType::ParseError>("expected ')'");
        }else{
          ++context.cursor;
        }
      }
      this->std::optional<GlobalType>::operator=(global);
      parent_context.cursor = context.cursor;
    }
  }
}
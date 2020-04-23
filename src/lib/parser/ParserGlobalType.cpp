#include <parser/ParserGlobalType.hpp>

#include <any>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserValue.hpp>
#include <structure/GlobalType.hpp>

ParserGlobalType::ParserGlobalType(ParserContext& parent_context){
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
    global.type = std::any_cast<ValueType>(type);
    if(global.immutable == false){
      Comment::skip(context);
      if((*context.cursor) != ')'){
        throw Error<ErrorType::SyntaxError>("expected ')'");
      }else{
        ++context.cursor;
      }
    }
    this->std::any::operator=(global);
    parent_context.cursor = context.cursor;
  }
}
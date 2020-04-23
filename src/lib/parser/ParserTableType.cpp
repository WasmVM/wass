#include <parser/ParserTableType.hpp>

#include <any>
#include <cstdint>
#include <parser/Comment.hpp>
#include <parser/ParserLimit.hpp>
#include <Util.hpp>
#include <Error.hpp>

ParserTableType::ParserTableType(ParserContext& parent_context){
  ParserContext context = parent_context;
  ParserLimit limit(context);
  if(limit.has_value()){
    Comment::skip(context);
    if(Util::matchString(context.cursor, context.end, "funcref")){
      context.cursor += 7;
      this->std::any::operator=(std::any_cast<Limit>(limit));
      parent_context = context;
    }else{
      throw Error<ErrorType::SyntaxError>("expected elememt type");
    }
  }
}
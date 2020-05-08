#include <parser/ParserTableType.hpp>

#include <optional>
#include <cstdint>
#include <parser/Comment.hpp>
#include <parser/ParserLimit.hpp>
#include <Util.hpp>
#include <Error.hpp>

ParserTableType::ParserTableType(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    ParserLimit limit(context);
    if(limit.has_value()){
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "funcref")){
        context.cursor += 7;
        this->std::optional<Limit>::operator=(*limit);
        parent_context = context;
      }else{
        throw Error<ErrorType::SyntaxError>("expected elememt type");
      }
    }
  }
}
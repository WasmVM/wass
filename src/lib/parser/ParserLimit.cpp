#include <parser/ParserLimit.hpp>

#include <optional>
#include <cstdint>
#include <parser/Comment.hpp>
#include <parser/IntegerLiteral.hpp>
#include <structure/Limit.hpp>

ParserLimit::ParserLimit(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    Comment::skip(context);
    IntegerLiteral min(context);
    if(min.has_value()){
      Limit limit((uint32_t)*min);
      Comment::skip(context);
      IntegerLiteral max(context);
      if(max.has_value()){
        limit.max = (uint32_t)*max;
      }
      this->std::optional<Limit>::operator=(limit);
      parent_context = context;
    }
  }
}
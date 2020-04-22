#include <parser/ParserLimit.hpp>

#include <any>
#include <cstdint>
#include <parser/Comment.hpp>
#include <parser/IntegerLiteral.hpp>
#include <structure/Limit.hpp>

ParserLimit::ParserLimit(ParserContext& parent_context){
  ParserContext context = parent_context;
  Comment::skip(context);
  IntegerLiteral min(context);
  if(min.has_value()){
    Limit limit((uint32_t)std::any_cast<int64_t>(min));
    Comment::skip(context);
    IntegerLiteral max(context);
    if(max.has_value()){
      limit.max = (uint32_t)std::any_cast<int64_t>(max);
    }
    this->std::any::operator=(limit);
    parent_context = context;
  }
}
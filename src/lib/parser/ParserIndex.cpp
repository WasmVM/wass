#include <parser/ParserIndex.hpp>

#include <optional>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/Identifier.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <structure/Index.hpp>

ParserIndex::ParserIndex(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    Identifier strIndex(context);
    if(strIndex.has_value()){
      emplace<Index>(Index(*strIndex));
    }else{
      IntegerLiteral intIndex(context);
      if(intIndex.has_value()){
        emplace<Index>(Index((uint32_t)*intIndex));
      }
    }
    parent_context.cursor = context.cursor;
  }
}
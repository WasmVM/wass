#include <parser/ParserMemory.hpp>

#include <optional>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/Limit.hpp>
#include <parser/ParserLimit.hpp>
#include <parser/Identifier.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserContext.hpp>

ParserMemory::ParserMemory(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "memory")){
        context.cursor += 6;
        Memory& memory = emplace<Memory>(Memory());
        // Id
        Comment::skip(context);
        Identifier id(context);
        if(id.has_value()){
          memory.id = *id;
        }
        // Memory type
        Comment::skip(context);
        ParserLimit memType(context);
        if(memType.has_value()){
          memory.memType = *memType;
        }else{
          throw Error<ErrorType::SyntaxError>("expected memtype in memory section");
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor == ')'){
          ++context.cursor;
          parent_context.cursor = context.cursor;
        }else{
          throw Error<ErrorType::SyntaxError>("expected ')' in the end memory section");
        }
      }
    }
  }
}
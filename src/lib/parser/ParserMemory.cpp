#include <parser/ParserMemory.hpp>

#include <optional>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/Limit.hpp>
#include <parser/ParserLimit.hpp>
#include <parser/Identifier.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserContext.hpp>
#include <parser/StringLiteral.hpp>
#include "_Abbreviated.hpp"

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
        // Export
        Comment::skip(context);
        for(AbbrExport abbrExport(context); abbrExport.has_value(); abbrExport = AbbrExport(context)){
          if(!memory.exportNames.has_value()){
            memory.exportNames.emplace();
          }
          memory.exportNames->emplace_back(*abbrExport);
          Comment::skip(context);
        }
        // Import
        Comment::skip(context);
        AbbrImport abbrImport(context);
        if(abbrImport.has_value()){
          memory.importModule = abbrImport->first;
          memory.importName = abbrImport->second;
        }else if(*context.cursor == '('){
          ++context.cursor;
          Comment::skip(context);
          if(Util::matchString(context.cursor, context.end, "data")){
            context.cursor += 4;
            Comment::skip(context);
            StringLiteral datastring(context);
            if(datastring.has_value()){
              memory.data.emplace(*datastring);
              uint32_t pageSize = datastring->size() / 65536 + 1;
              memory.memType.min = pageSize;
              memory.memType.max = pageSize;
              Comment::skip(context);
              if(*context.cursor == ')'){
                ++context.cursor;
              }else{
                throw Error<ErrorType::ParseError>("expected ')' in the end of abbreviated data section");
              }
            }else{
              throw Error<ErrorType::ParseError>("expected datastring in abbreviated data section");
            }
          }else{
            throw Error<ErrorType::ParseError>("unknown abbriviated section in memory section");
          }
        }
        // Memory type
        if(!memory.data.has_value()){
          Comment::skip(context);
          ParserLimit memType(context);
          if(memType.has_value()){
            memory.memType = *memType;
          }else{
            throw Error<ErrorType::ParseError>("expected memtype in memory section");
          }
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor == ')'){
          ++context.cursor;
          parent_context.cursor = context.cursor;
        }else{
          throw Error<ErrorType::ParseError>("expected ')' in the end of memory section");
        }
      }
    }
  }
}
#include <parser/ParserTable.hpp>

#include <optional>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/Limit.hpp>
#include <parser/ParserTableType.hpp>
#include <parser/Identifier.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserContext.hpp>
#include "_Abbreviated.hpp"

ParserTable::ParserTable(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "table")){
        context.cursor += 5;
        Table& table = emplace<Table>(Table());
        // Id
        Comment::skip(context);
        Identifier id(context);
        if(id.has_value()){
          table.id = *id;
        }
        // Export
        Comment::skip(context);
        for(AbbrExport abbrExport(context); abbrExport.has_value(); abbrExport = AbbrExport(context)){
          table.exportNames.emplace_back(*abbrExport);
          Comment::skip(context);
        }
        // Import
        Comment::skip(context);
        AbbrImport abbrImport(context);
        if(abbrImport.has_value()){
          table.importModule = abbrImport->first;
          table.importName = abbrImport->second;
        }
        // Table type
        Comment::skip(context);
        ParserTableType tableType(context);
        if(tableType.has_value()){
          table.tableType = *tableType;
        }else{
          throw Error<ErrorType::SyntaxError>("expected tabletype in table section");
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor == ')'){
          ++context.cursor;
          parent_context.cursor = context.cursor;
        }else{
          throw Error<ErrorType::SyntaxError>("expected ')' in the end table section");
        }
      }
    }
  }
}
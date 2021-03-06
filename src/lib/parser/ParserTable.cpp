#include <parser/ParserTable.hpp>

#include <optional>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/Limit.hpp>
#include <structure/Index.hpp>
#include <parser/ParserTableType.hpp>
#include <parser/Identifier.hpp>
#include <parser/ParserIndex.hpp>
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
        Comment::skip(context);
        // Import
        AbbrImport abbrImport(context);
        if(abbrImport.has_value()){
          table.importModule = abbrImport->first;
          table.importName = abbrImport->second;
        }else if(Util::matchString(context.cursor, context.end, "funcref")){
          // Elem
          context.cursor += 7;
          Comment::skip(context);
          if(*context.cursor == '('){
            ++context.cursor;
            Comment::skip(context);
            if(Util::matchString(context.cursor, context.end, "elem")){
              context.cursor += 4;
              Comment::skip(context);
              for(ParserIndex elem(context); elem.has_value(); elem = ParserIndex(context)){
                table.elements.emplace_back(*elem);
                Comment::skip(context);
              }
              table.tableType.min = table.elements.size();
              table.tableType.max = table.elements.size();
              Comment::skip(context);
              if(*context.cursor == ')'){
                ++context.cursor;
              }else{
                throw Error<ErrorType::ParseError>("expected ')' in abbreviated element of table section");
              }
            }else{
              throw Error<ErrorType::ParseError>("expected 'elem' in abbreviated element of table section");
            }
          }else{
            throw Error<ErrorType::ParseError>("expected '(' in abbreviated element of table section");
          }
        }
        // Table type
        if(table.elements.size() <= 0){
          Comment::skip(context);
          ParserTableType tableType(context);
          if(tableType.has_value()){
            table.tableType = *tableType;
          }else{
            throw Error<ErrorType::ParseError>("expected tabletype in table section");
          }
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor == ')'){
          ++context.cursor;
          parent_context.cursor = context.cursor;
        }else{
          throw Error<ErrorType::ParseError>("expected ')' in the end of table section");
        }
      }
    }
  }
}
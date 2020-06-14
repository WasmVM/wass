#include <parser/ParserExport.hpp>

#include <optional>
#include <cstdint>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/Name.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <structure/Export.hpp>

ParserExport::ParserExport(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "export")){
        context.cursor += 6;
        Export newExport;
        // Name
        Comment::skip(context);
        Name exportName(context);
        if(exportName.has_value()){
          newExport.name = *exportName;
        }else{
          throw Error<ErrorType::ParseError>("expected module name in export section");
        }
        // Export desc
        Comment::skip(context);
        if(*context.cursor != '('){
          throw Error<ErrorType::ParseError>("expected '(' before export description");
        }else{
          ++context.cursor;
        }
        Comment::skip(context);
        if(Util::matchString(context.cursor, context.end, "func")){
          context.cursor += 4;
          newExport.type = ExportType::Func;
        }else if(Util::matchString(context.cursor, context.end, "table")){
          context.cursor += 5;
          newExport.type = ExportType::Table;
        }else if(Util::matchString(context.cursor, context.end, "memory")){
          context.cursor += 6;
          newExport.type = ExportType::Memory;
        }else if(Util::matchString(context.cursor, context.end, "global")){
          context.cursor += 6;
          newExport.type = ExportType::Global;
        }else{
          throw Error<ErrorType::ParseError>("unknown type of export description");
        }
        Comment::skip(context);
        IntegerLiteral index(context);
        if(index.has_value()){
          newExport.index = (uint32_t)*index;
        }else{
          throw Error<ErrorType::ParseError>("expect index in export description");
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::ParseError>("expected ')' after export description");
        }else{
          ++context.cursor;
        }
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::ParseError>("expected ')' after export section");
        }else{
          ++context.cursor;
        }
        this->std::optional<Export>::operator=(newExport);
        parent_context.cursor = context.cursor;
      }
    }
  }
}
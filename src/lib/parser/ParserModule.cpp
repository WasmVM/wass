#include <parser/ParserModule.hpp>

#include <optional>
#include <cstdint>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/Identifier.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserType.hpp>
#include <parser/ParserImport.hpp>
#include <parser/ParserFunction.hpp>
#include <parser/ParserTable.hpp>
#include <parser/ParserMemory.hpp>
#include <parser/ParserGlobal.hpp>
#include <parser/ParserExport.hpp>
#include <parser/ParserElement.hpp>
#include <parser/ParserStart.hpp>
#include <parser/ParserData.hpp>
#include <structure/Module.hpp>

ParserModule::ParserModule(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "module")){
        context.cursor += 6;
        Module& newModule = emplace<Module>(Module());
        // Id
        Comment::skip(context);
        Identifier id(context);
        if(id.has_value()){
          newModule.id = *id;
        }
        // Sections
        bool has_section = false;
        do{
          has_section = false;
          // Type
          Comment::skip(context);
          ParserType newType(context);
          if(newType.has_value()){
            newModule.types.emplace_back(*newType);
            has_section = true;
          }
          // Imports
          Comment::skip(context);
          ParserImport newImport(context);
          if(newImport.has_value()){
            newModule.imports.emplace_back(*newImport);
            has_section = true;
          }
          // Func
          Comment::skip(context);
          ParserFunction newFunc(context);
          if(newFunc.has_value()){
            newModule.funcs.emplace_back(*newFunc);
            has_section = true;
          }
          // Table
          Comment::skip(context);
          ParserTable newTable(context);
          if(newTable.has_value()){
            newModule.tables.emplace_back(*newTable);
            has_section = true;
          }
          // Memory
          Comment::skip(context);
          ParserMemory newMemory(context);
          if(newMemory.has_value()){
            newModule.memories.emplace_back(*newMemory);
            has_section = true;
          }
          // Global
          Comment::skip(context);
          ParserGlobal newGlobal(context);
          if(newGlobal.has_value()){
            newModule.globals.emplace_back(*newGlobal);
            has_section = true;
          }
          // Export
          Comment::skip(context);
          ParserExport newExport(context);
          if(newExport.has_value()){
            newModule.exports.emplace_back(*newExport);
            has_section = true;
          }
          // Elem
          Comment::skip(context);
          ParserElement newElem(context);
          if(newElem.has_value()){
            newModule.elems.emplace_back(*newElem);
            has_section = true;
          }
          // Start
          Comment::skip(context);
          ParserStart newStart(context);
          if(newStart.has_value()){
            if(newModule.start.has_value()){
              throw Error<ErrorType::ParseError>("cannot define multiple start sections in one module");
            }else{
              newModule.start = *newStart;
            }
          }
          // Data
          Comment::skip(context);
          ParserData newData(context);
          if(newData.has_value()){
            newModule.datas.emplace_back(*newData);
            has_section = true;
          }
        }while(has_section);
        // Postfix
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::ParseError>("expected ')' after module");
        }else{
          ++context.cursor;
        }
        parent_context.cursor = context.cursor;
      }
    }
  }
}
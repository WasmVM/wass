#include <parser/ParserImport.hpp>

#include <Util.hpp>
#include <Error.hpp>
#include <parser/Identifier.hpp>
#include <parser/Name.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserTypeUse.hpp>
#include <parser/ParserTableType.hpp>
#include <parser/ParserLimit.hpp>
#include <parser/ParserGlobalType.hpp>
#include <structure/Import.hpp>

ParserImport::ParserImport(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "import")){
        context.cursor += 6;
        Import newImport;
        // Module name
        Comment::skip(context);
        Name moduleName(context);
        if(moduleName.has_value()){
          newImport.mod = *moduleName;
        }else{
          throw Error<ErrorType::SyntaxError>("expected module name in import section");
        }
        // Name
        Comment::skip(context);
        Name importName(context);
        if(importName.has_value()){
          newImport.name = *importName;
        }else{
          throw Error<ErrorType::SyntaxError>("expected module name in import section");
        }
        // Import desc
        Comment::skip(context);
        if(*context.cursor != '('){
          throw Error<ErrorType::SyntaxError>("expected '(' before import description");
        }else{
          ++context.cursor;
        }
        Comment::skip(context);
        if(Util::matchString(context.cursor, context.end, "func")){
          context.cursor += 4;
          Comment::skip(context);
          Identifier id(context);
          if(id.has_value()){
            newImport.descId = *id;
          }
          Comment::skip(context);
          ParserTypeUse funcType(context);
          if(funcType.has_value()){
            newImport.desc.emplace<TypeUse>(*funcType);
          }else{
            throw Error<ErrorType::SyntaxError>("expected typeuse in function import description");
          }
        }else if(Util::matchString(context.cursor, context.end, "table")){
          context.cursor += 5;
          Comment::skip(context);
          Identifier id(context);
          if(id.has_value()){
            newImport.descId = *id;
          }
          Comment::skip(context);
          ParserTableType tableType(context);
          if(tableType.has_value()){
            newImport.desc.emplace<Limit>(*tableType);
          }else{
            throw Error<ErrorType::SyntaxError>("expected tabletype in table import description");
          }
        }else if(Util::matchString(context.cursor, context.end, "memory")){
          context.cursor += 6;
          Comment::skip(context);
          Identifier id(context);
          if(id.has_value()){
            newImport.descId = *id;
          }
          Comment::skip(context);
          ParserLimit memoryType(context);
          if(memoryType.has_value()){
            newImport.desc.emplace<Limit>(*memoryType);
          }else{
            throw Error<ErrorType::SyntaxError>("expected memorytype in memory import description");
          }
        }else if(Util::matchString(context.cursor, context.end, "global")){
          context.cursor += 6;
          Comment::skip(context);
          Identifier id(context);
          if(id.has_value()){
            newImport.descId = *id;
          }
          Comment::skip(context);
          ParserGlobalType globalType(context);
          if(globalType.has_value()){
            newImport.desc.emplace<GlobalType>(*globalType);
          }else{
            throw Error<ErrorType::SyntaxError>("expected globaltype in global import description");
          }
        }else{
          throw Error<ErrorType::SyntaxError>("unknown type of import description");
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::SyntaxError>("expected ')' after import description");
        }else{
          ++context.cursor;
        }
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::SyntaxError>("expected ')' after import section");
        }else{
          ++context.cursor;
        }
        this->std::optional<Import>::operator=(newImport);
        parent_context.cursor = context.cursor;
      }
    }
  }
}
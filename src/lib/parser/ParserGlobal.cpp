#include <parser/ParserGlobal.hpp>

#include <optional>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/Global.hpp>
#include <parser/Identifier.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserConstInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserGlobalType.hpp>

ParserGlobal::ParserGlobal(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "global")){
        context.cursor += 6;
        Global& global = emplace<Global>(Global());
        // Id
        Comment::skip(context);
        Identifier id(context);
        if(id.has_value()){
          global.id = *id;
        }
        // Global type
        Comment::skip(context);
        ParserGlobalType globalType(context);
        if(globalType.has_value()){
          global.globalType = *globalType;
        }else{
          throw Error<ErrorType::SyntaxError>("expected globaltype in global section");
        }
        // Expression
        Comment::skip(context);
        ParserConstInstr constInstr(context);
        if(std::holds_alternative<std::monostate>(constInstr)){
          throw Error<ErrorType::SyntaxError>("expected globaltype in global section");
        }else{
          
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor == ')'){
          ++context.cursor;
          parent_context.cursor = context.cursor;
        }else{
          throw Error<ErrorType::SyntaxError>("expected ')' in the end of global section");
        }
      }
    }
  }
}
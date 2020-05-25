#include <parser/ParserGlobal.hpp>

#include <optional>
#include <variant>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/Global.hpp>
#include <structure/ConstInstr.hpp>
#include <structure/VariableInstr.hpp>
#include <structure/InstrVariant.hpp>
#include <parser/GetInstr.hpp>
#include <parser/Identifier.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserConstInstr.hpp>
#include <parser/ParserVariableInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserGlobalType.hpp>
#include "_AssignConstExprVisitor.hpp"

template <typename V, class... Args>
static V variant_cast(const std::variant<Args...>& v){
  return std::visit([](auto&& arg) -> V { return arg; }, v);
}

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
        ParserConstInstr constExpr(context);
        if(std::holds_alternative<std::monostate>(constExpr)){
          ParserVariableInstr varExpr(context);
          if(std::holds_alternative<GlobalGetInstr>(varExpr)){
            global.expr.emplace<GlobalGetInstr>(std::get<GlobalGetInstr>(varExpr));
          }else{
            throw Error<ErrorType::SyntaxError>("expected constant expression in global section");
          }
        }else{
          std::visit(AssignExprVisitor(global.expr), variant_cast<ConstExprVariant>(constExpr));
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
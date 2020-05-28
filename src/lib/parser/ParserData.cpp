#include <parser/ParserData.hpp>

#include <optional>
#include <cstdint>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/StringLiteral.hpp>
#include <parser/ParserConstInstr.hpp>
#include <parser/ParserVariableInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <structure/Data.hpp>
#include "_AssignConstExprVisitor.hpp"

template <typename V, class... Args>
static V variant_cast(const std::variant<Args...>& v){
  return std::visit([](auto&& arg) -> V { return arg; }, v);
}

ParserData::ParserData(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "data")){
        context.cursor += 4;
        Data& data = emplace<Data>(Data());
        // Memory index
        Comment::skip(context);
        IntegerLiteral memIndex(context);
        if(memIndex.has_value()){
          data.memIndex = (uint32_t)*memIndex;
        }else{
          data.memIndex = 0;
        }
        // Offset prefix
        bool abbrivate = false;
        Comment::skip(context);
        if(*context.cursor == '('){
          ++context.cursor;
          Comment::skip(context);
          if(Util::matchString(context.cursor, context.end, "offset")){
            context.cursor += 6;
            abbrivate = true;
          }else{
            throw Error<ErrorType::SyntaxError>("expected offset in data section");
          }
        }
        // Offset expression
        Comment::skip(context);
        ParserConstInstr constExpr(context);
        if(std::holds_alternative<std::monostate>(constExpr)){
          ParserVariableInstr varExpr(context);
          if(std::holds_alternative<GlobalGetInstr>(varExpr)){
            data.expr.emplace<GlobalGetInstr>(std::get<GlobalGetInstr>(varExpr));
          }else{
            throw Error<ErrorType::SyntaxError>("expected constant expression in data offset");
          }
        }else{
          std::visit(AssignExprVisitor(data.expr), variant_cast<ConstExprVariant>(constExpr));
        }
        // Offset Postfix
        if(abbrivate){
          Comment::skip(context);
          if(*context.cursor != ')'){
            throw Error<ErrorType::SyntaxError>("expected ')' after data offset");
          }else{
            ++context.cursor;
          }
        }
        // Data string
        Comment::skip(context);
        data.data = "";
        for(StringLiteral dataStr(context); dataStr.has_value(); dataStr = StringLiteral(context)){
          data.data += *dataStr;
          Comment::skip(context);
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::SyntaxError>("expected ')' after data section");
        }else{
          ++context.cursor;
        }
        parent_context.cursor = context.cursor;
      }
    }
  }
}
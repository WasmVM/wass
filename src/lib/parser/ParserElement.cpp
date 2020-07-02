#include <parser/ParserElement.hpp>

#include <optional>
#include <cstdint>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/ParserIndex.hpp>
#include <parser/ParserConstInstr.hpp>
#include <parser/ParserVariableInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <structure/Element.hpp>
#include "_AssignConstExprVisitor.hpp"

template <typename V, class... Args>
static V variant_cast(const std::variant<Args...>& v){
  return std::visit([](auto&& arg) -> V { return arg; }, v);
}

ParserElement::ParserElement(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(*context.cursor == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "elem")){
        context.cursor += 4;
        Element& element = emplace<Element>(Element());
        // Table index
        Comment::skip(context);
        ParserIndex tableIndex(context);
        if(tableIndex.has_value()){
          element.tableIndex = *tableIndex;
        }else{
          element.tableIndex = Index((uint32_t)0);
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
            throw Error<ErrorType::ParseError>("expected offset in element section");
          }
        }
        // Offset expression
        Comment::skip(context);
        ParserConstInstr constExpr(context);
        if(std::holds_alternative<std::monostate>(constExpr)){
          ParserVariableInstr varExpr(context);
          if(std::holds_alternative<GlobalGetInstr>(varExpr)){
            element.expr.emplace<GlobalGetInstr>(std::get<GlobalGetInstr>(varExpr));
          }else{
            throw Error<ErrorType::ParseError>("expected constant expression in element offset");
          }
        }else{
          std::visit(AssignExprVisitor(element.expr), variant_cast<ConstExprVariant>(constExpr));
        }
        // Offset Postfix
        if(abbrivate){
          Comment::skip(context);
          if(*context.cursor != ')'){
            throw Error<ErrorType::ParseError>("expected ')' after element offset");
          }else{
            ++context.cursor;
          }
        }
        // Function indices
        Comment::skip(context);
        for(ParserIndex funcidx(context); funcidx.has_value(); funcidx = ParserIndex(context)){
          element.funcIndices.emplace_back(*funcidx);
          Comment::skip(context);
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::ParseError>("expected ')' after element section");
        }else{
          ++context.cursor;
        }
        parent_context.cursor = context.cursor;
      }
    }
  }
}
#include <parser/ParserElement.hpp>

#include <optional>
#include <cstdint>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/IntegerLiteral.hpp>
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
        IntegerLiteral tableIndex(context);
        if(tableIndex.has_value()){
          element.tableIndex = (uint32_t)*tableIndex;
        }else{
          element.tableIndex = 0;
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
            throw Error<ErrorType::SyntaxError>("expected offset in element section");
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
            throw Error<ErrorType::SyntaxError>("expected constant expression in element offset");
          }
        }else{
          std::visit(AssignExprVisitor(element.expr), variant_cast<ConstExprVariant>(constExpr));
        }
        // Offset Postfix
        if(abbrivate){
          Comment::skip(context);
          if(*context.cursor != ')'){
            throw Error<ErrorType::SyntaxError>("expected ')' after element offset");
          }else{
            ++context.cursor;
          }
        }
        // Function indices
        Comment::skip(context);
        for(IntegerLiteral funcidx(context); funcidx.has_value(); funcidx = IntegerLiteral(context)){
          element.funcIndices.push_back((uint32_t)*funcidx);
          Comment::skip(context);
        }
        if(element.funcIndices.size() == 0){
          throw Error<ErrorType::SyntaxError>("expected at least one funcidx in element section");
        }
        // Postfix
        Comment::skip(context);
        if(*context.cursor != ')'){
          throw Error<ErrorType::SyntaxError>("expected ')' after element section");
        }else{
          ++context.cursor;
        }
        parent_context.cursor = context.cursor;
      }
    }
  }
}
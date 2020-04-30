#include <parser/ParserConstInstr.hpp>

#include <any>
#include <structure/ConstInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/FloatLiteral.hpp>
#include <Util.hpp>
#include <Error.hpp>

ParserConstInstr::ParserConstInstr(ParserContext& parent_context){
  ParserContext context = parent_context;
  if(Util::matchString(context.cursor, context.end, "i32.const")){
    context.cursor += 9;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      this->std::any::operator=(I32ConstInstr((int32_t)std::any_cast<int64_t>(literal)));
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after i32.const");
    }
  }else if(Util::matchString(context.cursor, context.end, "i64.const")){
    context.cursor += 9;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      this->std::any::operator=(I64ConstInstr(std::any_cast<int64_t>(literal)));
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after i64.const");
    }
  }else if(Util::matchString(context.cursor, context.end, "f32.const")){
    context.cursor += 9;
    Comment::skip(context);
    FloatLiteral literal(context);
    if(literal.has_value()){
      this->std::any::operator=(F32ConstInstr((float)std::any_cast<double>(literal)));
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after f32.const");
    }
  }else if(Util::matchString(context.cursor, context.end, "f64.const")){
    context.cursor += 9;
    Comment::skip(context);
    FloatLiteral literal(context);
    if(literal.has_value()){
      this->std::any::operator=(F64ConstInstr(std::any_cast<double>(literal)));
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after f64.const");
    }
  }
}
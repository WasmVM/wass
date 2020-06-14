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
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(Util::matchString(context.cursor, context.end, "i32.const")){
      context.cursor += 9;
      Comment::skip(context);
      IntegerLiteral literal(context);
      if(literal.has_value()){
        I32ConstInstr instr;
        instr.value = *literal;
        emplace<I32ConstInstr>(instr);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::ParseError>("expected integer immediate after i32.const");
      }
    }else if(Util::matchString(context.cursor, context.end, "i64.const")){
      context.cursor += 9;
      Comment::skip(context);
      IntegerLiteral literal(context);
      if(literal.has_value()){
        I64ConstInstr instr;
        instr.value = *literal;
        emplace<I64ConstInstr>(instr);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::ParseError>("expected integer immediate after i64.const");
      }
    }else if(Util::matchString(context.cursor, context.end, "f32.const")){
      context.cursor += 9;
      Comment::skip(context);
      FloatLiteral literal(context);
      if(literal.has_value()){
        F32ConstInstr instr;
        instr.value = *literal;
        emplace<F32ConstInstr>(instr);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::ParseError>("expected integer immediate after f32.const");
      }
    }else if(Util::matchString(context.cursor, context.end, "f64.const")){
      context.cursor += 9;
      Comment::skip(context);
      FloatLiteral literal(context);
      if(literal.has_value()){
        F64ConstInstr instr;
        instr.value = *literal;
        emplace<F64ConstInstr>(instr);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::ParseError>("expected integer immediate after f64.const");
      }
    }
  }
}
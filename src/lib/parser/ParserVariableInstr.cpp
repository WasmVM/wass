#include <parser/ParserVariableInstr.hpp>

#include <any>
#include <structure/VariableInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <parser/IntegerLiteral.hpp>
#include <Util.hpp>
#include <Error.hpp>

ParserVariableInstr::ParserVariableInstr(ParserContext& parent_context){
  ParserContext context = parent_context;
  if(Util::matchString(context.cursor, context.end, "local.get")){
    context.cursor += 9;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      VariableInstr<InstrType::LocalGet> instr;
      instr.index = std::any_cast<int64_t>(literal);
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after local.get");
    }
  }else if(Util::matchString(context.cursor, context.end, "local.set")){
    context.cursor += 9;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      VariableInstr<InstrType::LocalSet> instr;
      instr.index = std::any_cast<int64_t>(literal);
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after local.set");
    }
  }else if(Util::matchString(context.cursor, context.end, "local.tee")){
    context.cursor += 9;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      VariableInstr<InstrType::LocalTee> instr;
      instr.index = std::any_cast<int64_t>(literal);
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after local.tee");
    }
  }else if(Util::matchString(context.cursor, context.end, "global.get")){
    context.cursor += 10;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      VariableInstr<InstrType::GlobalGet> instr;
      instr.index = std::any_cast<int64_t>(literal);
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after global.get");
    }
  }else if(Util::matchString(context.cursor, context.end, "global.set")){
    context.cursor += 10;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      VariableInstr<InstrType::GlobalSet> instr;
      instr.index = std::any_cast<int64_t>(literal);
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer immediate after global.set");
    }
  }
}
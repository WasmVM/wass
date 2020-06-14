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
      LocalGetInstr instr;
      instr.index = *literal;
      emplace<LocalGetInstr>(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after local.get");
    }
  }else if(Util::matchString(context.cursor, context.end, "local.set")){
    context.cursor += 9;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      LocalSetInstr instr;
      instr.index = *literal;
      emplace<LocalSetInstr>(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after local.set");
    }
  }else if(Util::matchString(context.cursor, context.end, "local.tee")){
    context.cursor += 9;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      LocalTeeInstr instr;
      instr.index = *literal;
      emplace<LocalTeeInstr>(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after local.tee");
    }
  }else if(Util::matchString(context.cursor, context.end, "global.get")){
    context.cursor += 10;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      GlobalGetInstr instr;
      instr.index = *literal;
      emplace<GlobalGetInstr>(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after global.get");
    }
  }else if(Util::matchString(context.cursor, context.end, "global.set")){
    context.cursor += 10;
    Comment::skip(context);
    IntegerLiteral literal(context);
    if(literal.has_value()){
      GlobalSetInstr instr;
      instr.index = *literal;
      emplace<GlobalSetInstr>(instr);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after global.set");
    }
  }
}
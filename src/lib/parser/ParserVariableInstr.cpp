#include <parser/ParserVariableInstr.hpp>

#include <any>
#include <structure/VariableInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserIndex.hpp>
#include <Util.hpp>
#include <Error.hpp>

ParserVariableInstr::ParserVariableInstr(ParserContext& parent_context){
  ParserContext context = parent_context;
  if(Util::matchString(context.cursor, context.end, "local.get")){
    context.cursor += 9;
    Comment::skip(context);
    ParserIndex index(context);
    if(index.has_value()){
      emplace<LocalGetInstr>().index = *index;
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after local.get");
    }
  }else if(Util::matchString(context.cursor, context.end, "local.set")){
    context.cursor += 9;
    Comment::skip(context);
    ParserIndex index(context);
    if(index.has_value()){
      emplace<LocalSetInstr>().index = *index;
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after local.set");
    }
  }else if(Util::matchString(context.cursor, context.end, "local.tee")){
    context.cursor += 9;
    Comment::skip(context);
    ParserIndex index(context);
    if(index.has_value()){
      emplace<LocalTeeInstr>().index = *index;
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after local.tee");
    }
  }else if(Util::matchString(context.cursor, context.end, "global.get")){
    context.cursor += 10;
    Comment::skip(context);
    ParserIndex index(context);
    if(index.has_value()){
      emplace<GlobalGetInstr>().index = *index;
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after global.get");
    }
  }else if(Util::matchString(context.cursor, context.end, "global.set")){
    context.cursor += 10;
    Comment::skip(context);
    ParserIndex index(context);
    if(index.has_value()){
      emplace<GlobalSetInstr>().index = *index;
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::ParseError>("expected integer immediate after global.set");
    }
  }
}
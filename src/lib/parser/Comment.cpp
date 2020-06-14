#include <parser/Comment.hpp>
#include <string>
#include <Error.hpp>

static void single_line_comment(ParserContext& context){
  while (context.cursor != context.end && (
    *(context.cursor) == ' ' || 
    *(context.cursor) == '\t' || 
    *(context.cursor) == '\r'
  )){
    ++context.cursor;
  }
  if(context.cursor != context.end && *(context.cursor) == ';' && context.cursor + 1 != context.end && context.cursor[1] == ';'){
    while (context.cursor != context.end && *(context.cursor) != '\n')
    {
      ++context.cursor;
    }
  }
}

static void multi_line_comment(ParserContext& context){
  int nestedLevel = 0;
  do{
    if(context.cursor == context.end){
      break;
    }else if(*(context.cursor) == '(' && context.cursor + 1 != context.end && context.cursor[1] == ';'){
      nestedLevel += 1;
      context.cursor += 2;
    }else if(*(context.cursor) == ';' && context.cursor + 1 != context.end && context.cursor[1] == ')'){
      nestedLevel -= 1;
      context.cursor += 2;
    }else if(nestedLevel > 0){
      ++context.cursor;
    }
  } while (nestedLevel > 0);
  if(nestedLevel != 0){
    throw Error<ErrorType::ParseError>("Multi-line comment is not closed");
  }
}

static void white_space(ParserContext& context){
  while (context.cursor != context.end && (
    *(context.cursor) == ' ' ||
    *(context.cursor) == '\t' || 
    *(context.cursor) == '\r' || 
    *(context.cursor) == '\n'
  )){
    ++context.cursor;
  }
}

void Comment::skip(ParserContext& context){
  single_line_comment(context);
  white_space(context);
  multi_line_comment(context);
  white_space(context);
}
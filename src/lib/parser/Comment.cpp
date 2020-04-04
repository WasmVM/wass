#include <parser/Comment.hpp>
#include <string>

static void single_line_comment(ParserContext& context){
  while (context.cursor != context.end && (
    *(context.cursor) == ' ' || 
    *(context.cursor) == '\t' || 
    *(context.cursor) == '\r'
  )){
    ++context.cursor;
  }
  if(*(context.cursor) == ';' && context.cursor + 1 != context.end && context.cursor[1] == ';'){
    while (context.cursor != context.end && *(context.cursor) != '\n')
    {
      ++context.cursor;
    }
  }
}

static void multi_line_comment(ParserContext& context){

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
}
#include <parser/Comment.hpp>

static void single_line_comment(ParserContext& context){

}

static void multi_line_comment(ParserContext& context){

}

void Comment::skip(ParserContext& context){
  single_line_comment(context);
  multi_line_comment(context);
}
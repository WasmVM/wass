#include <gtest/gtest.h>

#include <string>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>

TEST(unittest, Comment_SingleLine_regular){
  std::string data(";;comment");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_SingleLine_more_semicolon){
  std::string data(";;;;;;;;;;;");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_SingleLine_leading_spaces){
  std::string data("    ;;comment");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_SingleLine_inside_module){
  std::string data(
    "( ;;comment\n"
    "module;;comment\n"
    ");;comment"
  );
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.begin());
  context.cursor += 1;
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.begin() + 12);
  context.cursor += 6;
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.begin() + 28);
  context.cursor += 1;
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_SingleLine_semi_paren){
  std::string data(";;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_SingleLine_more_semi_paren){
  std::string data(";;;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_SingleLine_semi_space_paren){
  std::string data(";; ;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_SingleLine_semi_space_left_paren){
  std::string data(";; (;");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

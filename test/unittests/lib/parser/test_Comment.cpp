#include <gtest/gtest.h>

#include <string>
#include <Error.hpp>
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

TEST(unittest, Comment_MultiLine_empty){
  std::string data("(;;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_regular){
  std::string data("(;comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_two_semi_prefix){
  std::string data("(;;;comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_more_semi){
  std::string data("(;;;;;;;;;;;;;;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_more_left_paren){
  std::string data("(;(((((((((( ;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_more_right_paren){
  std::string data("(;)))))))))));)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_one_double_quote){
  std::string data("(;comment\";)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_two_double_quote){
  std::string data("(;comment\"\";)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_more_double_quote){
  std::string data("(;comment\"\"\";)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_ascii_00_1F_7F){
  std::string data("(;(;\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x7f;);)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_unicode){
  std::string data("(;\x48\x65\x69\xC3\x9F\x65\x20\x57\xC3\xBC\x72\x73\x74\x63\x68\x65\x6E;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_wide_char){
  std::string data("(;\xEF\x98\x9A\xEF\x92\xA9;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_multi_line){
  std::string data("(;comment\ncomment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_space_prefixed){
  std::string data("         	(;comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_concat_with_left_paren){
  std::string data("(;comment;)((;comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_concat_with_text){
  std::string data("(;comment;)module(;comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_concat_with_right_paren){
  std::string data("(;comment;))(;comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_nested){
  std::string data("(;comment(;nested;)comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_nested_multi_line){
  std::string data("(;comment\n(;nested\n;)comment\n;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_nested_further){
  std::string data("(;comment(;nested(;further;)nested;)comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_two_semi_inside){
  std::string data("(;comment;;comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_two_semi_multi_line){
  std::string data("(;comment;;comment\n;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_nested_two_semi_inside){
  std::string data("(;comment;;comment(;nested;)comment;)");
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest, Comment_MultiLine_not_closed){
  std::string data("(;comment;;comment");
  ParserContext context(data);
  EXPECT_THROW(Comment::skip(context), SyntaxError);
}

TEST(unittest, Comment_MultiLine_nested_not_closed){
  std::string data("(;comment;;(;comment;)");
  ParserContext context(data);
  EXPECT_THROW(Comment::skip(context), SyntaxError);
}
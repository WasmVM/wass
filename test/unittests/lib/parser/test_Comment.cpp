#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <Util.hpp>

TEST(unittest_Comment, SingleLine_regular){
  std::vector<char> data(create_char_vector(";;comment"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, SingleLine_more_semicolon){
  std::vector<char> data(create_char_vector(";;;;;;;;;;;"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, SingleLine_leading_spaces){
  std::vector<char> data(create_char_vector("    ;;comment"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, SingleLine_inside_module){
  std::vector<char> data(create_char_vector(
    "( ;;comment\n"
    "module;;comment\n"
    ");;comment"
  ));
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

TEST(unittest_Comment, SingleLine_semi_paren){
  std::vector<char> data(create_char_vector(";;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, SingleLine_more_semi_paren){
  std::vector<char> data(create_char_vector(";;;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, SingleLine_semi_space_paren){
  std::vector<char> data(create_char_vector(";; ;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, SingleLine_semi_space_left_paren){
  std::vector<char> data(create_char_vector(";; (;"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_empty){
  std::vector<char> data(create_char_vector("(;;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_regular){
  std::vector<char> data(create_char_vector("(;comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_two_semi_prefix){
  std::vector<char> data(create_char_vector("(;;;comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_more_semi){
  std::vector<char> data(create_char_vector("(;;;;;;;;;;;;;;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_more_left_paren){
  std::vector<char> data(create_char_vector("(;(((((((((( ;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_more_right_paren){
  std::vector<char> data(create_char_vector("(;)))))))))));)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_one_double_quote){
  std::vector<char> data(create_char_vector("(;comment\";)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_two_double_quote){
  std::vector<char> data(create_char_vector("(;comment\"\";)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_more_double_quote){
  std::vector<char> data(create_char_vector("(;comment\"\"\";)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_ascii_00_1F_7F){
  std::vector<char> data(create_char_vector("(;(;\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f\x7f;);)", 41));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_unicode){
  std::vector<char> data(create_char_vector("(;\x48\x65\x69\xC3\x9F\x65\x20\x57\xC3\xBC\x72\x73\x74\x63\x68\x65\x6E;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_wide_char){
  std::vector<char> data(create_char_vector("(;\xEF\x98\x9A\xEF\x92\xA9;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_multi_line){
  std::vector<char> data(create_char_vector("(;comment\ncomment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_space_prefixed){
  std::vector<char> data(create_char_vector("         	(;comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_concat_with_left_paren){
  std::vector<char> data(create_char_vector("(;comment;)((;comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.begin() + 11);
  context.cursor += 1;
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_concat_with_text){
  std::vector<char> data(create_char_vector("(;comment;)module(;comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.begin() + 11);
  context.cursor += 6;
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_concat_with_right_paren){
  std::vector<char> data(create_char_vector("(;comment;))(;comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.begin() + 11);
  context.cursor += 1;
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_nested){
  std::vector<char> data(create_char_vector("(;comment(;nested;)comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_nested_multi_line){
  std::vector<char> data(create_char_vector("(;comment\n(;nested\n;)comment\n;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_nested_further){
  std::vector<char> data(create_char_vector("(;comment(;nested(;further;)nested;)comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_two_semi_inside){
  std::vector<char> data(create_char_vector("(;comment;;comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_two_semi_multi_line){
  std::vector<char> data(create_char_vector("(;comment;;comment\n;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_nested_two_semi_inside){
  std::vector<char> data(create_char_vector("(;comment;;comment(;nested;)comment;)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.end());
}

TEST(unittest_Comment, MultiLine_not_closed){
  std::vector<char> data(create_char_vector("(;comment;;comment"));
  ParserContext context(data);
  EXPECT_THROW(Comment::skip(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Comment, MultiLine_missing_matched_start){
  std::vector<char> data(create_char_vector("(;comment;;comment;);)"));
  ParserContext context(data);
  Comment::skip(context);
  EXPECT_EQ(context.cursor, data.begin() + 20);
  EXPECT_THROW(Comment::skip(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Comment, MultiLine_nested_not_closed){
  std::vector<char> data(create_char_vector("(;comment;;(;comment;)"));
  ParserContext context(data);
  EXPECT_THROW(Comment::skip(context), Error<ErrorType::SyntaxError>);
}
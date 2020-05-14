#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/StringLiteral.hpp>
#include <Helper.hpp>

TEST(unittest_StringLiteral, empty){
  std::vector<char> data(create_char_vector("\"\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "");
}

TEST(unittest_StringLiteral, regular){
  std::vector<char> data(create_char_vector("\"abcd\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "abcd");
}

TEST(unittest_StringLiteral, hexdigit){
  std::vector<char> data(create_char_vector("\"\\0a\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\x0a");
}

TEST(unittest_StringLiteral, hexdigit_one_digit){
  std::vector<char> data(create_char_vector("\"\\c\""));
  ParserContext context(data);
  StringLiteral* result = nullptr;
  EXPECT_THROW(result = new StringLiteral(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_StringLiteral, unicode_hexnum){
  std::vector<char> data(create_char_vector("\"\\u{e00c}\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\xe0\x0c");
}

TEST(unittest_StringLiteral, unicode_hexnum_separator){
  std::vector<char> data(create_char_vector("\"\\u{e0_0c}\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\xe0\x0c");
}

TEST(unittest_StringLiteral, unicode_hexnum_separator_more){
  std::vector<char> data(create_char_vector("\"\\u{e0_0_c}\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\xe0\x0c");
}

TEST(unittest_StringLiteral, unicode_hexnum_separator_prefix){
  std::vector<char> data(create_char_vector("\"\\u{_e00c}\""));
  ParserContext context(data);
  StringLiteral* result = nullptr;
  EXPECT_THROW(result = new StringLiteral(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_StringLiteral, unicode_hexnum_separator_postfix){
  std::vector<char> data(create_char_vector("\"\\u{e00c_}\""));
  ParserContext context(data);
  StringLiteral* result = nullptr;
  EXPECT_THROW(result = new StringLiteral(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_StringLiteral, unicode_hexnum_out_of_range){
  std::vector<char> data(create_char_vector("\"\\u{d900}\""));
  ParserContext context(data);
  StringLiteral* result = nullptr;
  EXPECT_THROW(result = new StringLiteral(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_StringLiteral, escape_tab){
  std::vector<char> data(create_char_vector("\"\\t\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\t");
}

TEST(unittest_StringLiteral, escape_newline){
  std::vector<char> data(create_char_vector("\"\\n\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\n");
}

TEST(unittest_StringLiteral, escape_return){
  std::vector<char> data(create_char_vector("\"\\r\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\r");
}

TEST(unittest_StringLiteral, escape_double_quote){
  std::vector<char> data(create_char_vector("\"\\\"\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\"");
}

TEST(unittest_StringLiteral, escape_single_quote){
  std::vector<char> data(create_char_vector("\"\\'\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "'");
}

TEST(unittest_StringLiteral, escape_backslash){
  std::vector<char> data(create_char_vector("\"\\\\\""));
  ParserContext context(data);
  StringLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\\");
}
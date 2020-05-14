#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Name.hpp>
#include <Helper.hpp>

TEST(unittest_Name, empty){
  std::vector<char> data(create_char_vector("\"\""));
  ParserContext context(data);
  Name result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "");
}

TEST(unittest_Name, regular){
  std::vector<char> data(create_char_vector("\"abcd\""));
  ParserContext context(data);
  Name result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "abcd");
}

TEST(unittest_Name, hexdigit){
  std::vector<char> data(create_char_vector("\"\\0a\""));
  ParserContext context(data);
  Name result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\x0a");
}

TEST(unittest_Name, invalid_character_single){
  std::vector<char> data(create_char_vector("\"\\90\""));
  ParserContext context(data);
  Name* result = nullptr;
  EXPECT_THROW(result = new Name(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_Name, character_double){
  std::vector<char> data(create_char_vector("\"\\c1\\a0\""));
  ParserContext context(data);
  Name result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\xc1\xa0");
}

TEST(unittest_Name, invalid_character_double){
  std::vector<char> data(create_char_vector("\"\\c1\\d1\""));
  ParserContext context(data);
  Name* result = nullptr;
  EXPECT_THROW(result = new Name(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_Name, invalid_character_double_big){
  std::vector<char> data(create_char_vector("\"\\e1\\a0\""));
  ParserContext context(data);
  Name* result = nullptr;
  EXPECT_THROW(result = new Name(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_Name, character_triple){
  std::vector<char> data(create_char_vector("\"\\e1\\82\\83\""));
  ParserContext context(data);
  Name result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\xe1\x82\x83");
}

TEST(unittest_Name, invalid_character_triple){
  std::vector<char> data(create_char_vector("\"\\e1\\93\\c2\""));
  ParserContext context(data);
  Name* result = nullptr;
  EXPECT_THROW(result = new Name(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_Name, invalid_character_triple_big){
  std::vector<char> data(create_char_vector("\"\\f1\\84\\A3\""));
  ParserContext context(data);
  Name* result = nullptr;
  EXPECT_THROW(result = new Name(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_Name, invalid_character_triple_preserved_range){
  std::vector<char> data(create_char_vector("\"\\ed\\A4\\80\""));
  ParserContext context(data);
  Name* result = nullptr;
  EXPECT_THROW(result = new Name(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_Name, character_quadruple){
  std::vector<char> data(create_char_vector("\"\\f1\\86\\83\\84\""));
  ParserContext context(data);
  Name result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, "\xf1\x86\x83\x84");
}

TEST(unittest_Name, invalid_character_quadruple){
  std::vector<char> data(create_char_vector("\"\\f1\\86\\82\\f0\""));
  ParserContext context(data);
  Name* result = nullptr;
  EXPECT_THROW(result = new Name(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_Name, invalid_character_quadruple_big){
  std::vector<char> data(create_char_vector("\"\\f4\\93\\82\\84\""));
  ParserContext context(data);
  Name* result = nullptr;
  EXPECT_THROW(result = new Name(context), Error<ErrorType::SyntaxError>);
  delete result;
}
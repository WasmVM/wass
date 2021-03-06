#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/IntegerLiteral.hpp>
#include <Helper.hpp>

TEST(unittest_IntegerLiteral, regular){
  std::vector<char> data(create_char_vector("234"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 234);
}

TEST(unittest_IntegerLiteral, plus_sign){
  std::vector<char> data(create_char_vector("+234"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 234);
}

TEST(unittest_IntegerLiteral, minus_sign){
  std::vector<char> data(create_char_vector("-234"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, -234);
}

TEST(unittest_IntegerLiteral, hex_lower){
  std::vector<char> data(create_char_vector("0x1a2b"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 0x1a2b);
}

TEST(unittest_IntegerLiteral, hex_upper){
  std::vector<char> data(create_char_vector("0x1A2B"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 0x1a2b);
}

TEST(unittest_IntegerLiteral, hex_mixed){
  std::vector<char> data(create_char_vector("0x1a2B"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 0x1a2b);
}

TEST(unittest_IntegerLiteral, non_octal){
  std::vector<char> data(create_char_vector("010"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 10);
}

TEST(unittest_IntegerLiteral, decimal_separator){
  std::vector<char> data(create_char_vector("2_000"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 2000);
}

TEST(unittest_IntegerLiteral, more_decimal_separator){
  std::vector<char> data(create_char_vector("2_000_1000"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 20001000);
}

TEST(unittest_IntegerLiteral, hex_separator){
  std::vector<char> data(create_char_vector("0xab_cd"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 0xabcd);
}

TEST(unittest_IntegerLiteral, more_hex_separator){
  std::vector<char> data(create_char_vector("0xab_cd_200"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 0xabcd200);
}

TEST(unittest_IntegerLiteral, decimal_seperator_prefix){
  std::vector<char> data(create_char_vector("_200"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, decimal_plus_seperator_prefix){
  std::vector<char> data(create_char_vector("+_200"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, decimal_minus_seperator_prefix){
  std::vector<char> data(create_char_vector("-_200"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, decimal_plus_seperator_postfix){
  std::vector<char> data(create_char_vector("200_"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, double_seperator){
  std::vector<char> data(create_char_vector("20__0"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, hex_seperator_prefix){
  std::vector<char> data(create_char_vector("_0x80"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, hex_seperator_middle){
  std::vector<char> data(create_char_vector("0_x80"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, hex_seperator_inside){
  std::vector<char> data(create_char_vector("0x_80"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, hex_seperator_postfix){
  std::vector<char> data(create_char_vector("0x80_"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_IntegerLiteral, hex_double_seperator){
  std::vector<char> data(create_char_vector("0x80__ff"));
  ParserContext context(data);
  IntegerLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}
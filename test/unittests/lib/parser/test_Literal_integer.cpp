#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Literal.hpp>
#include <Util.hpp>

TEST(unittest_Literal, i32_regular){
  std::vector<char> data(create_char_vector("234"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 234);
}

TEST(unittest_Literal, i64_regular){
  std::vector<char> data(create_char_vector("234"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 234);
}

TEST(unittest_Literal, i32_plus_sign){
  std::vector<char> data(create_char_vector("+234"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 234);
}

TEST(unittest_Literal, i64_plus_sign){
  std::vector<char> data(create_char_vector("+234"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 234);
}

TEST(unittest_Literal, i32_minus_sign){
  std::vector<char> data(create_char_vector("-234"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, -234);
}

TEST(unittest_Literal, i64_minus_sign){
  std::vector<char> data(create_char_vector("-234"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, -234);
}

TEST(unittest_Literal, i32_hex_lower){
  std::vector<char> data(create_char_vector("0x1a2b"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 0x1a2b);
}

TEST(unittest_Literal, i64_hex_lower){
  std::vector<char> data(create_char_vector("0x1a2b"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 0x1a2b);
}

TEST(unittest_Literal, i32_hex_upper){
  std::vector<char> data(create_char_vector("0x1A2B"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 0x1a2b);
}

TEST(unittest_Literal, i64_hex_upper){
  std::vector<char> data(create_char_vector("0x1A2B"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 0x1a2b);
}

TEST(unittest_Literal, i32_hex_mixed){
  std::vector<char> data(create_char_vector("0x1a2B"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 0x1a2b);
}

TEST(unittest_Literal, i64_hex_mixed){
  std::vector<char> data(create_char_vector("0x1a2B"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 0x1a2b);
}

TEST(unittest_Literal, i32_non_octal){
  std::vector<char> data(create_char_vector("010"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 10);
}

TEST(unittest_Literal, i64_non_octal){
  std::vector<char> data(create_char_vector("010"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 10);
}

TEST(unittest_Literal, i32_decimal_separator){
  std::vector<char> data(create_char_vector("2_000"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 2000);
}

TEST(unittest_Literal, i64_decimal_separator){
  std::vector<char> data(create_char_vector("2_000"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 2000);
}

TEST(unittest_Literal, i32_more_decimal_separator){
  std::vector<char> data(create_char_vector("2_000_1000"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 20001000);
}

TEST(unittest_Literal, i64_more_decimal_separator){
  std::vector<char> data(create_char_vector("2_000_1000"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 20001000);
}

TEST(unittest_Literal, i32_hex_separator){
  std::vector<char> data(create_char_vector("0xab_cd"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 0xabcd);
}

TEST(unittest_Literal, i64_hex_separator){
  std::vector<char> data(create_char_vector("0xab_cd"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 0xabcd);
}

TEST(unittest_Literal, i32_more_hex_separator){
  std::vector<char> data(create_char_vector("0xab_cd_200"));
  ParserContext context(data);
  Value::Int32 result = Litertal::parseInt32(context);
  EXPECT_EQ(result.value, 0xabcd200);
}

TEST(unittest_Literal, i64_more_hex_separator){
  std::vector<char> data(create_char_vector("0xab_cd_200"));
  ParserContext context(data);
  Value::Int64 result = Litertal::parseInt64(context);
  EXPECT_EQ(result.value, 0xabcd200);
}

TEST(unittest_Literal, i32_decimal_seperator_prefix){
  std::vector<char> data(create_char_vector("_200"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_decimal_seperator_prefix){
  std::vector<char> data(create_char_vector("_200"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_decimal_plus_seperator_prefix){
  std::vector<char> data(create_char_vector("+_200"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_decimal_plus_seperator_prefix){
  std::vector<char> data(create_char_vector("+_200"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_decimal_minus_seperator_prefix){
  std::vector<char> data(create_char_vector("-_200"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_decimal_minus_seperator_prefix){
  std::vector<char> data(create_char_vector("-_200"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_decimal_plus_seperator_postfix){
  std::vector<char> data(create_char_vector("200_"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_decimal_plus_seperator_postfix){
  std::vector<char> data(create_char_vector("200_"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_double_seperator){
  std::vector<char> data(create_char_vector("20__0"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_double_seperator){
  std::vector<char> data(create_char_vector("20__0"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_hex_seperator_prefix){
  std::vector<char> data(create_char_vector("_0x80"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_hex_seperator_prefix){
  std::vector<char> data(create_char_vector("_0x80"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_hex_seperator_middle){
  std::vector<char> data(create_char_vector("0_x80"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_hex_seperator_middle){
  std::vector<char> data(create_char_vector("0_x80"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_hex_seperator_inside){
  std::vector<char> data(create_char_vector("0x_80"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_hex_seperator_inside){
  std::vector<char> data(create_char_vector("0x_80"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_hex_seperator_postfix){
  std::vector<char> data(create_char_vector("0x80_"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_hex_seperator_postfix){
  std::vector<char> data(create_char_vector("0x80_"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i32_hex_double_seperator){
  std::vector<char> data(create_char_vector("0x80__ff"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt32(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_Literal, i64_hex_double_seperator){
  std::vector<char> data(create_char_vector("0x80__ff"));
  ParserContext context(data);
  EXPECT_THROW(Litertal::parseInt64(context), Error<ErrorType::SyntaxError>);
}
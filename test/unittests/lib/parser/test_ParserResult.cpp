#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserResult.hpp>
#include <Helper.hpp>

TEST(unittest_ParserResult, i32){
  std::vector<char> data(create_char_vector("(result i32)"));
  ParserContext context(data);
  ParserResult result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::i32);
}
TEST(unittest_ParserResult, i64){
  std::vector<char> data(create_char_vector("(result i64)"));
  ParserContext context(data);
  ParserResult result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::i64);
}
TEST(unittest_ParserResult, f32){
  std::vector<char> data(create_char_vector("(result f32)"));
  ParserContext context(data);
  ParserResult result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::f32);
}
TEST(unittest_ParserResult, f64){
  std::vector<char> data(create_char_vector("(result f64)"));
  ParserContext context(data);
  ParserResult result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::f64);
}

TEST(unittest_ParserResult, empty){
  std::vector<char> data(create_char_vector("(result)"));
  ParserContext context(data);
  ParserResult* result = nullptr;
  EXPECT_THROW(result = new ParserResult(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserResult, with_comment){
  std::vector<char> data(create_char_vector("(result (;comment;) i32)"));
  ParserContext context(data);
  ParserResult result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::i32);
}

TEST(unittest_ParserResult, empty_with_comment){
  std::vector<char> data(create_char_vector("(result(;comment;))"));
  ParserContext context(data);
  ParserResult* result = nullptr;
  EXPECT_THROW(result = new ParserResult(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserResult, with_id){
  std::vector<char> data(create_char_vector("(result $aaa i32)"));
  ParserContext context(data);
  ParserResult* result = nullptr;
  EXPECT_THROW(result = new ParserResult(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserResult, multi_value){
  std::vector<char> data(create_char_vector("(result i32 i32 i64)"));
  ParserContext context(data);
  ParserResult result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  std::vector params = std::any_cast<std::vector<ValueType>>(result);
  EXPECT_EQ(params.size(), 3);
  EXPECT_EQ(params[0], ValueType::i32);
  EXPECT_EQ(params[1], ValueType::i32);
  EXPECT_EQ(params[2], ValueType::i64);
}

TEST(unittest_ParserResult, multi_value_with_id){
  std::vector<char> data(create_char_vector("(result $aaa i32 i32 i64)"));
  ParserContext context(data);
  ParserResult* result = nullptr;
  EXPECT_THROW(result = new ParserResult(context), Error<ErrorType::ParseError>);
  delete result;
}
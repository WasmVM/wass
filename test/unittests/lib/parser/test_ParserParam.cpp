#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserParam.hpp>
#include <Helper.hpp>

TEST(unittest_ParserParam, i32){
  std::vector<char> data(create_char_vector("(param i32)"));
  ParserContext context(data);
  ParserParam result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::i32);
}
TEST(unittest_ParserParam, i64){
  std::vector<char> data(create_char_vector("(param i64)"));
  ParserContext context(data);
  ParserParam result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::i64);
}
TEST(unittest_ParserParam, f32){
  std::vector<char> data(create_char_vector("(param f32)"));
  ParserContext context(data);
  ParserParam result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::f32);
}
TEST(unittest_ParserParam, f64){
  std::vector<char> data(create_char_vector("(param f64)"));
  ParserContext context(data);
  ParserParam result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::f64);
}

TEST(unittest_ParserParam, empty){
  std::vector<char> data(create_char_vector("(param)"));
  ParserContext context(data);
  ParserParam* result = nullptr;
  EXPECT_THROW(result = new ParserParam(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserParam, with_comment){
  std::vector<char> data(create_char_vector("(param (;comment;) i32)"));
  ParserContext context(data);
  ParserParam result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::i32);
}

TEST(unittest_ParserParam, empty_with_comment){
  std::vector<char> data(create_char_vector("(param(;comment;))"));
  ParserContext context(data);
  ParserParam* result = nullptr;
  EXPECT_THROW(result = new ParserParam(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserParam, empty_with_id){
  std::vector<char> data(create_char_vector("(param $aaa)"));
  ParserContext context(data);
  ParserParam* result = nullptr;
  EXPECT_THROW(result = new ParserParam(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserParam, with_id){
  std::vector<char> data(create_char_vector("(param $aaa i32)"));
  ParserContext context(data);
  ParserParam result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result.id.c_str(), "aaa");
  ValueType param = std::any_cast<ValueType>(result);
  EXPECT_EQ(param, ValueType::i32);
}

TEST(unittest_ParserParam, multi_value){
  std::vector<char> data(create_char_vector("(param i32 i32 i64)"));
  ParserContext context(data);
  ParserParam result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  std::vector params = std::any_cast<std::vector<ValueType>>(result);
  EXPECT_EQ(params.size(), 3);
  EXPECT_EQ(params[0], ValueType::i32);
  EXPECT_EQ(params[1], ValueType::i32);
  EXPECT_EQ(params[2], ValueType::i64);
}

TEST(unittest_ParserParam, multi_value_with_id){
  std::vector<char> data(create_char_vector("(param $aaa i32 i32 i64)"));
  ParserContext context(data);
  ParserParam* result = nullptr;
  EXPECT_THROW(result = new ParserParam(context), Error<ErrorType::ParseError>);
  delete result;
}
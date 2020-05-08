#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserValueType.hpp>
#include <Helper.hpp>

TEST(unittest_ParserValue, type_i32){
  std::vector<char> data(create_char_vector("i32"));
  ParserContext context(data);
  ParserValueType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, ValueType::i32);
}

TEST(unittest_ParserValue, type_i64){
  std::vector<char> data(create_char_vector("i64"));
  ParserContext context(data);
  ParserValueType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, ValueType::i64);
}

TEST(unittest_ParserValue, type_f32){
  std::vector<char> data(create_char_vector("f32"));
  ParserContext context(data);
  ParserValueType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, ValueType::f32);
}

TEST(unittest_ParserValue, type_f64){
  std::vector<char> data(create_char_vector("f64"));
  ParserContext context(data);
  ParserValueType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, ValueType::f64);
}

TEST(unittest_ParserValue, type_none){
  std::vector<char> data(create_char_vector("f4"));
  ParserContext context(data);
  ParserValueType result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}
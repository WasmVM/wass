#include <gtest/gtest.h>

#include <any>
#include <vector>
#include <Error.hpp>
#include <structure/FuncType.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserFuncType.hpp>
#include <Helper.hpp>

TEST(unittest_ParserFuncType, empty){
  std::vector<char> data(create_char_vector("(func)"));
  ParserContext context(data);
  ParserFuncType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  FuncType funcType = std::any_cast<FuncType>(result);
  EXPECT_EQ(funcType.params.size(), 0);
  EXPECT_EQ(funcType.results.size(), 0);
}
TEST(unittest_ParserFuncType, regular){
  std::vector<char> data(create_char_vector("(func (param i32) (result i64))"));
  ParserContext context(data);
  ParserFuncType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  FuncType funcType = std::any_cast<FuncType>(result);
  EXPECT_EQ(funcType.params.size(), 1);
  EXPECT_EQ(funcType.params[0], ValueType::i32);
  EXPECT_EQ(funcType.results.size(), 1);
  EXPECT_EQ(funcType.results[0], ValueType::i64);
}
TEST(unittest_ParserFuncType, more_param){
  std::vector<char> data(create_char_vector("(func (param i32) (param f32) (result i64))"));
  ParserContext context(data);
  ParserFuncType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  FuncType funcType = std::any_cast<FuncType>(result);
  EXPECT_EQ(funcType.params.size(), 2);
  EXPECT_EQ(funcType.params[0], ValueType::i32);
  EXPECT_EQ(funcType.params[1], ValueType::f32);
  EXPECT_EQ(funcType.results.size(), 1);
  EXPECT_EQ(funcType.results[0], ValueType::i64);
}
TEST(unittest_ParserFuncType, more_result){
  std::vector<char> data(create_char_vector("(func (param i32) (result f32) (result i64))"));
  ParserContext context(data);
  ParserFuncType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  FuncType funcType = std::any_cast<FuncType>(result);
  EXPECT_EQ(funcType.params.size(), 1);
  EXPECT_EQ(funcType.params[0], ValueType::i32);
  EXPECT_EQ(funcType.results.size(), 2);
  EXPECT_EQ(funcType.results[0], ValueType::f32);
  EXPECT_EQ(funcType.results[1], ValueType::i64);
}
TEST(unittest_ParserFuncType, param_only){
  std::vector<char> data(create_char_vector("(func (param i32))"));
  ParserContext context(data);
  ParserFuncType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  FuncType funcType = std::any_cast<FuncType>(result);
  EXPECT_EQ(funcType.params.size(), 1);
  EXPECT_EQ(funcType.params[0], ValueType::i32);
  EXPECT_EQ(funcType.results.size(), 0);
}

TEST(unittest_ParserFuncType, param_with_id){
  std::vector<char> data(create_char_vector("(func (param i32) (param $aaa f32))"));
  ParserContext context(data);
  ParserFuncType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  FuncType funcType = std::any_cast<FuncType>(result);
  EXPECT_EQ(funcType.params.size(), 2);
  EXPECT_EQ(funcType.params[0], ValueType::i32);
  EXPECT_EQ(funcType.params[1], ValueType::f32);
  EXPECT_EQ(funcType.results.size(), 0);
  EXPECT_EQ(funcType.paramMap.size(), 1);
  EXPECT_EQ(funcType.paramMap["aaa"], 1);
}

TEST(unittest_ParserFuncType, result_only){
  std::vector<char> data(create_char_vector("(func (result i64))"));
  ParserContext context(data);
  ParserFuncType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  FuncType funcType = std::any_cast<FuncType>(result);
  EXPECT_EQ(funcType.params.size(), 0);
  EXPECT_EQ(funcType.results.size(), 1);
  EXPECT_EQ(funcType.results[0], ValueType::i64);
}

#include <gtest/gtest.h>

#include <any>
#include <cstdint>
#include <string>
#include <vector>
#include <Error.hpp>
#include <structure/TypeUse.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserTypeUse.hpp>
#include <Helper.hpp>

TEST(unittest_ParserTypeUse, empty){
  std::vector<char> data(create_char_vector(""));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 0);
  EXPECT_EQ(typeUse.results.size(), 0);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_FALSE(typeUse.index.has_value());
}

TEST(unittest_ParserTypeUse, param_only){
  std::vector<char> data(create_char_vector("(param f32 i64)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 2);
  EXPECT_EQ(typeUse.params[0], ValueType::f32);
  EXPECT_EQ(typeUse.params[1], ValueType::i64);
  EXPECT_EQ(typeUse.results.size(), 0);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_FALSE(typeUse.index.has_value());
}

TEST(unittest_ParserTypeUse, more_param){
  std::vector<char> data(create_char_vector("(param f32) (param i64)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 2);
  EXPECT_EQ(typeUse.params[0], ValueType::f32);
  EXPECT_EQ(typeUse.params[1], ValueType::i64);
  EXPECT_EQ(typeUse.results.size(), 0);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_FALSE(typeUse.index.has_value());
}

TEST(unittest_ParserTypeUse, result_only){
  std::vector<char> data(create_char_vector("(result f32 i64)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 0);
  EXPECT_EQ(typeUse.results.size(), 2);
  EXPECT_EQ(typeUse.results[0], ValueType::f32);
  EXPECT_EQ(typeUse.results[1], ValueType::i64);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_FALSE(typeUse.index.has_value());
}

TEST(unittest_ParserTypeUse, more_result){
  std::vector<char> data(create_char_vector("(result f32)(result i64)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 0);
  EXPECT_EQ(typeUse.results.size(), 2);
  EXPECT_EQ(typeUse.results[0], ValueType::f32);
  EXPECT_EQ(typeUse.results[1], ValueType::i64);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_FALSE(typeUse.index.has_value());
}

TEST(unittest_ParserTypeUse, param_result){
  std::vector<char> data(create_char_vector("(param i32 f64) (result f32 i64)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 2);
  EXPECT_EQ(typeUse.params[0], ValueType::i32);
  EXPECT_EQ(typeUse.params[1], ValueType::f64);
  EXPECT_EQ(typeUse.results.size(), 2);
  EXPECT_EQ(typeUse.results[0], ValueType::f32);
  EXPECT_EQ(typeUse.results[1], ValueType::i64);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_FALSE(typeUse.index.has_value());
}

TEST(unittest_ParserTypeUse, type_index){
  std::vector<char> data(create_char_vector("(type 5)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 0);
  EXPECT_EQ(typeUse.results.size(), 0);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_TRUE(typeUse.index.has_value());
  EXPECT_EQ(std::any_cast<uint32_t>(typeUse.index), 5);
}

TEST(unittest_ParserTypeUse, type_identifier){
  std::vector<char> data(create_char_vector("(type $test)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 0);
  EXPECT_EQ(typeUse.results.size(), 0);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_TRUE(typeUse.index.has_value());
  EXPECT_STREQ(std::any_cast<std::string>(typeUse.index).c_str(), "test");
}

TEST(unittest_ParserTypeUse, type_param){
  std::vector<char> data(create_char_vector("(type 5)(param i64)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 1);
  EXPECT_EQ(typeUse.params[0], ValueType::i64);
  EXPECT_EQ(typeUse.results.size(), 0);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_TRUE(typeUse.index.has_value());
  EXPECT_EQ(std::any_cast<uint32_t>(typeUse.index), 5);
}

TEST(unittest_ParserTypeUse, type_result){
  std::vector<char> data(create_char_vector("(type 5)(result i64)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 0);
  EXPECT_EQ(typeUse.results.size(), 1);
  EXPECT_EQ(typeUse.results[0], ValueType::i64);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_TRUE(typeUse.index.has_value());
  EXPECT_EQ(std::any_cast<uint32_t>(typeUse.index), 5);
}

TEST(unittest_ParserTypeUse, type_param_result){
  std::vector<char> data(create_char_vector("(type 5)(param f32)(result i64)"));
  ParserContext context(data);
  ParserTypeUse result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  TypeUse typeUse = *result;
  EXPECT_EQ(typeUse.params.size(), 1);
  EXPECT_EQ(typeUse.params[0], ValueType::f32);
  EXPECT_EQ(typeUse.results.size(), 1);
  EXPECT_EQ(typeUse.results[0], ValueType::i64);
  EXPECT_EQ(typeUse.paramMap.size(), 0);
  EXPECT_TRUE(typeUse.index.has_value());
  EXPECT_EQ(std::any_cast<uint32_t>(typeUse.index), 5);
}
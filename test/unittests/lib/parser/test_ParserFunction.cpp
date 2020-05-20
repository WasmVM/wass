#include <gtest/gtest.h>

#include <optional>
#include <vector>
#include <Error.hpp>
#include <structure/Function.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserFunction.hpp>
#include <Helper.hpp>

TEST(unittest_ParserFunction, empty){
  std::vector<char> data(create_char_vector("(func)"));
  ParserContext context(data);
  ParserFunction result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
}

TEST(unittest_ParserFunction, typeuse_only){
  std::vector<char> data(create_char_vector("(func (type $testType))"));
  ParserContext context(data);
  ParserFunction result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_TRUE(result->typeUse.index.has_value());
  EXPECT_STREQ(std::any_cast<std::string>(&result->typeUse.index)->c_str(), "testType");
}

TEST(unittest_ParserFunction, with_local){
  std::vector<char> data(create_char_vector("(func (type $testType) (local f32))"));
  ParserContext context(data);
  ParserFunction result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_TRUE(result->typeUse.index.has_value());
  EXPECT_STREQ(std::any_cast<std::string>(&result->typeUse.index)->c_str(), "testType");
  EXPECT_EQ(result->locals.size(), 1);
  EXPECT_EQ(result->locals[0], ValueType::f32);
}

TEST(unittest_ParserFunction, local_with_id){
  std::vector<char> data(create_char_vector("(func (type $testType) (local $loc f32))"));
  ParserContext context(data);
  ParserFunction result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_TRUE(result->typeUse.index.has_value());
  EXPECT_STREQ(std::any_cast<std::string>(&result->typeUse.index)->c_str(), "testType");
  EXPECT_EQ(result->locals.size(), 1);
  EXPECT_EQ(result->locals[0], ValueType::f32);
  EXPECT_EQ(result->localMap["loc"], 0);
}

TEST(unittest_ParserFunction, with_body){
  std::vector<char> data(create_char_vector("(func (type $testType) f32.const 2.0 drop)"));
  ParserContext context(data);
  ParserFunction result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->body.size(), 2);
  EXPECT_TRUE(std::holds_alternative<F32ConstInstr>(result->body[0]));
  EXPECT_TRUE(std::holds_alternative<DropInstr>(result->body[1]));
}

TEST(unittest_ParserFunction, with_id){
  std::vector<char> data(create_char_vector("(func $test (type $testType))"));
  ParserContext context(data);
  ParserFunction result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->id->c_str(), "test");
}

// TODO: Abbreviations
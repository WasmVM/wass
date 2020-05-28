#include <gtest/gtest.h>

#include <cstdint>
#include <string>
#include <Error.hpp>
#include <structure/Data.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserData.hpp>
#include <Helper.hpp>

TEST(unittest_ParserData, empty){
  std::vector<char> data(create_char_vector("(data)"));
  ParserContext context(data);
  ParserData* result = nullptr;
  EXPECT_THROW(result = new ParserData(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_ParserData, memidx_only){
  std::vector<char> data(create_char_vector("(data 0)"));
  ParserContext context(data);
  ParserData* result = nullptr;
  EXPECT_THROW(result = new ParserData(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_ParserData, no_string){
  std::vector<char> data(create_char_vector("(data 2 (offset i32.const 3))"));
  ParserContext context(data);
  ParserData result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memIndex, 2);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 3);
  EXPECT_EQ(result->data.size(), 0);
}

TEST(unittest_ParserData, single_string){
  std::vector<char> data(create_char_vector("(data 1 (offset i32.const 3) \"test\")"));
  ParserContext context(data);
  ParserData result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memIndex, 1);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 3);
  EXPECT_STREQ(result->data.c_str(), "test");
}

TEST(unittest_ParserData, two_string){
  std::vector<char> data(create_char_vector("(data 1 (offset i32.const 3) \"test\" \"string\")"));
  ParserContext context(data);
  ParserData result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memIndex, 1);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 3);
  EXPECT_STREQ(result->data.c_str(), "teststring");
}

TEST(unittest_ParserData, expr_abbreviated){
  std::vector<char> data(create_char_vector("(data 2 i32.const 3 \"test\")"));
  ParserContext context(data);
  ParserData result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memIndex, 2);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 3);
  EXPECT_STREQ(result->data.c_str(), "test");
}

TEST(unittest_ParserData, omit_memidx){
  std::vector<char> data(create_char_vector("(data i32.const 6 \"test\")"));
  ParserContext context(data);
  ParserData result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memIndex, 0);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 6);
  EXPECT_STREQ(result->data.c_str(), "test");
}
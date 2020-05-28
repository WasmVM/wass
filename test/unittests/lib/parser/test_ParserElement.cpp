#include <gtest/gtest.h>

#include <cstdint>
#include <Error.hpp>
#include <structure/Element.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserElement.hpp>
#include <Helper.hpp>

TEST(unittest_ParserElement, empty){
  std::vector<char> data(create_char_vector("(elem)"));
  ParserContext context(data);
  ParserElement* result = nullptr;
  EXPECT_THROW(result = new ParserElement(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_ParserElement, table_id_only){
  std::vector<char> data(create_char_vector("(elem 0)"));
  ParserContext context(data);
  ParserElement* result = nullptr;
  EXPECT_THROW(result = new ParserElement(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_ParserElement, no_list){
  std::vector<char> data(create_char_vector("(elem 2 (offset i32.const 3))"));
  ParserContext context(data);
  ParserElement result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableIndex, 2);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 3);
  EXPECT_EQ(result->funcIndices.size(), 0);
}

TEST(unittest_ParserElement, two_elem){
  std::vector<char> data(create_char_vector("(elem 1 (offset i32.const 3) 1 5)"));
  ParserContext context(data);
  ParserElement result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableIndex, 1);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 3);
  EXPECT_EQ(result->funcIndices.size(), 2);
  EXPECT_EQ(result->funcIndices[0], 1);
  EXPECT_EQ(result->funcIndices[1], 5);
}

TEST(unittest_ParserElement, expr_abbreviated){
  std::vector<char> data(create_char_vector("(elem 2 i32.const 3 1 5)"));
  ParserContext context(data);
  ParserElement result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableIndex, 2);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 3);
  EXPECT_EQ(result->funcIndices.size(), 2);
  EXPECT_EQ(result->funcIndices[0], 1);
  EXPECT_EQ(result->funcIndices[1], 5);
}

TEST(unittest_ParserElement, omit_tableid){
  std::vector<char> data(create_char_vector("(elem i32.const 6 1 5)"));
  ParserContext context(data);
  ParserElement result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableIndex, 0);
  EXPECT_TRUE(std::holds_alternative<I32ConstInstr>(result->expr));
  EXPECT_EQ(std::get_if<I32ConstInstr>(&result->expr)->value, 6);
  EXPECT_EQ(result->funcIndices.size(), 2);
  EXPECT_EQ(result->funcIndices[0], 1);
  EXPECT_EQ(result->funcIndices[1], 5);
}
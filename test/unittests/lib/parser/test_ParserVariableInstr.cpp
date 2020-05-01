#include <gtest/gtest.h>

#include <any>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserVariableInstr.hpp>
#include <structure/Instr.hpp>
#include <structure/VariableInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserVariableInstr, no_immediate){
  std::vector<char> data(create_char_vector("local.get"));
  ParserContext context(data);
  ParserVariableInstr* result = nullptr;
  EXPECT_THROW(result = new ParserVariableInstr(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_ParserVariableInstr, local_get){
  std::vector<char> data(create_char_vector("local.get 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(VariableInstr<InstrType::LocalGet>));
  EXPECT_EQ(std::any_cast<VariableInstr<InstrType::LocalGet>>(result).index, 1);
}

TEST(unittest_ParserVariableInstr, local_set){
  std::vector<char> data(create_char_vector("local.set 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(VariableInstr<InstrType::LocalSet>));
  EXPECT_EQ(std::any_cast<VariableInstr<InstrType::LocalSet>>(result).index, 1);
}

TEST(unittest_ParserVariableInstr, local_tee){
  std::vector<char> data(create_char_vector("local.tee 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(VariableInstr<InstrType::LocalTee>));
  EXPECT_EQ(std::any_cast<VariableInstr<InstrType::LocalTee>>(result).index, 1);
}

TEST(unittest_ParserVariableInstr, global_get){
  std::vector<char> data(create_char_vector("global.get 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(VariableInstr<InstrType::GlobalGet>));
  EXPECT_EQ(std::any_cast<VariableInstr<InstrType::GlobalGet>>(result).index, 1);
}

TEST(unittest_ParserVariableInstr, global_set){
  std::vector<char> data(create_char_vector("global.set 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(VariableInstr<InstrType::GlobalSet>));
  EXPECT_EQ(std::any_cast<VariableInstr<InstrType::GlobalSet>>(result).index, 1);
}
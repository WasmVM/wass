#include <gtest/gtest.h>

#include <any>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserVariableInstr.hpp>
#include <structure/BaseInstr.hpp>
#include <structure/VariableInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserVariableInstr, no_immediate){
  std::vector<char> data(create_char_vector("local.get"));
  ParserContext context(data);
  ParserVariableInstr* result = nullptr;
  EXPECT_THROW(result = new ParserVariableInstr(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserVariableInstr, local_get){
  std::vector<char> data(create_char_vector("local.get 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  LocalGetInstr* instr = std::get_if<LocalGetInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->index, 1);
}

TEST(unittest_ParserVariableInstr, local_set){
  std::vector<char> data(create_char_vector("local.set 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  LocalSetInstr* instr = std::get_if<LocalSetInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->index, 1);
}

TEST(unittest_ParserVariableInstr, local_tee){
  std::vector<char> data(create_char_vector("local.tee 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  LocalTeeInstr* instr = std::get_if<LocalTeeInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->index, 1);
}

TEST(unittest_ParserVariableInstr, global_get){
  std::vector<char> data(create_char_vector("global.get 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  GlobalGetInstr* instr = std::get_if<GlobalGetInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->index, 1);
}

TEST(unittest_ParserVariableInstr, global_set){
  std::vector<char> data(create_char_vector("global.set 1"));
  ParserContext context(data);
  ParserVariableInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  GlobalSetInstr* instr = std::get_if<GlobalSetInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->index, 1);
}
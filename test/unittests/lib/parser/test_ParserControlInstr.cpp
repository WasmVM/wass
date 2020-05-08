#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserControlInstr.hpp>
#include <structure/Instr.hpp>
#include <structure/ControlInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserControlInstr, unreachable){
  std::vector<char> data(create_char_vector("unreachable"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::Unreachable>));
}

TEST(unittest_ParserControlInstr, nop){
  std::vector<char> data(create_char_vector("nop"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::Nop>));
}

TEST(unittest_ParserControlInstr, Return){
  std::vector<char> data(create_char_vector("return"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::Return>));
}

TEST(unittest_ParserControlInstr, br){
  std::vector<char> data(create_char_vector("br 3"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(BrInstr));
}

TEST(unittest_ParserControlInstr, br_no_immediate){
  std::vector<char> data(create_char_vector("br"));
  ParserContext context(data);
  ParserControlInstr* result = nullptr;
  EXPECT_THROW(result = new ParserControlInstr(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_ParserControlInstr, br_if){
  std::vector<char> data(create_char_vector("br_if 3"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(BrIfInstr));
}

TEST(unittest_ParserControlInstr, br_if_no_immediate){
  std::vector<char> data(create_char_vector("br_if"));
  ParserContext context(data);
  ParserControlInstr* result = nullptr;
  EXPECT_THROW(result = new ParserControlInstr(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_ParserControlInstr, br_table){
  std::vector<char> data(create_char_vector("br_table 3 5"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(BrTableInstr));
  BrTableInstr instr = std::any_cast<BrTableInstr>(result);
  EXPECT_EQ(instr.labels.size(), 2);
  EXPECT_EQ(instr.labels[0], 3);
  EXPECT_EQ(instr.labels[1], 5);
}

TEST(unittest_ParserControlInstr, br_table_default_only){
  std::vector<char> data(create_char_vector("br_table 3"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(BrTableInstr));
  BrTableInstr instr = std::any_cast<BrTableInstr>(result);
  EXPECT_EQ(instr.labels.size(), 1);
  EXPECT_EQ(instr.labels[0], 3);
}

TEST(unittest_ParserControlInstr, br_table_no_immediate){
  std::vector<char> data(create_char_vector("br_table"));
  ParserContext context(data);
  ParserControlInstr* result = nullptr;
  EXPECT_THROW(result = new ParserControlInstr(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_ParserControlInstr, call){
  std::vector<char> data(create_char_vector("call 3"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(CallInstr));
}

TEST(unittest_ParserControlInstr, call_no_immediate){
  std::vector<char> data(create_char_vector("call"));
  ParserContext context(data);
  ParserControlInstr* result = nullptr;
  EXPECT_THROW(result = new ParserControlInstr(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_ParserControlInstr, call_indirect){
  std::vector<char> data(create_char_vector("call_indirect (type 3)"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(CallIndirectInstr));
  CallIndirectInstr instr = std::any_cast<CallIndirectInstr>(result);
  EXPECT_EQ(std::any_cast<uint32_t>(instr.type.index), 3);
  EXPECT_EQ(instr.type.params.size(), 0);
  EXPECT_EQ(instr.type.results.size(), 0);
}

TEST(unittest_ParserControlInstr, call_indirect_no_immediate){
  std::vector<char> data(create_char_vector("call_indirect"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(CallIndirectInstr));
  CallIndirectInstr instr = std::any_cast<CallIndirectInstr>(result);
  EXPECT_FALSE(instr.type.index.has_value());
  EXPECT_EQ(instr.type.params.size(), 0);
  EXPECT_EQ(instr.type.results.size(), 0);
}
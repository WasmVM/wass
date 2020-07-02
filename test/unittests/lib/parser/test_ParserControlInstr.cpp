#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserControlInstr.hpp>
#include <structure/BaseInstr.hpp>
#include <structure/ControlInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserControlInstr, unreachable){
  std::vector<char> data(create_char_vector("unreachable"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<UnreachableInstr>(&result), nullptr);
}

TEST(unittest_ParserControlInstr, nop){
  std::vector<char> data(create_char_vector("nop"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<NopInstr>(&result), nullptr);
}

TEST(unittest_ParserControlInstr, Return){
  std::vector<char> data(create_char_vector("return"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<ReturnInstr>(&result), nullptr);
}

TEST(unittest_ParserControlInstr, br){
  std::vector<char> data(create_char_vector("br 3"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BrInstr* instrPtr = std::get_if<BrInstr>(&result);
  EXPECT_NE(instrPtr, nullptr);
  EXPECT_EQ(std::get<uint32_t>(instrPtr->label), 3);
}

TEST(unittest_ParserControlInstr, br_by_id){
  std::vector<char> data(create_char_vector("br $test"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BrInstr* instrPtr = std::get_if<BrInstr>(&result);
  EXPECT_NE(instrPtr, nullptr);
  EXPECT_STREQ(std::get<std::string>(instrPtr->label).c_str(), "test");
}

TEST(unittest_ParserControlInstr, br_no_immediate){
  std::vector<char> data(create_char_vector("br"));
  ParserContext context(data);
  ParserControlInstr* result = nullptr;
  EXPECT_THROW(result = new ParserControlInstr(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserControlInstr, br_if){
  std::vector<char> data(create_char_vector("br_if 3"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BrIfInstr* instrPtr = std::get_if<BrIfInstr>(&result);
  EXPECT_NE(instrPtr, nullptr);
  EXPECT_EQ(std::get<uint32_t>(instrPtr->label), 3);
}

TEST(unittest_ParserControlInstr, br_if_by_id){
  std::vector<char> data(create_char_vector("br_if $test"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BrIfInstr* instrPtr = std::get_if<BrIfInstr>(&result);
  EXPECT_NE(instrPtr, nullptr);
  EXPECT_STREQ(std::get<std::string>(instrPtr->label).c_str(), "test");
}

TEST(unittest_ParserControlInstr, br_if_no_immediate){
  std::vector<char> data(create_char_vector("br_if"));
  ParserContext context(data);
  ParserControlInstr* result = nullptr;
  EXPECT_THROW(result = new ParserControlInstr(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserControlInstr, br_table){
  std::vector<char> data(create_char_vector("br_table 3 5"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BrTableInstr* instr = std::get_if<BrTableInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->labels.size(), 2);
  EXPECT_EQ(std::get<uint32_t>(instr->labels[0]), 3);
  EXPECT_EQ(std::get<uint32_t>(instr->labels[1]), 5);
}

TEST(unittest_ParserControlInstr, br_table_by_id){
  std::vector<char> data(create_char_vector("br_table $test 5"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BrTableInstr* instr = std::get_if<BrTableInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->labels.size(), 2);
  EXPECT_STREQ(std::get<std::string>(instr->labels[0]).c_str(), "test");
  EXPECT_EQ(std::get<uint32_t>(instr->labels[1]), 5);
}

TEST(unittest_ParserControlInstr, br_table_default_only){
  std::vector<char> data(create_char_vector("br_table 3"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BrTableInstr* instr = std::get_if<BrTableInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->labels.size(), 1);
  EXPECT_EQ(std::get<uint32_t>(instr->labels[0]), 3);
}

TEST(unittest_ParserControlInstr, br_table_no_immediate){
  std::vector<char> data(create_char_vector("br_table"));
  ParserContext context(data);
  ParserControlInstr* result = nullptr;
  EXPECT_THROW(result = new ParserControlInstr(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserControlInstr, call){
  std::vector<char> data(create_char_vector("call 3"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  CallInstr* instrPtr = std::get_if<CallInstr>(&result);
  EXPECT_NE(instrPtr, nullptr);
  EXPECT_EQ(std::get<uint32_t>(instrPtr->funcidx), 3);
}

TEST(unittest_ParserControlInstr, call_by_id){
  std::vector<char> data(create_char_vector("call $test"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  CallInstr* instrPtr = std::get_if<CallInstr>(&result);
  EXPECT_NE(instrPtr, nullptr);
  EXPECT_STREQ(std::get<std::string>(instrPtr->funcidx).c_str(), "test");
}

TEST(unittest_ParserControlInstr, call_no_immediate){
  std::vector<char> data(create_char_vector("call"));
  ParserContext context(data);
  ParserControlInstr* result = nullptr;
  EXPECT_THROW(result = new ParserControlInstr(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserControlInstr, call_indirect){
  std::vector<char> data(create_char_vector("call_indirect (type 3)"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  CallIndirectInstr* instr = std::get_if<CallIndirectInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(std::get<uint32_t>(*(instr->type.index)), 3);
  EXPECT_EQ(instr->type.params.size(), 0);
  EXPECT_EQ(instr->type.results.size(), 0);
}

TEST(unittest_ParserControlInstr, call_indirect_no_immediate){
  std::vector<char> data(create_char_vector("call_indirect"));
  ParserContext context(data);
  ParserControlInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  CallIndirectInstr* instr = std::get_if<CallIndirectInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_FALSE(instr->type.index.has_value());
  EXPECT_EQ(instr->type.params.size(), 0);
  EXPECT_EQ(instr->type.results.size(), 0);
}
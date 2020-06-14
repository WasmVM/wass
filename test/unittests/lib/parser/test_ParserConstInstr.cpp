#include <gtest/gtest.h>

#include <variant>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserConstInstr.hpp>
#include <structure/BaseInstr.hpp>
#include <structure/ConstInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserConstInstr, i32_const){
  std::vector<char> data(create_char_vector("i32.const 32"));
  ParserContext context(data);
  ParserConstInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32ConstInstr* instr = std::get_if<I32ConstInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->value, 32);
}

TEST(unittest_ParserConstInstr, no_immediate){
  std::vector<char> data(create_char_vector("i32.const"));
  ParserContext context(data);
  ParserConstInstr* result = nullptr;
  EXPECT_THROW(result = new ParserConstInstr(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserConstInstr, i64_const){
  std::vector<char> data(create_char_vector("i64.const 64"));
  ParserContext context(data);
  ParserConstInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64ConstInstr>(&result), nullptr);
  I64ConstInstr* instr = std::get_if<I64ConstInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_EQ(instr->value, 64);
}

TEST(unittest_ParserConstInstr, f32_const){
  std::vector<char> data(create_char_vector("f32.const 3.2"));
  ParserContext context(data);
  ParserConstInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32ConstInstr>(&result), nullptr);
  F32ConstInstr* instr = std::get_if<F32ConstInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_FLOAT_EQ(instr->value, 3.2);
}

TEST(unittest_ParserConstInstr, f64_const){
  std::vector<char> data(create_char_vector("f64.const 0.7"));
  ParserContext context(data);
  ParserConstInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64ConstInstr>(&result), nullptr);
  F64ConstInstr* instr = std::get_if<F64ConstInstr>(&result);
  EXPECT_NE(instr, nullptr);
  EXPECT_FLOAT_EQ(instr->value, 0.7);
}

#include <gtest/gtest.h>

#include <any>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserConstInstr.hpp>
#include <structure/Instr.hpp>
#include <structure/ConstInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserConstInstr, i32_const){
  std::vector<char> data(create_char_vector("i32.const 32"));
  ParserContext context(data);
  ParserConstInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(I32ConstInstr));
  EXPECT_EQ(std::any_cast<I32ConstInstr>(result).value, 32);
}

TEST(unittest_ParserConstInstr, no_immediate){
  std::vector<char> data(create_char_vector("i32.const"));
  ParserContext context(data);
  ParserConstInstr* result = nullptr;
  EXPECT_THROW(result = new ParserConstInstr(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_ParserConstInstr, i64_const){
  std::vector<char> data(create_char_vector("i64.const 64"));
  ParserContext context(data);
  ParserConstInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(I64ConstInstr));
  EXPECT_EQ(std::any_cast<I64ConstInstr>(result).value, 64);
}

TEST(unittest_ParserConstInstr, f32_const){
  std::vector<char> data(create_char_vector("f32.const 3.2"));
  ParserContext context(data);
  ParserConstInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(F32ConstInstr));
  EXPECT_FLOAT_EQ(std::any_cast<F32ConstInstr>(result).value, 3.2);
}

TEST(unittest_ParserConstInstr, f64_const){
  std::vector<char> data(create_char_vector("f64.const 0.7"));
  ParserContext context(data);
  ParserConstInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(F64ConstInstr));
  EXPECT_FLOAT_EQ(std::any_cast<F64ConstInstr>(result).value, 0.7);
}

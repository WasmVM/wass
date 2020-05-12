#include <gtest/gtest.h>

#include <variant>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserBlockedInstr.hpp>
#include <structure/BlockedInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserBlockedInstr, block){
  std::vector<char> data(create_char_vector("block $test (result f32) f32.const 3.2 end"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BlockInstr* instr = std::get_if<BlockInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
}

TEST(unittest_ParserBlockedInstr, block_with_postfix){
  std::vector<char> data(create_char_vector("block $test (result f32 i64) f32.const 3.2 i64.const 5 end $test"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BlockInstr* instr = std::get_if<BlockInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 2);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->resultTypes[1], ValueType::i64);
  EXPECT_EQ(instr->instrs.size(), 2);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
  EXPECT_NE(std::get_if<I64ConstInstr>(&(instr->instrs[1])), nullptr);
  EXPECT_EQ(std::get_if<I64ConstInstr>(&(instr->instrs[1]))->value, 5);
}

TEST(unittest_ParserBlockedInstr, block_without_id){
  std::vector<char> data(create_char_vector("block (result f32) f32.const 3.2 end"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BlockInstr* instr = std::get_if<BlockInstr>(&result);
  EXPECT_FALSE(instr->id.has_value());
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
}

TEST(unittest_ParserBlockedInstr, block_without_result){
  std::vector<char> data(create_char_vector("block f32.const 3.2 drop end"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BlockInstr* instr = std::get_if<BlockInstr>(&result);
  EXPECT_FALSE(instr->id.has_value());
  EXPECT_EQ(instr->resultTypes.size(), 0);
  EXPECT_EQ(instr->instrs.size(), 2);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
  EXPECT_NE(std::get_if<DropInstr>(&(instr->instrs[1])), nullptr);
}

TEST(unittest_ParserBlockedInstr, loop){
  std::vector<char> data(create_char_vector("loop $test (result f32) f32.const 3.2 end"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  LoopInstr* instr = std::get_if<LoopInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
}

TEST(unittest_ParserBlockedInstr, If){
  std::vector<char> data(create_char_vector("if $test (result f32) f32.const 3.2 else f32.const 0.5 end"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  IfInstr* instr = std::get_if<IfInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
  EXPECT_EQ(instr->elseInstrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->elseInstrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->elseInstrs[0]))->value, 0.5);
}

TEST(unittest_ParserBlockedInstr, If_without_else){
  std::vector<char> data(create_char_vector("if $test (result f32) f32.const 3.2 end"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  IfInstr* instr = std::get_if<IfInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
  EXPECT_EQ(instr->elseInstrs.size(), 0);
}

TEST(unittest_ParserBlockedInstr, block_folded){
  std::vector<char> data(create_char_vector("(block (result f32) f32.const 3.2)"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  BlockInstr* instr = std::get_if<BlockInstr>(&result);
  EXPECT_FALSE(instr->id.has_value());
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
}

TEST(unittest_ParserBlockedInstr, loop_folded){
  std::vector<char> data(create_char_vector("(loop $test (result f32) f32.const 3.2)"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  LoopInstr* instr = std::get_if<LoopInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
}

TEST(unittest_ParserBlockedInstr, folded){
  std::vector<char> data(create_char_vector("(drop (i32.const 2))"));
  ParserContext context(data);
  ParserFoldedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32ConstInstr>(&(result->at(0))), nullptr);
  EXPECT_EQ(std::get_if<I32ConstInstr>(&(result->at(0)))->value, 2);
  EXPECT_NE(std::get_if<DropInstr>(&(result->at(1))), nullptr);
}

TEST(unittest_ParserBlockedInstr, folded_plain_only){
  std::vector<char> data(create_char_vector("(nop)"));
  ParserContext context(data);
  ParserFoldedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<NopInstr>(&(result->at(0))), nullptr);
}

TEST(unittest_ParserBlockedInstr, folded_more){
  std::vector<char> data(create_char_vector("(drop (i32.const 2) (i32.const 3))"));
  ParserContext context(data);
  ParserFoldedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32ConstInstr>(&(result->at(0))), nullptr);
  EXPECT_EQ(std::get_if<I32ConstInstr>(&(result->at(0)))->value, 2);
  EXPECT_NE(std::get_if<I32ConstInstr>(&(result->at(1))), nullptr);
  EXPECT_EQ(std::get_if<I32ConstInstr>(&(result->at(1)))->value, 3);
  EXPECT_NE(std::get_if<DropInstr>(&(result->at(2))), nullptr);
}

TEST(unittest_ParserBlockedInstr, folded_If){
  std::vector<char> data(create_char_vector("(if $test (result f32) (then f32.const 3.2) (else f32.const 0.5))"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  IfInstr* instr = std::get_if<IfInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
  EXPECT_EQ(instr->elseInstrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->elseInstrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->elseInstrs[0]))->value, 0.5);
}

TEST(unittest_ParserBlockedInstr, folded_If_with_folded){
  std::vector<char> data(create_char_vector("(if $test (result f32) (i32.const 6) (then f32.const 3.2) (else f32.const 0.5))"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  IfInstr* instr = std::get_if<IfInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
  EXPECT_EQ(instr->elseInstrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->elseInstrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->elseInstrs[0]))->value, 0.5);
  EXPECT_EQ(instr->foldedInstrs.size(), 1);
  EXPECT_NE(std::get_if<I32ConstInstr>(&(instr->foldedInstrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<I32ConstInstr>(&(instr->foldedInstrs[0]))->value, 6);
}

TEST(unittest_ParserBlockedInstr, folded_If_without_else){
  std::vector<char> data(create_char_vector("(if $test (result f32) (then f32.const 3.2))"));
  ParserContext context(data);
  ParserBlockedInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  IfInstr* instr = std::get_if<IfInstr>(&result);
  EXPECT_STREQ(instr->id->c_str(), "test");
  EXPECT_EQ(instr->resultTypes.size(), 1);
  EXPECT_EQ(instr->resultTypes[0], ValueType::f32);
  EXPECT_EQ(instr->instrs.size(), 1);
  EXPECT_NE(std::get_if<F32ConstInstr>(&(instr->instrs[0])), nullptr);
  EXPECT_FLOAT_EQ(std::get_if<F32ConstInstr>(&(instr->instrs[0]))->value, 3.2);
  EXPECT_EQ(instr->elseInstrs.size(), 0);
}

TEST(unittest_ParserBlockedInstr, folded_If_without_then){
  std::vector<char> data(create_char_vector("(if $test (result f32))"));
  ParserContext context(data);
  ParserBlockedInstr* result = nullptr;
  EXPECT_THROW(result = new ParserBlockedInstr(context), Error<ErrorType::SyntaxError>);
  delete result;
}
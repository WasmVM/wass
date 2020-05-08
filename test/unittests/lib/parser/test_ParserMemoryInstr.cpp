#include <gtest/gtest.h>

#include <variant>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserMemoryInstr.hpp>
#include <structure/BaseInstr.hpp>
#include <structure/MemoryInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserMemoryInstr, with_align_offset){
  std::vector<char> data(create_char_vector("i32.load offset=3 align=2"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32LoadInstr* instr = std::get_if<I32LoadInstr>(&result);
  EXPECT_EQ(instr->offset, 3);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, with_offset){
  std::vector<char> data(create_char_vector("i32.load offset=3"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32LoadInstr* instr = std::get_if<I32LoadInstr>(&result);
  EXPECT_EQ(instr->offset, 3);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, with_align){
  std::vector<char> data(create_char_vector("i32.load align=2"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32LoadInstr* instr = std::get_if<I32LoadInstr>(&result);
  EXPECT_EQ(instr->align, 2);
  EXPECT_EQ(instr->offset, 0);
}

TEST(unittest_ParserMemoryInstr, reverse_align_offset){
  std::vector<char> data(create_char_vector("i32.load align=2 offset=3"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.begin() + 16);
  I32LoadInstr* instr = std::get_if<I32LoadInstr>(&result);
  EXPECT_EQ(instr->align, 2);
  EXPECT_EQ(instr->offset, 0);
}

TEST(unittest_ParserMemoryInstr, i32_load){
  std::vector<char> data(create_char_vector("i32.load"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32LoadInstr* instr = std::get_if<I32LoadInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, i64_load){
  std::vector<char> data(create_char_vector("i64.load"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64LoadInstr* instr = std::get_if<I64LoadInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, f32_load){
  std::vector<char> data(create_char_vector("f32.load"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  F32LoadInstr* instr = std::get_if<F32LoadInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, f64_load){
  std::vector<char> data(create_char_vector("f64.load"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  F64LoadInstr* instr = std::get_if<F64LoadInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i32_load8_s){
  std::vector<char> data(create_char_vector("i32.load8_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32Load8SInstr* instr = std::get_if<I32Load8SInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, i32_load8_u){
  std::vector<char> data(create_char_vector("i32.load8_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32Load8UInstr* instr = std::get_if<I32Load8UInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, i32_load16_s){
  std::vector<char> data(create_char_vector("i32.load16_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32Load16SInstr* instr = std::get_if<I32Load16SInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, i32_load16_u){
  std::vector<char> data(create_char_vector("i32.load16_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32Load16UInstr* instr = std::get_if<I32Load16UInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, i64_load8_s){
  std::vector<char> data(create_char_vector("i64.load8_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Load8SInstr* instr = std::get_if<I64Load8SInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load8_u){
  std::vector<char> data(create_char_vector("i64.load8_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Load8UInstr* instr = std::get_if<I64Load8UInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load16_s){
  std::vector<char> data(create_char_vector("i64.load16_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Load16SInstr* instr = std::get_if<I64Load16SInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load16_u){
  std::vector<char> data(create_char_vector("i64.load16_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Load16UInstr* instr = std::get_if<I64Load16UInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load32_s){
  std::vector<char> data(create_char_vector("i64.load32_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Load32SInstr* instr = std::get_if<I64Load32SInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load32_u){
  std::vector<char> data(create_char_vector("i64.load32_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Load32UInstr* instr = std::get_if<I64Load32UInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i32_store){
  std::vector<char> data(create_char_vector("i32.store"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32StoreInstr* instr = std::get_if<I32StoreInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, i64_store){
  std::vector<char> data(create_char_vector("i64.store"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64StoreInstr* instr = std::get_if<I64StoreInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, f32_store){
  std::vector<char> data(create_char_vector("f32.store"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  F32StoreInstr* instr = std::get_if<F32StoreInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, f64_store){
  std::vector<char> data(create_char_vector("f64.store"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  F64StoreInstr* instr = std::get_if<F64StoreInstr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i32_store8){
  std::vector<char> data(create_char_vector("i32.store8"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32Store8Instr* instr = std::get_if<I32Store8Instr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, i32_store16){
  std::vector<char> data(create_char_vector("i32.store16"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I32Store16Instr* instr = std::get_if<I32Store16Instr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 2);
}

TEST(unittest_ParserMemoryInstr, i64_store8){
  std::vector<char> data(create_char_vector("i64.store8"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Store8Instr* instr = std::get_if<I64Store8Instr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_store16){
  std::vector<char> data(create_char_vector("i64.store16"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Store16Instr* instr = std::get_if<I64Store16Instr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_store32){
  std::vector<char> data(create_char_vector("i64.store32"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  I64Store32Instr* instr = std::get_if<I64Store32Instr>(&result);
  EXPECT_EQ(instr->offset, 0);
  EXPECT_EQ(instr->align, 3);
}

TEST(unittest_ParserMemoryInstr, memory_size){
  std::vector<char> data(create_char_vector("memory.size"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  MemorySizeInstr* instr = std::get_if<MemorySizeInstr>(&result);
  EXPECT_NE(instr, nullptr);
}

TEST(unittest_ParserMemoryInstr, memory_grow){
  std::vector<char> data(create_char_vector("memory.grow"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  MemoryGrowInstr* instr = std::get_if<MemoryGrowInstr>(&result);
  EXPECT_NE(instr, nullptr);
}
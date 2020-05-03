#include <gtest/gtest.h>

#include <any>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserMemoryInstr.hpp>
#include <structure/Instr.hpp>
#include <structure/MemoryInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserMemoryInstr, with_align_offset){
  std::vector<char> data(create_char_vector("i32.load offset=3 align=2"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).offset, 3);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, with_offset){
  std::vector<char> data(create_char_vector("i32.load offset=3"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).offset, 3);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, with_align){
  std::vector<char> data(create_char_vector("i32.load align=2"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).align, 2);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).offset, 0);
}

TEST(unittest_ParserMemoryInstr, reverse_align_offset){
  std::vector<char> data(create_char_vector("i32.load align=2 offset=3"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.begin() + 16);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).align, 2);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).offset, 0);
}

TEST(unittest_ParserMemoryInstr, i32_load){
  std::vector<char> data(create_char_vector("i32.load"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, i64_load){
  std::vector<char> data(create_char_vector("i64.load"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Load>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, f32_load){
  std::vector<char> data(create_char_vector("f32.load"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::F32Load>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::F32Load>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::F32Load>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, f64_load){
  std::vector<char> data(create_char_vector("f64.load"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::F64Load>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::F64Load>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::F64Load>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i32_load8_s){
  std::vector<char> data(create_char_vector("i32.load8_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load8S>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load8S>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load8S>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, i32_load8_u){
  std::vector<char> data(create_char_vector("i32.load8_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load8U>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load8U>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load8U>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, i32_load16_s){
  std::vector<char> data(create_char_vector("i32.load16_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load16S>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load16S>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load16S>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, i32_load16_u){
  std::vector<char> data(create_char_vector("i32.load16_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Load16U>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load16U>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Load16U>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, i64_load8_s){
  std::vector<char> data(create_char_vector("i64.load8_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Load8S>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load8S>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load8S>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load8_u){
  std::vector<char> data(create_char_vector("i64.load8_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Load8U>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load8U>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load8U>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load16_s){
  std::vector<char> data(create_char_vector("i64.load16_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Load16S>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load16S>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load16S>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load16_u){
  std::vector<char> data(create_char_vector("i64.load16_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Load16U>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load16U>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load16U>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load32_s){
  std::vector<char> data(create_char_vector("i64.load32_s"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Load32S>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load32S>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load32S>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_load32_u){
  std::vector<char> data(create_char_vector("i64.load32_u"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Load32U>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load32U>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Load32U>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i32_store){
  std::vector<char> data(create_char_vector("i32.store"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Store>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Store>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Store>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, i64_store){
  std::vector<char> data(create_char_vector("i64.store"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Store>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Store>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Store>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, f32_store){
  std::vector<char> data(create_char_vector("f32.store"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::F32Store>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::F32Store>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::F32Store>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, f64_store){
  std::vector<char> data(create_char_vector("f64.store"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::F64Store>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::F64Store>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::F64Store>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i32_store8){
  std::vector<char> data(create_char_vector("i32.store8"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Store8>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Store8>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Store8>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, i32_store16){
  std::vector<char> data(create_char_vector("i32.store16"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I32Store16>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Store16>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I32Store16>>(result).align, 2);
}

TEST(unittest_ParserMemoryInstr, i64_store8){
  std::vector<char> data(create_char_vector("i64.store8"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Store8>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Store8>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Store8>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_store16){
  std::vector<char> data(create_char_vector("i64.store16"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Store16>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Store16>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Store16>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, i64_store32){
  std::vector<char> data(create_char_vector("i64.store32"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::I64Store32>));
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Store32>>(result).offset, 0);
  EXPECT_EQ(std::any_cast<MemoryInstr<InstrType::I64Store32>>(result).align, 3);
}

TEST(unittest_ParserMemoryInstr, memory_size){
  std::vector<char> data(create_char_vector("memory.size"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::MemorySize>));
}

TEST(unittest_ParserMemoryInstr, memory_grow){
  std::vector<char> data(create_char_vector("memory.grow"));
  ParserContext context(data);
  ParserMemoryInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(MemoryInstr<InstrType::MemoryGrow>));
}
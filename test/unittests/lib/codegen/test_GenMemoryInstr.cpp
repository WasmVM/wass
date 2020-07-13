#include <gtest/gtest.h>

#include <variant>
#include <structure/MemoryInstr.hpp>
#include <BinaryCode.hpp>
#include <codegen/CodeGenVisitor.hpp>

TEST(unittest_GenMemoryInstr, i32_load){
  I32LoadInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x28', '\x05', '\x09'}));
}

TEST(unittest_GenMemoryInstr, i32_load8_s){
  I32Load8SInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x2C', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i32_load8_u){
  I32Load8UInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x2D', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i32_load16_s){
  I32Load16SInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x2E', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i32_load16_u){
  I32Load16UInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x2F', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i32_store){
  I32StoreInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x36', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i32_store8){
  I32Store8Instr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x3A', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i32_store16){
  I32Store16Instr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x3B', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_load){
  I64LoadInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x29', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_load8_s){
  I64Load8SInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x30', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_load8_u){
  I64Load8UInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x31', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_load16_s){
  I64Load16SInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x32', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_load16_u){
  I64Load16UInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x33', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_load32_s){
  I64Load32SInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x34', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_load32_u){
  I64Load32UInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x35', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_store){
  I64StoreInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x37', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_store8){
  I64Store8Instr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x3C', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_store18){
  I64Store16Instr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x3D', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, i64_store32){
  I64Store32Instr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x3E', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, f32_load){
  F32LoadInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x2A', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, f32_store){
  F32StoreInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x38', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, f64_load){
  F64LoadInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x2B', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, f64_store){
  F64StoreInstr data;
  data.align = 5;
  data.offset = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x39', '\x05', '\x09'}));
}
TEST(unittest_GenMemoryInstr, memory_size){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(MemorySizeInstr())), BinaryCode({'\x3F', '\x00'}));
}
TEST(unittest_GenMemoryInstr, memory_grow){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(MemoryGrowInstr())), BinaryCode({'\x40', '\x00'}));
}
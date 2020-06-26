#include <gtest/gtest.h>

#include <variant>
#include <Error.hpp>
#include <structure/ConstInstr.hpp>
#include <structure/InstrVariant.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenConstInstr, i32_positive){
  I32ConstInstr data;
  data.value = 5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x41', '\x05'}));
}

TEST(unittest_GenConstInstr, i32_negative){
  I32ConstInstr data;
  data.value = -2;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x41', '\x7E'}));
}

TEST(unittest_GenConstInstr, i64_positive){
  I64ConstInstr data;
  data.value = 10;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x42', '\x0A'}));
}

TEST(unittest_GenConstInstr, i64_negative){
  I64ConstInstr data;
  data.value = -10;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x42', '\x76'}));
}

TEST(unittest_GenConstInstr, f32){
  F32ConstInstr data;
  data.value = 2.5f;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x43', '\x00', '\x00', '\x20', '\x40'}));
}

TEST(unittest_GenConstInstr, f64){
  F64ConstInstr data;
  data.value = 2.5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x44', '\x00', '\x00', '\x00', '\x00', '\x00', '\x00', '\x04', '\x40'}));
}
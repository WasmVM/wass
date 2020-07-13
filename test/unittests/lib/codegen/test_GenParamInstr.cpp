#include <gtest/gtest.h>

#include <variant>
#include <structure/ParamInstr.hpp>
#include <BinaryCode.hpp>
#include <codegen/CodeGenVisitor.hpp>

TEST(unittest_GenParamInstr, Drop){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(DropInstr())), BinaryCode({'\x1A'}));
}

TEST(unittest_GenParamInstr, Select){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(SelectInstr())), BinaryCode({'\x1B'}));
}
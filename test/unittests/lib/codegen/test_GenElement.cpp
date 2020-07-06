#include <gtest/gtest.h>

#include <variant>
#include <Error.hpp>
#include <structure/Element.hpp>
#include <structure/InstrVariant.hpp>
#include <structure/ConstInstr.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenElement, one_index){
  Element data;
  data.tableIndex = 2;
  data.expr.emplace<I32ConstInstr>().value = 7;
  data.funcIndices.emplace_back(3);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x02', '\x41', '\x07', '\x01', '\x03'}));
}

TEST(unittest_GenElement, two_indices){
  Element data;
  data.tableIndex = 2;
  data.expr.emplace<I32ConstInstr>().value = 7;
  data.funcIndices.emplace_back(3);
  data.funcIndices.emplace_back(6);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x02', '\x41', '\x07', '\x02', '\x03', '\x06'}));
}
#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/Data.hpp>
#include <structure/Index.hpp>
#include <structure/InstrVariant.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenData, with_datastring){
  Data data;
  data.memIndex.emplace<uint32_t>(4);
  I32ConstInstr& expr = data.expr.emplace<I32ConstInstr>(I32ConstInstr());
  expr.value = 5;
  data.data = "test";
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    '\x04',
    '\x41', '\x05',
    '\x04', 't', 'e', 's', 't'
  }));
}

TEST(unittest_GenData, without_datastring){
  Data data;
  data.memIndex.emplace<uint32_t>(4);
  I32ConstInstr& expr = data.expr.emplace<I32ConstInstr>(I32ConstInstr());
  expr.value = 5;
  data.data = "";
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    '\x04',
    '\x41', '\x05',
    '\x00'
  }));
}

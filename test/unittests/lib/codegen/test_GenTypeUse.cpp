#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/TypeUse.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenTypeUse, typeidx){
  TypeUse data;
  data.index = (uint32_t) 3;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x03'}));
}

TEST(unittest_GenTypeUse, identifier){
  TypeUse data;
  data.index = "test";
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x00', '\x00'}));
}
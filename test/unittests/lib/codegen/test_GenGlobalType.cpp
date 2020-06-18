#include <gtest/gtest.h>

#include <variant>
#include <Error.hpp>
#include <structure/GlobalType.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenGlobalType, const_value){
  GlobalType data;
  data.immutable = true;
  data.type = ValueType::i32;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x7F', '\x00'}));
}

TEST(unittest_GenGlobalType, mutable_value){
  GlobalType data;
  data.immutable = false;
  data.type = ValueType::i32;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x7F', '\x01'}));
}
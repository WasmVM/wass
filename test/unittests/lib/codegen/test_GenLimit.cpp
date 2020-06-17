#include <gtest/gtest.h>

#include <variant>
#include <structure/Limit.hpp>
#include <BinaryCode.hpp>
#include <codegen/CodeGenVisitor.hpp>

TEST(unittest_GenLimit, min_only){
  Limit data;
  data.min = 5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x00', '\x05'}));
}

TEST(unittest_GenLimit, min_max){
  Limit data;
  data.min = 6;
  data.max = 8;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x01', '\x06', '\x08'}));
}

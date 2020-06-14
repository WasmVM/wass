#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/Module.hpp>
#include <structure/Type.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <BinaryCode.hpp>
#include <Helper.hpp>

TEST(unittest_GenModule, empty){
  Module data;
  EXPECT_EQ(std::visit<BinaryCode>(CodeGenVisitor(), CodeGenVariant(data)), BinaryCode({BIN_MAGIC, BIN_VERSION}));
}

TEST(unittest_GenModule, type_section){
  Module data;
  data.types.push_back(Type());
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION, '\x01',
    '\x01', '\x60', '\x00', '\x00'
  }));
}
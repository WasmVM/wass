#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/Type.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenType, no_id){
  FuncType data;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x00', '\x00'}));
}

TEST(unittest_GenType, with_id){
  Type data;
  data.id = "test";
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x00', '\x00'}));
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 0);
}

TEST(unittest_GenType, id_not_unique){
  Type data;
  data.id = "test";
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["test"] = 1;
  EXPECT_THROW(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), Error<ErrorType::GenerateError>);
}
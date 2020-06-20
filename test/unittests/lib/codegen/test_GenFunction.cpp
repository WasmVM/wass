#include <gtest/gtest.h>

#include <variant>
#include <any>
#include <Error.hpp>
#include <structure/Function.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <BinaryCode.hpp>
#include <Helper.hpp>

TEST(unittest_GenFunction, regular){
  Function data;
  data.typeUse.index = (uint32_t) 3;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x03'}));
  EXPECT_EQ(visitor.getContext().funcCount, 1);
}

TEST(unittest_GenFunction, regular_with_id){
  Function data;
  data.id = "test";
  data.typeUse.index = (uint32_t) 3;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x03'}));
  EXPECT_EQ(visitor.getContext().funcCount, 1);
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 0);
}

TEST(unittest_GenFunction, import){
  Function data;
  data.typeUse.index = (uint32_t) 3;
  data.importModule = "mod";
  data.importName = "func";
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode());
  EXPECT_EQ(visitor.getContext().funcCount, 1);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().import));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x03', 'm', 'o', 'd',
    '\x04', 'f', 'u', 'n', 'c',
    '\x00', '\x03'
  }));
}

TEST(unittest_GenFunction, import_with_id){
  Function data;
  data.id = "test";
  data.typeUse.index = (uint32_t) 3;
  data.importModule = "mod";
  data.importName = "func";
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode());
  EXPECT_EQ(visitor.getContext().funcCount, 1);
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 0);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().import));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x03', 'm', 'o', 'd',
    '\x04', 'f', 'u', 'n', 'c',
    '\x00', '\x03'
  }));
}

// TODO: inline export
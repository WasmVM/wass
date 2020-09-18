#include <gtest/gtest.h>

#include <variant>
#include <any>
#include <Error.hpp>
#include <structure/Table.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <BinaryCode.hpp>
#include <Helper.hpp>

TEST(unittest_GenTable, regular){
  Table data;
  data.tableType.min = 5;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x70', '\x00', '\x05'}));
  EXPECT_EQ(visitor.getContext().tableCount, 1);
}

TEST(unittest_GenTable, regular_with_id){
  Table data;
  data.id = "test";
  data.tableType.min = 4;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x70', '\x00', '\x04'}));
  EXPECT_EQ(visitor.getContext().tableCount, 1);
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 0);
}

TEST(unittest_GenTable, import){
  Table data;
  data.tableType.min = 4;
  data.importModule = "mod";
  data.importName = "table";
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode());
  EXPECT_EQ(visitor.getContext().tableCount, 1);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().import));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x03', 'm', 'o', 'd',
    '\x05', 't', 'a', 'b', 'l', 'e',
    '\x01',
    '\x70', '\x00', '\x04'
  }));
}

TEST(unittest_GenTable, import_with_id){
  Table data;
  data.id = "test";
  data.tableType.min = 4;
  data.importModule = "mod";
  data.importName = "table";
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode());
  EXPECT_EQ(visitor.getContext().tableCount, 1);
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 0);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().import));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x03', 'm', 'o', 'd',
    '\x05', 't', 'a', 'b', 'l', 'e',
    '\x01',
    '\x70', '\x00', '\x04'
  }));
}

TEST(unittest_GenTable, inline_export){
  Table data;
  data.tableType.min = 5;
  data.exportNames.push_back("test");
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x70', '\x00', '\x05'}));
  EXPECT_EQ(visitor.getContext().tableCount, 1);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().exports));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x04', 't', 'e', 's', 't',
    '\x01', '\x00'
  }));
}

TEST(unittest_GenTable, inline_element){
  Table data;
  data.tableType.min = 5;
  data.elements.emplace_back(3);
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x70', '\x00', '\x05'}));
  EXPECT_EQ(visitor.getContext().tableCount, 1);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().elem));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x00', // tableidx
    '\x41', '\x00', '\x0B', // expr
    '\x01', '\x03'
  }));
}
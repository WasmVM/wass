#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/Import.hpp>
#include <structure/TypeUse.hpp>
#include <structure/Table.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenImport, desc_function){
  Import data;
  data.mod = "testMod";
  data.name = "testImport";
  data.type = Import::ImportType::Function;
  TypeUse typeUse;
  typeUse.index = (uint32_t) 3;
  data.desc.emplace<TypeUse>(typeUse);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    '\x07', 't', 'e', 's', 't', 'M', 'o', 'd',
    '\x0A', 't', 'e', 's', 't', 'I', 'm', 'p', 'o', 'r', 't',
    '\x00', '\x03'
  }));
}

TEST(unittest_GenImport, desc_table){
  Import data;
  data.mod = "testMod";
  data.name = "testImport";
  data.type = Import::ImportType::Table;
  Limit table;
  table.min = 3;
  data.desc.emplace<Limit>(table);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    '\x07', 't', 'e', 's', 't', 'M', 'o', 'd',
    '\x0A', 't', 'e', 's', 't', 'I', 'm', 'p', 'o', 'r', 't',
    '\x01', '\x70', '\x00', '\x03'
  }));
}
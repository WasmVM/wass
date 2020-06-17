#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/Module.hpp>
#include <structure/Type.hpp>
#include <structure/Import.hpp>
#include <structure/TypeUse.hpp>
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
    BIN_MAGIC, BIN_VERSION,
    '\x01', '\x04',
    '\x01', '\x60', '\x00', '\x00'
  }));
}

TEST(unittest_GenModule, import_section){
  Module data;
  Import testImport;
  testImport.mod = "mod";
  testImport.name = "test";
  testImport.type = Import::ImportType::Function;
  TypeUse typeUse;
  typeUse.index = (uint32_t) 2;
  testImport.desc.emplace<TypeUse>(typeUse);
  data.imports.push_back(testImport);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION,
    '\x02', '\x0C',
    '\x01',
    '\x03', 'm', 'o', 'd',
    '\x04', 't', 'e', 's', 't',
    '\x00', '\x02'
  }));
}
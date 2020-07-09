#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/Module.hpp>
#include <structure/Type.hpp>
#include <structure/Import.hpp>
#include <structure/TypeUse.hpp>
#include <structure/Table.hpp>
#include <structure/Memory.hpp>
#include <structure/Global.hpp>
#include <structure/Export.hpp>
#include <structure/Element.hpp>
#include <structure/ConstInstr.hpp>
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

TEST(unittest_GenModule, func_section){
  Module data;
  Function testFunc;
  testFunc.typeUse.index = (uint32_t)2;
  data.funcs.push_back(testFunc);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION,
    '\x03', '\x02',
    '\x01', '\x02'
  }));
}

TEST(unittest_GenModule, table_section){
  Module data;
  Table testTable;
  testTable.tableType.min = 3;
  data.tables.push_back(testTable);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION,
    '\x04', '\x04',
    '\x01', '\x70', '\x00', '\x03'
  }));
}

TEST(unittest_GenModule, memory_section){
  Module data;
  Memory testMem;
  testMem.memType.min = 3;
  data.memories.push_back(testMem);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION,
    '\x05', '\x03',
    '\x01', '\x00', '\x03'
  }));
}

TEST(unittest_GenModule, Global_section){
  Module data;
  Global testGlobal;
  testGlobal.globalType.immutable = false;
  testGlobal.globalType.type = ValueType::i64;
  testGlobal.expr.emplace<I64ConstInstr>().value = 6;
  data.globals.push_back(testGlobal);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION,
    '\x06', '\x06',
    '\x01', '\x7E', '\x01', '\x42', '\x06', '\x0B'
  }));
}

TEST(unittest_GenModule, Export_section){
  Module data;
  Export testExport;
  testExport.type = ExportType::Memory;
  testExport.name = "exp";
  testExport.index = (uint32_t) 3;
  data.exports.push_back(testExport);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION,
    '\x07', '\x07',
    '\x01', '\x03', 'e', 'x', 'p',
    '\x02', '\x03'
  }));
}

TEST(unittest_GenModule, Start_section){
  Module data;
  data.start = 9;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION,
    '\x08', '\x01', '\x09'
  }));
}

TEST(unittest_GenModule, Element_section){
  Module data;
  Element testElem;
  testElem.tableIndex = 12;
  testElem.expr.emplace<I32ConstInstr>().value = 8;
  testElem.funcIndices.push_back((uint32_t) 4);
  testElem.funcIndices.push_back((uint32_t) 9);
  data.elems.push_back(testElem);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({
    BIN_MAGIC, BIN_VERSION,
    '\x09', '\x08',
    '\x01', '\x0C', '\x41', '\x08', '\x0B',
    '\x02', '\x04', '\x09'
  }));
}
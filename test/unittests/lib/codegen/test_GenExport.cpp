#include <gtest/gtest.h>

#include <variant>
#include <Error.hpp>
#include <structure/Export.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenExport, func){
  Export data;
  data.name = "testExport";
  data.type = ExportType::Func;
  data.index = 12;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)),BinaryCode({
    '\x0A', 't', 'e', 's', 't', 'E', 'x', 'p', 'o', 'r', 't',
    '\x00', '\x0C'
  }));
}

TEST(unittest_GenExport, with_id){
  Export data;
  data.name = "testExport";
  data.type = ExportType::Func;
  data.index = "testFunc";
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["testFunc"] = 8;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)),BinaryCode({
    '\x0A', 't', 'e', 's', 't', 'E', 'x', 'p', 'o', 'r', 't',
    '\x00', '\x08'
  }));
}

TEST(unittest_GenExport, table){
  Export data;
  data.name = "testExport";
  data.type = ExportType::Table;
  data.index = 12;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)),BinaryCode({
    '\x0A', 't', 'e', 's', 't', 'E', 'x', 'p', 'o', 'r', 't',
    '\x01', '\x0C'
  }));
}

TEST(unittest_GenExport, memory){
  Export data;
  data.name = "testExport";
  data.type = ExportType::Memory;
  data.index = 12;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)),BinaryCode({
    '\x0A', 't', 'e', 's', 't', 'E', 'x', 'p', 'o', 'r', 't',
    '\x02', '\x0C'
  }));
}

TEST(unittest_GenExport, Global){
  Export data;
  data.name = "testExport";
  data.type = ExportType::Global;
  data.index = 12;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)),BinaryCode({
    '\x0A', 't', 'e', 's', 't', 'E', 'x', 'p', 'o', 'r', 't',
    '\x03', '\x0C'
  }));
}

TEST(unittest_GenExport, none){
  Export data;
  data.name = "testExport";
  data.type = ExportType::none;
  CodeGenVisitor visitor;
  EXPECT_THROW(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), Error<ErrorType::GenerateError>);
}

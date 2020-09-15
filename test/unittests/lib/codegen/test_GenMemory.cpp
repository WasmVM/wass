#include <gtest/gtest.h>

#include <variant>
#include <any>
#include <Error.hpp>
#include <structure/Memory.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <BinaryCode.hpp>
#include <Helper.hpp>

TEST(unittest_GenMemory, regular){
  Memory data;
  data.memType.min = 5;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x00', '\x05'}));
  EXPECT_EQ(visitor.getContext().memCount, 1);
}

TEST(unittest_GenMemory, regular_with_id){
  Memory data;
  data.id = "test";
  data.memType.min = 4;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x00', '\x04'}));
  EXPECT_EQ(visitor.getContext().memCount, 1);
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 0);
}

TEST(unittest_GenMemory, import){
  Memory data;
  data.memType.min = 4;
  data.importModule = "mod";
  data.importName = "mem";
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode());
  EXPECT_EQ(visitor.getContext().memCount, 1);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().import));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x03', 'm', 'o', 'd',
    '\x03', 'm', 'e', 'm',
    '\x02',
    '\x00', '\x04'
  }));
}

TEST(unittest_GenMemory, import_with_id){
  Memory data;
  data.id = "test";
  data.memType.min = 4;
  data.importModule = "mod";
  data.importName = "mem";
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode());
  EXPECT_EQ(visitor.getContext().memCount, 1);
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 0);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().import));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x03', 'm', 'o', 'd',
    '\x03', 'm', 'e', 'm',
    '\x02',
    '\x00', '\x04'
  }));
}

TEST(unittest_GenMemory, inline_export){
  Memory data;
  data.memType.min = 5;
  data.exportNames.push_back("test");
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x00', '\x05'}));
  EXPECT_EQ(visitor.getContext().memCount, 1);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().exports));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x04', 't', 'e', 's', 't',
    '\x02', '\x00'
  }));
}

// TODO: inline data
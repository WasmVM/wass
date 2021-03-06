#include <gtest/gtest.h>

#include <variant>
#include <Error.hpp>
#include <structure/Global.hpp>
#include <structure/InstrVariant.hpp>
#include <structure/ConstInstr.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenGlobal, const_value){
  Global data;
  data.globalType.immutable = true;
  data.globalType.type = ValueType::i32;
  data.expr.emplace<I32ConstInstr>().value = 5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x7F', '\x00', '\x41', '\x05', '\x0B'}));
}

TEST(unittest_GenGlobal, mutable_value){
  Global data;
  data.globalType.immutable = false;
  data.globalType.type = ValueType::i32;
  data.expr.emplace<GlobalGetInstr>().index = (uint32_t) 7;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x7F', '\x01', '\x23', '\x07', '\x0B'}));
}

TEST(unittest_GenGlobal, inline_export){
  Global data;
  data.globalType.immutable = true;
  data.globalType.type = ValueType::i32;
  data.expr.emplace<I32ConstInstr>().value = 5;
  data.exportNames.push_back("test");
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x7F', '\x00', '\x41', '\x05', '\x0B'}));
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().exports));
  EXPECT_EQ(generator.getCodes().size(), 1);
  EXPECT_EQ(generator.getCodes()[0], BinaryCode({
    '\x04', 't', 'e', 's', 't',
    '\x03', '\x00'
  }));
}
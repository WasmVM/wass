#include <gtest/gtest.h>

#include <variant>
#include <structure/ControlInstr.hpp>
#include <structure/TypeUse.hpp>
#include <BinaryCode.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenControlInstr, unreachable){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(UnreachableInstr())), BinaryCode({'\x00'}));
}
TEST(unittest_GenControlInstr, nop){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(NopInstr())), BinaryCode({'\x01'}));
}
TEST(unittest_GenControlInstr, Return){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(ReturnInstr())), BinaryCode({'\x0F'}));
}
TEST(unittest_GenControlInstr, br){
  CodeGenVisitor visitor;
  BrInstr data((uint32_t) 6);
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x0C', '\x06'
  }));
}
TEST(unittest_GenControlInstr, br_if){
  CodeGenVisitor visitor;
  BrIfInstr data((uint32_t) 6);
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x0D', '\x06'
  }));
}
TEST(unittest_GenControlInstr, br_table_one_label){
  CodeGenVisitor visitor;
  BrTableInstr data;
  data.labels.emplace_back((uint32_t) 7);
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x0E',
    '\x07'
  }));
}
TEST(unittest_GenControlInstr, br_table_more_label){
  CodeGenVisitor visitor;
  BrTableInstr data;
  data.labels.emplace_back((uint32_t) 7);
  data.labels.emplace_back((uint32_t) 9);
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x0E',
    '\x01', '\x07', '\x09'
  }));
}
TEST(unittest_GenControlInstr, call){
  CodeGenVisitor visitor;
  CallInstr data((uint32_t) 5);
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x10', '\x05'
  }));
}
TEST(unittest_GenControlInstr, call_indirect){
  CodeGenVisitor visitor;
  CallIndirectInstr data;
  data.type.index = (uint32_t) 8;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x11', '\x08', '\x00'
  }));
}
TEST(unittest_GenControlInstr, block_no_type){
  CodeGenVisitor visitor;
  BlockInstr data;
  data.instrs.emplace_back(NopInstr());
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x02', '\x40', '\x01', '\x0B'
  }));
}
TEST(unittest_GenControlInstr, block_with_type){
  BlockInstr data;
  data.instrs.emplace_back(NopInstr());
  TypeUse typeUse;
  typeUse.results.push_back(ValueType::i32);
  typeUse.results.push_back(ValueType::i64);
  data.blockType = typeUse;
  Mock_CodeGenVisitor visitor;
  visitor.getContext().typeDescs.emplace_back();
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x02', '\x01', '\x01', '\x0B'
  }));
}
TEST(unittest_GenControlInstr, block_with_one_result){
  BlockInstr data;
  data.instrs.emplace_back(NopInstr());
  ValueType valueType = ValueType::i32;
  data.blockType = valueType;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x02', '\x7F', '\x01', '\x0B'
  }));
}
TEST(unittest_GenControlInstr, loop){
  LoopInstr data;
  data.instrs.emplace_back(NopInstr());
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x03', '\x40', '\x01', '\x0B'
  }));
}
TEST(unittest_GenControlInstr, If_no_else){
  IfInstr data;
  data.instrs.emplace_back(NopInstr());
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x04', '\x40', '\x01', '\x0B'
  }));
}
TEST(unittest_GenControlInstr, If_with_else){
  IfInstr data;
  data.instrs.emplace_back(NopInstr());
  data.elseInstrs.emplace_back(ReturnInstr());
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x04', '\x40', '\x01', '\x05', '\x0F', '\x0B'
  }));
}
TEST(unittest_GenControlInstr, If_with_folded){
  IfInstr data;
  data.instrs.emplace_back(NopInstr());
  data.foldedInstrs.emplace_back(ReturnInstr());
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({
    '\x0F','\x04', '\x40', '\x01', '\x0B'
  }));
}
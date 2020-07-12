#include <gtest/gtest.h>

#include <variant>
#include <Error.hpp>
#include <structure/Function.hpp>
#include <structure/InstrVariant.hpp>
#include <structure/ConstInstr.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenFunctionContent, empty){
  Function data;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data.content)), BinaryCode({'\x02', '\x00', '\x0B'}));
}

TEST(unittest_GenFunctionContent, one_local){
  Function data;
  data.content.locals.push_back(ValueType::f32);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data.content)), BinaryCode({
    '\x04',
    '\x01', '\x01', '\x7D',
    '\x0B'
  }));
}

TEST(unittest_GenFunctionContent, one_local_with_id){
  Function data;
  data.content.locals.push_back(ValueType::f64);
  data.content.localMap["test"] = 8;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data.content)), BinaryCode({
    '\x04',
    '\x01', '\x01', '\x7C',
    '\x0B'
  }));
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 8);
}

TEST(unittest_GenFunctionContent, two_local){
  Function data;
  data.content.locals.push_back(ValueType::i32);
  data.content.locals.push_back(ValueType::i64);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data.content)), BinaryCode({
    '\x06',
    '\x02', '\x01', '\x7F', '\x01', '\x7E',
    '\x0B'
  }));
}

TEST(unittest_GenFunctionContent, compress_local){
  Function data;
  data.content.locals.push_back(ValueType::i32);
  data.content.locals.push_back(ValueType::i32);
  data.content.locals.push_back(ValueType::i64);
  data.content.locals.push_back(ValueType::i32);
  data.content.locals.push_back(ValueType::i32);
  data.content.locals.push_back(ValueType::i32);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data.content)), BinaryCode({
    '\x08',
    '\x03', '\x02', '\x7F', '\x01', '\x7E', '\x03', '\x7F',
    '\x0B'
  }));
}

TEST(unittest_GenFunctionContent, one_expr){
  Function data;
  I32ConstInstr instr;
  instr.value = 10;
  data.content.body.push_back(InstrVariant(instr));
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data.content)), BinaryCode({
    '\x04',
    '\x00',
    '\x41', '\x0A',
    '\x0B'
  }));
}

TEST(unittest_GenFunctionContent, mixed){
  Function data;
  data.content.locals.push_back(ValueType::f64);
  I32ConstInstr instr;
  instr.value = 11;
  data.content.body.push_back(InstrVariant(instr));
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data.content)), BinaryCode({
    '\x06',
    '\x01', '\x01', '\x7C',
    '\x41', '\x0B',
    '\x0B'
  }));
}
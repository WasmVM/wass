#include <gtest/gtest.h>

#include <variant>
#include <Error.hpp>
#include <structure/VariableInstr.hpp>
#include <structure/InstrVariant.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

/*
TEST(unittest_GenVariableInstr, local_get){
  LocalGetInstr data;
  data.index = 5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x20', '\x05'}));
}

TEST(unittest_GenVariableInstr, local_get_by_id){
  LocalGetInstr data;
  data.index = "test";
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["test"] = 4;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x20', '\x04'}));
}


TEST(unittest_GenVariableInstr, local_set){
  LocalSetInstr data;
  data.index = 5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x21', '\x05'}));
}

TEST(unittest_GenVariableInstr, local_set_by_id){
  LocalSetInstr data;
  data.index = "test";
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["test"] = 4;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x21', '\x04'}));
}

TEST(unittest_GenVariableInstr, local_tee){
  LocalTeeInstr data;
  data.index = 5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x22', '\x05'}));
}

TEST(unittest_GenVariableInstr, local_tee_by_id){
  LocalTeeInstr data;
  data.index = "test";
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["test"] = 4;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x22', '\x04'}));
}
*/

TEST(unittest_GenVariableInstr, global_get){
  GlobalGetInstr data;
  data.index = 5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x23', '\x05'}));
}

TEST(unittest_GenVariableInstr, global_get_by_id){
  GlobalGetInstr data;
  data.index = "test";
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["test"] = 4;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, ConstExprVariant(data)), BinaryCode({'\x23', '\x04'}));
}

/*
TEST(unittest_GenVariableInstr, global_set){
  GlobalSetInstr data;
  data.index = 5;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x24', '\x05'}));
}

TEST(unittest_GenVariableInstr, global_set_by_id){
  GlobalSetInstr data;
  data.index = "test";
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["test"] = 4;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(data)), BinaryCode({'\x24', '\x04'}));
}
*/
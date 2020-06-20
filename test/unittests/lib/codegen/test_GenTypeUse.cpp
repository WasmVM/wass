#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/TypeUse.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <codegen/SectionGenerator.hpp>
#include <Helper.hpp>

TEST(unittest_GenTypeUse, typeidx){
  TypeUse data;
  data.index = (uint32_t) 3;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x03'}));
}

TEST(unittest_GenTypeUse, identifier){
  TypeUse data;
  data.index = std::string("test");
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["test"] = 2;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x02'}));
}

TEST(unittest_GenTypeUse, inline_matched){
  TypeUse data;
  data.params.push_back(ValueType::i32);
  Mock_CodeGenVisitor visitor;
  FuncType existed;
  existed.params.push_back(ValueType::i32);
  visitor.getContext().typeDescs.push_back(FuncType());
  visitor.getContext().typeDescs.push_back(existed);
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x01'}));
}

TEST(unittest_GenTypeUse, inline_matched_with_id){
  TypeUse data;
  data.params.push_back(ValueType::i32);
  data.paramMap["test"] = 2;
  Mock_CodeGenVisitor visitor;
  FuncType existed;
  existed.params.push_back(ValueType::i32);
  visitor.getContext().typeDescs.push_back(FuncType());
  visitor.getContext().typeDescs.push_back(existed);
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x01'}));
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 2);
}

TEST(unittest_GenTypeUse, inline_no_matched){
  TypeUse data;
  data.params.push_back(ValueType::i32);
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x00'}));
  EXPECT_EQ(visitor.getContext().typeDescs.size(), 1);
}

TEST(unittest_GenTypeUse, inline_no_matched_with_id){
  TypeUse data;
  data.params.push_back(ValueType::i32);
  data.paramMap["test"] = 1;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x00'}));
  EXPECT_EQ(visitor.getContext().typeDescs.size(), 1);
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 1);
  Mock_SectionGenerator generator(std::any_cast<SectionGenerator>(visitor.getSections().type));
  EXPECT_EQ(generator.getCodes().size(), 1);
}
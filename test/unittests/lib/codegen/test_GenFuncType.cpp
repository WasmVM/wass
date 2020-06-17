#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/FuncType.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenFuncType, empty){
  FuncType data;
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x00', '\x00'}));
}

TEST(unittest_GenFuncType, one_param){
  FuncType data;
  data.params.push_back(ValueType::i64);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x01', '\x7E', '\x00'}));
}

TEST(unittest_GenFuncType, more_params){
  FuncType data;
  data.params.push_back(ValueType::i64);
  data.params.push_back(ValueType::f32);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x02', '\x7E', '\x7D', '\x00'}));
}

TEST(unittest_GenFuncType, one_result){
  FuncType data;
  data.results.push_back(ValueType::i64);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x00', '\x01', '\x7E'}));
}

TEST(unittest_GenFuncType, more_results){
  FuncType data;
  data.results.push_back(ValueType::i64);
  data.results.push_back(ValueType::f32);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x00', '\x02', '\x7E', '\x7D'}));
}

TEST(unittest_GenFuncType, mixed){
  FuncType data;
  data.params.push_back(ValueType::i32);
  data.results.push_back(ValueType::i64);
  data.results.push_back(ValueType::f32);
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x01', '\x7F', '\x02', '\x7E', '\x7D'}));
}

TEST(unittest_GenFuncType, param_with_id){
  FuncType data;
  data.params.push_back(ValueType::i64);
  data.paramMap["test"] = 2;
  Mock_CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), BinaryCode({'\x60', '\x01', '\x7E', '\x00'}));
  EXPECT_EQ(visitor.getContext().identifierMap["test"], 2);
}

TEST(unittest_GenFuncType, id_not_unique){
  FuncType data;
  data.params.push_back(ValueType::i64);
  data.paramMap["test"] = 2;
  Mock_CodeGenVisitor visitor;
  visitor.getContext().identifierMap["test"] = 1;
  EXPECT_THROW(std::visit<BinaryCode>(visitor, CodeGenVariant(data)), Error<ErrorType::GenerateError>);
}
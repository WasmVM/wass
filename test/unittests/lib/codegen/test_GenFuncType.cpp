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
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x60', '\x00', '\x00'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}

TEST(unittest_GenFuncType, one_param){
  FuncType data;
  data.params.push_back(ValueType::i64);
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x60', '\x01', '\x7E', '\x00'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}

TEST(unittest_GenFuncType, more_params){
  FuncType data;
  data.params.push_back(ValueType::i64);
  data.params.push_back(ValueType::f32);
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x60', '\x02', '\x7E', '\x7D', '\x00'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}

TEST(unittest_GenFuncType, one_result){
  FuncType data;
  data.results.push_back(ValueType::i64);
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x60', '\x00', '\x01', '\x7E'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}

TEST(unittest_GenFuncType, more_results){
  FuncType data;
  data.results.push_back(ValueType::i64);
  data.results.push_back(ValueType::f32);
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x60', '\x00', '\x02', '\x7E', '\x7D'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}

TEST(unittest_GenFuncType, mixed){
  FuncType data;
  data.params.push_back(ValueType::i32);
  data.results.push_back(ValueType::i64);
  data.results.push_back(ValueType::f32);
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x60', '\x01', '\x7F', '\x02', '\x7E', '\x7D'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}
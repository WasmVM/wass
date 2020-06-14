#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/ValueType.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenValueType, i32){
  ValueType data = ValueType::i32;
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x7F'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}

TEST(unittest_GenValueType, i64){
  ValueType data = ValueType::i64;
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x7E'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}

TEST(unittest_GenValueType, f32){
  ValueType data = ValueType::f32;
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x7D'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}

TEST(unittest_GenValueType, f64){
  ValueType data = ValueType::f64;
  CodeGenVisitor visitor;
  std::vector<char> result = std::visit<std::vector<char>>(visitor, CodeGenVariant(data));
  std::vector<char> expect {'\x7C'};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_EQ(result[i], expect[i]);
  }
}
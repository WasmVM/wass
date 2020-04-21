#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>
#include <structure/Value.hpp>
#include <structure/FuncType.hpp>

TEST(unittest_FuncType, empty){
  FuncType funcType;
  EXPECT_EQ(funcType.params.size(), 0);
  EXPECT_EQ(funcType.results.size(), 0);
  EXPECT_EQ(funcType.paramMap.size(), 0);
}

TEST(unittest_FuncType, copy){
  std::vector<ValueType> params = {ValueType::i32, ValueType::f64};
  std::vector<ValueType> results = {ValueType::i64, ValueType::f32};
  std::unordered_map<std::string, uint32_t> paramMap = {{"a", 1}};
  FuncType funcType;
  funcType.params = params;
  funcType.results = results;
  funcType.paramMap = paramMap;
  FuncType copied(funcType);
  EXPECT_EQ(copied.params.size(), 2);
  EXPECT_EQ(copied.params[0], ValueType::i32);
  EXPECT_EQ(copied.params[1], ValueType::f64);
  EXPECT_EQ(copied.results.size(), 2);
  EXPECT_EQ(copied.results[0], ValueType::i64);
  EXPECT_EQ(copied.results[1], ValueType::f32);
  EXPECT_EQ(copied.paramMap.size(), 1);
  EXPECT_EQ(copied.paramMap["a"], 1);
}

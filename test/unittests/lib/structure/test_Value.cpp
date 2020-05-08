#include <gtest/gtest.h>

#include <variant>
#include <structure/Value.hpp>
#include <cstdint>

TEST(unittest_Value, empty){
  Value result;
  EXPECT_EQ(result.type(), ValueType::none);
  EXPECT_NE(std::get_if<std::monostate>(&result), nullptr);
}

TEST(unittest_Value, i32){
  Value result((int32_t)23);
  EXPECT_EQ(result.type(), ValueType::i32);
  EXPECT_EQ(*(std::get_if<int32_t>(&result)), 23);
}

TEST(unittest_Value, i64){
  Value result((int64_t)23);
  EXPECT_EQ(result.type(), ValueType::i64);
  EXPECT_EQ(*(std::get_if<int64_t>(&result)), 23);
}

TEST(unittest_Value, f32){
  Value result((float)23.5);
  EXPECT_EQ(result.type(), ValueType::f32);
  EXPECT_EQ(*(std::get_if<float>(&result)), 23.5);
}

TEST(unittest_Value, f64){
  Value result((double)23.5);
  EXPECT_EQ(result.type(), ValueType::f64);
  EXPECT_EQ(*(std::get_if<double>(&result)), 23.5);
}
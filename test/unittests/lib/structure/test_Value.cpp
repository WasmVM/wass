#include <gtest/gtest.h>

#include <structure/Value.hpp>
#include <cstdint>

TEST(unittest_Value, empty){
  Value result;
  EXPECT_EQ(result.type(), ValueType::none);
  EXPECT_FALSE(result.std::any::has_value());
}

TEST(unittest_Value, i32){
  Value result((int32_t)23);
  EXPECT_EQ(result.type(), ValueType::i32);
  EXPECT_TRUE(result.std::any::has_value());
  EXPECT_EQ(std::any_cast<int32_t>(result), 23);
}

TEST(unittest_Value, i64){
  Value result((int64_t)23);
  EXPECT_EQ(result.type(), ValueType::i64);
  EXPECT_TRUE(result.std::any::has_value());
  EXPECT_EQ(std::any_cast<int64_t>(result), 23);
}

TEST(unittest_Value, f32){
  Value result((float)23.5);
  EXPECT_EQ(result.type(), ValueType::f32);
  EXPECT_TRUE(result.std::any::has_value());
  EXPECT_EQ(std::any_cast<float>(result), 23.5);
}

TEST(unittest_Value, f64){
  Value result((double)23.5);
  EXPECT_EQ(result.type(), ValueType::f64);
  EXPECT_TRUE(result.std::any::has_value());
  EXPECT_EQ(std::any_cast<double>(result), 23.5);
}
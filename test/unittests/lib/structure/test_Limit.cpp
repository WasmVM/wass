#include <gtest/gtest.h>

#include <optional>
#include <structure/Limit.hpp>

TEST(unittest_Limit, min_only){
  Limit result(4);
  EXPECT_EQ(result.min, 4);
  EXPECT_FALSE(result.max.has_value());
}

TEST(unittest_Limit, min_max){
  Limit result(4, 8);
  EXPECT_EQ(result.min, 4);
  EXPECT_TRUE(result.max.has_value());
  EXPECT_EQ(result.max.value(), 8);
}
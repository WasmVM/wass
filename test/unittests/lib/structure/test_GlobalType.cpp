#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>
#include <structure/ValueType.hpp>
#include <structure/GlobalType.hpp>

TEST(unittest_GlobalType, immutable){
  GlobalType globalType(ValueType::i32, true);
  EXPECT_EQ(globalType.type, ValueType::i32);
  EXPECT_TRUE(globalType.immutable);
}

TEST(unittest_GlobalType, Mutable){
  GlobalType globalType(ValueType::i32, false);
  EXPECT_EQ(globalType.type, ValueType::i32);
  EXPECT_FALSE(globalType.immutable);
}

TEST(unittest_GlobalType, immutable_default){
  GlobalType globalType(ValueType::i32, true);
  EXPECT_EQ(globalType.type, ValueType::i32);
  EXPECT_TRUE(globalType.immutable);
}
#include <gtest/gtest.h>

#include <any>
#include <vector>
#include <Error.hpp>
#include <structure/GlobalType.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserGlobalType.hpp>
#include <Helper.hpp>

TEST(unittest_ParserGlobalType, immutable){
  std::vector<char> data(create_char_vector("i32"));
  ParserContext context(data);
  ParserGlobalType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  GlobalType globalType = *result;
  EXPECT_EQ(globalType.type, ValueType::i32);
  EXPECT_TRUE(globalType.immutable);
}

TEST(unittest_ParserGlobalType, Mutable){
  std::vector<char> data(create_char_vector("(mut i64)"));
  ParserContext context(data);
  ParserGlobalType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  GlobalType globalType = *result;
  EXPECT_EQ(globalType.type, ValueType::i64);
  EXPECT_FALSE(globalType.immutable);
}

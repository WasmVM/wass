#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserLimit.hpp>
#include <Helper.hpp>

TEST(unittest_ParserLimit, min_only){
  std::vector<char> data(create_char_vector("24"));
  ParserContext context(data);
  ParserLimit result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->min, 24);
  EXPECT_FALSE(result->max.has_value());
}

TEST(unittest_ParserLimit, min_max){
  std::vector<char> data(create_char_vector("24 36"));
  ParserContext context(data);
  ParserLimit result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->min, 24);
  EXPECT_TRUE(result->max.has_value());
  EXPECT_EQ(result->max, 36);
}
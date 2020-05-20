#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserMemory.hpp>
#include <Helper.hpp>

TEST(unittest_ParserMemory, min_only){
  std::vector<char> data(create_char_vector("(memory 24)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_FALSE(result->memType.max.has_value());
}

TEST(unittest_ParserMemory, min_max){
  std::vector<char> data(create_char_vector("(memory 24 36)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_TRUE(result->memType.max.has_value());
  EXPECT_EQ(result->memType.max, 36);
}

TEST(unittest_ParserMemory, min_max_with_id){
  std::vector<char> data(create_char_vector("(memory $test 24 36)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->id->c_str(), "test");
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_TRUE(result->memType.max.has_value());
  EXPECT_EQ(result->memType.max, 36);
}

// TODO: Abbreviations
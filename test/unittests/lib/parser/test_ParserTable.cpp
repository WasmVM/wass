#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserTable.hpp>
#include <Helper.hpp>

TEST(unittest_ParserTable, min_only){
  std::vector<char> data(create_char_vector("(table 24 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_FALSE(result->tableType.max.has_value());
}

TEST(unittest_ParserTable, min_max){
  std::vector<char> data(create_char_vector("(table 24 36 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_TRUE(result->tableType.max.has_value());
  EXPECT_EQ(result->tableType.max, 36);
}

TEST(unittest_ParserTable, min_max_with_id){
  std::vector<char> data(create_char_vector("(table $test 24 36 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->id->c_str(), "test");
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_TRUE(result->tableType.max.has_value());
  EXPECT_EQ(result->tableType.max, 36);
}
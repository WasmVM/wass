#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserTableType.hpp>
#include <Helper.hpp>

TEST(unittest_ParserTableType, min_only){
  std::vector<char> data(create_char_vector("24 funcref"));
  ParserContext context(data);
  ParserTableType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->min, 24);
  EXPECT_FALSE(result->max.has_value());
}

TEST(unittest_ParserTableType, min_max){
  std::vector<char> data(create_char_vector("24 36 funcref"));
  ParserContext context(data);
  ParserTableType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->min, 24);
  EXPECT_TRUE(result->max.has_value());
  EXPECT_EQ(result->max, 36);
}

TEST(unittest_ParserTableType, no_funcref){
  std::vector<char> data(create_char_vector("24 36"));
  ParserContext context(data);
  ParserTableType* result = nullptr;
  EXPECT_THROW(result = new ParserTableType(context), Error<ErrorType::ParseError>);
  delete result;
}
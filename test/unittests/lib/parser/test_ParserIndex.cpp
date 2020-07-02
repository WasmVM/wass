#include <gtest/gtest.h>

#include <cstdint>
#include <string>
#include <Error.hpp>
#include <parser/ParserIndex.hpp>
#include <Helper.hpp>

TEST(unittest_ParserIndex, unknown){
  std::vector<char> data(create_char_vector("abcd1234"));
  ParserContext context(data);
  ParserIndex *result = nullptr;
  EXPECT_THROW(result = new ParserIndex(context), Error<ErrorType::ParseError>);
}

TEST(unittest_ParserIndex, string_index){
  std::vector<char> data(create_char_vector("$test"));
  ParserContext context(data);
  ParserIndex result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(std::get<std::string>(*result), "test");
}


TEST(unittest_ParserIndex, integer_index){
  std::vector<char> data(create_char_vector("7"));
  ParserContext context(data);
  ParserIndex result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(std::get<uint32_t>(*result), 7);
}


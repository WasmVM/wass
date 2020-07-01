#include <gtest/gtest.h>

#include <cstdint>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserStart.hpp>
#include <Helper.hpp>

TEST(unittest_ParserStart, empty){
  std::vector<char> data(create_char_vector("(start)"));
  ParserContext context(data);
  ParserStart* result = nullptr;
  EXPECT_THROW(result = new ParserStart(context), Error<ErrorType::ParseError>);
}

TEST(unittest_ParserStart, numeric_index){
  std::vector<char> data(create_char_vector("(start 5)"));
  ParserContext context(data);
  ParserStart result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(std::get<uint32_t>(*result), 5);
}

TEST(unittest_ParserStart, string_index){
  std::vector<char> data(create_char_vector("(start $test)"));
  ParserContext context(data);
  ParserStart result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(std::get<std::string>(*result).c_str(), "test");
}

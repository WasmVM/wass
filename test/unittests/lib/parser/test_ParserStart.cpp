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
  EXPECT_THROW(result = new ParserStart(context), Error<ErrorType::SyntaxError>);
}

TEST(unittest_ParserStart, no_desc){
  std::vector<char> data(create_char_vector("(start 5)"));
  ParserContext context(data);
  ParserStart result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(*result, 5);
}

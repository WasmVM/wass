#include <gtest/gtest.h>

#include <any>
#include <vector>
#include <Error.hpp>
#include <structure/Type.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserType.hpp>
#include <Helper.hpp>

TEST(unittest_ParserType, empty){
  std::vector<char> data(create_char_vector("(type)"));
  ParserContext context(data);
  ParserType* result = nullptr;
  EXPECT_THROW(result = new ParserType(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserType, with_id){
  std::vector<char> data(create_char_vector("(type $test (func))"));
  ParserContext context(data);
  ParserType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  Type type = *result;
  EXPECT_EQ(type.funcType.params.size(), 0);
  EXPECT_EQ(type.funcType.results.size(), 0);
}

TEST(unittest_ParserType, without_id){
  std::vector<char> data(create_char_vector("(type (func))"));
  ParserContext context(data);
  ParserType result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  Type type = *result;
  EXPECT_FALSE(type.id.has_value());
  EXPECT_EQ(type.funcType.params.size(), 0);
  EXPECT_EQ(type.funcType.results.size(), 0);
}
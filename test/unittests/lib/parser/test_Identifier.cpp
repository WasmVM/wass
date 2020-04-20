#include <gtest/gtest.h>

#include <vector>
#include <string>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Identifier.hpp>
#include <Helper.hpp>

TEST(unittest_Identifier, regular){
  std::vector<char> data(create_char_vector("$abcd1234"));
  ParserContext context(data);
  Identifier result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(std::any_cast<std::string>(result), "abcd1234");
}

TEST(unittest_Identifier, lowercase_alphabet){
  std::vector<char> data(create_char_vector("$abcdefghijklmnopqrstuvwxyz"));
  ParserContext context(data);
  Identifier result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(std::any_cast<std::string>(result), "abcdefghijklmnopqrstuvwxyz");
}


TEST(unittest_Identifier, uppercase_alphabet){
  std::vector<char> data(create_char_vector("$ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
  ParserContext context(data);
  Identifier result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(std::any_cast<std::string>(result), "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

TEST(unittest_Identifier, digit){
  std::vector<char> data(create_char_vector("$0123456789"));
  ParserContext context(data);
  Identifier result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(std::any_cast<std::string>(result), "0123456789");
}

TEST(unittest_Identifier, punctuator){
  std::vector<char>data(create_char_vector("$!#$%&'*+-./:<=>?@\\^_`|~"));
  ParserContext context(data);
  Identifier result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(std::any_cast<std::string>(result), "!#$%&'*+-./:<=>?@\\^_`|~");
}

TEST(unittest_Identifier, empty){
  std::vector<char> data(create_char_vector("$"));
  ParserContext context(data);
  Identifier* result = nullptr;
  EXPECT_THROW(result = new Identifier(context), Error<ErrorType::SyntaxError>);
  delete result;
}

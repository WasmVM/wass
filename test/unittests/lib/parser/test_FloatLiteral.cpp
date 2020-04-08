#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/FloatLiteral.hpp>
#include <Helper.hpp>

TEST(unittest_FloatLiteral, nan){
  std::vector<char> data(create_char_vector("nan"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_nan();
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, minus_nan){
  std::vector<char> data(create_char_vector("-nan"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_nan(true);
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, plus_nan){
  std::vector<char> data(create_char_vector("+nan"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_nan();
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, misc_nan){
  std::vector<char> data(create_char_vector("nan:0x012345"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_nan((int64_t)0x12345);
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, plus_misc_nan){
  std::vector<char> data(create_char_vector("+nan:0x304050"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_nan((int64_t)0x304050);
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, minus_misc_nan){
  std::vector<char> data(create_char_vector("-nan:0x2abcde"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_nan((int64_t)0x2abcde);
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, inf){
  std::vector<char> data(create_char_vector("inf"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_inf();
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, minus_inf){
  std::vector<char> data(create_char_vector("+inf"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_inf();
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, plus_inf){
  std::vector<char> data(create_char_vector("-inf"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = create_double_inf(false);
  EXPECT_BITWISE_EQ(value, expect);
}
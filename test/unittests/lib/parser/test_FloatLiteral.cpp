#include <gtest/gtest.h>

#include <vector>
#include <cmath>
#include <limits>
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
  double expect = std::nan("");
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, minus_nan){
  std::vector<char> data(create_char_vector("-nan"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = -std::nan("");
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, plus_nan){
  std::vector<char> data(create_char_vector("+nan"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = std::nan("");
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, misc_nan){
  std::vector<char> data(create_char_vector("nan:0x012345"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = std::nan("0x012345");
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, plus_misc_nan){
  std::vector<char> data(create_char_vector("+nan:0x304050"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = std::nan("0x304050");
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, minus_misc_nan){
  std::vector<char> data(create_char_vector("-nan:0x2abcde"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = std::nan("0x2abcde");
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, inf){
  std::vector<char> data(create_char_vector("inf"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = std::numeric_limits<double>::infinity();
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, plus_inf){
  std::vector<char> data(create_char_vector("+inf"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = std::numeric_limits<double>::infinity();
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, minus_inf){
  std::vector<char> data(create_char_vector("-inf"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  double value = std::any_cast<double>(result);
  double expect = -std::numeric_limits<double>::infinity();
  EXPECT_BITWISE_EQ(value, expect);
}

TEST(unittest_FloatLiteral, decimal_integer_only){
  std::vector<char> data(create_char_vector("23"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 23);
}

TEST(unittest_FloatLiteral, decimal_integer_with_point){
  std::vector<char> data(create_char_vector("23."));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 23);
}

TEST(unittest_FloatLiteral, decimal_regular){
  std::vector<char> data(create_char_vector("12.05"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 12.05);
}

TEST(unittest_FloatLiteral, plus_decimal){
  std::vector<char> data(create_char_vector("+12.05"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 12.05);
}

TEST(unittest_FloatLiteral, minus_decimal){
  std::vector<char> data(create_char_vector("-12.05"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), -12.05);
}

TEST(unittest_FloatLiteral, decimal_seperator_integer){
  std::vector<char> data(create_char_vector("1_2.05"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 12.05);
}

TEST(unittest_FloatLiteral, decimal_seperator_integer_more){
  std::vector<char> data(create_char_vector("1_2_4.05"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 124.05);
}

TEST(unittest_FloatLiteral, decimal_seperator_fraction){
  std::vector<char> data(create_char_vector("12.0_5"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 12.05);
}

TEST(unittest_FloatLiteral, decimal_seperator_fraction_more){
  std::vector<char> data(create_char_vector("12.0_5_3"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 12.053);
}

TEST(unittest_FloatLiteral, decimal_seperator_mix){
  std::vector<char> data(create_char_vector("1_2.0_53"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 12.053);
}

TEST(unittest_FloatLiteral, decimal_seperator_mix_more){
  std::vector<char> data(create_char_vector("1_42.0_53_6"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 142.0536);
}

TEST(unittest_FloatLiteral, decimal_seperator_prefix_plus){
  std::vector<char> data(create_char_vector("+_42.25"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_prefix_minus){
  std::vector<char> data(create_char_vector("-_42.25"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_prefix_integer){
  std::vector<char> data(create_char_vector("_42.25"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_double_integer){
  std::vector<char> data(create_char_vector("4__2.25"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_postfix_integer){
  std::vector<char> data(create_char_vector("42_.25"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_prefix_fraction){
  std::vector<char> data(create_char_vector("42._25"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_double_fraction){
  std::vector<char> data(create_char_vector("42.2__5"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_postfix_fraction){
  std::vector<char> data(create_char_vector("42.25_"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_exponent){
  std::vector<char> data(create_char_vector("42.325e2"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 4232.5);
}

TEST(unittest_FloatLiteral, decimal_upper_exponent){
  std::vector<char> data(create_char_vector("42.325E2"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 4232.5);
}

TEST(unittest_FloatLiteral, decimal_plus_exponent){
  std::vector<char> data(create_char_vector("42.325E+2"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 4232.5);
}

TEST(unittest_FloatLiteral, decimal_minus_exponent){
  std::vector<char> data(create_char_vector("142.325E-2"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 1.42325);
}

TEST(unittest_FloatLiteral, decimal_exponent_separator){
  std::vector<char> data(create_char_vector("142.325E-0_2"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 1.42325);
}

TEST(unittest_FloatLiteral, decimal_exponent_separator_more){
  std::vector<char> data(create_char_vector("2.325E+0_2_0"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 2.325e20);
}

TEST(unittest_FloatLiteral, decimal_seperator_prefix_exponent){
  std::vector<char> data(create_char_vector("42.2e_25"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_double_exponent){
  std::vector<char> data(create_char_vector("42.7e2__5"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, decimal_seperator_postfix_exponent){
  std::vector<char> data(create_char_vector("42.8e25_"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}
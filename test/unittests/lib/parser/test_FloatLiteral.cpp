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

TEST(unittest_FloatLiteral, hex_integer_only){
  std::vector<char> data(create_char_vector("0x2e"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 0x2e);
}

TEST(unittest_FloatLiteral, hex_integer_with_point){
  std::vector<char> data(create_char_vector("0x2e."));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 0x2e);
}

TEST(unittest_FloatLiteral, hex_regular){
  std::vector<char> data(create_char_vector("0x1C.4"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 28.25);
}

TEST(unittest_FloatLiteral, plus_hex){
  std::vector<char> data(create_char_vector("+0x1C.4"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 28.25);
}

TEST(unittest_FloatLiteral, minus_hex){
  std::vector<char> data(create_char_vector("-0x1C.4"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), -28.25);
}

TEST(unittest_FloatLiteral, hex_seperator_integer){
  std::vector<char> data(create_char_vector("0x1_C.08"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 28.03125);
}

TEST(unittest_FloatLiteral, hex_seperator_integer_more){
  std::vector<char> data(create_char_vector("0x1_2_0.08"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 288.03125);
}

TEST(unittest_FloatLiteral, hex_seperator_fraction){
  std::vector<char> data(create_char_vector("0x1C.0_8"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 28.03125);
}

TEST(unittest_FloatLiteral, hex_seperator_fraction_more){
  std::vector<char> data(create_char_vector("0x1C.0_8_0"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 28.03125);
}

TEST(unittest_FloatLiteral, hex_seperator_mix){
  std::vector<char> data(create_char_vector("0x1_2.0_80"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 18.03125);
}

TEST(unittest_FloatLiteral, hex_seperator_mix_more){
  std::vector<char> data(create_char_vector("0x0_20_0.0_80_0"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 512.03125);
}

TEST(unittest_FloatLiteral, hex_seperator_prefix_plus){
  std::vector<char> data(create_char_vector("+0x_42.2a"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_prefix_minus){
  std::vector<char> data(create_char_vector("-0x_42.2b"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_prefix_integer){
  std::vector<char> data(create_char_vector("0x_42.2c"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_double_integer){
  std::vector<char> data(create_char_vector("0x4__2.d5"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_postfix_integer){
  std::vector<char> data(create_char_vector("0x42_.a5"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_prefix_fraction){
  std::vector<char> data(create_char_vector("0x42._15"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_double_fraction){
  std::vector<char> data(create_char_vector("0x42.2__5"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_postfix_fraction){
  std::vector<char> data(create_char_vector("0x42.25_"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_exponent){
  std::vector<char> data(create_char_vector("0x22.008p2"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 8704.5);
}

TEST(unittest_FloatLiteral, hex_upper_exponent){
  std::vector<char> data(create_char_vector("0x22.008P2"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 8704.5);
}

TEST(unittest_FloatLiteral, hex_plus_exponent){
  std::vector<char> data(create_char_vector("0x22.008p+2"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 8704.5);
}

TEST(unittest_FloatLiteral, hex_minus_exponent){
  std::vector<char> data(create_char_vector("0x12.8p-1"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 1.15625);
}

TEST(unittest_FloatLiteral, hex_exponent_separator){
  std::vector<char> data(create_char_vector("0x12.8p-0_1"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 1.15625);
}

TEST(unittest_FloatLiteral, hex_exponent_separator_more){
  std::vector<char> data(create_char_vector("0x12.08p+0_0_1"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_FLOAT_EQ(std::any_cast<double>(result), 288.5);
}

TEST(unittest_FloatLiteral, hex_seperator_prefix_exponent){
  std::vector<char> data(create_char_vector("0x42.2p_25"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_double_exponent){
  std::vector<char> data(create_char_vector("0x42.7p2__5"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}

TEST(unittest_FloatLiteral, hex_seperator_postfix_exponent){
  std::vector<char> data(create_char_vector("0x42.8p25_"));
  ParserContext context(data);
  FloatLiteral result(context);
  EXPECT_EQ(context.cursor, data.begin());
  EXPECT_FALSE(result.has_value());
}
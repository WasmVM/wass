#include <gtest/gtest.h>

#include <variant>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserParamInstr.hpp>
#include <structure/BaseInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserParamInstr, Select){
  std::vector<char> data(create_char_vector("select"));
  ParserContext context(data);
  ParserParamInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<SelectInstr>(&result), nullptr);
}

TEST(unittest_ParserParamInstr, drop){
  std::vector<char> data(create_char_vector("drop"));
  ParserContext context(data);
  ParserParamInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<DropInstr>(&result), nullptr);
}

#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserParamInstr.hpp>
#include <structure/Instr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserParamInstr, Select){
  std::vector<char> data(create_char_vector("select"));
  ParserContext context(data);
  ParserParamInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::Select>));
}

TEST(unittest_ParserParamInstr, drop){
  std::vector<char> data(create_char_vector("drop"));
  ParserContext context(data);
  ParserParamInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::Drop>));
}

#include <gtest/gtest.h>

#include <variant>
#include <optional>
#include <vector>
#include <Error.hpp>
#include <structure/Global.hpp>
#include <structure/ConstInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserGlobal.hpp>
#include <Helper.hpp>

TEST(unittest_ParserGlobal, empty){
  std::vector<char> data(create_char_vector("(global)"));
  ParserContext context(data);
  ParserGlobal* result = nullptr;
  EXPECT_THROW(result = new ParserGlobal(context), Error<ErrorType::SyntaxError>);
  delete result;
}

TEST(unittest_ParserGlobal, with_id){
  std::vector<char> data(create_char_vector("(global $test i64 i64.const 6)"));
  ParserContext context(data);
  ParserGlobal result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  Global global = *result;
  EXPECT_STREQ(global.id->c_str(), "test");
  EXPECT_EQ(global.globalType.type, ValueType::i64);
  EXPECT_TRUE(std::holds_alternative<I64ConstInstr>(global.expr));
  EXPECT_EQ(std::get_if<I64ConstInstr>(&global.expr)->value, 6);
}

TEST(unittest_ParserGlobal, without_id){
  std::vector<char> data(create_char_vector("(global i64 i64.const 6)"));
  ParserContext context(data);
  ParserGlobal result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  Global global = *result;
  EXPECT_FALSE(global.id.has_value());
  EXPECT_EQ(global.globalType.type, ValueType::i64);
  EXPECT_TRUE(std::holds_alternative<I64ConstInstr>(global.expr));
  EXPECT_EQ(std::get_if<I64ConstInstr>(&global.expr)->value, 6);
}

TEST(unittest_ParserGlobal, no_expr){
  std::vector<char> data(create_char_vector("(global i64)"));
  ParserContext context(data);
  ParserGlobal* result = nullptr;
  EXPECT_THROW(result = new ParserGlobal(context), Error<ErrorType::SyntaxError>);
  delete result;
}

// TODO: Abbreviation
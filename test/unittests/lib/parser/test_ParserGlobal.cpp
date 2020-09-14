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
  EXPECT_THROW(result = new ParserGlobal(context), Error<ErrorType::ParseError>);
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
  EXPECT_THROW(result = new ParserGlobal(context), Error<ErrorType::ParseError>);
  delete result;
}

TEST(unittest_ParserGlobal, with_import){
  std::vector<char> data(create_char_vector("(global (import \"module\" \"test\") i64)"));
  ParserContext context(data);
  ParserGlobal result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->importModule->c_str(), "module");
  EXPECT_STREQ(result->importName->c_str(), "test");
}

TEST(unittest_ParserGlobal, with_export){
  std::vector<char> data(create_char_vector("(global (export \"test\") i64 i64.const 6)"));
  ParserContext context(data);
  ParserGlobal result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->exportNames.size(), 1);
  EXPECT_STREQ(result->exportNames.at(0).c_str(), "test");
}

TEST(unittest_ParserGlobal, with_more_export){
  std::vector<char> data(create_char_vector("(global (export \"test1\") (export \"test2\") i64 i64.const 6)"));
  ParserContext context(data);
  ParserGlobal result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->exportNames.size(), 2);
  EXPECT_STREQ(result->exportNames.at(0).c_str(), "test1");
  EXPECT_STREQ(result->exportNames.at(1).c_str(), "test2");
}

TEST(unittest_ParserGlobal, with_import_export){
  std::vector<char> data(create_char_vector("(global (export \"testEx\") (import \"module\" \"test\") i64)"));
  ParserContext context(data);
  ParserGlobal result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->importModule->c_str(), "module");
  EXPECT_STREQ(result->importName->c_str(), "test");
  EXPECT_EQ(result->exportNames.size(), 1);
  EXPECT_STREQ(result->exportNames.at(0).c_str(), "testEx");
}
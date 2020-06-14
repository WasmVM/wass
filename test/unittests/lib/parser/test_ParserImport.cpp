#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <variant>
#include <parser/ParserContext.hpp>
#include <parser/ParserImport.hpp>
#include <structure/FuncType.hpp>
#include <structure/Import.hpp>
#include <structure/Limit.hpp>
#include <structure/GlobalType.hpp>
#include <Helper.hpp>

TEST(unittest_ParserImport, empty){
  std::vector<char> data(create_char_vector("(import)"));
  ParserContext context(data);
  ParserImport* result = nullptr;
  EXPECT_THROW(result = new ParserImport(context), Error<ErrorType::ParseError>);
}

TEST(unittest_ParserImport, mod_name_only){
  std::vector<char> data(create_char_vector("(import \"testmod\")"));
  ParserContext context(data);
  ParserImport* result = nullptr;
  EXPECT_THROW(result = new ParserImport(context), Error<ErrorType::ParseError>);
}

TEST(unittest_ParserImport, no_desc){
  std::vector<char> data(create_char_vector("(import \"testmod\" \"test\")"));
  ParserContext context(data);
  ParserImport* result = nullptr;
  EXPECT_THROW(result = new ParserImport(context), Error<ErrorType::ParseError>);
}

TEST(unittest_ParserImport, func){
  std::vector<char> data(create_char_vector("(import \"testmod\" \"test\" (func $testfunc (param i32) (result i64)))"));
  ParserContext context(data);
  ParserImport result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->mod.c_str(), "testmod");
  EXPECT_STREQ(result->name.c_str(), "test");
  EXPECT_STREQ(result->descId->c_str(), "testfunc");
  TypeUse* funcType = std::get_if<TypeUse>(&(result->desc));
  EXPECT_EQ(funcType->results.size(), 1);
  EXPECT_EQ(funcType->results[0], ValueType::i64);
  EXPECT_EQ(funcType->params.size(), 1);
  EXPECT_EQ(funcType->params[0], ValueType::i32);
}

TEST(unittest_ParserImport, table){
  std::vector<char> data(create_char_vector("(import \"testmod\" \"test\" (table $testtable 1 funcref))"));
  ParserContext context(data);
  ParserImport result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->mod.c_str(), "testmod");
  EXPECT_STREQ(result->name.c_str(), "test");
  EXPECT_STREQ(result->descId->c_str(), "testtable");
  Limit* tableType = std::get_if<Limit>(&(result->desc));
  EXPECT_EQ(tableType->min, 1);
}

TEST(unittest_ParserImport, memory){
  std::vector<char> data(create_char_vector("(import \"testmod\" \"test\" (memory $testmem 1))"));
  ParserContext context(data);
  ParserImport result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->mod.c_str(), "testmod");
  EXPECT_STREQ(result->name.c_str(), "test");
  EXPECT_STREQ(result->descId->c_str(), "testmem");
  Limit* memType = std::get_if<Limit>(&(result->desc));
  EXPECT_EQ(memType->min, 1);
}

TEST(unittest_ParserImport, Global){
  std::vector<char> data(create_char_vector("(import \"testmod\" \"test\" (global $testglobal i32))"));
  ParserContext context(data);
  ParserImport result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->mod.c_str(), "testmod");
  EXPECT_STREQ(result->name.c_str(), "test");
  EXPECT_STREQ(result->descId->c_str(), "testglobal");
  GlobalType* globalType = std::get_if<GlobalType>(&(result->desc));
  EXPECT_TRUE(globalType->immutable);
  EXPECT_EQ(globalType->type, ValueType::i32);
}
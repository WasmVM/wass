#include <gtest/gtest.h>

#include <cstdint>
#include <string>
#include <Error.hpp>
#include <structure/Module.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserModule.hpp>
#include <Helper.hpp>

TEST(unittest_ParserModule, empty){
  std::vector<char> data(create_char_vector("(module)"));
  ParserContext context(data);
  ParserModule result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->types.size(), 0);
  EXPECT_EQ(result->imports.size(), 0);
  EXPECT_EQ(result->funcs.size(), 0);
  EXPECT_EQ(result->tables.size(), 0);
  EXPECT_EQ(result->memories.size(), 0);
  EXPECT_EQ(result->globals.size(), 0);
  EXPECT_EQ(result->exports.size(), 0);
  EXPECT_EQ(result->elems.size(), 0);
  EXPECT_EQ(result->datas.size(), 0);
  EXPECT_FALSE(result->start.has_value());
  EXPECT_FALSE(result->id.has_value());
}

TEST(unittest_ParserModule, empty_with_id){
  std::vector<char> data(create_char_vector("(module $test)"));
  ParserContext context(data);
  ParserModule result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->types.size(), 0);
  EXPECT_EQ(result->imports.size(), 0);
  EXPECT_EQ(result->funcs.size(), 0);
  EXPECT_EQ(result->tables.size(), 0);
  EXPECT_EQ(result->memories.size(), 0);
  EXPECT_EQ(result->globals.size(), 0);
  EXPECT_EQ(result->exports.size(), 0);
  EXPECT_EQ(result->elems.size(), 0);
  EXPECT_EQ(result->datas.size(), 0);
  EXPECT_FALSE(result->start.has_value());
  EXPECT_TRUE(result->id.has_value());
  EXPECT_STREQ(result->id->c_str(), "test");
}

TEST(unittest_ParserModule, with_one_section){
  std::vector<char> data(create_char_vector("(module (export \"test\" (func 2)))"));
  ParserContext context(data);
  ParserModule result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->types.size(), 0);
  EXPECT_EQ(result->imports.size(), 0);
  EXPECT_EQ(result->funcs.size(), 0);
  EXPECT_EQ(result->tables.size(), 0);
  EXPECT_EQ(result->memories.size(), 0);
  EXPECT_EQ(result->globals.size(), 0);
  EXPECT_EQ(result->exports.size(), 1);
  EXPECT_STREQ(result->exports[0].name.c_str(), "test");
  EXPECT_EQ(result->exports[0].index, 2);
  EXPECT_EQ(result->exports[0].type, ExportType::Func);
  EXPECT_EQ(result->elems.size(), 0);
  EXPECT_EQ(result->datas.size(), 0);
  EXPECT_FALSE(result->start.has_value());
  EXPECT_FALSE(result->id.has_value());
}

TEST(unittest_ParserModule, one_section_with_id){
  std::vector<char> data(create_char_vector("(module $test (export \"testEx\" (func 2)))"));
  ParserContext context(data);
  ParserModule result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->types.size(), 0);
  EXPECT_EQ(result->imports.size(), 0);
  EXPECT_EQ(result->funcs.size(), 0);
  EXPECT_EQ(result->tables.size(), 0);
  EXPECT_EQ(result->memories.size(), 0);
  EXPECT_EQ(result->globals.size(), 0);
  EXPECT_EQ(result->exports.size(), 1);
  EXPECT_STREQ(result->exports[0].name.c_str(), "testEx");
  EXPECT_EQ(result->exports[0].index, 2);
  EXPECT_EQ(result->exports[0].type, ExportType::Func);
  EXPECT_EQ(result->elems.size(), 0);
  EXPECT_EQ(result->datas.size(), 0);
  EXPECT_FALSE(result->start.has_value());
  EXPECT_TRUE(result->id.has_value());
  EXPECT_STREQ(result->id->c_str(), "test");
}

TEST(unittest_ParserModule, with_more_section){
  std::vector<char> data(create_char_vector("(module (export \"test\" (func 2)) (start 3))"));
  ParserContext context(data);
  ParserModule result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->types.size(), 0);
  EXPECT_EQ(result->imports.size(), 0);
  EXPECT_EQ(result->funcs.size(), 0);
  EXPECT_EQ(result->tables.size(), 0);
  EXPECT_EQ(result->memories.size(), 0);
  EXPECT_EQ(result->globals.size(), 0);
  EXPECT_EQ(result->exports.size(), 1);
  EXPECT_STREQ(result->exports[0].name.c_str(), "test");
  EXPECT_EQ(result->exports[0].index, 2);
  EXPECT_EQ(result->exports[0].type, ExportType::Func);
  EXPECT_EQ(result->elems.size(), 0);
  EXPECT_EQ(result->datas.size(), 0);
  EXPECT_TRUE(result->start.has_value());
  EXPECT_EQ(*result->start, 3);
  EXPECT_FALSE(result->id.has_value());
}

TEST(unittest_ParserModule, multiple_start){
  std::vector<char> data(create_char_vector("(module (start 3) (start 4))"));
  ParserContext context(data);
  ParserModule* result = nullptr;
  EXPECT_THROW(result = new ParserModule(context), Error<ErrorType::ParseError>);
}


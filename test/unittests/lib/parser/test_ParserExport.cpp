#include <gtest/gtest.h>

#include <cstdint>
#include <Error.hpp>
#include <structure/Export.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserExport.hpp>
#include <Helper.hpp>

TEST(unittest_ParserExport, empty){
  std::vector<char> data(create_char_vector("(export)"));
  ParserContext context(data);
  ParserExport* result = nullptr;
  EXPECT_THROW(result = new ParserExport(context), Error<ErrorType::ParseError>);
}

TEST(unittest_ParserExport, no_desc){
  std::vector<char> data(create_char_vector("(export \"test\")"));
  ParserContext context(data);
  ParserExport* result = nullptr;
  EXPECT_THROW(result = new ParserExport(context), Error<ErrorType::ParseError>);
}

TEST(unittest_ParserExport, func){
  std::vector<char> data(create_char_vector("(export \"test\" (func 2))"));
  ParserContext context(data);
  ParserExport result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->name.c_str(), "test");
  EXPECT_EQ(result->type, ExportType::Func);
  EXPECT_EQ(result->index, 2);
}

TEST(unittest_ParserExport, table){
  std::vector<char> data(create_char_vector("(export \"test\" (table 2))"));
  ParserContext context(data);
  ParserExport result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->name.c_str(), "test");
  EXPECT_EQ(result->type, ExportType::Table);
  EXPECT_EQ(result->index, 2);
}

TEST(unittest_ParserExport, memory){
  std::vector<char> data(create_char_vector("(export \"test\" (memory 2))"));
  ParserContext context(data);
  ParserExport result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->name.c_str(), "test");
  EXPECT_EQ(result->type, ExportType::Memory);
  EXPECT_EQ(result->index, 2);
}

TEST(unittest_ParserExport, Global){
  std::vector<char> data(create_char_vector("(export \"test\" (global 2))"));
  ParserContext context(data);
  ParserExport result(context);
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->name.c_str(), "test");
  EXPECT_EQ(result->type, ExportType::Global);
  EXPECT_EQ(result->index, 2);
}
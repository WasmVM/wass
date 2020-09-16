#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserTable.hpp>
#include <Helper.hpp>

TEST(unittest_ParserTable, min_only){
  std::vector<char> data(create_char_vector("(table 24 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_FALSE(result->tableType.max.has_value());
}

TEST(unittest_ParserTable, min_max){
  std::vector<char> data(create_char_vector("(table 24 36 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_TRUE(result->tableType.max.has_value());
  EXPECT_EQ(result->tableType.max, 36);
}

TEST(unittest_ParserTable, min_max_with_id){
  std::vector<char> data(create_char_vector("(table $test 24 36 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->id->c_str(), "test");
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_TRUE(result->tableType.max.has_value());
  EXPECT_EQ(result->tableType.max, 36);
}

TEST(unittest_ParserTable, with_import){
  std::vector<char> data(create_char_vector("(table (import \"module\" \"test\") 24 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_FALSE(result->tableType.max.has_value());
  EXPECT_STREQ(result->importModule->c_str(), "module");
  EXPECT_STREQ(result->importName->c_str(), "test");
}

TEST(unittest_ParserTable, with_export){
  std::vector<char> data(create_char_vector("(table (export \"test\") 24 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_FALSE(result->tableType.max.has_value());
  EXPECT_EQ(result->exportNames.size(), 1);
  EXPECT_STREQ(result->exportNames.at(0).c_str(), "test");
}

TEST(unittest_ParserTable, with_more_export){
  std::vector<char> data(create_char_vector("(table (export \"test1\") (export \"test2\") 24 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_FALSE(result->tableType.max.has_value());
  EXPECT_EQ(result->exportNames.size(), 2);
  EXPECT_STREQ(result->exportNames.at(0).c_str(), "test1");
  EXPECT_STREQ(result->exportNames.at(1).c_str(), "test2");
}

TEST(unittest_ParserTable, with_import_export){
  std::vector<char> data(create_char_vector("(table (export \"testEx\") (import \"module\" \"test\") 24 funcref)"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 24);
  EXPECT_FALSE(result->tableType.max.has_value());
  EXPECT_STREQ(result->importModule->c_str(), "module");
  EXPECT_STREQ(result->importName->c_str(), "test");
  EXPECT_EQ(result->exportNames.size(), 1);
  EXPECT_STREQ(result->exportNames.at(0).c_str(), "testEx");
}

TEST(unittest_ParserTable, with_elem){
  std::vector<char> data(create_char_vector("(table funcref (elem 4 6))"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 2);
  EXPECT_TRUE(result->tableType.max.has_value());
  EXPECT_EQ(result->tableType.max, 2);
  EXPECT_TRUE(result->elements.has_value());
  EXPECT_EQ(std::get<uint32_t>(result->elements->at(0)), 4);
  EXPECT_EQ(std::get<uint32_t>(result->elements->at(1)), 6);
}

TEST(unittest_ParserTable, with_elem_in_id){
  std::vector<char> data(create_char_vector("(table funcref (elem $test 6))"));
  ParserContext context(data);
  ParserTable result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->tableType.min, 2);
  EXPECT_TRUE(result->tableType.max.has_value());
  EXPECT_EQ(result->tableType.max, 2);
  EXPECT_TRUE(result->elements.has_value());
  EXPECT_STREQ(std::get<std::string>(result->elements->at(0)).c_str(), "test");
  EXPECT_EQ(std::get<uint32_t>(result->elements->at(1)), 6);
}
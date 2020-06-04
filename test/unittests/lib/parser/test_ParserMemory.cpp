#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserMemory.hpp>
#include <Helper.hpp>

TEST(unittest_ParserMemory, min_only){
  std::vector<char> data(create_char_vector("(memory 24)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_FALSE(result->memType.max.has_value());
}

TEST(unittest_ParserMemory, min_max){
  std::vector<char> data(create_char_vector("(memory 24 36)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_TRUE(result->memType.max.has_value());
  EXPECT_EQ(result->memType.max, 36);
}

TEST(unittest_ParserMemory, min_max_with_id){
  std::vector<char> data(create_char_vector("(memory $test 24 36)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_STREQ(result->id->c_str(), "test");
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_TRUE(result->memType.max.has_value());
  EXPECT_EQ(result->memType.max, 36);
}

TEST(unittest_ParserMemory, with_import){
  std::vector<char> data(create_char_vector("(memory (import \"module\" \"test\") 24)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_FALSE(result->memType.max.has_value());
  EXPECT_STREQ(result->importModule->c_str(), "module");
  EXPECT_STREQ(result->importName->c_str(), "test");
}

TEST(unittest_ParserMemory, with_export){
  std::vector<char> data(create_char_vector("(memory (export \"test\") 24)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_FALSE(result->memType.max.has_value());
  EXPECT_EQ(result->exportNames->size(), 1);
  EXPECT_STREQ(result->exportNames->at(0).c_str(), "test");
}

TEST(unittest_ParserMemory, with_more_export){
  std::vector<char> data(create_char_vector("(memory (export \"test1\") (export \"test2\") 24)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_FALSE(result->memType.max.has_value());
  EXPECT_EQ(result->exportNames->size(), 2);
  EXPECT_STREQ(result->exportNames->at(0).c_str(), "test1");
  EXPECT_STREQ(result->exportNames->at(1).c_str(), "test2");
}

TEST(unittest_ParserMemory, with_import_export){
  std::vector<char> data(create_char_vector("(memory (export \"testEx\") (import \"module\" \"test\") 24)"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 24);
  EXPECT_FALSE(result->memType.max.has_value());
  EXPECT_STREQ(result->importModule->c_str(), "module");
  EXPECT_STREQ(result->importName->c_str(), "test");
  EXPECT_EQ(result->exportNames->size(), 1);
  EXPECT_STREQ(result->exportNames->at(0).c_str(), "testEx");
}

TEST(unittest_ParserMemory, with_data){
  std::vector<char> data(create_char_vector("(memory (data \"hello\"))"));
  ParserContext context(data);
  ParserMemory result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result->memType.min, 1);
  EXPECT_TRUE(result->memType.max.has_value());
  EXPECT_EQ(result->memType.max, 1);
  EXPECT_TRUE(result->data.has_value());
  EXPECT_STREQ(result->data->c_str(), "hello");
}
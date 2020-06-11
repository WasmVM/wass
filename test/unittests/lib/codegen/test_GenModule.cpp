#include <gtest/gtest.h>

#include <vector>
#include <variant>
#include <Error.hpp>
#include <structure/Module.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include <Helper.hpp>

TEST(unittest_GenModule, empty){
  Module data;
  std::vector<char> result = std::visit<std::vector<char>>(CodeGenVisitor(), CodeGenVariant(data));
  std::vector<char> expect {BIN_MAGIC, BIN_VERSION};
  ASSERT_EQ(result.size(), expect.size());
  for(size_t i = 0; i < expect.size(); ++i){
    EXPECT_BITWISE_EQ(result[i], expect[i]);
  }
}

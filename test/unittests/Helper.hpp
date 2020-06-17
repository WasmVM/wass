#include <gtest/gtest.h>

#include <vector>
#include <cstddef>
#include <cstdint>
#include <codegen/CodeGenVisitor.hpp>

std::vector<char> create_char_vector(const char* data, size_t size);

std::vector<char> create_char_vector(const char* data);

#define EXPECT_BITWISE_EQ(a, b) EXPECT_EQ(*((uint32_t*)&a) ^ *((uint32_t*)&b), 0);

#define BIN_MAGIC   '\x00','\x61','\x73','\x6d'
#define BIN_VERSION '\x01','\x00','\x00','\x00'

class Mock_CodeGenVisitor: public CodeGenVisitor{
public:
  CodeGenVisitor::Context& getContext();
};
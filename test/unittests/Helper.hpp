#include <gtest/gtest.h>

#include <vector>
#include <cstddef>
#include <cstdint>

std::vector<char> create_char_vector(const char* data, size_t size);

std::vector<char> create_char_vector(const char* data);

double create_double_nan(bool negative = false);

double create_double_nan(int64_t mantissa, bool negative = false);

double create_double_inf(bool negative = false);

#define EXPECT_BITWISE_EQ(a, b) EXPECT_EQ(*((uint32_t*)&a) ^ *((uint32_t*)&b), 0);
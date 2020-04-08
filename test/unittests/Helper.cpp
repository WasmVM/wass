#include "Helper.hpp"

#include <cstring>

std::vector<char> create_char_vector(const char* data, size_t size){
  std::vector<char> result(size);
  std::memcpy(result.data(), data, size);
  return result;
}

std::vector<char> create_char_vector(const char* data){
  return create_char_vector(data, strlen(data));
}

union DoubleUnion{
  struct {
    int8_t sign: 1;
    int16_t exponent: 11;
    int64_t mantissa: 52;
  } part;
  double value;
};
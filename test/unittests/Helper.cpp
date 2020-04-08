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

double create_double_nan(bool negative){
  DoubleUnion data;
  data.part.sign = negative ? 1 : 0;
  data.part.exponent = 0x7ff;
  data.part.mantissa = 1;
  return data.value;
}

double create_double_nan(int64_t mantissa, bool negative){
  DoubleUnion data;
  data.part.sign = negative ? 1 : 0;
  data.part.exponent = 0x7ff;
  data.part.mantissa = mantissa;
  return data.value;
}

double create_double_inf(bool negative){
  DoubleUnion data;
  data.part.sign = negative ? 1 : 0;
  data.part.exponent = 0x7ff;
  data.part.mantissa = 0;
  return data.value;
}
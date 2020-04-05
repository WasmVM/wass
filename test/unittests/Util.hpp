#include <vector>
#include <cstddef>
#include <cstring>

std::vector<char> create_char_vector(const char* data, size_t size){
  std::vector<char> result(size);
  std::memcpy(result.data(), data, size);
  return result;
}

std::vector<char> create_char_vector(const char* data){
  return create_char_vector(data, strlen(data));
}
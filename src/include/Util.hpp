#ifndef GUARD_wass_Util
#define GUARD_wass_Util

#include <vector>
#include <string>
#include <cstdint>

namespace Util{
  bool matchString(std::vector<char>::iterator& begin, std::vector<char>::iterator& end, std::string str);
  template<typename T>
  std::vector<char> toLEB128(T value);
}

#endif
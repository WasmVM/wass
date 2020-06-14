#ifndef GUARD_wass_Util
#define GUARD_wass_Util

#include <vector>
#include <string>
#include <cstdint>
#include <BinaryCode.hpp>

namespace Util{
  bool matchString(std::vector<char>::iterator& begin, std::vector<char>::iterator& end, std::string str);
  template<typename T>
  BinaryCode toLEB128(T value);
}

#endif
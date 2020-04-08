#ifndef GUARD_wass_Util
#define GUARD_wass_Util

#include <vector>
#include <string>

namespace Util{
  bool matchString(std::vector<char>::iterator& begin, std::vector<char>::iterator& end, std::string str);
}

#endif
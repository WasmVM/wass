#ifndef GUARD_wass_structure_Data
#define GUARD_wass_structure_Data

#include <string>
#include <cstdint>
#include <structure/InstrVariant.hpp>

class Data{
public:
  uint32_t memIndex;
  ConstExprVariant expr;
  std::string data;
};

#endif
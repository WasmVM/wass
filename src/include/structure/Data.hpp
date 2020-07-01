#ifndef GUARD_wass_structure_Data
#define GUARD_wass_structure_Data

#include <string>
#include <cstdint>
#include <structure/InstrVariant.hpp>
#include <structure/Index.hpp>

class Data{
public:
  Index memIndex;
  ConstExprVariant expr;
  std::string data;
};

#endif
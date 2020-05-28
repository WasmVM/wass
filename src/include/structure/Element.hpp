#ifndef GUARD_wass_structure_Element
#define GUARD_wass_structure_Element

#include <string>
#include <vector>
#include <cstdint>
#include <structure/InstrVariant.hpp>

class Element{
public:
  uint32_t tableIndex;
  ConstExprVariant expr;
  std::vector<uint32_t> funcIndices;
};

#endif
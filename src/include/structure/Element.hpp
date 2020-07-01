#ifndef GUARD_wass_structure_Element
#define GUARD_wass_structure_Element

#include <string>
#include <vector>
#include <cstdint>
#include <structure/InstrVariant.hpp>
#include <structure/Index.hpp>

class Element{
public:
  Index tableIndex;
  ConstExprVariant expr;
  std::vector<Index> funcIndices;
};

#endif
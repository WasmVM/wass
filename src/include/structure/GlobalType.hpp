#ifndef GUARD_wass_structure_GlobalType
#define GUARD_wass_structure_GlobalType

#include <structure/Value.hpp>

class GlobalType{
public:
  GlobalType(const GlobalType&) = default;
  GlobalType();
  GlobalType(ValueType type, bool immutable = true);
  ValueType type;
  bool immutable;
};

#endif
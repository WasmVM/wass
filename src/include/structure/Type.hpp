#ifndef GUARD_wass_structure_Type
#define GUARD_wass_structure_Type

#include <optional>
#include <string>
#include <structure/FuncType.hpp>

class Type{
public:
  std::optional<std::string> id;
  FuncType funcType;
};

#endif
#ifndef GUARD_wass_structure_FuncType
#define GUARD_wass_structure_FuncType

#include <unordered_map>
#include <string>
#include <vector>
#include <cstdint>
#include <structure/ValueType.hpp>

class FuncType{
public:
  FuncType() = default;
  FuncType(const FuncType&);
  std::unordered_map<std::string, uint32_t> paramMap;
  std::vector<ValueType> params;
  std::vector<ValueType> results;
};

#endif
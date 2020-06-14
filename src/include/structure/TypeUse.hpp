#ifndef GUARD_wass_structure_TypeUse
#define GUARD_wass_structure_TypeUse

#include <any>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdint>
#include <structure/ValueType.hpp>

class TypeUse{
public:
  TypeUse() = default;
  TypeUse(const TypeUse&);
  std::any index; // string: identifier, uint32_t: typeidx
  std::unordered_map<std::string, uint32_t> paramMap;
  std::vector<ValueType> params;
  std::vector<ValueType> results;
};

#endif
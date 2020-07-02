#ifndef GUARD_wass_structure_TypeUse
#define GUARD_wass_structure_TypeUse

#include <optional>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdint>
#include <structure/ValueType.hpp>
#include <structure/Index.hpp>

class TypeUse{
public:
  TypeUse() = default;
  TypeUse(const TypeUse&);
  std::optional<Index> index;
  std::unordered_map<std::string, uint32_t> paramMap;
  std::vector<ValueType> params;
  std::vector<ValueType> results;
};

#endif
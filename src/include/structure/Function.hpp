#ifndef GUARD_wass_structure_Function
#define GUARD_wass_structure_Function

#include <map>
#include <vector>
#include <string>
#include <utility>
#include <optional>
#include <cstdint>
#include <structure/TypeUse.hpp>
#include <structure/InstrVariant.hpp>

class Function{
public:
  Function();
  std::optional<std::string> id;
  TypeUse typeUse;
  std::string importModule;
  std::string importName;
  std::vector<std::string> exportNames;
  struct Content{
    std::map<std::string, uint32_t> localMap;
    std::vector<ValueType> locals;
    std::vector<InstrVariant> body;
  } content;
};

#endif
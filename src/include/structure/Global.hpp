#ifndef GUARD_wass_structure_Global
#define GUARD_wass_structure_Global

#include <optional>
#include <vector>
#include <cstdint>
#include <string>
#include <structure/GlobalType.hpp>
#include <structure/InstrVariant.hpp>

class Global{
public:
  Global() = default;
  std::optional<std::string> id;
  GlobalType globalType;
  ConstExprVariant expr;
  std::optional<std::string> importModule;
  std::optional<std::string> importName;
  std::optional<std::vector<std::string>> exportNames;
};

#endif
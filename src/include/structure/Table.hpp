#ifndef GUARD_wass_structure_Table
#define GUARD_wass_structure_Table

#include <optional>
#include <string>
#include <vector>
#include <cstdint>
#include <structure/Limit.hpp>

class Table{
public:
  Table() = default;
  std::optional<std::string> id;
  Limit tableType;
  std::optional<std::vector<uint32_t>> elements;
  std::optional<std::string> importModule;
  std::optional<std::string> importName;
  std::optional<std::vector<std::string>> exportNames;
};

#endif
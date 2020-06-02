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
  std::string importModule;
  std::string importName;
  std::vector<std::string> exportNames;
};

#endif
#ifndef GUARD_wass_structure_Memory
#define GUARD_wass_structure_Memory

#include <optional>
#include <string>
#include <cstdint>
#include <vector>
#include <structure/Limit.hpp>

class Memory{
public:
  Memory() = default;
  std::optional<std::string> id;
  Limit memType;
  std::optional<std::string> data;
  std::optional<std::string> importModule;
  std::optional<std::string> importName;
  std::optional<std::vector<std::string>> exportNames;
};

#endif
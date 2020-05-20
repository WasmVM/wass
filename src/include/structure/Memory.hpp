#ifndef GUARD_wass_structure_Memory
#define GUARD_wass_structure_Memory

#include <optional>
#include <string>
#include <cstdint>
#include <structure/Limit.hpp>

class Memory{
public:
  Memory() = default;
  std::optional<std::string> id;
  Limit memType;
};

#endif
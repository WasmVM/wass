#ifndef GUARD_wass_structure_Limit
#define GUARD_wass_structure_Limit

#include <optional>
#include <cstdint>

class Limit{
public:
  Limit() = default;
  Limit(uint32_t min);
  Limit(uint32_t min, uint32_t max);
  uint32_t min;
  std::optional<uint32_t> max;
};

#endif
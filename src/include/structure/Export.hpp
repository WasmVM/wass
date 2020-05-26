#ifndef GUARD_wass_structure_Export
#define GUARD_wass_structure_Export

#include <string>
#include <cstdint>

enum class ExportType{
  none,
  Table,
  Memory,
  Func,
  Global
};

class Export{
public:
  std::string name;
  uint32_t index;
  ExportType type;
};

#endif
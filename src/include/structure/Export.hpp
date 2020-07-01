#ifndef GUARD_wass_structure_Export
#define GUARD_wass_structure_Export

#include <string>
#include <cstdint>
#include <structure/Index.hpp>

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
  Index index;
  ExportType type;
};

#endif
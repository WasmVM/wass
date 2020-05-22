#ifndef GUARD_wass_structure_Global
#define GUARD_wass_structure_Global

#include <optional>
#include <string>
#include <structure/GlobalType.hpp>
#include <structure/InstrVariant.hpp>

class Global{
public:
  Global() = default;
  std::optional<std::string> id;
  GlobalType globalType;
  InstrVariant expr;
};

#endif
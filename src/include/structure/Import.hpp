#ifndef GUARD_wass_structure_Import
#define GUARD_wass_structure_Import

#include <variant>
#include <optional>
#include <string>
#include <structure/Limit.hpp>
#include <structure/TypeUse.hpp>
#include <structure/GlobalType.hpp>

using ImportDesc = std::variant<
  std::monostate,
  TypeUse,
  Limit,
  GlobalType
>;

class Import{
public:
  std::string mod;
  std::string name;
  std::optional<std::string> descId;
  enum class ImportType{
    Function,
    Table,
    Memory,
    Global
  };
  ImportType type;
  ImportDesc desc;
};

#endif
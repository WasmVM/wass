#ifndef GUARD_wass_structure_Module
#define GUARD_wass_structure_Module

#include <string>
#include <vector>
#include <cstdint>
#include <optional>
#include <structure/Type.hpp>
#include <structure/Import.hpp>
#include <structure/Function.hpp>
#include <structure/Table.hpp>
#include <structure/Memory.hpp>
#include <structure/Global.hpp>
#include <structure/Export.hpp>
#include <structure/Element.hpp>
#include <structure/Data.hpp>

class Module{
public:
  std::optional<std::string> id;
  std::vector<Type> types;
  std::vector<Import> imports;
  std::vector<Function> funcs;
  std::vector<Table> tables;
  std::vector<Memory> memories;
  std::vector<Global> globals;
  std::vector<Export> exports;
  std::vector<Element> elems;
  std::optional<uint32_t> start;
  std::vector<Data> datas;
};

#endif
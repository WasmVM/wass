#ifndef GUARD_wass_codegen_CodeGenVisitor
#define GUARD_wass_codegen_CodeGenVisitor

#include <variant>
#include <vector>
#include <map>
#include <cstdint>
#include <string>
#include <structure/Module.hpp>
#include <structure/Type.hpp>
#include <structure/FuncType.hpp>
#include <structure/ValueType.hpp>

using CodeGenVariant = std::variant<
  Module,
  Type,
  FuncType,
  ValueType
>;

class CodeGenVisitor{
public:
  struct {
    std::vector<char> typeCode;
    std::map<std::string, uint32_t> typeMap;
  } context;

  std::vector<char> operator()(Module&&);
  std::vector<char> operator()(Type&&);
  std::vector<char> operator()(FuncType&&);
  std::vector<char> operator()(ValueType&&);
};

#endif
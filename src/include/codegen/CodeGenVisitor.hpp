#ifndef GUARD_wass_codegen_CodeGenVisitor
#define GUARD_wass_codegen_CodeGenVisitor

#include <variant>
#include <vector>
#include <map>
#include <cstdint>
#include <string>
#include <BinaryCode.hpp>
#include <structure/Module.hpp>
#include <structure/FuncType.hpp>
#include <structure/ValueType.hpp>

using CodeGenVariant = std::variant<
  Module,
  FuncType,
  ValueType
>;

class CodeGenVisitor{
public:
  BinaryCode operator()(Module&&);
  BinaryCode operator()(FuncType&&);
  BinaryCode operator()(ValueType&&);
private:
  struct {
    std::vector<BinaryCode> typeCodes;
    std::map<std::string, uint32_t> typeMap;
  } context;
};

#endif
#ifndef GUARD_wass_codegen_CodeGenVisitor
#define GUARD_wass_codegen_CodeGenVisitor

#include <variant>
#include <vector>
#include <map>
#include <cstdint>
#include <string>
#include <utility>
#include <BinaryCode.hpp>
#include <structure/Type.hpp>
#include <structure/Module.hpp>
#include <structure/FuncType.hpp>
#include <structure/ValueType.hpp>
#include <structure/TypeUse.hpp>

using CodeGenVariant = std::variant<
  Module,
  FuncType,
  ValueType,
  Type,
  TypeUse
>;

class CodeGenVisitor{
public:
  BinaryCode operator()(Module&&);
  BinaryCode operator()(Type&&);
  BinaryCode operator()(FuncType&&);
  BinaryCode operator()(ValueType&&);
  BinaryCode operator()(TypeUse&&);
protected:
  struct Context{
    std::vector<FuncType> typeDescs;
    std::map<std::string, uint32_t> identifierMap;
  } context;
};

#endif
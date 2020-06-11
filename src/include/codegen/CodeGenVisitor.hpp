#ifndef GUARD_wass_codegen_CodeGenVisitor
#define GUARD_wass_codegen_CodeGenVisitor

#include <variant>
#include <vector>
#include <structure/Module.hpp>

using CodeGenVariant = std::variant<
  Module
>;

class CodeGenVisitor{
public:
  std::vector<char> operator()(Module&&);
};

#endif
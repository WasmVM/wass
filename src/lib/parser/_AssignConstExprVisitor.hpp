#ifndef GUARD_wass_parser__AssignConstExprVisitor
#define GUARD_wass_parser__AssignConstExprVisitor

#include <variant>
#include <structure/InstrVariant.hpp>

struct AssignExprVisitor{
  ConstExprVariant& expr;
  AssignExprVisitor(ConstExprVariant& expr);
  void operator()(I32ConstInstr arg);
  void operator()(I64ConstInstr arg);
  void operator()(F32ConstInstr arg);
  void operator()(F64ConstInstr arg);
  void operator()(GlobalGetInstr arg);
  void operator()(std::monostate);
};

#endif
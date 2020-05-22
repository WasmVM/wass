#ifndef GUARD_wass_parser_ParserConstExpr
#define GUARD_wass_parser_ParserConstExpr

#include <variant>
#include <structure/ConstInstr.hpp>
#include <structure/VariableInstr.hpp>
#include <parser/ParserContext.hpp>

class ParserConstInstr: public std::variant<
  std::monostate,
  I32ConstInstr,
  I64ConstInstr,
  F32ConstInstr,
  F64ConstInstr
>{
public:
  ParserConstInstr(ParserContext& context);
};

#endif
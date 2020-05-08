#ifndef GUARD_wass_parser_ParserControlcInstr
#define GUARD_wass_parser_ParserControlcInstr

#include <optional>
#include <variant>
#include <structure/ControlInstr.hpp>
#include <parser/ParserContext.hpp>

class ParserControlInstr: public std::variant<
  std::monostate,
  UnreachableInstr,
  NopInstr,
  ReturnInstr,
  BrInstr,
  BrIfInstr,
  BrTableInstr,
  CallInstr,
  CallIndirectInstr
>{
public:
  ParserControlInstr(ParserContext& context);
};

#endif
#ifndef GUARD_wass_parser_ParserConstInstr
#define GUARD_wass_parser_ParserConstInstr

#include <variant>
#include <structure/ConstInstr.hpp>
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
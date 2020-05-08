#ifndef GUARD_wass_parser_ParserVariableInstr
#define GUARD_wass_parser_ParserVariableInstr

#include <variant>
#include <structure/VariableInstr.hpp>
#include <parser/ParserContext.hpp>

class ParserVariableInstr: public std::variant<
  std::monostate,
  LocalGetInstr,
  LocalSetInstr,
  LocalTeeInstr,
  GlobalGetInstr,
  GlobalSetInstr
>{
public:
  ParserVariableInstr(ParserContext& context);
};

#endif
#ifndef GUARD_wass_parser_ParserNumericInstr
#define GUARD_wass_parser_ParserNumericInstr

#include <variant>
#include <parser/ParserContext.hpp>
#include <structure/ParamInstr.hpp>

class ParserParamInstr: public std::variant<
  std::monostate,
  SelectInstr,
  DropInstr
>{
public:
  ParserParamInstr(ParserContext& context);
};

#endif
#ifndef GUARD_wass_parser_ParserBlockedInstr
#define GUARD_wass_parser_ParserBlockedInstr

#include <variant>
#include <structure/BlockedInstr.hpp>
#include <parser/ParserContext.hpp>

class ParserBlockedInstr: public std::variant<
  std::monostate,
  BlockInstr,
  LoopInstr,
  IfInstr
>{
public:
  ParserBlockedInstr(ParserContext& context);
};

#endif
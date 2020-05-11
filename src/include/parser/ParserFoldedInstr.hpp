#ifndef GUARD_wass_parser_ParserFoldedInstr
#define GUARD_wass_parser_ParserFoldedInstr

#include <optionl>
#include <structure/BlockedInstr.hpp>
#include <parser/ParserContext.hpp>

class ParserFoldedInstr: public std::variant<
  std::monostate,
  BlockInstr,
  LoopInstr,
  IfInstr
>{
public:
  ParserFoldedInstr(ParserContext& context);
};

#endif
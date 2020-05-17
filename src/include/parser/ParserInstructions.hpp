#ifndef GUARD_wass_parser_ParserInstructions
#define GUARD_wass_parser_ParserInstructions

#include <optional>
#include <vector>
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

class ParserFoldedInstr: public std::optional<std::vector<InstrVariant>>{
public:
  ParserFoldedInstr(ParserContext& context);
};

InstrVariant getInstruction(ParserContext& context);

#endif
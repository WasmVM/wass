#ifndef GUARD_wass_parser_ParserFunction
#define GUARD_wass_parser_ParserFunction

#include <optional>
#include <structure/Function.hpp>
#include <parser/ParserContext.hpp>

class ParserFunction: public std::optional<Function>{
public:
  ParserFunction(ParserContext& context);
};

#endif
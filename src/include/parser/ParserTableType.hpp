#ifndef GUARD_wass_parser_ParserTableType
#define GUARD_wass_parser_ParserTableType

#include <optional>
#include <structure/Limit.hpp>
#include <parser/ParserContext.hpp>

class ParserTableType: public std::optional<Limit>{
public:
  ParserTableType(ParserContext& context);
};

#endif
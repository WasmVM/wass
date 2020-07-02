#ifndef GUARD_wass_parser_ParserStart
#define GUARD_wass_parser_ParserStart

#include <optional>
#include <cstdint>
#include <parser/ParserContext.hpp>
#include <structure/Index.hpp>

class ParserStart: public std::optional<Index>{
public:
  ParserStart(ParserContext& context);
};

#endif
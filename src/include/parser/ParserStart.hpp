#ifndef GUARD_wass_parser_ParserStart
#define GUARD_wass_parser_ParserStart

#include <optional>
#include <cstdint>
#include <parser/ParserContext.hpp>

class ParserStart: public std::optional<uint32_t>{
public:
  ParserStart(ParserContext& context);
};

#endif
#ifndef GUARD_wass_parser_ParserMemory
#define GUARD_wass_parser_ParserMemory

#include <optional>
#include <structure/Memory.hpp>
#include <parser/ParserContext.hpp>

class ParserMemory : public std::optional<Memory>{
public:
  ParserMemory(ParserContext& context);
};

#endif
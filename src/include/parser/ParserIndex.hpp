#ifndef GUARD_wass_parser_ParserIndex
#define GUARD_wass_parser_ParserIndex

#include <optional>
#include <structure/Index.hpp>
#include <parser/ParserContext.hpp>

class ParserIndex: public std::optional<Index>{
public:
  ParserIndex(ParserContext& context);
};

#endif
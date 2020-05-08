#ifndef GUARD_wass_parser_ParserGlobalType
#define GUARD_wass_parser_ParserGlobalType

#include <optional>
#include <structure/GlobalType.hpp>
#include <parser/ParserContext.hpp>

class ParserGlobalType : public std::optional<GlobalType>{
public:
  ParserGlobalType(ParserContext& context);
};

#endif
#ifndef GUARD_wass_parser_ParserTypeUse
#define GUARD_wass_parser_ParserTypeUse

#include <optional>
#include <structure/TypeUse.hpp>
#include <parser/ParserContext.hpp>

class ParserTypeUse : public std::optional<TypeUse>{
public:
  ParserTypeUse(ParserContext& context);
};

#endif
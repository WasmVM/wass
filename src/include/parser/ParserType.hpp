#ifndef GUARD_wass_parser_Type
#define GUARD_wass_parser_Type

#include <optional>
#include <parser/ParserContext.hpp>
#include <structure/Type.hpp>

class ParserType: public std::optional<Type>{
public:
  ParserType(ParserContext& context);
};

#endif
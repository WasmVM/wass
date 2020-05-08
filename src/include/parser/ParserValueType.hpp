#ifndef GUARD_wass_parser_ParserValueType
#define GUARD_wass_parser_ParserValueType

#include <optional>
#include <structure/Value.hpp>
#include <parser/ParserContext.hpp>

class ParserValueType: public std::optional<ValueType>{
public:
  ParserValueType(ParserContext& context);
};

#endif
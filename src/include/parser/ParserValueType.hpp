#ifndef GUARD_wass_parser_ParserValueType
#define GUARD_wass_parser_ParserValueType

#include <any>
#include <structure/Value.hpp>
#include <parser/ParserContext.hpp>

class ParserValueType: public std::any{
public:
  ParserValueType(ParserContext& context);
};

#endif
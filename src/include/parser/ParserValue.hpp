#ifndef GUARD_wass_parser_ParserValue
#define GUARD_wass_parser_ParserValue

#include <any>
#include <structure/Value.hpp>
#include <parser/ParserContext.hpp>

class ParserValueType: public std::any{
public:
  ParserValueType(ParserContext& context);
};

class ParserValue: public Value{
public:
  ParserValue(ParserContext& context);
};

#endif
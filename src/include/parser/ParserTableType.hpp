#ifndef GUARD_wass_parser_ParserTableType
#define GUARD_wass_parser_ParserTableType

#include <any>
#include <structure/Limit.hpp>
#include <parser/ParserContext.hpp>

class ParserTableType: public std::any{
public:
  ParserTableType(ParserContext& context);
};

#endif
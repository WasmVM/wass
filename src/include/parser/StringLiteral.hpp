#ifndef GUARD_wass_parser_StringLiteral
#define GUARD_wass_parser_StringLiteral

#include <any>
#include <parser/ParserContext.hpp>

class StringLiteral: public std::any{
public:
  StringLiteral(ParserContext& context);
};

#endif
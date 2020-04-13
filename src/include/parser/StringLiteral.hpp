#ifndef GUARD_wass_parser_FloatLiteral
#define GUARD_wass_parser_FloatLiteral

#include <any>
#include <parser/ParserContext.hpp>

class StringLiteral: public std::any{
public:
  StringLiteral(ParserContext& context);
};

#endif
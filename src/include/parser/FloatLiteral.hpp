#ifndef GUARD_wass_parser_FloatLiteral
#define GUARD_wass_parser_FloatLiteral

#include <any>
#include <parser/ParserContext.hpp>

class FloatLiteral: public std::any{
public:
  FloatLiteral(ParserContext& context);
};

#endif
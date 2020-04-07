#ifndef GUARD_wass_parser_IntegerLiteral
#define GUARD_wass_parser_IntegerLiteral

#include <any>
#include <parser/ParserContext.hpp>

class IntegerLiteral: public std::any{
public:
  IntegerLiteral(ParserContext& context);
};

#endif
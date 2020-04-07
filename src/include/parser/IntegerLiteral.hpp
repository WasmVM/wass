#ifndef GUARD_wass_parser_Literal
#define GUARD_wass_parser_Literal

#include <parser/ParserInstance.hpp>
#include <parser/ParserContext.hpp>

class IntegerLiteral: public ParserInstance{
public:
  IntegerLiteral(ParserContext& context);
};

#endif
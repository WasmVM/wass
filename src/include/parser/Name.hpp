#ifndef GUARD_wass_parser_Name
#define GUARD_wass_parser_Name

#include <parser/StringLiteral.hpp>

class Name: public StringLiteral{
public:
  Name(ParserContext& context);
};

#endif
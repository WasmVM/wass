#ifndef GUARD_wass_parser_Identifier
#define GUARD_wass_parser_Identifier

#include <any>
#include <parser/ParserContext.hpp>

class Identifier: public std::any{
public:
  Identifier(ParserContext& context);
};

#endif
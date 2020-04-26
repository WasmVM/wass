#ifndef GUARD_wass_parser_ParserNumericInstr
#define GUARD_wass_parser_ParserNumericInstr

#include <any>
#include <parser/ParserContext.hpp>

class ParserNumericInstr: public std::any{
public:
  ParserNumericInstr(ParserContext& context);
};

#endif
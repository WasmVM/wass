#ifndef GUARD_wass_parser_ParserControlcInstr
#define GUARD_wass_parser_ParserControlcInstr

#include <any>
#include <parser/ParserContext.hpp>

class ParserControlInstr: public std::any{
public:
  ParserControlInstr(ParserContext& context);
};

#endif
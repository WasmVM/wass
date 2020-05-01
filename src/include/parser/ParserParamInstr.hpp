#ifndef GUARD_wass_parser_ParserNumericInstr
#define GUARD_wass_parser_ParserNumericInstr

#include <any>
#include <parser/ParserContext.hpp>

class ParserParamInstr: public std::any{
public:
  ParserParamInstr(ParserContext& context);
};

#endif
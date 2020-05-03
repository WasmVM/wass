#ifndef GUARD_wass_parser_ParserVariableInstr
#define GUARD_wass_parser_ParserVariableInstr

#include <any>
#include <parser/ParserContext.hpp>

class ParserVariableInstr: public std::any{
public:
  ParserVariableInstr(ParserContext& context);
};

#endif
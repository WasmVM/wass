#ifndef GUARD_wass_parser_ParserConstInstr
#define GUARD_wass_parser_ParserConstInstr

#include <any>
#include <parser/ParserContext.hpp>

class ParserVariableInstr: public std::any{
public:
  ParserVariableInstr(ParserContext& context);
};

#endif
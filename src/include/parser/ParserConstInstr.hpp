#ifndef GUARD_wass_parser_ParserConstInstr
#define GUARD_wass_parser_ParserConstInstr

#include <any>
#include <parser/ParserContext.hpp>
#include <structure/ConstInstr.hpp>

class ParserConstInstr: public std::any{
public:
  ParserConstInstr(ParserContext& context);
};

#endif
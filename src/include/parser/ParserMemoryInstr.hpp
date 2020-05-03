#ifndef GUARD_wass_parser_ParserMemoryInstr
#define GUARD_wass_parser_ParserMemoryInstr

#include <any>
#include <parser/ParserContext.hpp>

class ParserMemoryInstr: public std::any{
public:
  ParserMemoryInstr(ParserContext& context);
};

#endif
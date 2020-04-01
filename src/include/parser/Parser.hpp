#ifndef GUARD_wass_parser_Parser
#define GUARD_wass_parser_Parser

#include <any>

#include <parser/ParserContext.hpp>

class Parser{
public:
  virtual std::any parse() = 0;

protected:
  Parser(ParserContext& context);
  ParserContext& context;
};

#endif
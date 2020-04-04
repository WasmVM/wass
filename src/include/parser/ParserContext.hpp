#ifndef GUARD_wass_parser_ParserContext
#define GUARD_wass_parser_ParserContext

#include <string>

struct ParserContext{
  ParserContext(std::string& data);
  std::string::iterator cursor;
  std::string::iterator end;
};

#endif
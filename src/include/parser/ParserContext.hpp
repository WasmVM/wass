#ifndef GUARD_wass_parser_ParserContext
#define GUARD_wass_parser_ParserContext

#include <vector>

struct ParserContext{
  ParserContext(std::vector<char>& data);
  std::vector<char>::iterator cursor;
  std::vector<char>::iterator end;
};

#endif
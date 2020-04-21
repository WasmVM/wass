#ifndef GUARD_wass_parser_ParserResult
#define GUARD_wass_parser_ParserResult

#include <any>
#include <string>
#include <parser/ParserValue.hpp>
#include <parser/ParserContext.hpp>

class ParserResult : public std::any{
public:
  std::string id;
  ParserResult(ParserContext& context);
};

#endif
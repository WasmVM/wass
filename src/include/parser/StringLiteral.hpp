#ifndef GUARD_wass_parser_StringLiteral
#define GUARD_wass_parser_StringLiteral

#include <optional>
#include <string>
#include <parser/ParserContext.hpp>

class StringLiteral: public std::optional<std::string>{
public:
  StringLiteral(ParserContext& context);
};

#endif
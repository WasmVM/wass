#ifndef GUARD_wass_parser_Identifier
#define GUARD_wass_parser_Identifier

#include <string>
#include <optional>
#include <parser/ParserContext.hpp>

class Identifier: public std::optional<std::string>{
public:
  Identifier(ParserContext& context);
};

#endif
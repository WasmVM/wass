#ifndef GUARD_wass_parser_IntegerLiteral
#define GUARD_wass_parser_IntegerLiteral

#include <optional>
#include <parser/ParserContext.hpp>

class IntegerLiteral: public std::optional<int64_t>{
public:
  IntegerLiteral(ParserContext& context);
};

#endif
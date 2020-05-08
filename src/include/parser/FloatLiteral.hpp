#ifndef GUARD_wass_parser_FloatLiteral
#define GUARD_wass_parser_FloatLiteral

#include <optional>
#include <parser/ParserContext.hpp>

class FloatLiteral: public std::optional<double>{
public:
  FloatLiteral(ParserContext& context);
};

#endif
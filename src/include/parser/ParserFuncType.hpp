#ifndef GUARD_wass_parser_ParserFuncType
#define GUARD_wass_parser_ParserFuncType

#include <optional>
#include <structure/FuncType.hpp>
#include <parser/ParserContext.hpp>

class ParserFuncType : public std::optional<FuncType>{
public:
  ParserFuncType(ParserContext& context);
};

#endif
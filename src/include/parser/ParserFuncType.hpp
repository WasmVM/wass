#ifndef GUARD_wass_parser_ParserFuncType
#define GUARD_wass_parser_ParserFuncType

#include <any>
#include <parser/ParserContext.hpp>

class ParserFuncType : public std::any{
public:
  ParserFuncType(ParserContext& context);
};

#endif
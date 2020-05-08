#ifndef GUARD_wass_parser_ParserTypeUse
#define GUARD_wass_parser_ParserTypeUse

#include <any>
#include <parser/ParserContext.hpp>

class ParserTypeUse : public std::any{
public:
  ParserTypeUse(ParserContext& context);
};

#endif
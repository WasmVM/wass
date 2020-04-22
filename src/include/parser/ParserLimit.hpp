#ifndef GUARD_wass_parser_ParserLimit
#define GUARD_wass_parser_ParserLimit

#include <any>
#include <structure/Limit.hpp>
#include <parser/ParserContext.hpp>

class ParserLimit: public std::any{
public:
  ParserLimit(ParserContext& context);
};

#endif
#ifndef GUARD_wass_parser_ParserLimit
#define GUARD_wass_parser_ParserLimit

#include <optional>
#include <structure/Limit.hpp>
#include <parser/ParserContext.hpp>

class ParserLimit: public std::optional<Limit>{
public:
  ParserLimit(ParserContext& context);
};

#endif
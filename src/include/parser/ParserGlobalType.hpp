#ifndef GUARD_wass_parser_ParserGlobalType
#define GUARD_wass_parser_ParserGlobalType

#include <any>
#include <parser/ParserContext.hpp>

class ParserGlobalType : public std::any{
public:
  ParserGlobalType(ParserContext& context);
};

#endif
#ifndef GUARD_wass_parser_ParserInstance
#define GUARD_wass_parser_ParserInstance

#include <any>
#include <parser/ParserContext.hpp>

class ParserInstance: public std::any{
  ParserInstance() = delete;
protected:
  ParserInstance(ParserContext& context);
  ParserContext& context;
};

#endif
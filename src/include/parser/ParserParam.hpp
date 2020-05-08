#ifndef GUARD_wass_parser_ParserParam
#define GUARD_wass_parser_ParserParam

#include <any>
#include <string>
#include <parser/ParserValueType.hpp>
#include <parser/ParserContext.hpp>

class ParserParam : public std::any{
public:
  std::string id;
  ParserParam(ParserContext& context);
};

#endif
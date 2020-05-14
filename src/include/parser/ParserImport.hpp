#ifndef GUARD_wass_parser_ParserImport
#define GUARD_wass_parser_ParserImport

#include <optional>
#include <structure/Import.hpp>
#include <parser/ParserContext.hpp>

class ParserImport: public std::optional<Import>{
public:
  ParserImport(ParserContext& context);
};

#endif
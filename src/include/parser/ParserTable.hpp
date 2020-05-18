#ifndef GUARD_wass_parser_ParserTable
#define GUARD_wass_parser_ParserTable

#include <optional>
#include <structure/Table.hpp>
#include <parser/ParserContext.hpp>

class ParserTable : public std::optional<Table>{
public:
  ParserTable(ParserContext& context);
};

#endif
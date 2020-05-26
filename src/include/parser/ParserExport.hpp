#ifndef GUARD_wass_parser_ParserExport
#define GUARD_wass_parser_ParserExport

#include <optional>
#include <structure/Export.hpp>
#include <parser/ParserContext.hpp>

class ParserExport: public std::optional<Export>{
public:
  ParserExport(ParserContext& context);
};

#endif
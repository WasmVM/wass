#ifndef GUARD_wass_parser_ParserData
#define GUARD_wass_parser_ParserData

#include <optional>
#include <structure/Data.hpp>
#include <parser/ParserContext.hpp>

class ParserData: public std::optional<Data>{
public:
  ParserData(ParserContext& context);
};

#endif
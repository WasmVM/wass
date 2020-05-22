#ifndef GUARD_wass_parser_ParserGlobal
#define GUARD_wass_parser_ParserGlobal

#include <optional>
#include <structure/Global.hpp>
#include <parser/ParserContext.hpp>

class ParserGlobal : public std::optional<Global>{
public:
  ParserGlobal(ParserContext& context);
};

#endif
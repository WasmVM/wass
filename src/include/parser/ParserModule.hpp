#ifndef GUARD_wass_parser_ParserModule
#define GUARD_wass_parser_ParserModule

#include <optional>
#include <structure/Module.hpp>
#include <parser/ParserContext.hpp>

class ParserModule: public std::optional<Module>{
public:
  ParserModule(ParserContext& context);
};

#endif
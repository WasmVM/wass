#ifndef GUARD_wass_parser_ParserElement
#define GUARD_wass_parser_ParserElement

#include <optional>
#include <structure/Element.hpp>
#include <parser/ParserContext.hpp>

class ParserElement: public std::optional<Element>{
public:
  ParserElement(ParserContext& context);
};

#endif
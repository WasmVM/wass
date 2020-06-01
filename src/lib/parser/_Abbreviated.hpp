#ifndef GUARD_wass_parser__Abbreviated
#define GUARD_wass_parser__Abbreviated

#include <optional>
#include <string>
#include <utility>
#include <parser/ParserContext.hpp>

class AbbrImport: public std::optional<std::pair<std::string, std::string>>{
public:
  AbbrImport(ParserContext& context);
};

class AbbrExport: public std::optional<std::string>{
public:
  AbbrExport(ParserContext& context);
};

#endif
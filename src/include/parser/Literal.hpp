#ifndef GUARD_wass_parser_Literal
#define GUARD_wass_parser_Literal

#include <structure/Value.hpp>
#include <parser/ParserContext.hpp>

namespace Litertal {
  Value::Int32 parseInt32(ParserContext& context);
  Value::Int64 parseInt64(ParserContext& context);
  Value::Float32 parseFloat32(ParserContext& context);
  Value::Float64 parseFloat64(ParserContext& context);
}

#endif
#include <parser/Literal.hpp>

#include <Error.hpp>

Value::Int32 Litertal::parseInt32(ParserContext& context){
  throw Error<ErrorType::UnImplemented>("Int32 literal unimplemented");
}

Value::Int64 Litertal::parseInt64(ParserContext& context){
  throw Error<ErrorType::UnImplemented>("Int64 literal unimplemented");
}

Value::Float32 Litertal::parseFloat32(ParserContext& context){
  throw Error<ErrorType::UnImplemented>("Float32 literal unimplemented");
}

Value::Float64 Litertal::parseFloat64(ParserContext& context){
  throw Error<ErrorType::UnImplemented>("Float64 literal unimplemented");
}
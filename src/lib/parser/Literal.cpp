#include <parser/Literal.hpp>

#include <cstdint>
#include <Error.hpp>

static bool isNegative(ParserContext& context){
  if((*context.cursor) == '-' || (*context.cursor) == '+'){
    return *(context.cursor++) == '-';
  }
  return false;
}

template<typename T>
static T decimalNumber(ParserContext& context){
  T result = 0;
  while (context.cursor != context.end){
    if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
      result = result * 10 + ((*context.cursor) - '0');
    }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || context.cursor[1] < '0' || context.cursor[1] > '9'){
      break;
    }
    ++context.cursor;
  }
  if((*context.cursor) == '_'){
    throw Error<ErrorType::SyntaxError>("unknown operator");
  }
  return result;
}

template<typename T>
static T hexNumber(ParserContext& context){
  T result = 0;
  if((*context.cursor) == '_'){
    throw Error<ErrorType::SyntaxError>("unknown operator");
  }
  while (context.cursor != context.end){
    if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
      result = (result << 4) + (*context.cursor) - '0';
    }else if((*context.cursor) >= 'a' && (*context.cursor) <= 'f'){
      result = (result << 4) + (*context.cursor) - 'a' + 10;
    }else if((*context.cursor) >= 'A' && (*context.cursor) <= 'F'){
      result = (result << 4) + (*context.cursor) - 'A' + 10;
    }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || (
      (context.cursor[1] < '0' || context.cursor[1] > '9') &&
      (context.cursor[1] < 'a' || context.cursor[1] > 'f') &&
      (context.cursor[1] < 'A' || context.cursor[1] > 'F'))
    ){
      break;
    }
    ++context.cursor;
  }
  if((*context.cursor) == '_'){
    throw Error<ErrorType::SyntaxError>("unknown operator");
  }
  return result;
}

Value::Int32 Litertal::parseInt32(ParserContext& context){
  bool negative = isNegative(context);
  if((*context.cursor) == '_'){
    throw Error<ErrorType::SyntaxError>("unknown operator");
  }
  if((*context.cursor) == '0' && context.cursor + 1 != context.end && context.cursor[1] == 'x'){
    context.cursor += 2;
    return Value::Int32(hexNumber<int32_t>(context) * ((negative) ? -1 : 1));
  }else{
    return Value::Int32(decimalNumber<int32_t>(context) * ((negative) ? -1 : 1));
  }
}

Value::Int64 Litertal::parseInt64(ParserContext& context){
  bool negative = isNegative(context);
  if((*context.cursor) == '_'){
    throw Error<ErrorType::SyntaxError>("unknown operator");
  }
  if((*context.cursor) == '0' && context.cursor + 1 != context.end && context.cursor[1] == 'x'){
    context.cursor += 2;
    return Value::Int64(hexNumber<int64_t>(context) * ((negative) ? -1 : 1));
  }else{
    return Value::Int64(decimalNumber<int64_t>(context) * ((negative) ? -1 : 1));
  }
}

Value::Float32 Litertal::parseFloat32(ParserContext& context){
  throw Error<ErrorType::UnImplemented>("Float32 literal unimplemented");
}

Value::Float64 Litertal::parseFloat64(ParserContext& context){
  throw Error<ErrorType::UnImplemented>("Float64 literal unimplemented");
}
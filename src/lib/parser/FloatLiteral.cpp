#include <parser/FloatLiteral.hpp>

#include <cstdint>
#include <Error.hpp>
#include <Util.hpp>

union DoubleUnion{
  struct {
    int8_t sign: 1;
    int16_t exponent: 11;
    int64_t mantissa: 52;
  } part;
  double value;
};


static int8_t signBit(ParserContext& context){
  if((*context.cursor) == '-' || (*context.cursor) == '+'){
    return (*(context.cursor++) == '-') ? 1 : 0;
  }
  return 0;
}

static void decimalNumber(std::any& thisAny, ParserContext& context, int8_t sign){
  DoubleUnion data;
  data.part.sign = sign;
  /*
  while(context.cursor != context.end){
    if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
      if(!thisAny.has_value()){
        thisAny = (int64_t)((*context.cursor) - '0');
      }else{
        thisAny = std::any_cast<int64_t>(thisAny) * 10 + (*context.cursor) - '0';
      }
    }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || context.cursor[1] < '0' || context.cursor[1] > '9'){
      if((*context.cursor) == '_'){
        thisAny.reset();
      }
      break;
    }
    ++context.cursor;
  }
  if(thisAny.has_value() && isNegative){
    thisAny = -std::any_cast<int64_t>(thisAny);
  }*/
}

static void hexNumber(std::any& thisAny, ParserContext& context, int8_t sign){
  // FIXME:
  /*
  if((*context.cursor) != '_'){
    while (context.cursor != context.end){
      if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
        if(!thisAny.has_value()){
          thisAny = (int64_t)((*context.cursor) - '0');
        }else{
          thisAny = (std::any_cast<int64_t>(thisAny) << 4) + (*context.cursor) - '0';
        }
      }else if((*context.cursor) >= 'a' && (*context.cursor) <= 'f'){
        if(!thisAny.has_value()){
          thisAny = (int64_t)(((*context.cursor) - 'a' + 10) * (isNegative ? -1 : 1));
        }else{
          thisAny = (std::any_cast<int64_t>(thisAny) << 4) + (*context.cursor) - 'a' + 10;
        }
      }else if((*context.cursor) >= 'A' && (*context.cursor) <= 'F'){
        if(!thisAny.has_value()){
          thisAny = (int64_t)(((*context.cursor) - 'A' + 10) * (isNegative ? -1 : 1));
        }else{
          thisAny = (std::any_cast<int64_t>(thisAny) << 4) + (*context.cursor) - 'A' + 10;
        }
      }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || (
        (context.cursor[1] < '0' || context.cursor[1] > '9') &&
        (context.cursor[1] < 'a' || context.cursor[1] > 'f') &&
        (context.cursor[1] < 'A' || context.cursor[1] > 'F'))
      ){
        if((*context.cursor) == '_'){
          thisAny.reset();
        }
        break;
      }
      ++context.cursor;
    }
    if(thisAny.has_value() && isNegative){
      thisAny = -std::any_cast<int64_t>(thisAny);
    }
  }*/
}

static void nanNumber(std::any& thisAny, ParserContext& context, int8_t sign){
  DoubleUnion data;
  data.part.sign = sign;
  data.part.exponent = 0x7ff;
  data.part.mantissa = 1;
  if(Util::matchString(context.cursor, context.end, ":0x")){
    data.part.mantissa = 0;
    if((*context.cursor) != '_'){
      while (context.cursor != context.end){
        if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
          data.part.mantissa = (data.part.mantissa << 4) + (*context.cursor) - '0';
        }else if((*context.cursor) >= 'a' && (*context.cursor) <= 'f'){
          data.part.mantissa = (data.part.mantissa << 4) + (*context.cursor) - 'a' + 10;
        }else if((*context.cursor) >= 'A' && (*context.cursor) <= 'F'){
          data.part.mantissa = (data.part.mantissa << 4) + (*context.cursor) - 'A' + 10;
        }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || (
          (context.cursor[1] < '0' || context.cursor[1] > '9') &&
          (context.cursor[1] < 'a' || context.cursor[1] > 'f') &&
          (context.cursor[1] < 'A' || context.cursor[1] > 'F'))
        ){
          if((*context.cursor) == '_'){
            return;
          }
        }
        ++context.cursor;
      }
      thisAny = data.value;
    }
  }else{
    thisAny = data.value;
  }
}

static void infNumber(std::any& thisAny, ParserContext& context, int8_t sign){
  DoubleUnion data;
  data.part.sign = sign;
  data.part.exponent = 0x7ff;
  data.part.mantissa = 0;
  thisAny = data.value;
}

FloatLiteral::FloatLiteral(ParserContext& parent_context){
  ParserContext context = parent_context;
  int8_t sign = signBit(context);
  if((*context.cursor) != '_'){
    int diff = context.end - context.cursor;
    if(Util::matchString(context.cursor, context.end, "nan")){
      context.cursor += 3;
      nanNumber(*this, context, sign);
    }else if(Util::matchString(context.cursor, context.end, "inf")){
      context.cursor += 3;
      infNumber(*this, context, sign);
    }else if((*context.cursor) == '0' && (context.cursor + 1 != context.end) && context.cursor[1] == 'x'){
      context.cursor += 2;
      hexNumber(*this, context, sign);
    }else{
      decimalNumber(*this, context, sign);
    }
    if(has_value()){
      parent_context.cursor = context.cursor;
    }
  }
}
#include <parser/FloatLiteral.hpp>

#include <cstdint>
#include <cmath>
#include <limits>
#include <string>
#include <Error.hpp>
#include <Util.hpp>

static bool isNegative(ParserContext& context){
  if((*context.cursor) == '-' || (*context.cursor) == '+'){
    return (*(context.cursor++)) == '-';
  }
  return false;
}

static void decimalNumber(std::any& thisAny, ParserContext& context, bool negative){
  double value = 0;
  // Integer part
  while(context.cursor != context.end){
    if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
      value = value * 10 + (*context.cursor) - '0';
    }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || context.cursor[1] < '0' || context.cursor[1] > '9'){
      if((*context.cursor) == '_'){
        return;
      }
      break;
    }
    ++context.cursor;
  }
  // Decimal point
  if((*context.cursor) != '.'){
    thisAny = (negative) ? -value : value;
    return;
  }else{
    ++context.cursor;
  }
  // fragment part
  if((*context.cursor) != '_'){
    for(double exp = -1; context.cursor != context.end;){
      if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
        value += pow(10, exp) * ((*context.cursor) - '0');
        --exp;
      }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || context.cursor[1] < '0' || context.cursor[1] > '9'){
        if((*context.cursor) == '_'){
          return;
        }
        break;
      }
      ++context.cursor;
    }
  }else{
    return;
  }
  // Expoment part
  if((*context.cursor) == 'E' || (*context.cursor) == 'e'){
    ++context.cursor;
    bool exponent_negative = isNegative(context);
    double exponent = 0;
    if((*context.cursor) != '_'){
      while(context.cursor != context.end){
        if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
          exponent = exponent * 10 + (*context.cursor) - '0';
        }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || context.cursor[1] < '0' || context.cursor[1] > '9'){
          if((*context.cursor) == '_'){
            return;
          }
          break;
        }
        ++context.cursor;
      }
      exponent = (exponent_negative) ? -exponent : exponent;
      value *= pow(10, exponent);
      thisAny = (negative) ? -value : value;
    }else{
      return;
    }
  }else{
    thisAny = (negative) ? -value : value;
  }
}

static void hexNumber(std::any& thisAny, ParserContext& context, bool negative){
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

static void nanNumber(std::any& thisAny, ParserContext& context, bool negative){
  if(Util::matchString(context.cursor, context.end, ":0x")){
    context.cursor += 3;
    std::string mantissa("0x");
    if((*context.cursor) != '_'){
      while (context.cursor != context.end){
        if(((*context.cursor) >= '0' && (*context.cursor) <= '9') ||
           ((*context.cursor) >= 'a' && (*context.cursor) <= 'f') ||
           ((*context.cursor) >= 'A' && (*context.cursor) <= 'F')
        ){
          mantissa += (*context.cursor);
        }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || (
          (context.cursor[1] < '0' || context.cursor[1] > '9') &&
          (context.cursor[1] < 'a' || context.cursor[1] > 'f') &&
          (context.cursor[1] < 'A' || context.cursor[1] > 'F'))
        ){
          if((*context.cursor) == '_'){
            return;
          }
          break;
        }
        ++context.cursor;
      }
      thisAny = (negative) ? -std::nan(mantissa.c_str()) : std::nan(mantissa.c_str());
    }
  }else{
    thisAny = (negative) ? -std::nan("") : std::nan("");
  }
}

static void infNumber(std::any& thisAny, ParserContext& context, bool negative){
  thisAny = (negative) ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
}

FloatLiteral::FloatLiteral(ParserContext& parent_context){
  ParserContext context = parent_context;
  bool negative = isNegative(context);
  if((*context.cursor) != '_'){
    int diff = context.end - context.cursor;
    if(Util::matchString(context.cursor, context.end, "nan")){
      context.cursor += 3;
      nanNumber(*this, context, negative);
    }else if(Util::matchString(context.cursor, context.end, "inf")){
      context.cursor += 3;
      infNumber(*this, context, negative);
    }else if((*context.cursor) == '0' && (context.cursor + 1 != context.end) && context.cursor[1] == 'x'){
      context.cursor += 2;
      hexNumber(*this, context, negative);
    }else{
      decimalNumber(*this, context, negative);
    }
    if(has_value()){
      parent_context.cursor = context.cursor;
    }
  }
}
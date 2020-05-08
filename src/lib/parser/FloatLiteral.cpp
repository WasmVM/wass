#include <parser/FloatLiteral.hpp>

#include <optional>
#include <cstdint>
#include <cmath>
#include <limits>
#include <string>
#include <Error.hpp>
#include <Util.hpp>

using Double = std::optional<double>;

static bool isNegative(ParserContext& context){
  if((*context.cursor) == '-' || (*context.cursor) == '+'){
    return (*(context.cursor++)) == '-';
  }
  return false;
}

static Double decimalNumber(ParserContext& context, bool negative){
  double value = 0;
  // Integer part
  while(context.cursor != context.end){
    if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
      value = value * 10 + (*context.cursor) - '0';
    }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || context.cursor[1] < '0' || context.cursor[1] > '9'){
      if((*context.cursor) == '_'){
        return Double();
      }
      break;
    }
    ++context.cursor;
  }
  // Point
  if((*context.cursor) != '.'){
    return Double((negative) ? -value : value);
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
          return Double();
        }
        break;
      }
      ++context.cursor;
    }
  }else{
    return Double();
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
            return Double();
          }
          break;
        }
        ++context.cursor;
      }
      exponent = (exponent_negative) ? -exponent : exponent;
      value *= pow(10, exponent);
      return Double((negative) ? -value : value);
    }else{
      return Double();
    }
  }else{
    return Double((negative) ? -value : value);
  }
}

static Double hexNumber(ParserContext& context, bool negative){
  double value = 0;
  // Integer part
  if((*context.cursor) != '_'){
    while(context.cursor != context.end){
      if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
        value = value * 16 + (*context.cursor) - '0';
      }else if((*context.cursor) >= 'a' && (*context.cursor) <= 'f'){
        value = value * 16 + (*context.cursor) - 'a' + 10;
      }else if((*context.cursor) >= 'A' && (*context.cursor) <= 'F'){
        value = value * 16 + (*context.cursor) - 'A' + 10;
      }else if(
        (*context.cursor) != '_' ||
        context.cursor + 1 == context.end || (
          (context.cursor[1] < '0' ||  context.cursor[1] > '9') &&
          (context.cursor[1] < 'a' ||  context.cursor[1] > 'f') &&
          (context.cursor[1] < 'A' ||  context.cursor[1] > 'F')
        )
      ){
        if((*context.cursor) == '_'){
          return Double();
        }
        break;
      }
      ++context.cursor;
    }
  }else{
    return Double();
  }
  // Point
  if((*context.cursor) != '.'){
    return Double((negative) ? -value : value);
  }else{
    ++context.cursor;
  }
  // fragment part
  if((*context.cursor) != '_'){
    for(double exp = -1; context.cursor != context.end;){
      if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
        value += pow(16, exp) * ((*context.cursor) - '0');
        --exp;
      }else if((*context.cursor) >= 'a' && (*context.cursor) <= 'f'){
        value += pow(16, exp) * ((*context.cursor) - 'a' + 10);
        --exp;
      }else if((*context.cursor) >= 'A' && (*context.cursor) <= 'F'){
        value += pow(16, exp) * ((*context.cursor) - 'A' + 10);
        --exp;
      }else if(
        (*context.cursor) != '_' ||
        context.cursor + 1 == context.end || (
          (context.cursor[1] < '0' ||  context.cursor[1] > '9') &&
          (context.cursor[1] < 'a' ||  context.cursor[1] > 'f') &&
          (context.cursor[1] < 'A' ||  context.cursor[1] > 'F')
        )
      ){
        if((*context.cursor) == '_'){
          return Double();
        }
        break;
      }
      ++context.cursor;
    }
  }else{
    return Double();
  }
  // Expoment part
  if((*context.cursor) == 'P' || (*context.cursor) == 'p'){
    ++context.cursor;
    bool exponent_negative = isNegative(context);
    double exponent = 0;
    if((*context.cursor) != '_'){
      while(context.cursor != context.end){
        if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
          exponent = exponent * 10 + (*context.cursor) - '0';
        }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || context.cursor[1] < '0' || context.cursor[1] > '9'){
          if((*context.cursor) == '_'){
            return Double();
          }
          break;
        }
        ++context.cursor;
      }
      exponent = (exponent_negative) ? -exponent : exponent;
      value *= pow(16, exponent);
      return Double((negative) ? -value : value);
    }else{
      return Double();
    }
  }else{
    return Double((negative) ? -value : value);
  }
}

static Double nanNumber(ParserContext& context, bool negative){
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
            return Double();
          }
          break;
        }
        ++context.cursor;
      }
      return Double((negative) ? -std::nan(mantissa.c_str()) : std::nan(mantissa.c_str()));
    }
  }else{
    return Double((negative) ? -std::nan("") : std::nan(""));
  }
}

static Double infNumber(ParserContext& context, bool negative){
  return Double((negative) ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity());
}

FloatLiteral::FloatLiteral(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    bool negative = isNegative(context);
    if((*context.cursor) != '_'){
      int diff = context.end - context.cursor;
      if(Util::matchString(context.cursor, context.end, "nan")){
        context.cursor += 3;
        this->Double::operator=(nanNumber(context, negative));
      }else if(Util::matchString(context.cursor, context.end, "inf")){
        context.cursor += 3;
        this->Double::operator=(infNumber(context, negative));
      }else if((*context.cursor) == '0' && (context.cursor + 1 != context.end) && context.cursor[1] == 'x'){
        context.cursor += 2;
        this->Double::operator=(hexNumber(context, negative));
      }else{
        this->Double::operator=(decimalNumber(context, negative));
      }
      if(has_value()){
        parent_context.cursor = context.cursor;
      }
    }
  }
}
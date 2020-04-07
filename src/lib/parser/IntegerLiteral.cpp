#include <parser/IntegerLiteral.hpp>

#include <cstdint>
#include <Error.hpp>

static bool isNegative(ParserContext& context){
  if((*context.cursor) == '-' || (*context.cursor) == '+'){
    return *(context.cursor++) == '-';
  }
  return false;
}

static void decimalNumber(std::any& thisAny, ParserContext& context, bool& isNegative){
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
  }
}

static void hexNumber(std::any& thisAny, ParserContext& context, bool& isNegative){
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
  }
}

IntegerLiteral::IntegerLiteral(ParserContext& context) : ParserInstance(context){
  bool negative = isNegative(context);
  if((*context.cursor) != '_'){
    if((*context.cursor) == '0' && (context.cursor + 1 != context.end) && context.cursor[1] == 'x'){
      context.cursor += 2;
      hexNumber(*this, context, negative);
    }else{
      decimalNumber(*this, context, negative);
    }
  }
}
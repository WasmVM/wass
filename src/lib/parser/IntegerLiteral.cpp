#include <parser/IntegerLiteral.hpp>

#include <optional>
#include <cstdint>
#include <Error.hpp>

static bool isNegative(ParserContext& context){
  if((*context.cursor) == '-' || (*context.cursor) == '+'){
    return *(context.cursor++) == '-';
  }
  return false;
}

static std::optional<int64_t> decimalNumber(ParserContext& context, bool& isNegative){
  std::optional<int64_t> value;
  while(context.cursor != context.end){
    if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
      if(value.has_value()){
        value = (*value) * 10 + (*context.cursor) - '0';
      }else{
        value = (*context.cursor) - '0';
      }
    }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || context.cursor[1] < '0' || context.cursor[1] > '9'){
      if((*context.cursor) == '_'){
        value.reset();
      }
      break;
    }
    ++context.cursor;
  }
  if(value.has_value() && isNegative){
    value = -(*value);
  }
  return value;
}

static std::optional<int64_t> hexNumber(ParserContext& context, bool& isNegative){
  std::optional<int64_t> value;
  if((*context.cursor) != '_'){
    while (context.cursor != context.end){
      if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
        if(value.has_value()){
          value = (*value << 4) + (*context.cursor) - '0';
        }else{
          value = (int64_t)((*context.cursor) - '0');
        }
      }else if((*context.cursor) >= 'a' && (*context.cursor) <= 'f'){
        if(value.has_value()){
          value = (*value << 4) + (*context.cursor) - 'a' + 10;
        }else{
          value = (int64_t)(((*context.cursor) - 'a' + 10) * (isNegative ? -1 : 1));
        }
      }else if((*context.cursor) >= 'A' && (*context.cursor) <= 'F'){
        if(value.has_value()){
          value = (*value << 4) + (*context.cursor) - 'A' + 10;
        }else{
          value = (int64_t)(((*context.cursor) - 'A' + 10) * (isNegative ? -1 : 1));
        }
      }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || (
        (context.cursor[1] < '0' || context.cursor[1] > '9') &&
        (context.cursor[1] < 'a' || context.cursor[1] > 'f') &&
        (context.cursor[1] < 'A' || context.cursor[1] > 'F'))
      ){
        if((*context.cursor) == '_'){
          value.reset();
        }
        break;
      }
      ++context.cursor;
    }
    if(value.has_value() && isNegative){
      value = -(*value);
    }
  }
  return value;
}

IntegerLiteral::IntegerLiteral(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    bool negative = isNegative(context);
    if((*context.cursor) != '_'){
      if((*context.cursor) == '0' && (context.cursor + 1 != context.end) && context.cursor[1] == 'x'){
        context.cursor += 2;
        this->std::optional<int64_t>::operator=(hexNumber(context, negative));
      }else{
        this->std::optional<int64_t>::operator=(decimalNumber(context, negative));
      }
      if(has_value()){
        parent_context.cursor = context.cursor;
      }
    }
  }
}
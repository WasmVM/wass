#include <parser/StringLiteral.hpp>

#include <string>
#include <cstdint>
#include <Error.hpp>
#include <parser/ParserContext.hpp>

static std::string unicodeHexNumber(ParserContext& context){
  uint32_t value = 0;  
  if((*context.cursor) == '{'){
    ++context.cursor;
    if((*context.cursor) != '_'){
      while (context.cursor != context.end){
        if((*context.cursor) >= '0' && (*context.cursor) <= '9'){
          value = (value << 4) + (*context.cursor) - '0';
        }else if((*context.cursor) >= 'a' && (*context.cursor) <= 'f'){
          value = (value << 4) + (*context.cursor) - 'a' + 10;
        }else if((*context.cursor) >= 'A' && (*context.cursor) <= 'F'){
          value = (value << 4) + (*context.cursor) - 'A' + 10;
        }else if((*context.cursor) != '_' || context.cursor + 1 == context.end || (
          (context.cursor[1] < '0' || context.cursor[1] > '9') &&
          (context.cursor[1] < 'a' || context.cursor[1] > 'f') &&
          (context.cursor[1] < 'A' || context.cursor[1] > 'F'))
        ){
          if((*context.cursor) == '_'){
            throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
          }
          break;
        }
        ++context.cursor;
      }
    }else{
      throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
    }
    if((*context.cursor) == '}' && (
      value < 0xD800 || (value >= 0xE000 && value < 0x110000)
    )){
      std::string result("");
      if(value > 0xFFFF){
        result += (char)((value & 0xFF0000) >> 16);
        value &= 0xFFFF;
      }
      if(value > 0xFF){
        result += (char)((value & 0xFF00) >> 8);
        value &= 0xFF;
      }
      result += (char)(value & 0xff);
      return result;
    }else{
      throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
    }
  }else{
    throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
  }
}

static char hexNumber(ParserContext& context){
  if((context.cursor + 2) != context.end){
    char value = 0;
    for(int i = 0; i < 2; ++i){
      if(context.cursor[i] >= '0' && context.cursor[i] <= '9'){
        value = (value << 4) + context.cursor[i] - '0';
      }else if(context.cursor[i] >= 'a' && context.cursor[i] <= 'f'){
        value = (value << 4) + context.cursor[i] - 'a' + 10;
      }else if(context.cursor[i] >= 'A' && context.cursor[i] <= 'F'){
        value = (value << 4) + context.cursor[i] - 'A' + 10;
      }else{
        throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
      }
    }
    ++context.cursor;
    return value;
  }else{
    throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
  }
}

StringLiteral::StringLiteral(ParserContext& parent_context){
  ParserContext context = parent_context;
  if((*context.cursor) == '"'){
    ++context.cursor;
    std::string value;
    while(context.cursor != context.end && (*context.cursor) != '"'){
      if((*context.cursor) == '\\'){
        ++context.cursor;
        if(context.cursor != context.end){
          switch(*context.cursor){
            case 't':
              value += "\t";
            break;
            case 'n':
              value += "\n";
            break;
            case 'r':
              value += "\r";
            break;
            case '"':
              value += "\"";
            break;
            case '\'':
              value += "'";
            break;
            case '\\':
              value += "\\";
            break;
            case 'u':
              ++context.cursor;
              value += unicodeHexNumber(context);
            break;
            default:
              value += hexNumber(context);
          }
        }else{
          throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
        }
      }else{
        value += *context.cursor;
      }
      ++context.cursor;
    }
    if((*context.cursor) == '"'){
      this->std::optional<std::string>::operator=(value);
      parent_context.cursor = context.cursor + 1;
    }else{
      throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
    }
  }
}
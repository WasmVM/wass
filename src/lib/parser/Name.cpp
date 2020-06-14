#include <parser/Name.hpp>

#include <optional>
#include <string>
#include <cstdint>
#include <Error.hpp>
#include <parser/ParserContext.hpp>

Name::Name(ParserContext& parent_context) : StringLiteral(parent_context){
  if(has_value()){
    std::string value = **this;
    for(std::string::iterator it = value.begin(); it != value.end(); ++it){
      if((uint8_t)*it > 0x80){
        if((uint8_t)*it < 0xC0 || it + 1 == value.end() || (uint8_t)it[1] < 0x80 || (uint8_t)it[1] >= 0xC0){
          throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
        }
        if((uint8_t)*it >= 0xE0){
          if((it + 2 == value.end() || (uint8_t)it[2] < 0x80 || (uint8_t)it[2] >= 0xC0)){
            throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
          }
        }else{
          // Double
          ++it;
          continue;
        }
        if((uint8_t)*it >= 0xF0){
          if((it + 3 == value.end() || (uint8_t)it[3] < 0x80 || (uint8_t)it[3] >= 0xC0)){
            throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
          }
          // Quadruple
          uint32_t intValue = ((uint32_t)((uint8_t)*it - 0xF0) << 18) + ((uint32_t)((uint8_t)it[1] - 0x80) << 12) + ((uint32_t)((uint8_t)it[2] - 0x80) << 6) + ((uint8_t)it[3] - 0x80);
          if(intValue >= 0x110000){
            throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
          }
          it += 3;
        }else{
          // Triple
          uint16_t intValue = ((uint16_t)((uint8_t)*it - 0xE0) << 12) + ((uint16_t)((uint8_t)it[1] - 0x80) << 6) + ((uint8_t)it[2] - 0x80);
          if(intValue >= 0xD800 && intValue < 0xE000){
            throw Error<ErrorType::ParseError>("invalid UTF-8 encoding");
          }
          it += 2;
        }
      }
    }
  }
}
#include <parser/Identifier.hpp>

#include <string>
#include <Error.hpp>

Identifier::Identifier(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if((*context.cursor) == '$'){
      ++context.cursor;
      bool isBreak = false;
      std::string value;
      while (context.cursor != context.end){
        if(!(
          ((*context.cursor) >= '0' && (*context.cursor) <= '9') ||
          ((*context.cursor) >= 'a' && (*context.cursor) <= 'z') ||
          ((*context.cursor) >= 'A' && (*context.cursor) <= 'Z')
        )){
          switch (*context.cursor){
          case '!':
          case ':':
          case '#':
          case '$':
          case '%':
          case '&':
          case '\'':
          case '*':
          case '+':
          case '-':
          case '.':
          case '/':
          case '<':
          case '=':
          case '>':
          case '?':
          case '@':
          case '\\':
          case '^':
          case '_':
          case '`':
          case '|':
          case '~':
          break;
          default:
            isBreak = true;
            break;
          }
        }
        if(isBreak){
          break;
        }else{
          value += *context.cursor;
          ++context.cursor;
        }
      }
      if(value != ""){
        this->std::any::operator=(value);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("identifier can't be empty");
      }
    }
  }
}
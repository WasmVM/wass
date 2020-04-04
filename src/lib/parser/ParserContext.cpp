#include <parser/ParserContext.hpp>

ParserContext::ParserContext(std::string& data){
  cursor = data.begin();
  end = data.end();
}
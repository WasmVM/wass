#include <parser/ParserContext.hpp>

ParserContext::ParserContext(std::vector<char>& data){
  cursor = data.begin();
  end = data.end();
}
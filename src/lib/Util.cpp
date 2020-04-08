#include <Util.hpp>
 
bool Util::matchString(std::vector<char>::iterator& begin, std::vector<char>::iterator& end, std::string str){
  if(begin - end < str.size()){
    return false;
  }
  std::string::iterator sIt = str.begin();
  for(std::vector<char>::iterator it = begin; it != end && sIt != str.end(); ++it, ++sIt){
    if(*it != *sIt){
      return false;
    }
  }
  return true;
}
#include <Util.hpp>
#include <Error.hpp>
 
bool Util::matchString(std::vector<char>::iterator& begin, std::vector<char>::iterator& end, std::string str){
  if(begin - end < str.size()){
    return false;
  }
  std::string::iterator sIt = str.begin();
  for(std::vector<char>::iterator it = begin; sIt != str.end() && it != end; ++it, ++sIt){
    if(*it != *sIt){
      return false;
    }
  }
  return sIt == str.end();
}

template<> std::vector<char> Util::toLEB128<uint32_t>(uint32_t value){
  std::vector<char> result;
  if(value == 0){
    result.emplace_back(0);
  }else{
    for(int i = 0; (i < 5) && (value != 0); ++i){
      result.emplace_back((value & 0x7F) | 0x80);
      value >>= 7;
    }
    result.back() &= 0x7F;
  }
  return result;
}

template<> std::vector<char> Util::toLEB128<int32_t>(int32_t value){
  std::vector<char> result;
  if(value == 0){
    result.emplace_back(0);
  }else{
    uint32_t mask = (value < 0) ? 0xFFFFFFFF : 0; 
    for(int i = 0; (i < 5) && (((uint32_t)value & mask) != mask); ++i){
      result.emplace_back((value & 0x7F) | 0x80);
      value >>= 7;
      mask >>= 7;
    }
    if(result.size() < 5){
      if(mask == 0 && ((result.back() & 0x40) != 0)){
        result.emplace_back(0);
      }else if(mask != 0 && ((result.back() & 0x40) == 0)){
        result.emplace_back(0x7F);
      }
    }else{
      if(mask == 0){
        result.back() &= 0x0F;
      }else{
        result.back() |= 0x30;
      }
    }
    result.back() &= 0x7F;
  }
  return result;
}

template<> std::vector<char> Util::toLEB128<uint64_t>(uint64_t value){
  std::vector<char> result;
  if(value == 0){
    result.emplace_back(0);
  }else{
    for(int i = 0; (i < 10) && (value != 0); ++i){
      result.emplace_back(value & 0x7F);
      value >>= 7;
    }
    result.back() |= 0x80;
  }
  return result;
}

template<> std::vector<char> Util::toLEB128<int64_t>(int64_t value){
  std::vector<char> result;
  if(value == 0){
    result.emplace_back(0);
  }else{
    uint64_t mask = (value < 0) ? 0xFFFFFFFFFFFFFFFF : 0; 
    for(int i = 0; (i < 10) && (((uint64_t)value & mask) != mask); ++i){
      result.emplace_back((value & 0x7F) | 0x80);
      value >>= 7;
      mask >>= 7;
    }
    if(result.size() < 10){
      if(mask == 0 && ((result.back() & 0x40) != 0)){
        result.emplace_back(0);
      }else if(mask != 0 && ((result.back() & 0x40) == 0)){
        result.emplace_back(0x7F);
      }
    }else{
      if(mask == 0){
        result.back() &= 0x01;
      }else{
        result.back() |= 0x3E;
      }
    }
    result.back() &= 0x7F;
  }
  return result;
}

template<typename T> std::vector<char> Util::toLEB128(T){
  throw Error<ErrorType::GenerateError>("this type cannot convert to LEB128");
}
#include <Util.hpp>
#include <Error.hpp>
#include <cstdint>

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

template<> BinaryCode Util::toLEB128<uint32_t>(uint32_t value){
  if(value == 0){
    return BinaryCode({'\x00'});
  }else{
    BinaryCode result;
    for(int i = 0; (i < 5) && (value != 0); ++i){
      result += (char)((value & 0x7F) | 0x80);
      value >>= 7;
    }
    result.back() &= 0x7F;
    return result;
  }
}

template<> BinaryCode Util::toLEB128<int32_t>(int32_t value){
  if(value == 0){
    return BinaryCode({'\x00'});
  }else{
    BinaryCode result;
    bool isPositive = (value > 0);
    // Count significant bits
    uint32_t absolute = value ^ ((value > 0) ? 0 : 0xFFFFFFFF);
    int8_t num = 0;
    if (absolute >= 0x0000FFFF) { num += 16; absolute >>= 16; }
    if (absolute >= 0x000000FF) { num += 8; absolute >>= 8; }
    if (absolute >= 0x0000000F) { num += 4; absolute >>= 4; }
    if (absolute >= 0x00000003) { num += 2; absolute >>= 2; }
    num += absolute;
    // Encode
    for(int i = (num / 7) + 1; i > 0; --i){
      result += (char)((value & 0x7F) | 0x80);
      value >>= 7;
    }
    // Sign extend
    uint8_t mask = 0x7F - ((1 << (num % 7)) - 1);
    if(isPositive){
      result.back() &= ~mask;
    }else{
      result.back() |= mask;
    }
    result.back() &= 0x7F;
    return result;
  }
}

template<> BinaryCode Util::toLEB128<uint64_t>(uint64_t value){
  if(value == 0){
    return BinaryCode({'\x00'});
  }else{
    BinaryCode result;
    for(int i = 0; (i < 10) && (value != 0); ++i){
      result += (char)((value & 0x7F) | 0x80);
      value >>= 7;
    }
    result.back() &= 0x7F;
    return result;
  }
}

template<> BinaryCode Util::toLEB128<int64_t>(int64_t value){
  if(value == 0){
    return BinaryCode({'\x00'});
  }else{
    BinaryCode result;
    bool isPositive = (value > 0);
    // Count significant bits
    uint64_t absolute = value ^ ((value > 0) ? 0 : 0xFFFFFFFFFFFFFFFF);
    int8_t num = 0;
    if (absolute >= 0x00000000FFFFFFFF) { num += 32; absolute >>= 32; }
    if (absolute >= 0x000000000000FFFF) { num += 16; absolute >>= 16; }
    if (absolute >= 0x00000000000000FF) { num += 8; absolute >>= 8; }
    if (absolute >= 0x000000000000000F) { num += 4; absolute >>= 4; }
    if (absolute >= 0x0000000000000003) { num += 2; absolute >>= 2; }
    num += absolute;
    // Encode
    for(int i = (num / 7) + 1; i > 0; --i){
      result += (char)((value & 0x7F) | 0x80);
      value >>= 7;
    }
    // Sign extend
    uint8_t mask = 0x7F - ((1 << (num % 7)) - 1);
    if(isPositive){
      result.back() &= ~mask;
    }else{
      result.back() |= mask;
    }
    result.back() &= 0x7F;
    return result;
  }
}

template<typename T> BinaryCode Util::toLEB128(T){
  throw Error<ErrorType::GenerateError>("this type cannot convert to LEB128");
}
#include <BinaryCode.hpp>

#include <cstring>

BinaryCode::BinaryCode(std::initializer_list<char> list):std::vector<char>(list){
}

BinaryCode& BinaryCode::operator+=(const BinaryCode& rhs){
  resize(size() + rhs.size());
  memcpy(data() + size() - rhs.size(), rhs.data(), sizeof(char) * rhs.size());
  return *this;
}

BinaryCode& BinaryCode::operator+=(const char& rhs){
  emplace_back(rhs);
  return *this;
}

BinaryCode operator+(BinaryCode lhs,const BinaryCode& rhs){
  lhs.resize(lhs.size() + rhs.size());
  memcpy(lhs.data() + lhs.size() - rhs.size(), rhs.data(), sizeof(char) * rhs.size());
  return lhs;
}

bool operator==(const BinaryCode& lhs, const BinaryCode& rhs){
  if(lhs.size() != rhs.size()){
    return false;
  }
  for(size_t i = 0; i < lhs.size(); ++i){
    if(lhs[i] != rhs[i]){
      return false;
    }
  }
  return true;
}
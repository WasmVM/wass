#ifndef GUARD_wass_BinaryCode
#define GUARD_wass_BinaryCode

#include <vector>
#include <initializer_list>

class BinaryCode: public std::vector<char>{
public:
  BinaryCode() = default;
  BinaryCode(std::initializer_list<char>);
  BinaryCode& operator+=(const BinaryCode&);
  BinaryCode& operator+=(const char&);
  friend BinaryCode operator+(BinaryCode, const BinaryCode&);
  friend bool operator==(const BinaryCode&, const BinaryCode&);
};

#endif
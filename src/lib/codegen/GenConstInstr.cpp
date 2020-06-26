#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/ConstInstr.hpp>
#include <Util.hpp>

union FloatIntUnion{
  float f;
  uint8_t i[4];
};

BinaryCode CodeGenVisitor::operator()(I32ConstInstr&& target){
  return BinaryCode({'\x41'}) + Util::toLEB128(target.value);
}
BinaryCode CodeGenVisitor::operator()(I64ConstInstr&& target){
  return BinaryCode({'\x42'}) + Util::toLEB128(target.value);
}
BinaryCode CodeGenVisitor::operator()(F32ConstInstr&& target){
  static bool isLittleEndian = (FloatIntUnion({.f = 128.5f}).i[1] == 128);
  FloatIntUnion converter = {.f = target.value};
  if(isLittleEndian){
    return BinaryCode({'\x43', (char)converter.i[0], (char)converter.i[1], (char)converter.i[2], (char)converter.i[3]});
  }else{
    return BinaryCode({'\x43', (char)converter.i[3], (char)converter.i[2], (char)converter.i[1], (char)converter.i[0]});
  }
}

BinaryCode CodeGenVisitor::operator()(F64ConstInstr&& target){
  static bool isLittleEndian = (FloatIntUnion({.f = 128.5f}).i[1] == 128);
  union {
    double d;
    uint8_t i[8];
  } converter = {.d = target.value};
  if(isLittleEndian){
    return BinaryCode({'\x44',
      (char)converter.i[0], (char)converter.i[1], (char)converter.i[2], (char)converter.i[3],
      (char)converter.i[4], (char)converter.i[5], (char)converter.i[6], (char)converter.i[7]
    });
  }else{
    return BinaryCode({'\x44',
      (char)converter.i[7], (char)converter.i[6], (char)converter.i[5], (char)converter.i[4],
      (char)converter.i[3], (char)converter.i[2], (char)converter.i[1], (char)converter.i[0]
    });
  }
}
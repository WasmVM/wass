#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <vector>
#include <structure/ValueType.hpp>

BinaryCode CodeGenVisitor::operator()(ValueType&& target){
  switch(target){
    case ValueType::i32:
      return BinaryCode({0x7F});
      break;
    case ValueType::i64:
      return BinaryCode({0x7E});
      break;
    case ValueType::f32:
      return BinaryCode({0x7D});
      break;
    case ValueType::f64:
      return BinaryCode({0x7C});
      break;
    default:
      return BinaryCode();
      break;
  }
}
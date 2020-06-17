#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Limit.hpp>
#include <Error.hpp>
#include <Util.hpp>

BinaryCode CodeGenVisitor::operator()(Limit&& target){
  BinaryCode result;
  if(target.max.has_value()){
    result += '\x01';
    result += Util::toLEB128(target.min) + Util::toLEB128(*(target.max));
  }else{
    result += '\x00';
    result += Util::toLEB128(target.min);
  }
  return result;
}
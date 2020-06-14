#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <vector>
#include <structure/FuncType.hpp>
#include <Util.hpp>

BinaryCode CodeGenVisitor::operator()(FuncType&& target){
  BinaryCode result {0x60};
  result += Util::toLEB128<uint32_t>(target.params.size());
  for(ValueType type : target.params){
    result += std::visit<BinaryCode>(*this, CodeGenVariant(type));
  }
  result += Util::toLEB128<uint32_t>(target.results.size());
  for(ValueType type : target.results){
    result += std::visit<BinaryCode>(*this, CodeGenVariant(type));
  }
  return result;
}
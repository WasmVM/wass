#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <vector>
#include <utility>
#include <structure/FuncType.hpp>
#include <Util.hpp>
#include <Error.hpp>

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
  context.typeDescs.emplace_back(target);
  for(std::pair<std::string, uint32_t> pair : target.paramMap){
    context.identifierMap[pair.first] = pair.second;
  }
  return result;
}
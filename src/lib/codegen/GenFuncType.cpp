#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <vector>
#include <structure/FuncType.hpp>
#include <Util.hpp>

std::vector<char> CodeGenVisitor::operator()(FuncType&& target){
  std::vector<char> result {0x60};
  for(char c : Util::toLEB128<uint32_t>(target.params.size())){
    result.emplace_back(c);
  }
  for(ValueType type : target.params){
    result.push_back(std::visit<std::vector<char>>(*this, CodeGenVariant(type))[0]);
  }
  for(char c : Util::toLEB128<uint32_t>(target.results.size())){
    result.emplace_back(c);
  }
  for(ValueType type : target.results){
    result.push_back(std::visit<std::vector<char>>(*this, CodeGenVariant(type))[0]);
  }
  return result;
}
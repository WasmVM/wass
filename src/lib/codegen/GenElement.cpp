#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Element.hpp>
#include <Util.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Element&& target){
  BinaryCode result = std::visit<BinaryCode>(*this, CodeGenVariant(target.tableIndex));
  result += std::visit<BinaryCode>(*this, ConstExprVariant(target.expr));
  result += Util::toLEB128((uint32_t) target.funcIndices.size());
  for(std::vector<Index>::iterator it = target.funcIndices.begin(); it != target.funcIndices.end(); ++it){
    result += std::visit<BinaryCode>(*this, CodeGenVariant(*it));
  }
  return result;
}
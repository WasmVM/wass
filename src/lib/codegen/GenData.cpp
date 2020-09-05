#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Data.hpp>
#include <Error.hpp>
#include <Util.hpp>

BinaryCode CodeGenVisitor::operator()(Data&& target){
  BinaryCode result;
  result += std::visit<BinaryCode>(*this, CodeGenVariant(target.memIndex));
  result += std::visit<BinaryCode>(*this, ConstExprVariant(target.expr));
  result += '\x0B';
  result += Util::toLEB128((uint32_t)target.data.size());
  result += target.data;
  return result;
}
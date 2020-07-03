#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/VariableInstr.hpp>
#include <Util.hpp>

BinaryCode CodeGenVisitor::operator()(GlobalGetInstr&& target){
  return BinaryCode({'\x23'}) + std::visit<BinaryCode>(*this, CodeGenVariant(target.index));
}

#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/GlobalType.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(GlobalType&& target){
  return std::visit<BinaryCode>(*this, CodeGenVariant(target.type)) + (target.immutable ? '\x00' : '\x01');
}
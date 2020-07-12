#include <codegen/CodeGenVisitor.hpp>

#include <structure/ParamInstr.hpp>

BinaryCode CodeGenVisitor::operator()(DropInstr&&){
  return BinaryCode({'\x1A'});
}
BinaryCode CodeGenVisitor::operator()(SelectInstr&&){
  return BinaryCode({'\x1B'});
}
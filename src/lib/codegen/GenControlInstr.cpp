#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/ControlInstr.hpp>
#include <Util.hpp>

// TODO:
BinaryCode CodeGenVisitor::operator()(UnreachableInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(NopInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(ReturnInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(BrInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(BrIfInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(BrTableInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(CallInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(CallIndirectInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(BlockInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(LoopInstr&&){
  return BinaryCode();
}
BinaryCode CodeGenVisitor::operator()(IfInstr&&){
  return BinaryCode();
}

#include <codegen/CodeGenVisitor.hpp>

CodeGenVisitor::CodeGenVisitor(){
  context.funcCount = 0;
  context.globalCount = 0;
  context.memCount = 0;
  context.tableCount = 0;
}

BinaryCode CodeGenVisitor::operator()(std::monostate&&){
  return BinaryCode();
}
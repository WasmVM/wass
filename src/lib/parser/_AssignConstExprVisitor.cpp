#include "_AssignConstExprVisitor.hpp"

AssignExprVisitor::AssignExprVisitor(ConstExprVariant& expr):expr(expr){};
void AssignExprVisitor::operator()(I32ConstInstr arg){
  expr.emplace<I32ConstInstr>(arg);
}
void AssignExprVisitor::operator()(I64ConstInstr arg){
  expr.emplace<I64ConstInstr>(arg);
}
void AssignExprVisitor::operator()(F32ConstInstr arg){
  expr.emplace<F32ConstInstr>(arg);
}
void AssignExprVisitor::operator()(F64ConstInstr arg){
  expr.emplace<F64ConstInstr>(arg);
}
void AssignExprVisitor::operator()(GlobalGetInstr arg){
  expr.emplace<GlobalGetInstr>(arg);
}
void AssignExprVisitor::operator()(std::monostate){
  expr.emplace<std::monostate>();
}
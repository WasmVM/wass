#include <codegen/CodeGenVisitor.hpp>

#include <string>

std::vector<char> CodeGenVisitor::operator()(Module&& target){
  std::vector<char> result{
    '\x00','\x61','\x73','\x6D', // Magic
    '\x01','\x00','\x00','\x00', // Version
  };
  return result;
}
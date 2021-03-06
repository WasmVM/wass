#include "Helper.hpp"

#include <cstring>

std::vector<char> create_char_vector(const char* data, size_t size){
  std::vector<char> result(size);
  std::memcpy(result.data(), data, size);
  return result;
}

std::vector<char> create_char_vector(const char* data){
  return create_char_vector(data, strlen(data));
}

CodeGenVisitor::Context& Mock_CodeGenVisitor::getContext(){
  return context;
}

CodeGenVisitor::Sections& Mock_CodeGenVisitor::getSections(){
  return sections;
}

Mock_SectionGenerator::Mock_SectionGenerator(const SectionGenerator& origin):SectionGenerator(origin){
}

std::vector<BinaryCode>& Mock_SectionGenerator::getCodes(){
  return codes;
}
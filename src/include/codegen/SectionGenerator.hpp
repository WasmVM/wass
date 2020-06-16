#ifndef GUARD_wass_codegen_SectionGenerator
#define GUARD_wass_codegen_SectionGenerator

#include <cstdint>
#include <vector>
#include <BinaryCode.hpp>
#include <codegen/CodeGenVisitor.hpp>

class SectionGenerator{
public:
  template<typename T>
  void generate(CodeGenVisitor& visitor, std::vector<T>& targets);
  BinaryCode wrap(uint8_t SectionNum);
private:
  std::vector<BinaryCode> codes;
};

#endif
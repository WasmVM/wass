#ifndef GUARD_wass_codegen_SectionGenerator
#define GUARD_wass_codegen_SectionGenerator

#include <cstdint>
#include <vector>
#include <BinaryCode.hpp>
#include <codegen/CodeGenVisitor.hpp>

class SectionGenerator{
public:
  SectionGenerator() = default;
  SectionGenerator(const SectionGenerator&) = default;

  template<typename T>
  void generate(CodeGenVisitor& visitor, std::vector<T>& targets);
  template<typename T>
  void generate(CodeGenVisitor& visitor, T& target);

  BinaryCode wrap(uint8_t SectionNum);

protected:
  std::vector<BinaryCode> codes;
};

#endif
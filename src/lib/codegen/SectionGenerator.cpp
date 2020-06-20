#include <codegen/SectionGenerator.hpp>

#include <variant>
#include <structure/Type.hpp>
#include <structure/Import.hpp>
#include <Util.hpp>

template<typename T>
void SectionGenerator::generate(CodeGenVisitor& visitor, std::vector<T>& targets){
  for(T& target : targets){
    generate<T>(visitor, target);
  }
}
template void SectionGenerator::generate<Type>(CodeGenVisitor&, std::vector<Type>&);
template void SectionGenerator::generate<Import>(CodeGenVisitor&, std::vector<Import>&);

template<typename T>
void SectionGenerator::generate(CodeGenVisitor& visitor, T& target){
  codes.push_back(std::visit<BinaryCode>(visitor, CodeGenVariant(target)));
}
template void SectionGenerator::generate<Type>(CodeGenVisitor&, Type&);
template void SectionGenerator::generate<Import>(CodeGenVisitor&, Import&);

BinaryCode SectionGenerator::wrap(uint8_t SectionNum){
  BinaryCode result;
  result += Util::toLEB128((uint32_t)codes.size());
  for(BinaryCode& code : codes){
    result += code;
  }
  return BinaryCode({(char)SectionNum}) + Util::toLEB128((uint32_t)result.size()) + result;
}
#include <codegen/SectionGenerator.hpp>

#include <variant>
#include <structure/Type.hpp>
#include <Util.hpp>

template<typename T>
void SectionGenerator::generate(CodeGenVisitor& visitor, std::vector<T>& targets){
  for(T& target : targets){
    codes.push_back(std::visit<BinaryCode>(visitor, CodeGenVariant(target)));
  }
}
template void SectionGenerator::generate<Type>(CodeGenVisitor&, std::vector<Type>&);

BinaryCode SectionGenerator::wrap(uint8_t SectionNum){
  BinaryCode result;
  result += Util::toLEB128((uint32_t)codes.size());
  for(BinaryCode& code : codes){
    result += code;
  }
  return BinaryCode({(char)SectionNum}) + Util::toLEB128((uint32_t)result.size()) + result;
}
#include <codegen/SectionGenerator.hpp>

#include <variant>
#include <structure/Type.hpp>
#include <structure/Import.hpp>
#include <structure/Function.hpp>
#include <structure/Table.hpp>
#include <structure/Memory.hpp>
#include <structure/Global.hpp>
#include <structure/Export.hpp>
#include <structure/Element.hpp>
#include <structure/Data.hpp>

#include <Util.hpp>

template<typename T>
void SectionGenerator::generate(CodeGenVisitor& visitor, std::vector<T>& targets){
  for(T& target : targets){
    generate<T>(visitor, target);
  }
}
template void SectionGenerator::generate<Type>(CodeGenVisitor&, std::vector<Type>&);
template void SectionGenerator::generate<Import>(CodeGenVisitor&, std::vector<Import>&);
template void SectionGenerator::generate<Function>(CodeGenVisitor&, std::vector<Function>&);
template void SectionGenerator::generate<Table>(CodeGenVisitor&, std::vector<Table>&);
template void SectionGenerator::generate<Memory>(CodeGenVisitor&, std::vector<Memory>&);
template void SectionGenerator::generate<Global>(CodeGenVisitor&, std::vector<Global>&);
template void SectionGenerator::generate<Export>(CodeGenVisitor&, std::vector<Export>&);
template void SectionGenerator::generate<Element>(CodeGenVisitor&, std::vector<Element>&);
template void SectionGenerator::generate<Data>(CodeGenVisitor&, std::vector<Data>&);

template<typename T>
void SectionGenerator::generate(CodeGenVisitor& visitor, T& target){
  BinaryCode code = std::visit<BinaryCode>(visitor, CodeGenVariant(target));
  if(code.size() > 0){
    codes.push_back(code);
  }
}
template void SectionGenerator::generate<Type>(CodeGenVisitor&, Type&);
template void SectionGenerator::generate<Import>(CodeGenVisitor&, Import&);
template void SectionGenerator::generate<Function>(CodeGenVisitor&, Function&);
template void SectionGenerator::generate<Table>(CodeGenVisitor&, Table&);
template void SectionGenerator::generate<Memory>(CodeGenVisitor&, Memory&);
template void SectionGenerator::generate<Global>(CodeGenVisitor&, Global&);
template void SectionGenerator::generate<Export>(CodeGenVisitor&, Export&);
template void SectionGenerator::generate<Element>(CodeGenVisitor&, Element&);
template void SectionGenerator::generate<Function::Content>(CodeGenVisitor&, Function::Content&);
template void SectionGenerator::generate<Data>(CodeGenVisitor&, Data&);

BinaryCode SectionGenerator::wrap(uint8_t SectionNum){
  BinaryCode result;
  result += Util::toLEB128((uint32_t)codes.size());
  for(BinaryCode& code : codes){
    result += code;
  }
  return BinaryCode({(char)SectionNum}) + Util::toLEB128((uint32_t)result.size()) + result;
}
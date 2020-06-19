#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <optional>
#include <vector>
#include <cstdint>
#include <structure/Type.hpp>
#include <structure/Function.hpp>
#include <codegen/SectionGenerator.hpp>
#include <Util.hpp>
#include <BinaryCode.hpp>

BinaryCode CodeGenVisitor::operator()(Module&& target){
  BinaryCode result({
    '\x00','\x61','\x73','\x6D', // Magic
    '\x01','\x00','\x00','\x00', // Version
  });
  // TODO: Module id is omitted now, but maybe we can performed in a custom section
  
  // Type section
  std::optional<SectionGenerator> typeSection;
  if(target.types.size() > 0){
    typeSection.emplace(SectionGenerator());
    typeSection->generate(*this, target.types);
  }
  // Import section
  std::optional<SectionGenerator> importSection;
  if(target.imports.size() > 0){
    importSection.emplace(SectionGenerator());
    importSection->generate(*this, target.imports);
  }
  // Func section
  std::optional<BinaryCode> funcSection;
  if(target.funcs.size() > 0){
    BinaryCode& codes = funcSection.emplace(BinaryCode(Util::toLEB128((uint32_t)target.funcs.size())));
    for(Function& func : target.funcs){
      codes += std::visit<BinaryCode>(*this, CodeGenVariant(func.typeUse));
    }
  }

  // Wrap sections
  if(typeSection.has_value()){
    result += typeSection->wrap(1);
  }
  if(importSection.has_value()){
    result += importSection->wrap(2);
  }
  if(funcSection.has_value()){
    result += '\x03';
    result += Util::toLEB128((uint32_t)funcSection->size()) + *funcSection;
  }
  return result;
}
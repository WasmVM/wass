#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <optional>
#include <vector>
#include <cstdint>
#include <structure/Type.hpp>
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

  // Wrap sections
  if(typeSection.has_value()){
    result += typeSection->wrap(1);
  }
  return result;
}
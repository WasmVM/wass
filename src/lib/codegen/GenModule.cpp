#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <optional>
#include <vector>
#include <cstdint>
#include <structure/Type.hpp>
#include <structure/Function.hpp>
#include <Util.hpp>
#include <Error.hpp>
#include <BinaryCode.hpp>
#include <codegen/SectionGenerator.hpp>

BinaryCode CodeGenVisitor::operator()(Module&& target){
  BinaryCode result({
    '\x00','\x61','\x73','\x6D', // Magic
    '\x01','\x00','\x00','\x00', // Version
  });
  // TODO: Module id is omitted now, but maybe we can performed in a custom section
  
  // Type section
  if(target.types.size() > 0){
    sections.type.emplace<SectionGenerator>().generate(*this, target.types);
  }
  // Import section
  if(target.imports.size() > 0){
    sections.import.emplace<SectionGenerator>().generate(*this, target.imports);
  }
  // Func section
  if(target.funcs.size() > 0){
    sections.func.emplace<SectionGenerator>().generate(*this, target.funcs);
  }
  // Table section
  if(target.tables.size() > 0){
    sections.table.emplace<SectionGenerator>().generate(*this, target.tables);
  }

  // Wrap sections
  if(sections.type.has_value()){
    result += std::any_cast<SectionGenerator>(sections.type).wrap(1);
  }
  if(sections.import.has_value()){
    result += std::any_cast<SectionGenerator>(sections.import).wrap(2);
  }
  if(sections.func.has_value()){
    result += std::any_cast<SectionGenerator>(sections.func).wrap(3);
  }
  if(sections.table.has_value()){
    result += std::any_cast<SectionGenerator>(sections.table).wrap(4);
  }
  return result;
}
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
  // Memory section
  if(target.memories.size() > 0){
    sections.memory.emplace<SectionGenerator>().generate(*this, target.memories);
  }
  // Global section
  if(target.globals.size() > 0){
    sections.global.emplace<SectionGenerator>().generate(*this, target.globals);
  }
  // Export section
  if(target.exports.size() > 0){
    if(!sections.exports.has_value()){
      sections.exports.emplace<SectionGenerator>().generate(*this, target.exports);
    }else{
      std::any_cast<SectionGenerator>(&(sections.exports))->generate(*this, target.exports);
    }
  }
  // Element section
  if(target.elems.size() > 0){
    sections.elem.emplace<SectionGenerator>().generate(*this, target.elems);
  }
  // Code section
  if(target.funcs.size() > 0){
    SectionGenerator& section = sections.code.emplace<SectionGenerator>();
    for(auto it = target.funcs.begin(); it != target.funcs.end(); ++it){
      section.generate(*this, it->content);
    }
  }
  // Data section
  if(target.datas.size() > 0){
    if(!sections.data.has_value()){
      sections.data.emplace<SectionGenerator>().generate(*this, target.datas);
    }else{
      std::any_cast<SectionGenerator>(&(sections.data))->generate(*this, target.datas);
    }
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
  if(sections.memory.has_value()){
    result += std::any_cast<SectionGenerator>(sections.memory).wrap(5);
  }
  if(sections.global.has_value()){
    result += std::any_cast<SectionGenerator>(sections.global).wrap(6);
  }
  if(sections.exports.has_value()){
    result += std::any_cast<SectionGenerator>(sections.exports).wrap(7);
  }
  if(target.start.has_value()){
    result += '\x08';
    BinaryCode startCode = std::visit<BinaryCode>(*this, CodeGenVariant(*(target.start)));
    result += Util::toLEB128((uint32_t) startCode.size());
    result += startCode;
  }
  if(sections.elem.has_value()){
    result += std::any_cast<SectionGenerator>(sections.elem).wrap(9);
  }
  if(sections.code.has_value()){
    result += std::any_cast<SectionGenerator>(sections.code).wrap(10);
  }
  if(sections.data.has_value()){
    result += std::any_cast<SectionGenerator>(sections.data).wrap(11);
  }
  return result;
}
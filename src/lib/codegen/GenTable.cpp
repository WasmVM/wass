#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Import.hpp>
#include <structure/Table.hpp>
#include <structure/Element.hpp>
#include <structure/ConstInstr.hpp>
#include <codegen/SectionGenerator.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Table&& target){
  BinaryCode result;
  if(target.elements.size() > 0){
    Element newElem;
    newElem.funcIndices = target.elements;
    I32ConstInstr& expr = newElem.expr.emplace<I32ConstInstr>(I32ConstInstr());
    expr.value = 0;
    newElem.tableIndex = context.tableCount;
    if(!sections.elem.has_value()){
      sections.elem.emplace<SectionGenerator>().generate(*this, newElem);
    }else{
      std::any_cast<SectionGenerator>(&(sections.data))->generate(*this, newElem);
    }
  }
  if(target.exportNames.size() > 0){
    for(std::string name : target.exportNames){
      // Inline export
      Export newExport;
      newExport.index.emplace<uint32_t>(context.tableCount);
      newExport.name = name;
      newExport.type = ExportType::Table;
      if(!sections.exports.has_value()){
        sections.exports.emplace<SectionGenerator>().generate(*this, newExport);
      }else{
        std::any_cast<SectionGenerator>(&(sections.exports))->generate(*this, newExport);
      }
    }
  }
  if(target.importModule.has_value() && target.importName.has_value()){
    // Inline import
    Import newImport;
    newImport.mod = *(target.importModule);
    newImport.name = *(target.importName);
    newImport.type = Import::ImportType::Table;
    newImport.descId = target.id;
    newImport.desc.emplace<Limit>(target.tableType);
    if(!sections.import.has_value()){
      sections.import.emplace<SectionGenerator>().generate(*this, newImport);
    }else{
      std::any_cast<SectionGenerator>(&(sections.import))->generate(*this, newImport);
    }
  }else if((!target.importModule.has_value()) && (!target.importName.has_value())){
    // Regular
    result += '\x70';
    if(target.id.has_value()){
      context.identifierMap[*(target.id)] = context.tableCount;
    }
    ++context.tableCount;
    result += std::visit<BinaryCode>(*this, CodeGenVariant(target.tableType));
  }else{
    throw Error<ErrorType::GenerateError>("import name and module name should be both performed");
  }
  return result;
}
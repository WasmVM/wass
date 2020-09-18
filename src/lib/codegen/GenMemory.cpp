#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Import.hpp>
#include <structure/Memory.hpp>
#include <structure/Data.hpp>
#include <structure/ConstInstr.hpp>
#include <codegen/SectionGenerator.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Memory&& target){
  BinaryCode result;
  if(target.data.has_value()){
    Data newData;
    newData.data = *target.data;
    I32ConstInstr& expr = newData.expr.emplace<I32ConstInstr>(I32ConstInstr());
    expr.value = 0;
    newData.memIndex = context.memCount;
    if(!sections.data.has_value()){
      sections.data.emplace<SectionGenerator>().generate(*this, newData);
    }else{
      std::any_cast<SectionGenerator>(&(sections.data))->generate(*this, newData);
    }
  }
  if(target.exportNames.size() > 0){
    for(std::string name : target.exportNames){
      // Inline export
      Export newExport;
      newExport.index.emplace<uint32_t>(context.memCount);
      newExport.name = name;
      newExport.type = ExportType::Memory;
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
    newImport.type = Import::ImportType::Memory;
    newImport.descId = target.id;
    newImport.desc.emplace<Limit>(target.memType);
    if(!sections.import.has_value()){
      sections.import.emplace<SectionGenerator>().generate(*this, newImport);
    }else{
      std::any_cast<SectionGenerator>(&(sections.import))->generate(*this, newImport);
    }
  }else if((!target.importModule.has_value()) && (!target.importName.has_value())){
    // Regular
    if(target.id.has_value()){
      context.identifierMap[*(target.id)] = context.memCount;
    }
    ++context.memCount;
    result += std::visit<BinaryCode>(*this, CodeGenVariant(target.memType));
  }else{
    throw Error<ErrorType::GenerateError>("import name and module name should be both performed");
  }
  return result;
}
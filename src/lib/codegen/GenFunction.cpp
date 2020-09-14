#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Import.hpp>
#include <structure/Function.hpp>
#include <structure/Export.hpp>
#include <codegen/SectionGenerator.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Function&& target){
  BinaryCode result;
  if(target.exportNames.size() > 0){
    for(std::string name : target.exportNames){
      // Inline export
      Export newExport;
      newExport.index.emplace<uint32_t>(context.funcCount);
      newExport.name = name;
      newExport.type = ExportType::Func;
      if(!sections.exports.has_value()){
        sections.exports.emplace<SectionGenerator>().generate(*this, newExport);
      }else{
        std::any_cast<SectionGenerator>(&(sections.exports))->generate(*this, newExport);
      }
    }
  }
  if((target.importModule.has_value()) && (target.importName.has_value())){
    // Inline import
    Import newImport;
    newImport.mod = *(target.importModule);
    newImport.name = *(target.importName);
    newImport.type = Import::ImportType::Function;
    newImport.descId = target.id;
    newImport.desc.emplace<TypeUse>(target.typeUse);
    if(!sections.import.has_value()){
      sections.import.emplace<SectionGenerator>().generate(*this, newImport);
    }else{
      std::any_cast<SectionGenerator>(&(sections.import))->generate(*this, newImport);
    }
  }else if((!target.importModule.has_value()) && (!target.importName.has_value())){
    // Regular
    if(target.id.has_value()){
      context.identifierMap[*(target.id)] = context.funcCount;
    }
    ++context.funcCount;
    result += std::visit<BinaryCode>(*this, CodeGenVariant(target.typeUse));
  }else{
    throw Error<ErrorType::GenerateError>("import name and module name should be both performed");
  }
  return result;
}
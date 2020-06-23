#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Import.hpp>
#include <structure/Global.hpp>
#include <codegen/SectionGenerator.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Global&& target){
  BinaryCode result;
  // TODO: inline export
  if((target.importModule.has_value()) && (target.importName.has_value())){
    // Inline import
    Import newImport;
    newImport.mod = *(target.importModule);
    newImport.name = *(target.importName);
    newImport.type = Import::ImportType::Global;
    newImport.descId = target.id;
    newImport.desc.emplace<GlobalType>(target.globalType);
    if(!sections.import.has_value()){
      sections.import.emplace<SectionGenerator>().generate(*this, newImport);
    }else{
      std::any_cast<SectionGenerator>(&(sections.import))->generate(*this, newImport);
    }
  }else if((!target.importModule.has_value()) && (!target.importName.has_value())){
    // Regular
    if(target.id.has_value()){
      context.identifierMap[*(target.id)] = context.globalCount;
    }
    ++context.globalCount;
    result += std::visit<BinaryCode>(*this, CodeGenVariant(target.globalType));
    result += std::visit<BinaryCode>(*this, target.expr);
  }else{
    throw Error<ErrorType::GenerateError>("import name and module name should be both performed");
  }
  return result;
}
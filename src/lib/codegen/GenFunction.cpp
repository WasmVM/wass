#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Import.hpp>
#include <structure/Function.hpp>
#include <codegen/SectionGenerator.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Function&& target){
  BinaryCode result;
  // TODO: inline export
  if((target.importModule.size() != 0) && (target.importName.size() != 0)){
    // Inline import
    Import newImport;
    newImport.mod = target.importModule;
    newImport.name = target.importName;
    newImport.type = Import::ImportType::Function;
    newImport.descId = target.id;
    newImport.desc.emplace<TypeUse>(target.typeUse);
    if(!sections.import.has_value()){
      sections.import.emplace<SectionGenerator>().generate(*this, newImport);
    }else{
      std::any_cast<SectionGenerator>(&(sections.import))->generate(*this, newImport);
    }
  }else if((target.importModule.size() == 0) && (target.importName.size() == 0)){
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
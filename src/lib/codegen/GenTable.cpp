#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Import.hpp>
#include <structure/Table.hpp>
#include <codegen/SectionGenerator.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Table&& target){
  BinaryCode result;
  // TODO: inline export
  // TODO: inline element
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
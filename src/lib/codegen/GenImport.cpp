#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Import.hpp>
#include <Error.hpp>
#include <Util.hpp>

BinaryCode CodeGenVisitor::operator()(Import&& target){
  BinaryCode result;
  result += Util::toLEB128((uint32_t)target.mod.size());
  result += target.mod;
  result += Util::toLEB128((uint32_t)target.name.size());
  result += target.name;
  switch (target.type){
    case (Import::ImportType::Function):
      if(target.descId.has_value()){
        context.identifierMap[*(target.descId)] = context.funcCount;
      }
      result += '\x00';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<TypeUse>(target.desc)));
      ++context.funcCount;
      break;
    case (Import::ImportType::Table):
      if(target.descId.has_value()){
        context.identifierMap[*(target.descId)] = context.tableCount;
      }
      result += '\x01';
      result += '\x70';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<Limit>(target.desc)));
      ++context.tableCount;
      break;
    case (Import::ImportType::Memory):
      if(target.descId.has_value()){
        context.identifierMap[*(target.descId)] = context.memCount;
      }
      result += '\x02';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<Limit>(target.desc)));
      ++context.memCount;
      break;
    case (Import::ImportType::Global):
      if(target.descId.has_value()){
        context.identifierMap[*(target.descId)] = context.globalCount;
      }
      result += '\x03';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<GlobalType>(target.desc)));
      ++context.globalCount;
      break;
  }
  return result;
}
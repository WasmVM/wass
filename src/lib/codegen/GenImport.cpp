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
        context.identifierMap[*(target.descId)] = context.funcIdx;
      }
      result += '\x00';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<TypeUse>(target.desc)));
      ++context.funcIdx;
      break;
    case (Import::ImportType::Table):
      if(target.descId.has_value()){
        context.identifierMap[*(target.descId)] = context.tableIdx;
      }
      result += '\x01';
      result += '\x70';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<Limit>(target.desc)));
      ++context.tableIdx;
      break;
    case (Import::ImportType::Memory):
      if(target.descId.has_value()){
        context.identifierMap[*(target.descId)] = context.memIdx;
      }
      result += '\x02';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<Limit>(target.desc)));
      ++context.memIdx;
      break;
    case (Import::ImportType::Global):
      if(target.descId.has_value()){
        context.identifierMap[*(target.descId)] = context.globalIdx;
      }
      result += '\x03';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<GlobalType>(target.desc)));
      ++context.globalIdx;
      break;
  }
  return result;
}
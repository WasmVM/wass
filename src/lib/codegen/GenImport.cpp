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
      result += '\x00';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<TypeUse>(target.desc)));
      break;
    case (Import::ImportType::Table):
      result += '\x01';
      result += '\x70';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<Limit>(target.desc)));
      break;
    case (Import::ImportType::Memory):
      result += '\x02';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<Limit>(target.desc)));
      break;
    case (Import::ImportType::Global):
      result += '\x03';
      result += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<GlobalType>(target.desc)));
      break;
  }
  return result;
}
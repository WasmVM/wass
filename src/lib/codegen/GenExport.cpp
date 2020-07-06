#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Export.hpp>
#include <Util.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Export&& target){
  BinaryCode result = Util::toLEB128((uint32_t)target.name.size());
  result += target.name;
  switch(target.type){
    case ExportType::Func :
      result += '\x00';
    break;
    case ExportType::Table :
      result += '\x01';
    break;
    case ExportType::Memory :
      result += '\x02';
    break;
    case ExportType::Global :
      result += '\x03';
    break;
    default:
      throw Error<ErrorType::GenerateError>("index is required in Export");
  }
  return result + std::visit<BinaryCode>(*this, CodeGenVariant(target.index));
}
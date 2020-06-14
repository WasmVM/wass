#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <vector>
#include <cstdint>
#include <structure/Type.hpp>
#include <Util.hpp>
#include <BinaryCode.hpp>

BinaryCode CodeGenVisitor::operator()(Module&& target){
  BinaryCode result({
    '\x00','\x61','\x73','\x6D', // Magic
    '\x01','\x00','\x00','\x00', // Version
  });
  // TODO: Module id is omitted now, but maybe we can performed in a custom section
  // Type section
  for(Type& type : target.types){
    context.typeCodes.emplace_back(std::visit<BinaryCode>(*this, CodeGenVariant(type.funcType)));
    if(type.id.has_value()){
      context.typeMap[*(type.id)] = context.typeCodes.size() - 1;
    }
  }
  // Wrap Type section
  if(context.typeCodes.size() > 0){
    result += '\x01';
    result += Util::toLEB128((uint32_t)context.typeCodes.size());
    for(BinaryCode& code : context.typeCodes){
      result += code;
    }
  }
  return result;
}
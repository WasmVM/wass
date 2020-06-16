#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Type.hpp>
#include <Error.hpp>

BinaryCode CodeGenVisitor::operator()(Type&& target){
  if(target.id.has_value()){
    if(context.identifierMap.contains(*(target.id))){
      throw Error<ErrorType::GenerateError>("Identifier must be unique");
    }
    context.identifierMap[*(target.id)] = context.typeDescs.size();
    context.typeDescs.emplace_back(target.funcType);
  }
  return std::visit<BinaryCode>(*this, CodeGenVariant(target.funcType));
}
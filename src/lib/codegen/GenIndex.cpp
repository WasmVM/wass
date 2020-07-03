#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/Index.hpp>
#include <Util.hpp>
#include <Error.hpp>

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

BinaryCode CodeGenVisitor::operator()(Index&& target){
  BinaryCode result;
  std::visit(overloaded {
    [&result](uint32_t index){
      result += Util::toLEB128(index);
    },
    [&result, this](std::string index){
      if(context.identifierMap.contains(index)){
        result += Util::toLEB128(context.identifierMap[index]);
      }else{
        throw Error<ErrorType::GenerateError>("identifier should be declared before use as index");
      }
    }
  }, target);
  return result;
}

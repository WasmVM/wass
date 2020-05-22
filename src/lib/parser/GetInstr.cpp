#include <parser/GetInstr.hpp>

#include <variant>
#include <vector>
#include <parser/ParserConstInstr.hpp>
#include <parser/ParserControlInstr.hpp>
#include <parser/ParserMemoryInstr.hpp>
#include <parser/ParserNumericInstr.hpp>
#include <parser/ParserParamInstr.hpp>
#include <parser/ParserBlockedInstr.hpp>
#include <parser/ParserVariableInstr.hpp>

template <class... Args>
static InstrVariant variant_cast(const std::variant<Args...>& v){
  return std::visit([](auto&& arg) -> InstrVariant { return arg; }, v);
}

template <class... T>
static InstrVariant getInstr(ParserContext& context){
  for(InstrVariant result : std::vector<InstrVariant>({variant_cast(T(context))...})){
    if(!std::holds_alternative<std::monostate>(result)){
      return result;
    }
  }
  return InstrVariant(std::monostate());
}

InstrVariant getInstruction(ParserContext& context){
  return getInstr<
    ParserConstInstr,
    ParserControlInstr,
    ParserMemoryInstr,
    ParserNumericInstr,
    ParserParamInstr,
    ParserVariableInstr,
    ParserBlockedInstr
  >(context);
}
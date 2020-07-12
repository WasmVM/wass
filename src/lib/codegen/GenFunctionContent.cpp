#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <vector>
#include <tuple>
#include <structure/Function.hpp>
#include <Util.hpp>

static std::vector<std::tuple<uint32_t, ValueType>> getTupleofLocals(std::vector<ValueType> locals){
  std::vector<std::tuple<uint32_t, ValueType>> result;
  if(locals.size() != 0){
    result.emplace_back(std::make_tuple((uint32_t)1, locals.front()));
    for(auto it = locals.begin() + 1; it != locals.end(); ++it){
      ValueType& curType = std::get<1>(result.back());
      if(*it == curType){
        std::get<0>(result.back()) += 1;
      }else{
        result.emplace_back(std::make_tuple((uint32_t)1, *it));
      }
    }
  }
  return result;
}

BinaryCode CodeGenVisitor::operator()(Function::Content&& target){
  for(auto it = target.localMap.begin(); it != target.localMap.end(); ++it){
    context.identifierMap[it->first] = it->second;
  }
  std::vector<std::tuple<uint32_t, ValueType>> locals(getTupleofLocals(target.locals));
  BinaryCode localCode(Util::toLEB128(locals.size()));
  for(auto it = locals.begin(); it != locals.end(); ++it){
    localCode += Util::toLEB128(std::get<0>(*it));
    localCode += std::visit<BinaryCode>(*this, CodeGenVariant(std::get<1>(*it)));
  }
  BinaryCode exprCode;
  for(auto it = target.body.cbegin(); it != target.body.cend(); ++it){
    exprCode += std::visit<BinaryCode>(*this, InstrVariant(*it));
  }
  exprCode += '\x0B';
  return Util::toLEB128((uint32_t)localCode.size() + (uint32_t)exprCode.size()) + localCode + exprCode;
}
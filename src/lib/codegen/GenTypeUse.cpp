#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <optional>
#include <utility>
#include <vector>
#include <string>
#include <cstdint>
#include <structure/TypeUse.hpp>
#include <structure/Type.hpp>
#include <Util.hpp>
#include <Error.hpp>
#include <codegen/SectionGenerator.hpp>

static bool isMatched(const FuncType& funcType, const TypeUse& target){
  bool matched = true;
  for(size_t j = 0; j < funcType.params.size(); ++j){
    if(funcType.params[j] != target.params[j]){
      matched = false;
      break;
    }
  }
  if(matched){
    for(size_t j = 0; j < funcType.results.size(); ++j){
      if(funcType.results[j] != target.results[j]){
        matched = false;
        break;
      }
    }
    if(matched){
      return true;
    }
  }
  return false;
}

static std::optional<uint32_t> matchedType(const std::vector<FuncType>& types, const TypeUse& target){
  for(size_t i = 0; i < types.size(); ++i){
    if((types[i].params.size() == target.params.size()) && (types[i].results.size() == target.results.size())){
      if(isMatched(types[i], target)){
        return std::optional<uint32_t>((uint32_t)i);
      }
    }
  }
  return std::optional<uint32_t>();
}

BinaryCode CodeGenVisitor::operator()(TypeUse&& target){
  if(target.index.has_value()){
    return std::visit<BinaryCode>(*this, CodeGenVariant(*target.index));
  }else{
    std::optional<uint32_t> matchedIndex = matchedType(context.typeDescs, target);
    if(!matchedIndex.has_value()){
      matchedIndex = (uint32_t)context.typeDescs.size();
      Type newType;
      newType.funcType = FuncType(target);
      if(!sections.type.has_value()){
        sections.type.emplace<SectionGenerator>();
      }
      std::any_cast<SectionGenerator>(&(sections.type))->generate(*this, newType);
    }else{
      for(std::pair<std::string, uint32_t> idPair : target.paramMap){
        context.identifierMap[idPair.first] = idPair.second;
      }
    }
    return Util::toLEB128((uint32_t)*matchedIndex);
  }
}
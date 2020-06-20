#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <optional>
#include <utility>
#include <vector>
#include <cstdint>
#include <any>
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
  BinaryCode result;
  if(target.index.has_value()){
    if(target.index.type() == typeid(std::string)){
      std::string* index = std::any_cast<std::string>(&(target.index));
      if(context.identifierMap.contains(*index)){
        result += Util::toLEB128(context.identifierMap[*index]);
      }else{
        throw Error<ErrorType::GenerateError>("Unknown identifier of index in TypeUse");
      }
    }else if(target.index.type() == typeid(uint32_t)){
      result += Util::toLEB128(*(std::any_cast<uint32_t>(&(target.index))));
    }else{
      throw Error<ErrorType::GenerateError>("Unknown type of index in TypeUse");
    }
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
        if(context.identifierMap.contains(idPair.first)){
          throw Error<ErrorType::GenerateError>("Identifier must be unique");
        }
        context.identifierMap[idPair.first] = idPair.second;
      }
    }
    result += Util::toLEB128((uint32_t)*matchedIndex);
  }
  return result;
}
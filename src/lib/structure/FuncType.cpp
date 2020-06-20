#include <structure/FuncType.hpp>

FuncType::FuncType(const FuncType& funcType){
  params = funcType.params;
  results = funcType.results;
  paramMap = funcType.paramMap;
}

FuncType::FuncType(const TypeUse& typeUse){
  params = typeUse.params;
  results = typeUse.results;
  paramMap = typeUse.paramMap;
}
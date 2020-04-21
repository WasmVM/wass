#include <structure/FuncType.hpp>

FuncType::FuncType(const FuncType& funcType){
  params = funcType.params;
  results = funcType.results;
  paramMap = funcType.paramMap;
}
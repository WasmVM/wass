#include <parser/ParserFuncType.hpp>

#include <any>
#include <vector>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/ParserParam.hpp>
#include <parser/ParserResult.hpp>
#include <parser/Comment.hpp>
#include <structure/FuncType.hpp>

ParserFuncType::ParserFuncType(ParserContext& parent_context){
  ParserContext context = parent_context;
  if((*context.cursor) == '('){
    ++context.cursor;
    Comment::skip(context);
    if(Util::matchString(context.cursor, context.end, "func")){
      context.cursor += 4;
      Comment::skip(context);
      FuncType funcType;
      for(ParserParam param(context); param.has_value(); param = ParserParam(context)){
        if(param.type() == typeid(ValueType)){
          if(param.id != ""){
            funcType.paramMap[param.id] = funcType.params.size();
          }
          funcType.params.push_back(std::any_cast<ValueType>(param));
        }else if(param.type() == typeid(std::vector<ValueType>)){
          std::vector<ValueType> params = std::any_cast<std::vector<ValueType>>(param);
          for(std::vector<ValueType>::iterator it = params.begin(); it != params.end(); ++it){
            funcType.params.push_back(*it);
          }
        }
        Comment::skip(context);
      }
      Comment::skip(context);
      for(ParserResult result(context); result.has_value(); result = ParserResult(context)){
        if(result.type() == typeid(ValueType)){
          funcType.results.push_back(std::any_cast<ValueType>(result));
        }else if(result.type() == typeid(std::vector<ValueType>)){
          std::vector<ValueType> results = std::any_cast<std::vector<ValueType>>(result);
          for(std::vector<ValueType>::iterator it = results.begin(); it != results.end(); ++it){
            funcType.results.push_back(*it);
          }
        }
        Comment::skip(context);
      }
      Comment::skip(context);
      if((*context.cursor) == ')'){
        ++context.cursor;
        this->std::any::operator=(funcType);
        parent_context = context;
      }else{
        throw Error<ErrorType::SyntaxError>("expected ')'");
      }
    }
  }
}
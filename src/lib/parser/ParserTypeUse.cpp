#include <parser/ParserTypeUse.hpp>

#include <any>
#include <vector>
#include <string>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/ParserParam.hpp>
#include <parser/ParserResult.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/Identifier.hpp>
#include <parser/Comment.hpp>
#include <structure/TypeUse.hpp>

static void parsrTypeIndex(ParserContext& parent_context, TypeUse& typeUse){
  ParserContext context = parent_context;
  if((context.cursor != parent_context.end) && *context.cursor == '('){
    ++context.cursor;
    Comment::skip(context);
    if(Util::matchString(context.cursor, context.end, "type")){
      context.cursor += 4;
      Comment::skip(context);
      IntegerLiteral literal(context);
      if(literal.has_value()){
        typeUse.index = (uint32_t)*literal;
      }else{
        Identifier identifier(context);
        if(identifier.has_value()){
          typeUse.index = *identifier;
        }
      }
      if(typeUse.index.has_value()){
        Comment::skip(context);
        if(Util::matchString(context.cursor, context.end, ")")){
          parent_context.cursor = ++context.cursor;
        }else{
          throw Error<ErrorType::SyntaxError>("expected )");
        }
      }else{
        throw Error<ErrorType::SyntaxError>("expected identifier or type index");
      }
    }
  }
}

ParserTypeUse::ParserTypeUse(ParserContext& parent_context){
  ParserContext context = parent_context;
  TypeUse typeUse;
  parsrTypeIndex(context, typeUse);
  Comment::skip(context);
  for(ParserParam param(context); param.has_value(); param = ParserParam(context)){
    if(param.type() == typeid(ValueType)){
      if(param.id != ""){
        typeUse.paramMap[param.id] = typeUse.params.size();
      }
      typeUse.params.push_back(std::any_cast<ValueType>(param));
    }else if(param.type() == typeid(std::vector<ValueType>)){
      std::vector<ValueType> params = std::any_cast<std::vector<ValueType>>(param);
      for(std::vector<ValueType>::iterator it = params.begin(); it != params.end(); ++it){
        typeUse.params.push_back(*it);
      }
    }
    Comment::skip(context);
  }
  Comment::skip(context);
  for(ParserResult result(context); result.has_value(); result = ParserResult(context)){
    if(result.type() == typeid(ValueType)){
      typeUse.results.push_back(std::any_cast<ValueType>(result));
    }else if(result.type() == typeid(std::vector<ValueType>)){
      std::vector<ValueType> results = std::any_cast<std::vector<ValueType>>(result);
      for(std::vector<ValueType>::iterator it = results.begin(); it != results.end(); ++it){
        typeUse.results.push_back(*it);
      }
    }
    Comment::skip(context);
  }
  this->std::optional<TypeUse>::operator=(typeUse);
  parent_context.cursor = context.cursor;
}
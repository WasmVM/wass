#include <parser/ParserParam.hpp>

#include <any>
#include <string>
#include <vector>
#include <parser/Comment.hpp>
#include <parser/Identifier.hpp>
#include <parser/ParserValueType.hpp>
#include <structure/Value.hpp>
#include <Util.hpp>
#include <Error.hpp>

ParserParam::ParserParam(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if((*context.cursor) == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "param")){
        context.cursor += 5;
        Comment::skip(context);
        Identifier paramId(context);
        if(paramId.has_value()){
          id = std::any_cast<std::string>(paramId);
          Comment::skip(context);
          ParserValueType param(context);
          if(param.has_value()){
            this->std::any::operator=(std::any_cast<ValueType>(param));
          }else{
            throw Error<ErrorType::SyntaxError>("expected a parameter type");
          }
        }else{
          std::vector<ValueType> params;
          for(ParserValueType param(context); param.has_value(); param = ParserValueType(context)){
            params.push_back(std::any_cast<ValueType>(param));
            Comment::skip(context);
          }
          switch(params.size()){
            case 0:
              throw Error<ErrorType::SyntaxError>("expected a parameter type");
            case 1:
              this->std::any::operator=(params[0]);
              break;
            default:
              this->std::any::operator=(params);
              break;
          }
        }
        Comment::skip(context);
        if((*context.cursor) == ')'){
          ++context.cursor;
          parent_context = context;
        }else{
          reset();
          throw Error<ErrorType::SyntaxError>("expected ')'");
        }
      }
    }
  }
}
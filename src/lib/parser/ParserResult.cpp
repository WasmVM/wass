#include <parser/ParserResult.hpp>

#include <any>
#include <string>
#include <vector>
#include <parser/Comment.hpp>
#include <parser/ParserValue.hpp>
#include <structure/Value.hpp>
#include <Util.hpp>
#include <Error.hpp>

ParserResult::ParserResult(ParserContext& parent_context){
  ParserContext context = parent_context;
  if((*context.cursor) == '('){
    ++context.cursor;
    Comment::skip(context);
    if(Util::matchString(context.cursor, context.end, "result")){
      context.cursor += 6;
      Comment::skip(context);
      std::vector<ValueType> results;
      for(ParserValueType result(context); result.has_value(); result = ParserValueType(context)){
        results.push_back(std::any_cast<ValueType>(result));
        Comment::skip(context);
      }
      switch(results.size()){
        case 0:
          throw Error<ErrorType::SyntaxError>("expected a result type");
        case 1:
          this->std::any::operator=(results[0]);
          break;
        default:
          this->std::any::operator=(results);
          break;
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
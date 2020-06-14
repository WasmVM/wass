#include "_Abbreviated.hpp"

#include <optional>
#include <string>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/Comment.hpp>
#include <parser/Name.hpp>

AbbrImport::AbbrImport(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if((*context.cursor) == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "import")){
        context.cursor += 6;
        std::pair<std::string, std::string>& importPair = emplace<std::pair<std::string, std::string>>(std::pair<std::string, std::string>());
        // module name
        Comment::skip(context);
        Name modName(context);
        if(modName.has_value()){
          importPair.first = *modName;
        }else{
          throw Error<ErrorType::ParseError>("expected module name in import section");
        }
        // import name
        Comment::skip(context);
        Name name(context);
        if(name.has_value()){
          importPair.second = *name;
        }else{
          throw Error<ErrorType::ParseError>("expected name in import section");
        }
        // postfix
        Comment::skip(context);
        if((*context.cursor) == ')'){
          ++context.cursor;
          parent_context = context;
        }else{
          throw Error<ErrorType::ParseError>("expected ')'");
        }
      }
    }
  }
}

AbbrExport::AbbrExport(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if((*context.cursor) == '('){
      ++context.cursor;
      Comment::skip(context);
      if(Util::matchString(context.cursor, context.end, "export")){
        context.cursor += 6;
        // export name
        Comment::skip(context);
        Name name(context);
        if(name.has_value()){
          this->std::optional<std::string>::emplace(*name);
        }else{
          throw Error<ErrorType::ParseError>("expected name in export section");
        }
        // postfix
        Comment::skip(context);
        if((*context.cursor) == ')'){
          ++context.cursor;
          parent_context = context;
        }else{
          throw Error<ErrorType::ParseError>("expected ')'");
        }
      }
    }
  }
}
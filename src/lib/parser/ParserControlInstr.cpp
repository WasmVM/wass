#include <parser/ParserControlInstr.hpp>

#include <optional>
#include <variant>
#include <vector>
#include <cstdint>
#include <parser/ParserContext.hpp>
#include <parser/ParserIndex.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserTypeUse.hpp>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/ControlInstr.hpp>
#include <structure/Index.hpp>

ParserControlInstr::ParserControlInstr(ParserContext & parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(Util::matchString(context.cursor, context.end, "unreachable")){
      context.cursor += 11;
      emplace<UnreachableInstr>(UnreachableInstr());
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "nop")){
      context.cursor += 3;
      emplace<NopInstr>(NopInstr());
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "return")){
      context.cursor += 6;
      emplace<ReturnInstr>(ReturnInstr());
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "br_table")){
      context.cursor += 8;
      std::vector<Index> labels;
      Comment::skip(context);
      for(ParserIndex label(context); label.has_value(); label = ParserIndex(context)){
        labels.push_back(*label);
        Comment::skip(context);
      }
      if(labels.size() > 0){
        emplace<BrTableInstr>(BrTableInstr(labels));
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::ParseError>("expected at least a label index for br_table");
      }
    }else if(Util::matchString(context.cursor, context.end, "br_if")){
      context.cursor += 5;
      Comment::skip(context);
      ParserIndex label(context);
      if(label.has_value()){
        emplace<BrIfInstr>(BrIfInstr(*label));
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::ParseError>("expected a label index for br_if");
      }
    }else if(Util::matchString(context.cursor, context.end, "br")){
      context.cursor += 2;
      Comment::skip(context);
      ParserIndex label(context);
      if(label.has_value()){
        emplace<BrInstr>(BrInstr(*label));
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::ParseError>("expected a label index for br");
      }
    }else if(Util::matchString(context.cursor, context.end, "call_indirect")){
      context.cursor += 13;
      Comment::skip(context);
      ParserTypeUse typeUse(context);
      emplace<CallIndirectInstr>(CallIndirectInstr(*typeUse));
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "call")){
      context.cursor += 4;
      Comment::skip(context);
      ParserIndex label(context);
      if(label.has_value()){
        emplace<CallInstr>(*label);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::ParseError>("expected a function index for call");
      }
    }
  }
}
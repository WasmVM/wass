#include <parser/ParserControlInstr.hpp>

#include <optional>
#include <variant>
#include <vector>
#include <cstdint>
#include <parser/ParserContext.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserTypeUse.hpp>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/ControlInstr.hpp>

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
      std::vector<uint32_t> labels;
      Comment::skip(context);
      for(IntegerLiteral immediate(context); immediate.has_value(); immediate = IntegerLiteral(context)){
        labels.push_back(*immediate);
        Comment::skip(context);
      }
      if(labels.size() > 0){
        emplace<BrTableInstr>(BrTableInstr(labels));
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("expected at least a label index for br_table");
      }
    }else if(Util::matchString(context.cursor, context.end, "br_if")){
      context.cursor += 5;
      Comment::skip(context);
      IntegerLiteral label(context);
      if(label.has_value()){
        emplace<BrIfInstr>(BrIfInstr(*label));
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("expected a label index for br_if");
      }
    }else if(Util::matchString(context.cursor, context.end, "br")){
      context.cursor += 2;
      Comment::skip(context);
      IntegerLiteral label(context);
      if(label.has_value()){
        emplace<BrInstr>(BrInstr(*label));
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("expected a label index for br");
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
      IntegerLiteral label(context);
      if(label.has_value()){
        emplace<CallInstr>(*label);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("expected a function index for call");
      }
    }
  }
}
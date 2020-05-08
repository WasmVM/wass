#include <parser/ParserControlInstr.hpp>

#include <any>
#include <vector>
#include <cstdint>
#include <parser/ParserContext.hpp>
#include <parser/IntegerLiteral.hpp>
#include <parser/Comment.hpp>
#include <parser/ParserTypeUse.hpp>
#include <Util.hpp>
#include <Error.hpp>
#include <structure/Instr.hpp>
#include <structure/ControlInstr.hpp>

ParserControlInstr::ParserControlInstr(ParserContext & parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(Util::matchString(context.cursor, context.end, "unreachable")){
      context.cursor += 11;
      this->std::any::operator=(Instr<InstrType::Unreachable>());
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "nop")){
      context.cursor += 3;
      this->std::any::operator=(Instr<InstrType::Nop>());
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "return")){
      context.cursor += 6;
      this->std::any::operator=(Instr<InstrType::Return>());
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "br_table")){
      context.cursor += 8;
      std::vector<uint32_t> labels;
      Comment::skip(context);
      for(IntegerLiteral immediate(context); immediate.has_value(); immediate = IntegerLiteral(context)){
        labels.push_back(std::any_cast<int64_t>(immediate));
        Comment::skip(context);
      }
      if(labels.size() > 0){
        this->std::any::operator=(BrTableInstr(labels));
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("expected at least a label index for br_table");
      }
    }else if(Util::matchString(context.cursor, context.end, "br_if")){
      context.cursor += 5;
      Comment::skip(context);
      IntegerLiteral label(context);
      if(label.has_value()){
        BrIfInstr instr(std::any_cast<int64_t>(label));
        this->std::any::operator=(instr);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("expected a label index for br_if");
      }
    }else if(Util::matchString(context.cursor, context.end, "br")){
      context.cursor += 2;
      Comment::skip(context);
      IntegerLiteral label(context);
      if(label.has_value()){
        BrInstr instr(std::any_cast<int64_t>(label));
        this->std::any::operator=(instr);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("expected a label index for br");
      }
    }else if(Util::matchString(context.cursor, context.end, "call_indirect")){
      context.cursor += 13;
      Comment::skip(context);
      TypeUse typeUse = std::any_cast<TypeUse>(ParserTypeUse(context));
      this->std::any::operator=(CallIndirectInstr(typeUse));
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "call")){
      context.cursor += 4;
      Comment::skip(context);
      IntegerLiteral label(context);
      if(label.has_value()){
        CallInstr instr(std::any_cast<int64_t>(label));
        this->std::any::operator=(instr);
        parent_context.cursor = context.cursor;
      }else{
        throw Error<ErrorType::SyntaxError>("expected a function index for call");
      }
    }
  }
}
#include <parser/ParserMemoryInstr.hpp>

#include <any>
#include <structure/MemoryInstr.hpp>
#include <parser/ParserContext.hpp>
#include <parser/Comment.hpp>
#include <parser/IntegerLiteral.hpp>
#include <Util.hpp>
#include <Error.hpp>

class MemArg{
public:
  MemArg(ParserContext& context, int64_t default_align);
  int64_t align;
  int64_t offset;
};

MemArg::MemArg(ParserContext& parent_context, int64_t default_align){
  ParserContext context = parent_context;
  Comment::skip(context);
  if(Util::matchString(context.cursor, context.end, "offset=")){
    context.cursor += 7;
    IntegerLiteral offsetLiteral(context);
    if(offsetLiteral.has_value()){
      this->offset = std::any_cast<int64_t>(offsetLiteral);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer literal in offset=");
    }
  }else{
    this->offset = 0;
  }
  Comment::skip(context);
  if(Util::matchString(context.cursor, context.end, "align=")){
    context.cursor += 6;
    IntegerLiteral alignLiteral(context);
    if(alignLiteral.has_value()){
      this->align = std::any_cast<int64_t>(alignLiteral);
      parent_context.cursor = context.cursor;
    }else{
      throw Error<ErrorType::SyntaxError>("expected integer literal in align=");
    }
  }else{
    this->align = default_align;
  }
}

ParserMemoryInstr::ParserMemoryInstr(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;
    if(Util::matchString(context.cursor, context.end, "memory.grow")){
      context.cursor += 11;
      MemoryInstr<InstrType::MemoryGrow> instr;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "memory.size")){
      context.cursor += 11;
      MemoryInstr<InstrType::MemorySize> instr;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load8_s")){
      context.cursor += 11;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::I32Load8S> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load8_u")){
      context.cursor += 11;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::I32Load8U> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load16_s")){
      context.cursor += 12;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::I32Load16S> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load16_u")){
      context.cursor += 12;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::I32Load16U> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load8_s")){
      context.cursor += 11;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Load8S> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load8_u")){
      context.cursor += 11;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Load8U> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load16_s")){
      context.cursor += 12;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Load16S> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load16_u")){
      context.cursor += 12;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Load16U> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load32_s")){
      context.cursor += 12;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Load32S> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load32_u")){
      context.cursor += 12;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Load32U> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.store8")){
      context.cursor += 10;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::I32Store8> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.store16")){
      context.cursor += 11;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::I32Store16> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.store8")){
      context.cursor += 10;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Store8> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.store16")){
      context.cursor += 11;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Store16> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.store32")){
      context.cursor += 11;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Store32> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.store")){
      context.cursor += 9;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::I32Store> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.store")){
      context.cursor += 9;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Store> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "f32.store")){
      context.cursor += 9;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::F32Store> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "f64.store")){
      context.cursor += 9;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::F64Store> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load")){
      context.cursor += 8;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::I32Load> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load")){
      context.cursor += 8;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::I64Load> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "f32.load")){
      context.cursor += 8;
      MemArg memarg(context, 2);
      MemoryInstr<InstrType::F32Load> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "f64.load")){
      context.cursor += 8;
      MemArg memarg(context, 3);
      MemoryInstr<InstrType::F64Load> instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      this->std::any::operator=(instr);
      parent_context.cursor = context.cursor;
    }
  }
}
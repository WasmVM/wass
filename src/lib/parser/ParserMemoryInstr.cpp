#include <parser/ParserMemoryInstr.hpp>

#include <variant>
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
      this->offset = *offsetLiteral;
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
      this->align = *alignLiteral;
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
      emplace<MemoryGrowInstr>(MemoryGrowInstr());
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "memory.size")){
      context.cursor += 11;
      emplace<MemorySizeInstr>(MemorySizeInstr());
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load8_s")){
      context.cursor += 11;
      MemArg memarg(context, 2);
      I32Load8SInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I32Load8SInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load8_u")){
      context.cursor += 11;
      MemArg memarg(context, 2);
      I32Load8UInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I32Load8UInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load16_s")){
      context.cursor += 12;
      MemArg memarg(context, 2);
      I32Load16SInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I32Load16SInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load16_u")){
      context.cursor += 12;
      MemArg memarg(context, 2);
      I32Load16UInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I32Load16UInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load8_s")){
      context.cursor += 11;
      MemArg memarg(context, 3);
      I64Load8SInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Load8SInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load8_u")){
      context.cursor += 11;
      MemArg memarg(context, 3);
      I64Load8UInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Load8UInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load16_s")){
      context.cursor += 12;
      MemArg memarg(context, 3);
      I64Load16SInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Load16SInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load16_u")){
      context.cursor += 12;
      MemArg memarg(context, 3);
      I64Load16UInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Load16UInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load32_s")){
      context.cursor += 12;
      MemArg memarg(context, 3);
      I64Load32SInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Load32SInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load32_u")){
      context.cursor += 12;
      MemArg memarg(context, 3);
      I64Load32UInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Load32UInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.store8")){
      context.cursor += 10;
      MemArg memarg(context, 2);
      I32Store8Instr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I32Store8Instr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.store16")){
      context.cursor += 11;
      MemArg memarg(context, 2);
      I32Store16Instr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I32Store16Instr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.store8")){
      context.cursor += 10;
      MemArg memarg(context, 3);
      I64Store8Instr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Store8Instr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.store16")){
      context.cursor += 11;
      MemArg memarg(context, 3);
      I64Store16Instr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Store16Instr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.store32")){
      context.cursor += 11;
      MemArg memarg(context, 3);
      I64Store32Instr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64Store32Instr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.store")){
      context.cursor += 9;
      MemArg memarg(context, 2);
      I32StoreInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I32StoreInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.store")){
      context.cursor += 9;
      MemArg memarg(context, 3);
      I64StoreInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64StoreInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "f32.store")){
      context.cursor += 9;
      MemArg memarg(context, 2);
      F32StoreInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<F32StoreInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "f64.store")){
      context.cursor += 9;
      MemArg memarg(context, 3);
      F64StoreInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<F64StoreInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i32.load")){
      context.cursor += 8;
      MemArg memarg(context, 2);
      I32LoadInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I32LoadInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "i64.load")){
      context.cursor += 8;
      MemArg memarg(context, 3);
      I64LoadInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<I64LoadInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "f32.load")){
      context.cursor += 8;
      MemArg memarg(context, 2);
      F32LoadInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<F32LoadInstr>(instr);
      parent_context.cursor = context.cursor;
    }else if(Util::matchString(context.cursor, context.end, "f64.load")){
      context.cursor += 8;
      MemArg memarg(context, 3);
      F64LoadInstr instr;
      instr.align = memarg.align;
      instr.offset = memarg.offset;
      emplace<F64LoadInstr>(instr);
      parent_context.cursor = context.cursor;
    }
  }
}
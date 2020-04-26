#include <parser/ParserNumericInstr.hpp>

#include <Util.hpp>
#include <structure/Instr.hpp>

ParserNumericInstr::ParserNumericInstr(ParserContext& context){
  if(Util::matchString(context.cursor, context.end, "i32.clz")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32Clz>());
  }else if(Util::matchString(context.cursor, context.end, "i32.ctz")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32Ctz>());
  }else if(Util::matchString(context.cursor, context.end, "i32.popcnt")){
    context.cursor += 10;
    this->std::any::operator=(Instr<InstrType::I32Popcnt>());
  }else if(Util::matchString(context.cursor, context.end, "i32.add")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32Add>());
  }else if(Util::matchString(context.cursor, context.end, "i32.sub")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32Sub>());
  }else if(Util::matchString(context.cursor, context.end, "i32.mul")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32Mul>());
  }else if(Util::matchString(context.cursor, context.end, "i32.div_s")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I32DivS>());
  }else if(Util::matchString(context.cursor, context.end, "i32.div_u")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I32DivU>());
  }else if(Util::matchString(context.cursor, context.end, "i32.rem_s")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I32RemS>());
  }else if(Util::matchString(context.cursor, context.end, "i32.rem_u")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I32RemU>());
  }else if(Util::matchString(context.cursor, context.end, "i32.and")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32And>());
  }else if(Util::matchString(context.cursor, context.end, "i32.or")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::I32Or>());
  }else if(Util::matchString(context.cursor, context.end, "i32.xor")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32Xor>());
  }else if(Util::matchString(context.cursor, context.end, "i32.shl")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32Shl>());
  }else if(Util::matchString(context.cursor, context.end, "i32.shr_s")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I32ShrS>());
  }else if(Util::matchString(context.cursor, context.end, "i32.shr_u")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I32ShrU>());
  }else if(Util::matchString(context.cursor, context.end, "i32.rotl")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32Rotl>());
  }else if(Util::matchString(context.cursor, context.end, "i32.rotr")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32Rotr>());
  }else if(Util::matchString(context.cursor, context.end, "i64.clz")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64Clz>());
  }else if(Util::matchString(context.cursor, context.end, "i64.ctz")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64Ctz>());
  }else if(Util::matchString(context.cursor, context.end, "i64.popcnt")){
    context.cursor += 10;
    this->std::any::operator=(Instr<InstrType::I64Popcnt>());
  }else if(Util::matchString(context.cursor, context.end, "i64.add")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64Add>());
  }else if(Util::matchString(context.cursor, context.end, "i64.sub")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64Sub>());
  }else if(Util::matchString(context.cursor, context.end, "i64.mul")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64Mul>());
  }else if(Util::matchString(context.cursor, context.end, "i64.div_s")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I64DivS>());
  }else if(Util::matchString(context.cursor, context.end, "i64.div_u")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I64DivU>());
  }else if(Util::matchString(context.cursor, context.end, "i64.rem_s")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I64RemS>());
  }else if(Util::matchString(context.cursor, context.end, "i64.rem_u")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I64RemU>());
  }else if(Util::matchString(context.cursor, context.end, "i64.and")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64And>());
  }else if(Util::matchString(context.cursor, context.end, "i64.or")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::I64Or>());
  }else if(Util::matchString(context.cursor, context.end, "i64.xor")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64Xor>());
  }else if(Util::matchString(context.cursor, context.end, "i64.shl")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64Shl>());
  }else if(Util::matchString(context.cursor, context.end, "i64.shr_s")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I64ShrS>());
  }else if(Util::matchString(context.cursor, context.end, "i64.shr_u")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::I64ShrU>());
  }else if(Util::matchString(context.cursor, context.end, "i64.rotl")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64Rotl>());
  }else if(Util::matchString(context.cursor, context.end, "i64.rotr")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64Rotr>());
  }
}
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
  }else if(Util::matchString(context.cursor, context.end, "f32.abs")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F32Abs>());
  }else if(Util::matchString(context.cursor, context.end, "f32.neg")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F32Neg>());
  }else if(Util::matchString(context.cursor, context.end, "f32.ceil")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::F32Ceil>());
  }else if(Util::matchString(context.cursor, context.end, "f32.floor")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::F32Floor>());
  }else if(Util::matchString(context.cursor, context.end, "f32.trunc")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::F32Trunc>());
  }else if(Util::matchString(context.cursor, context.end, "f32.nearest")){
    context.cursor += 11;
    this->std::any::operator=(Instr<InstrType::F32Nearest>());
  }else if(Util::matchString(context.cursor, context.end, "f32.sqrt")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::F32Sqrt>());
  }else if(Util::matchString(context.cursor, context.end, "f32.add")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F32Add>());
  }else if(Util::matchString(context.cursor, context.end, "f32.sub")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F32Sub>());
  }else if(Util::matchString(context.cursor, context.end, "f32.mul")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F32Mul>());
  }else if(Util::matchString(context.cursor, context.end, "f32.div")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F32Div>());
  }else if(Util::matchString(context.cursor, context.end, "f32.min")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F32Min>());
  }else if(Util::matchString(context.cursor, context.end, "f32.max")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F32Max>());
  }else if(Util::matchString(context.cursor, context.end, "f32.copysign")){
    context.cursor += 12;
    this->std::any::operator=(Instr<InstrType::F32Copysign>());
  }else if(Util::matchString(context.cursor, context.end, "f64.abs")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F64Abs>());
  }else if(Util::matchString(context.cursor, context.end, "f64.neg")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F64Neg>());
  }else if(Util::matchString(context.cursor, context.end, "f64.ceil")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::F64Ceil>());
  }else if(Util::matchString(context.cursor, context.end, "f64.floor")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::F64Floor>());
  }else if(Util::matchString(context.cursor, context.end, "f64.trunc")){
    context.cursor += 9;
    this->std::any::operator=(Instr<InstrType::F64Trunc>());
  }else if(Util::matchString(context.cursor, context.end, "f64.nearest")){
    context.cursor += 11;
    this->std::any::operator=(Instr<InstrType::F64Nearest>());
  }else if(Util::matchString(context.cursor, context.end, "f64.sqrt")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::F64Sqrt>());
  }else if(Util::matchString(context.cursor, context.end, "f64.add")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F64Add>());
  }else if(Util::matchString(context.cursor, context.end, "f64.sub")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F64Sub>());
  }else if(Util::matchString(context.cursor, context.end, "f64.mul")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F64Mul>());
  }else if(Util::matchString(context.cursor, context.end, "f64.div")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F64Div>());
  }else if(Util::matchString(context.cursor, context.end, "f64.min")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F64Min>());
  }else if(Util::matchString(context.cursor, context.end, "f64.max")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::F64Max>());
  }else if(Util::matchString(context.cursor, context.end, "f64.copysign")){
    context.cursor += 12;
    this->std::any::operator=(Instr<InstrType::F64Copysign>());
  }else if(Util::matchString(context.cursor, context.end, "i32.eqz")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I32Eqz>());
  }else if(Util::matchString(context.cursor, context.end, "i32.eq")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::I32Eq>());
  }else if(Util::matchString(context.cursor, context.end, "i32.ne")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::I32Ne>());
  }else if(Util::matchString(context.cursor, context.end, "i32.lt_s")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32LtS>());
  }else if(Util::matchString(context.cursor, context.end, "i32.lt_u")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32LtU>());
  }else if(Util::matchString(context.cursor, context.end, "i32.le_s")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32LeS>());
  }else if(Util::matchString(context.cursor, context.end, "i32.le_u")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32LeU>());
  }else if(Util::matchString(context.cursor, context.end, "i32.gt_s")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32GtS>());
  }else if(Util::matchString(context.cursor, context.end, "i32.gt_u")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32GtU>());
  }else if(Util::matchString(context.cursor, context.end, "i32.ge_s")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32GeS>());
  }else if(Util::matchString(context.cursor, context.end, "i32.ge_u")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I32GeU>());
  }else if(Util::matchString(context.cursor, context.end, "i64.eqz")){
    context.cursor += 7;
    this->std::any::operator=(Instr<InstrType::I64Eqz>());
  }else if(Util::matchString(context.cursor, context.end, "i64.eq")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::I64Eq>());
  }else if(Util::matchString(context.cursor, context.end, "i64.ne")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::I64Ne>());
  }else if(Util::matchString(context.cursor, context.end, "i64.lt_s")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64LtS>());
  }else if(Util::matchString(context.cursor, context.end, "i64.lt_u")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64LtU>());
  }else if(Util::matchString(context.cursor, context.end, "i64.le_s")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64LeS>());
  }else if(Util::matchString(context.cursor, context.end, "i64.le_u")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64LeU>());
  }else if(Util::matchString(context.cursor, context.end, "i64.gt_s")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64GtS>());
  }else if(Util::matchString(context.cursor, context.end, "i64.gt_u")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64GtU>());
  }else if(Util::matchString(context.cursor, context.end, "i64.ge_s")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64GeS>());
  }else if(Util::matchString(context.cursor, context.end, "i64.ge_u")){
    context.cursor += 8;
    this->std::any::operator=(Instr<InstrType::I64GeU>());
  }else if(Util::matchString(context.cursor, context.end, "f32.eq")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F32Eq>());
  }else if(Util::matchString(context.cursor, context.end, "f32.ne")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F32Ne>());
  }else if(Util::matchString(context.cursor, context.end, "f32.lt")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F32Lt>());
  }else if(Util::matchString(context.cursor, context.end, "f32.gt")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F32Gt>());
  }else if(Util::matchString(context.cursor, context.end, "f32.le")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F32Le>());
  }else if(Util::matchString(context.cursor, context.end, "f32.ge")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F32Ge>());
  }else if(Util::matchString(context.cursor, context.end, "f64.eq")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F64Eq>());
  }else if(Util::matchString(context.cursor, context.end, "f64.ne")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F64Ne>());
  }else if(Util::matchString(context.cursor, context.end, "f64.lt")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F64Lt>());
  }else if(Util::matchString(context.cursor, context.end, "f64.gt")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F64Gt>());
  }else if(Util::matchString(context.cursor, context.end, "f64.le")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F64Le>());
  }else if(Util::matchString(context.cursor, context.end, "f64.ge")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::F64Ge>());
  }else if(Util::matchString(context.cursor, context.end, "i32.wrap_i64")){
    context.cursor += 12;
    this->std::any::operator=(Instr<InstrType::I32WrapI64>());
  }else if(Util::matchString(context.cursor, context.end, "i32.trunc_f32_s")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::I32TruncF32S>());
  }else if(Util::matchString(context.cursor, context.end, "i32.trunc_f32_u")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::I32TruncF32U>());
  }else if(Util::matchString(context.cursor, context.end, "i32.trunc_f64_s")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::I32TruncF64S>());
  }else if(Util::matchString(context.cursor, context.end, "i32.trunc_f64_u")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::I32TruncF64U>());
  }else if(Util::matchString(context.cursor, context.end, "i64.extend_i32_s")){
    context.cursor += 16;
    this->std::any::operator=(Instr<InstrType::I64ExtendI32S>());
  }else if(Util::matchString(context.cursor, context.end, "i64.extend_i32_u")){
    context.cursor += 16;
    this->std::any::operator=(Instr<InstrType::I64ExtendI32U>());
  }else if(Util::matchString(context.cursor, context.end, "i64.trunc_f32_s")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::I64TruncF32S>());
  }else if(Util::matchString(context.cursor, context.end, "i64.trunc_f32_u")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::I64TruncF32U>());
  }else if(Util::matchString(context.cursor, context.end, "i64.trunc_f64_s")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::I64TruncF64S>());
  }else if(Util::matchString(context.cursor, context.end, "i64.trunc_f64_u")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::I64TruncF64U>());
  }else if(Util::matchString(context.cursor, context.end, "f32.convert_i32_s")){
    context.cursor += 17;
    this->std::any::operator=(Instr<InstrType::F32ConvertI32S>());
  }else if(Util::matchString(context.cursor, context.end, "f32.convert_i32_u")){
    context.cursor += 17;
    this->std::any::operator=(Instr<InstrType::F32ConvertI32U>());
  }else if(Util::matchString(context.cursor, context.end, "f32.convert_i64_s")){
    context.cursor += 17;
    this->std::any::operator=(Instr<InstrType::F32ConvertI64S>());
  }else if(Util::matchString(context.cursor, context.end, "f32.convert_i64_u")){
    context.cursor += 17;
    this->std::any::operator=(Instr<InstrType::F32ConvertI64U>());
  }else if(Util::matchString(context.cursor, context.end, "f32.demote_f64")){
    context.cursor += 14;
    this->std::any::operator=(Instr<InstrType::F32DemoteF64>());
  }else if(Util::matchString(context.cursor, context.end, "f64.convert_i32_s")){
    context.cursor += 17;
    this->std::any::operator=(Instr<InstrType::F64ConvertI32S>());
  }else if(Util::matchString(context.cursor, context.end, "f64.convert_i32_u")){
    context.cursor += 17;
    this->std::any::operator=(Instr<InstrType::F64ConvertI32U>());
  }else if(Util::matchString(context.cursor, context.end, "f64.convert_i64_s")){
    context.cursor += 17;
    this->std::any::operator=(Instr<InstrType::F64ConvertI64S>());
  }else if(Util::matchString(context.cursor, context.end, "f64.convert_i64_u")){
    context.cursor += 17;
    this->std::any::operator=(Instr<InstrType::F64ConvertI64U>());
  }else if(Util::matchString(context.cursor, context.end, "f64.promote_f32")){
    context.cursor += 15;
    this->std::any::operator=(Instr<InstrType::F64PromoteF32>());
  }else if(Util::matchString(context.cursor, context.end, "i32.reinterpret_f32")){
    context.cursor += 19;
    this->std::any::operator=(Instr<InstrType::I32ReinterpretF32>());
  }else if(Util::matchString(context.cursor, context.end, "i64.reinterpret_f64")){
    context.cursor += 19;
    this->std::any::operator=(Instr<InstrType::I64ReinterpretF64>());
  }else if(Util::matchString(context.cursor, context.end, "f32.reinterpret_i32")){
    context.cursor += 19;
    this->std::any::operator=(Instr<InstrType::F32ReinterpretI32>());
  }else if(Util::matchString(context.cursor, context.end, "f64.reinterpret_i64")){
    context.cursor += 19;
    this->std::any::operator=(Instr<InstrType::F64ReinterpretI64>());
  }
}

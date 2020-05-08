#include <parser/ParserNumericInstr.hpp>

#include <variant>
#include <Util.hpp>
#include <structure/BaseInstr.hpp>

ParserNumericInstr::ParserNumericInstr(ParserContext& context){
  if(Util::matchString(context.cursor, context.end, "i32.clz")){
    context.cursor += 7;
    emplace<I32ClzInstr>(I32ClzInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.ctz")){
    context.cursor += 7;
    emplace<I32CtzInstr>(I32CtzInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.popcnt")){
    context.cursor += 10;
    emplace<I32PopcntInstr>(I32PopcntInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.add")){
    context.cursor += 7;
    emplace<I32AddInstr>(I32AddInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.sub")){
    context.cursor += 7;
    emplace<I32SubInstr>(I32SubInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.mul")){
    context.cursor += 7;
    emplace<I32MulInstr>(I32MulInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.div_s")){
    context.cursor += 9;
    emplace<I32DivSInstr>(I32DivSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.div_u")){
    context.cursor += 9;
    emplace<I32DivUInstr>(I32DivUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.rem_s")){
    context.cursor += 9;
    emplace<I32RemSInstr>(I32RemSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.rem_u")){
    context.cursor += 9;
    emplace<I32RemUInstr>(I32RemUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.and")){
    context.cursor += 7;
    emplace<I32AndInstr>(I32AndInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.or")){
    context.cursor += 6;
    emplace<I32OrInstr>(I32OrInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.xor")){
    context.cursor += 7;
    emplace<I32XorInstr>(I32XorInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.shl")){
    context.cursor += 7;
    emplace<I32ShlInstr>(I32ShlInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.shr_s")){
    context.cursor += 9;
    emplace<I32ShrSInstr>(I32ShrSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.shr_u")){
    context.cursor += 9;
    emplace<I32ShrUInstr>(I32ShrUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.rotl")){
    context.cursor += 8;
    emplace<I32RotlInstr>(I32RotlInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.rotr")){
    context.cursor += 8;
    emplace<I32RotrInstr>(I32RotrInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.clz")){
    context.cursor += 7;
    emplace<I64ClzInstr>(I64ClzInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.ctz")){
    context.cursor += 7;
    emplace<I64CtzInstr>(I64CtzInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.popcnt")){
    context.cursor += 10;
    emplace<I64PopcntInstr>(I64PopcntInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.add")){
    context.cursor += 7;
    emplace<I64AddInstr>(I64AddInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.sub")){
    context.cursor += 7;
    emplace<I64SubInstr>(I64SubInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.mul")){
    context.cursor += 7;
    emplace<I64MulInstr>(I64MulInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.div_s")){
    context.cursor += 9;
    emplace<I64DivSInstr>(I64DivSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.div_u")){
    context.cursor += 9;
    emplace<I64DivUInstr>(I64DivUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.rem_s")){
    context.cursor += 9;
    emplace<I64RemSInstr>(I64RemSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.rem_u")){
    context.cursor += 9;
    emplace<I64RemUInstr>(I64RemUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.and")){
    context.cursor += 7;
    emplace<I64AndInstr>(I64AndInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.or")){
    context.cursor += 6;
    emplace<I64OrInstr>(I64OrInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.xor")){
    context.cursor += 7;
    emplace<I64XorInstr>(I64XorInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.shl")){
    context.cursor += 7;
    emplace<I64ShlInstr>(I64ShlInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.shr_s")){
    context.cursor += 9;
    emplace<I64ShrSInstr>(I64ShrSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.shr_u")){
    context.cursor += 9;
    emplace<I64ShrUInstr>(I64ShrUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.rotl")){
    context.cursor += 8;
    emplace<I64RotlInstr>(I64RotlInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.rotr")){
    context.cursor += 8;
    emplace<I64RotrInstr>(I64RotrInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.abs")){
    context.cursor += 7;
    emplace<F32AbsInstr>(F32AbsInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.neg")){
    context.cursor += 7;
    emplace<F32NegInstr>(F32NegInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.ceil")){
    context.cursor += 8;
    emplace<F32CeilInstr>(F32CeilInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.floor")){
    context.cursor += 9;
    emplace<F32FloorInstr>(F32FloorInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.trunc")){
    context.cursor += 9;
    emplace<F32TruncInstr>(F32TruncInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.nearest")){
    context.cursor += 11;
    emplace<F32NearestInstr>(F32NearestInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.sqrt")){
    context.cursor += 8;
    emplace<F32SqrtInstr>(F32SqrtInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.add")){
    context.cursor += 7;
    emplace<F32AddInstr>(F32AddInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.sub")){
    context.cursor += 7;
    emplace<F32SubInstr>(F32SubInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.mul")){
    context.cursor += 7;
    emplace<F32MulInstr>(F32MulInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.div")){
    context.cursor += 7;
    emplace<F32DivInstr>(F32DivInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.min")){
    context.cursor += 7;
    emplace<F32MinInstr>(F32MinInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.max")){
    context.cursor += 7;
    emplace<F32MaxInstr>(F32MaxInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.copysign")){
    context.cursor += 12;
    emplace<F32CopysignInstr>(F32CopysignInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.abs")){
    context.cursor += 7;
    emplace<F64AbsInstr>(F64AbsInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.neg")){
    context.cursor += 7;
    emplace<F64NegInstr>(F64NegInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.ceil")){
    context.cursor += 8;
    emplace<F64CeilInstr>(F64CeilInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.floor")){
    context.cursor += 9;
    emplace<F64FloorInstr>(F64FloorInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.trunc")){
    context.cursor += 9;
    emplace<F64TruncInstr>(F64TruncInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.nearest")){
    context.cursor += 11;
    emplace<F64NearestInstr>(F64NearestInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.sqrt")){
    context.cursor += 8;
    emplace<F64SqrtInstr>(F64SqrtInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.add")){
    context.cursor += 7;
    emplace<F64AddInstr>(F64AddInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.sub")){
    context.cursor += 7;
    emplace<F64SubInstr>(F64SubInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.mul")){
    context.cursor += 7;
    emplace<F64MulInstr>(F64MulInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.div")){
    context.cursor += 7;
    emplace<F64DivInstr>(F64DivInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.min")){
    context.cursor += 7;
    emplace<F64MinInstr>(F64MinInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.max")){
    context.cursor += 7;
    emplace<F64MaxInstr>(F64MaxInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.copysign")){
    context.cursor += 12;
    emplace<F64CopysignInstr>(F64CopysignInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.eqz")){
    context.cursor += 7;
    emplace<I32EqzInstr>(I32EqzInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.eq")){
    context.cursor += 6;
    emplace<I32EqInstr>(I32EqInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.ne")){
    context.cursor += 6;
    emplace<I32NeInstr>(I32NeInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.lt_s")){
    context.cursor += 8;
    emplace<I32LtSInstr>(I32LtSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.lt_u")){
    context.cursor += 8;
    emplace<I32LtUInstr>(I32LtUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.le_s")){
    context.cursor += 8;
    emplace<I32LeSInstr>(I32LeSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.le_u")){
    context.cursor += 8;
    emplace<I32LeUInstr>(I32LeUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.gt_s")){
    context.cursor += 8;
    emplace<I32GtSInstr>(I32GtSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.gt_u")){
    context.cursor += 8;
    emplace<I32GtUInstr>(I32GtUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.ge_s")){
    context.cursor += 8;
    emplace<I32GeSInstr>(I32GeSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.ge_u")){
    context.cursor += 8;
    emplace<I32GeUInstr>(I32GeUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.eqz")){
    context.cursor += 7;
    emplace<I64EqzInstr>(I64EqzInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.eq")){
    context.cursor += 6;
    emplace<I64EqInstr>(I64EqInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.ne")){
    context.cursor += 6;
    emplace<I64NeInstr>(I64NeInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.lt_s")){
    context.cursor += 8;
    emplace<I64LtSInstr>(I64LtSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.lt_u")){
    context.cursor += 8;
    emplace<I64LtUInstr>(I64LtUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.le_s")){
    context.cursor += 8;
    emplace<I64LeSInstr>(I64LeSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.le_u")){
    context.cursor += 8;
    emplace<I64LeUInstr>(I64LeUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.gt_s")){
    context.cursor += 8;
    emplace<I64GtSInstr>(I64GtSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.gt_u")){
    context.cursor += 8;
    emplace<I64GtUInstr>(I64GtUInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.ge_s")){
    context.cursor += 8;
    emplace<I64GeSInstr>(I64GeSInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.ge_u")){
    context.cursor += 8;
    emplace<I64GeUInstr>(I64GeUInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.eq")){
    context.cursor += 6;
    emplace<F32EqInstr>(F32EqInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.ne")){
    context.cursor += 6;
    emplace<F32NeInstr>(F32NeInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.lt")){
    context.cursor += 6;
    emplace<F32LtInstr>(F32LtInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.gt")){
    context.cursor += 6;
    emplace<F32GtInstr>(F32GtInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.le")){
    context.cursor += 6;
    emplace<F32LeInstr>(F32LeInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.ge")){
    context.cursor += 6;
    emplace<F32GeInstr>(F32GeInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.eq")){
    context.cursor += 6;
    emplace<F64EqInstr>(F64EqInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.ne")){
    context.cursor += 6;
    emplace<F64NeInstr>(F64NeInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.lt")){
    context.cursor += 6;
    emplace<F64LtInstr>(F64LtInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.gt")){
    context.cursor += 6;
    emplace<F64GtInstr>(F64GtInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.le")){
    context.cursor += 6;
    emplace<F64LeInstr>(F64LeInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.ge")){
    context.cursor += 6;
    emplace<F64GeInstr>(F64GeInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.wrap_i64")){
    context.cursor += 12;
    emplace<I32WrapI64Instr>(I32WrapI64Instr());
  }else if(Util::matchString(context.cursor, context.end, "i32.trunc_f32_s")){
    context.cursor += 15;
    emplace<I32TruncF32SInstr>(I32TruncF32SInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.trunc_f32_u")){
    context.cursor += 15;
    emplace<I32TruncF32UInstr>(I32TruncF32UInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.trunc_f64_s")){
    context.cursor += 15;
    emplace<I32TruncF64SInstr>(I32TruncF64SInstr());
  }else if(Util::matchString(context.cursor, context.end, "i32.trunc_f64_u")){
    context.cursor += 15;
    emplace<I32TruncF64UInstr>(I32TruncF64UInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.extend_i32_s")){
    context.cursor += 16;
    emplace<I64ExtendI32SInstr>(I64ExtendI32SInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.extend_i32_u")){
    context.cursor += 16;
    emplace<I64ExtendI32UInstr>(I64ExtendI32UInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.trunc_f32_s")){
    context.cursor += 15;
    emplace<I64TruncF32SInstr>(I64TruncF32SInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.trunc_f32_u")){
    context.cursor += 15;
    emplace<I64TruncF32UInstr>(I64TruncF32UInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.trunc_f64_s")){
    context.cursor += 15;
    emplace<I64TruncF64SInstr>(I64TruncF64SInstr());
  }else if(Util::matchString(context.cursor, context.end, "i64.trunc_f64_u")){
    context.cursor += 15;
    emplace<I64TruncF64UInstr>(I64TruncF64UInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.convert_i32_s")){
    context.cursor += 17;
    emplace<F32ConvertI32SInstr>(F32ConvertI32SInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.convert_i32_u")){
    context.cursor += 17;
    emplace<F32ConvertI32UInstr>(F32ConvertI32UInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.convert_i64_s")){
    context.cursor += 17;
    emplace<F32ConvertI64SInstr>(F32ConvertI64SInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.convert_i64_u")){
    context.cursor += 17;
    emplace<F32ConvertI64UInstr>(F32ConvertI64UInstr());
  }else if(Util::matchString(context.cursor, context.end, "f32.demote_f64")){
    context.cursor += 14;
    emplace<F32DemoteF64Instr>(F32DemoteF64Instr());
  }else if(Util::matchString(context.cursor, context.end, "f64.convert_i32_s")){
    context.cursor += 17;
    emplace<F64ConvertI32SInstr>(F64ConvertI32SInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.convert_i32_u")){
    context.cursor += 17;
    emplace<F64ConvertI32UInstr>(F64ConvertI32UInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.convert_i64_s")){
    context.cursor += 17;
    emplace<F64ConvertI64SInstr>(F64ConvertI64SInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.convert_i64_u")){
    context.cursor += 17;
    emplace<F64ConvertI64UInstr>(F64ConvertI64UInstr());
  }else if(Util::matchString(context.cursor, context.end, "f64.promote_f32")){
    context.cursor += 15;
    emplace<F64PromoteF32Instr>(F64PromoteF32Instr());
  }else if(Util::matchString(context.cursor, context.end, "i32.reinterpret_f32")){
    context.cursor += 19;
    emplace<I32ReinterpretF32Instr>(I32ReinterpretF32Instr());
  }else if(Util::matchString(context.cursor, context.end, "i64.reinterpret_f64")){
    context.cursor += 19;
    emplace<I64ReinterpretF64Instr>(I64ReinterpretF64Instr());
  }else if(Util::matchString(context.cursor, context.end, "f32.reinterpret_i32")){
    context.cursor += 19;
    emplace<F32ReinterpretI32Instr>(F32ReinterpretI32Instr());
  }else if(Util::matchString(context.cursor, context.end, "f64.reinterpret_i64")){
    context.cursor += 19;
    emplace<F64ReinterpretI64Instr>(F64ReinterpretI64Instr());
  }
}

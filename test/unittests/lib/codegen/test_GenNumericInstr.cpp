#include <gtest/gtest.h>

#include <variant>
#include <structure/NumericInstr.hpp>
#include <BinaryCode.hpp>
#include <codegen/CodeGenVisitor.hpp>

TEST(unittest_GenNumericInstr, i32_clz){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32ClzInstr())), BinaryCode({'\x67'}));
}

TEST(unittest_GenNumericInstr, i32_ctz){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32CtzInstr())), BinaryCode({'\x68'}));
}

TEST(unittest_GenNumericInstr, i32_popcnt){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32PopcntInstr())), BinaryCode({'\x69'}));
}

TEST(unittest_GenNumericInstr, i32_add){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32AddInstr())), BinaryCode({'\x6A'}));
}

TEST(unittest_GenNumericInstr, i32_sub){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32SubInstr())), BinaryCode({'\x6B'}));
}

TEST(unittest_GenNumericInstr, i32_mul){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32MulInstr())), BinaryCode({'\x6C'}));
}

TEST(unittest_GenNumericInstr, i32_div_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32DivSInstr())), BinaryCode({'\x6D'}));
}

TEST(unittest_GenNumericInstr, i32_div_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32DivUInstr())), BinaryCode({'\x6E'}));
}

TEST(unittest_GenNumericInstr, i32_rem_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32RemSInstr())), BinaryCode({'\x6F'}));
}

TEST(unittest_GenNumericInstr, i32_rem_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32RemUInstr())), BinaryCode({'\x70'}));
}

TEST(unittest_GenNumericInstr, i32_and){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32AndInstr())), BinaryCode({'\x71'}));
}

TEST(unittest_GenNumericInstr, i32_or){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32OrInstr())), BinaryCode({'\x72'}));
}

TEST(unittest_GenNumericInstr, i32_xor){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32XorInstr())), BinaryCode({'\x73'}));
}

TEST(unittest_GenNumericInstr, i32_shl){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32ShlInstr())), BinaryCode({'\x74'}));
}

TEST(unittest_GenNumericInstr, i32_shr_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32ShrSInstr())), BinaryCode({'\x75'}));
}

TEST(unittest_GenNumericInstr, i32_shr_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32ShrUInstr())), BinaryCode({'\x76'}));
}

TEST(unittest_GenNumericInstr, i32_rotl){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32RotlInstr())), BinaryCode({'\x77'}));
}

TEST(unittest_GenNumericInstr, i32_rotr){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32RotrInstr())), BinaryCode({'\x78'}));
}

TEST(unittest_GenNumericInstr, i64_clz){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64ClzInstr())), BinaryCode({'\x79'}));
}

TEST(unittest_GenNumericInstr, i64_ctz){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64CtzInstr())), BinaryCode({'\x7A'}));
}

TEST(unittest_GenNumericInstr, i64_popcnt){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64PopcntInstr())), BinaryCode({'\x7B'}));
}

TEST(unittest_GenNumericInstr, i64_add){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64AddInstr())), BinaryCode({'\x7C'}));
}

TEST(unittest_GenNumericInstr, i64_sub){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64SubInstr())), BinaryCode({'\x7D'}));
}

TEST(unittest_GenNumericInstr, i64_mul){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64MulInstr())), BinaryCode({'\x7E'}));
}

TEST(unittest_GenNumericInstr, i64_div_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64DivSInstr())), BinaryCode({'\x7F'}));
}

TEST(unittest_GenNumericInstr, i64_div_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64DivUInstr())), BinaryCode({'\x80'}));
}

TEST(unittest_GenNumericInstr, i64_rem_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64RemSInstr())), BinaryCode({'\x81'}));
}

TEST(unittest_GenNumericInstr, i64_rem_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64RemUInstr())), BinaryCode({'\x82'}));
}

TEST(unittest_GenNumericInstr, i64_and){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64AndInstr())), BinaryCode({'\x83'}));
}

TEST(unittest_GenNumericInstr, i64_or){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64OrInstr())), BinaryCode({'\x84'}));
}

TEST(unittest_GenNumericInstr, i64_xor){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64XorInstr())), BinaryCode({'\x85'}));
}

TEST(unittest_GenNumericInstr, i64_shl){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64ShlInstr())), BinaryCode({'\x86'}));
}

TEST(unittest_GenNumericInstr, i64_shr_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64ShrSInstr())), BinaryCode({'\x87'}));
}

TEST(unittest_GenNumericInstr, i64_shr_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64ShrUInstr())), BinaryCode({'\x88'}));
}

TEST(unittest_GenNumericInstr, i64_rotl){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64RotlInstr())), BinaryCode({'\x89'}));
}

TEST(unittest_GenNumericInstr, i64_rotr){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64RotrInstr())), BinaryCode({'\x8A'}));
}

TEST(unittest_GenNumericInstr, f32_abs){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32AbsInstr())), BinaryCode({'\x8B'}));
}

TEST(unittest_GenNumericInstr, f32_neg){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32NegInstr())), BinaryCode({'\x8C'}));
}

TEST(unittest_GenNumericInstr, f32_ceil){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32CeilInstr())), BinaryCode({'\x8D'}));
}

TEST(unittest_GenNumericInstr, f32_floor){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32FloorInstr())), BinaryCode({'\x8E'}));
}

TEST(unittest_GenNumericInstr, f32_trunc){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32TruncInstr())), BinaryCode({'\x8F'}));
}

TEST(unittest_GenNumericInstr, f32_nearest){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32NearestInstr())), BinaryCode({'\x90'}));
}

TEST(unittest_GenNumericInstr, f32_sqrt){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32SqrtInstr())), BinaryCode({'\x91'}));
}

TEST(unittest_GenNumericInstr, f32_add){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32AddInstr())), BinaryCode({'\x92'}));
}

TEST(unittest_GenNumericInstr, f32_sub){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32SubInstr())), BinaryCode({'\x93'}));
}

TEST(unittest_GenNumericInstr, f32_mul){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32MulInstr())), BinaryCode({'\x94'}));
}

TEST(unittest_GenNumericInstr, f32_div){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32DivInstr())), BinaryCode({'\x95'}));
}

TEST(unittest_GenNumericInstr, f32_min){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32MinInstr())), BinaryCode({'\x96'}));
}

TEST(unittest_GenNumericInstr, f32_max){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32MaxInstr())), BinaryCode({'\x97'}));
}

TEST(unittest_GenNumericInstr, f32_copysign){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32CopysignInstr())), BinaryCode({'\x98'}));
}

TEST(unittest_GenNumericInstr, f64_abs){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64AbsInstr())), BinaryCode({'\x99'}));
}

TEST(unittest_GenNumericInstr, f64_neg){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64NegInstr())), BinaryCode({'\x9A'}));
}

TEST(unittest_GenNumericInstr, f64_ceil){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64CeilInstr())), BinaryCode({'\x9B'}));
}

TEST(unittest_GenNumericInstr, f64_floor){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64FloorInstr())), BinaryCode({'\x9C'}));
}

TEST(unittest_GenNumericInstr, f64_trunc){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64TruncInstr())), BinaryCode({'\x9D'}));
}

TEST(unittest_GenNumericInstr, f64_nearest){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64NearestInstr())), BinaryCode({'\x9E'}));
}

TEST(unittest_GenNumericInstr, f64_sqrt){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64SqrtInstr())), BinaryCode({'\x9F'}));
}

TEST(unittest_GenNumericInstr, f64_add){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64AddInstr())), BinaryCode({'\xA0'}));
}

TEST(unittest_GenNumericInstr, f64_sub){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64SubInstr())), BinaryCode({'\xA1'}));
}

TEST(unittest_GenNumericInstr, f64_mul){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64MulInstr())), BinaryCode({'\xA2'}));
}

TEST(unittest_GenNumericInstr, f64_div){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64DivInstr())), BinaryCode({'\xA3'}));
}

TEST(unittest_GenNumericInstr, f64_min){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64MinInstr())), BinaryCode({'\xA4'}));
}

TEST(unittest_GenNumericInstr, f64_max){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64MaxInstr())), BinaryCode({'\xA5'}));
}

TEST(unittest_GenNumericInstr, f64_copysign){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64CopysignInstr())), BinaryCode({'\xA6'}));
}

TEST(unittest_GenNumericInstr, i32_eqz){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32EqzInstr())), BinaryCode({'\x45'}));
}

TEST(unittest_GenNumericInstr, i32_eq){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32EqInstr())), BinaryCode({'\x46'}));
}

TEST(unittest_GenNumericInstr, i32_ne){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32NeInstr())), BinaryCode({'\x47'}));
}

TEST(unittest_GenNumericInstr, i32_lt_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32LtSInstr())), BinaryCode({'\x48'}));
}

TEST(unittest_GenNumericInstr, i32_lt_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32LtUInstr())), BinaryCode({'\x49'}));
}

TEST(unittest_GenNumericInstr, i32_gt_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32GtSInstr())), BinaryCode({'\x4A'}));
}

TEST(unittest_GenNumericInstr, i32_gt_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32GtUInstr())), BinaryCode({'\x4B'}));
}

TEST(unittest_GenNumericInstr, i32_le_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32LeSInstr())), BinaryCode({'\x4C'}));
}

TEST(unittest_GenNumericInstr, i32_le_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32LeUInstr())), BinaryCode({'\x4D'}));
}

TEST(unittest_GenNumericInstr, i32_ge_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32GeSInstr())), BinaryCode({'\x4E'}));
}

TEST(unittest_GenNumericInstr, i32_ge_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32GeUInstr())), BinaryCode({'\x4F'}));
}

TEST(unittest_GenNumericInstr, i64_eqz){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64EqzInstr())), BinaryCode({'\x50'}));
}

TEST(unittest_GenNumericInstr, i64_eq){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64EqInstr())), BinaryCode({'\x51'}));
}

TEST(unittest_GenNumericInstr, i64_ne){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64NeInstr())), BinaryCode({'\x52'}));
}

TEST(unittest_GenNumericInstr, i64_lt_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64LtSInstr())), BinaryCode({'\x53'}));
}

TEST(unittest_GenNumericInstr, i64_lt_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64LtUInstr())), BinaryCode({'\x54'}));
}

TEST(unittest_GenNumericInstr, i64_gt_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64GtSInstr())), BinaryCode({'\x55'}));
}

TEST(unittest_GenNumericInstr, i64_gt_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64GtUInstr())), BinaryCode({'\x56'}));
}

TEST(unittest_GenNumericInstr, i64_le_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64LeSInstr())), BinaryCode({'\x57'}));
}

TEST(unittest_GenNumericInstr, i64_le_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64LeUInstr())), BinaryCode({'\x58'}));
}

TEST(unittest_GenNumericInstr, i64_ge_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64GeSInstr())), BinaryCode({'\x59'}));
}

TEST(unittest_GenNumericInstr, i64_ge_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64GeUInstr())), BinaryCode({'\x5A'}));
}

TEST(unittest_GenNumericInstr, f32_eq){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32EqInstr())), BinaryCode({'\x5B'}));
}

TEST(unittest_GenNumericInstr, f32_ne){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32NeInstr())), BinaryCode({'\x5C'}));
}

TEST(unittest_GenNumericInstr, f32_lt){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32LtInstr())), BinaryCode({'\x5D'}));
}

TEST(unittest_GenNumericInstr, f32_gt){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32GtInstr())), BinaryCode({'\x5E'}));
}

TEST(unittest_GenNumericInstr, f32_le){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32LeInstr())), BinaryCode({'\x5F'}));
}

TEST(unittest_GenNumericInstr, f32_ge){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32GeInstr())), BinaryCode({'\x60'}));
}

TEST(unittest_GenNumericInstr, f64_eq){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64EqInstr())), BinaryCode({'\x61'}));
}

TEST(unittest_GenNumericInstr, f64_ne){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64NeInstr())), BinaryCode({'\x62'}));
}

TEST(unittest_GenNumericInstr, f64_lt){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64LtInstr())), BinaryCode({'\x63'}));
}

TEST(unittest_GenNumericInstr, f64_gt){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64GtInstr())), BinaryCode({'\x64'}));
}

TEST(unittest_GenNumericInstr, f64_le){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64LeInstr())), BinaryCode({'\x65'}));
}

TEST(unittest_GenNumericInstr, f64_ge){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64GeInstr())), BinaryCode({'\x66'}));
}

TEST(unittest_GenNumericInstr, i32_wrap_i64){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32WrapI64Instr())), BinaryCode({'\xA7'}));
}

TEST(unittest_GenNumericInstr, i32_trunc_f32_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32TruncF32SInstr())), BinaryCode({'\xA8'}));
}

TEST(unittest_GenNumericInstr, i32_trunc_f32_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32TruncF32UInstr())), BinaryCode({'\xA9'}));
}

TEST(unittest_GenNumericInstr, i32_trunc_f64_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32TruncF64SInstr())), BinaryCode({'\xAA'}));
}

TEST(unittest_GenNumericInstr, i32_trunc_f64_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32TruncF64UInstr())), BinaryCode({'\xAB'}));
}

TEST(unittest_GenNumericInstr, i64_extend_i32_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64ExtendI32SInstr())), BinaryCode({'\xAC'}));
}

TEST(unittest_GenNumericInstr, i64_extend_i32_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64ExtendI32UInstr())), BinaryCode({'\xAD'}));
}

TEST(unittest_GenNumericInstr, i64_trunc_f32_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64TruncF32SInstr())), BinaryCode({'\xAE'}));
}

TEST(unittest_GenNumericInstr, i64_trunc_f32_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64TruncF32UInstr())), BinaryCode({'\xAF'}));
}

TEST(unittest_GenNumericInstr, i64_trunc_f64_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64TruncF64SInstr())), BinaryCode({'\xB0'}));
}

TEST(unittest_GenNumericInstr, i64_trunc_f64_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64TruncF64UInstr())), BinaryCode({'\xB1'}));
}

TEST(unittest_GenNumericInstr, f32_convert_i32_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32ConvertI32SInstr())), BinaryCode({'\xB2'}));
}

TEST(unittest_GenNumericInstr, f32_convert_i32_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32ConvertI32UInstr())), BinaryCode({'\xB3'}));
}

TEST(unittest_GenNumericInstr, f32_convert_i64_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32ConvertI64SInstr())), BinaryCode({'\xB4'}));
}

TEST(unittest_GenNumericInstr, f32_convert_i64_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32ConvertI64UInstr())), BinaryCode({'\xB5'}));
}

TEST(unittest_GenNumericInstr, f32_demote_f64){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32DemoteF64Instr())), BinaryCode({'\xB6'}));
}

TEST(unittest_GenNumericInstr, f64_convert_i32_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64ConvertI32SInstr())), BinaryCode({'\xB7'}));
}

TEST(unittest_GenNumericInstr, f64_convert_i32_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64ConvertI32UInstr())), BinaryCode({'\xB8'}));
}

TEST(unittest_GenNumericInstr, f64_convert_i64_s){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64ConvertI64SInstr())), BinaryCode({'\xB9'}));
}

TEST(unittest_GenNumericInstr, f64_convert_i64_u){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64ConvertI64UInstr())), BinaryCode({'\xBA'}));
}

TEST(unittest_GenNumericInstr, f64_promote_f32){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64PromoteF32Instr())), BinaryCode({'\xBB'}));
}

TEST(unittest_GenNumericInstr, i32_reinterpret_f32){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I32ReinterpretF32Instr())), BinaryCode({'\xBC'}));
}

TEST(unittest_GenNumericInstr, i64_reinterpret_f64){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(I64ReinterpretF64Instr())), BinaryCode({'\xBD'}));
}

TEST(unittest_GenNumericInstr, f32_reinterpret_i32){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F32ReinterpretI32Instr())), BinaryCode({'\xBE'}));
}

TEST(unittest_GenNumericInstr, f64_reinterpret_i64){
  CodeGenVisitor visitor;
  EXPECT_EQ(std::visit<BinaryCode>(visitor, InstrVariant(F64ReinterpretI64Instr())), BinaryCode({'\xBF'}));
}

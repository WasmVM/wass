#include <gtest/gtest.h>

#include <variant>
#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserNumericInstr.hpp>
#include <structure/BaseInstr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserNumericInstr, i32_clz){
  std::vector<char> data(create_char_vector("i32.clz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32ClzInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_ctz){
  std::vector<char> data(create_char_vector("i32.ctz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32CtzInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_add){
  std::vector<char> data(create_char_vector("i32.add"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32AddInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_sub){
  std::vector<char> data(create_char_vector("i32.sub"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32SubInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_mul){
  std::vector<char> data(create_char_vector("i32.mul"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32MulInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_div_s){
  std::vector<char> data(create_char_vector("i32.div_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32DivSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_div_u){
  std::vector<char> data(create_char_vector("i32.div_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32DivUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_rem_s){
  std::vector<char> data(create_char_vector("i32.rem_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32RemSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_rem_u){
  std::vector<char> data(create_char_vector("i32.rem_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32RemUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_and){
  std::vector<char> data(create_char_vector("i32.and"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32AndInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_or){
  std::vector<char> data(create_char_vector("i32.or"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32OrInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_xor){
  std::vector<char> data(create_char_vector("i32.xor"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32XorInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_shl){
  std::vector<char> data(create_char_vector("i32.shl"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32ShlInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_shr_s){
  std::vector<char> data(create_char_vector("i32.shr_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32ShrSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_shr_u){
  std::vector<char> data(create_char_vector("i32.shr_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32ShrUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_rotl){
  std::vector<char> data(create_char_vector("i32.rotl"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32RotlInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_rotr){
  std::vector<char> data(create_char_vector("i32.rotr"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32RotrInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_clz){
  std::vector<char> data(create_char_vector("i64.clz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64ClzInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_ctz){
  std::vector<char> data(create_char_vector("i64.ctz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64CtzInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_add){
  std::vector<char> data(create_char_vector("i64.add"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64AddInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_sub){
  std::vector<char> data(create_char_vector("i64.sub"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64SubInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_mul){
  std::vector<char> data(create_char_vector("i64.mul"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64MulInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_div_s){
  std::vector<char> data(create_char_vector("i64.div_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64DivSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_div_u){
  std::vector<char> data(create_char_vector("i64.div_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64DivUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_rem_s){
  std::vector<char> data(create_char_vector("i64.rem_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64RemSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_rem_u){
  std::vector<char> data(create_char_vector("i64.rem_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64RemUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_and){
  std::vector<char> data(create_char_vector("i64.and"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64AndInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_or){
  std::vector<char> data(create_char_vector("i64.or"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64OrInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_xor){
  std::vector<char> data(create_char_vector("i64.xor"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64XorInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_shl){
  std::vector<char> data(create_char_vector("i64.shl"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64ShlInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_shr_s){
  std::vector<char> data(create_char_vector("i64.shr_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64ShrSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_shr_u){
  std::vector<char> data(create_char_vector("i64.shr_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64ShrUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_rotl){
  std::vector<char> data(create_char_vector("i64.rotl"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64RotlInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_rotr){
  std::vector<char> data(create_char_vector("i64.rotr"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64RotrInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_abs){
  std::vector<char> data(create_char_vector("f32.abs"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32AbsInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_neg){
  std::vector<char> data(create_char_vector("f32.neg"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32NegInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_ceil){
  std::vector<char> data(create_char_vector("f32.ceil"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32CeilInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_floor){
  std::vector<char> data(create_char_vector("f32.floor"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32FloorInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_trunc){
  std::vector<char> data(create_char_vector("f32.trunc"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32TruncInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_nearest){
  std::vector<char> data(create_char_vector("f32.nearest"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32NearestInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_sqrt){
  std::vector<char> data(create_char_vector("f32.sqrt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32SqrtInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_add){
  std::vector<char> data(create_char_vector("f32.add"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32AddInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_sub){
  std::vector<char> data(create_char_vector("f32.sub"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32SubInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_mul){
  std::vector<char> data(create_char_vector("f32.mul"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32MulInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_div){
  std::vector<char> data(create_char_vector("f32.div"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32DivInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_min){
  std::vector<char> data(create_char_vector("f32.min"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32MinInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_max){
  std::vector<char> data(create_char_vector("f32.max"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32MaxInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_copysign){
  std::vector<char> data(create_char_vector("f32.copysign"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32CopysignInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_abs){
  std::vector<char> data(create_char_vector("f64.abs"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64AbsInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_neg){
  std::vector<char> data(create_char_vector("f64.neg"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64NegInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_ceil){
  std::vector<char> data(create_char_vector("f64.ceil"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64CeilInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_floor){
  std::vector<char> data(create_char_vector("f64.floor"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64FloorInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_trunc){
  std::vector<char> data(create_char_vector("f64.trunc"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64TruncInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_nearest){
  std::vector<char> data(create_char_vector("f64.nearest"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64NearestInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_sqrt){
  std::vector<char> data(create_char_vector("f64.sqrt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64SqrtInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_add){
  std::vector<char> data(create_char_vector("f64.add"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64AddInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_sub){
  std::vector<char> data(create_char_vector("f64.sub"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64SubInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_mul){
  std::vector<char> data(create_char_vector("f64.mul"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64MulInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_div){
  std::vector<char> data(create_char_vector("f64.div"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64DivInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_min){
  std::vector<char> data(create_char_vector("f64.min"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64MinInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_max){
  std::vector<char> data(create_char_vector("f64.max"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64MaxInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_copysign){
  std::vector<char> data(create_char_vector("f64.copysign"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64CopysignInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_eqz){
  std::vector<char> data(create_char_vector("i32.eqz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32EqzInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_eq){
  std::vector<char> data(create_char_vector("i32.eq"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32EqInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_ne){
  std::vector<char> data(create_char_vector("i32.ne"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32NeInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_lt_s){
  std::vector<char> data(create_char_vector("i32.lt_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32LtSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_lt_u){
  std::vector<char> data(create_char_vector("i32.lt_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32LtUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_gt_s){
  std::vector<char> data(create_char_vector("i32.gt_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32GtSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_gt_u){
  std::vector<char> data(create_char_vector("i32.gt_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32GtUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_le_s){
  std::vector<char> data(create_char_vector("i32.le_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32LeSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_le_u){
  std::vector<char> data(create_char_vector("i32.le_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32LeUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_ge_s){
  std::vector<char> data(create_char_vector("i32.ge_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32GeSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_ge_u){
  std::vector<char> data(create_char_vector("i32.ge_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32GeUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_eqz){
  std::vector<char> data(create_char_vector("i64.eqz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64EqzInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_eq){
  std::vector<char> data(create_char_vector("i64.eq"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64EqInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_ne){
  std::vector<char> data(create_char_vector("i64.ne"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64NeInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_lt_s){
  std::vector<char> data(create_char_vector("i64.lt_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64LtSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_lt_u){
  std::vector<char> data(create_char_vector("i64.lt_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64LtUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_gt_s){
  std::vector<char> data(create_char_vector("i64.gt_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64GtSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_gt_u){
  std::vector<char> data(create_char_vector("i64.gt_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64GtUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_le_s){
  std::vector<char> data(create_char_vector("i64.le_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64LeSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_le_u){
  std::vector<char> data(create_char_vector("i64.le_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64LeUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_ge_s){
  std::vector<char> data(create_char_vector("i64.ge_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64GeSInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_ge_u){
  std::vector<char> data(create_char_vector("i64.ge_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64GeUInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_eq){
  std::vector<char> data(create_char_vector("f32.eq"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32EqInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_ne){
  std::vector<char> data(create_char_vector("f32.ne"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32NeInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_lt){
  std::vector<char> data(create_char_vector("f32.lt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32LtInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_gt){
  std::vector<char> data(create_char_vector("f32.gt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32GtInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_le){
  std::vector<char> data(create_char_vector("f32.le"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32LeInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_ge){
  std::vector<char> data(create_char_vector("f32.ge"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32GeInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_eq){
  std::vector<char> data(create_char_vector("f64.eq"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64EqInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_ne){
  std::vector<char> data(create_char_vector("f64.ne"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64NeInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_lt){
  std::vector<char> data(create_char_vector("f64.lt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64LtInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_gt){
  std::vector<char> data(create_char_vector("f64.gt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64GtInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_le){
  std::vector<char> data(create_char_vector("f64.le"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64LeInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_ge){
  std::vector<char> data(create_char_vector("f64.ge"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64GeInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_wrap_i64){
  std::vector<char> data(create_char_vector("i32.wrap_i64"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32WrapI64Instr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_trunc_f32_s){
  std::vector<char> data(create_char_vector("i32.trunc_f32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32TruncF32SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_trunc_f32_u){
  std::vector<char> data(create_char_vector("i32.trunc_f32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32TruncF32UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_trunc_f64_s){
  std::vector<char> data(create_char_vector("i32.trunc_f64_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32TruncF64SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_trunc_f64_u){
  std::vector<char> data(create_char_vector("i32.trunc_f64_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32TruncF64UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_trunc_f32_s){
  std::vector<char> data(create_char_vector("i64.trunc_f32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64TruncF32SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_trunc_f32_u){
  std::vector<char> data(create_char_vector("i64.trunc_f32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64TruncF32UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_trunc_f64_s){
  std::vector<char> data(create_char_vector("i64.trunc_f64_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64TruncF64SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_trunc_f64_u){
  std::vector<char> data(create_char_vector("i64.trunc_f64_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64TruncF64UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_extend_i32_s){
  std::vector<char> data(create_char_vector("i64.extend_i32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64ExtendI32SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_extend_i32_u){
  std::vector<char> data(create_char_vector("i64.extend_i32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64ExtendI32UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_convert_i32_s){
  std::vector<char> data(create_char_vector("f32.convert_i32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32ConvertI32SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_convert_i32_u){
  std::vector<char> data(create_char_vector("f32.convert_i32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32ConvertI32UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_convert_i64_s){
  std::vector<char> data(create_char_vector("f32.convert_i64_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32ConvertI64SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_convert_i64_u){
  std::vector<char> data(create_char_vector("f32.convert_i64_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32ConvertI64UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_convert_i32_s){
  std::vector<char> data(create_char_vector("f64.convert_i32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64ConvertI32SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_convert_i32_u){
  std::vector<char> data(create_char_vector("f64.convert_i32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64ConvertI32UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_convert_i64_s){
  std::vector<char> data(create_char_vector("f64.convert_i64_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64ConvertI64SInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_convert_i64_u){
  std::vector<char> data(create_char_vector("f64.convert_i64_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64ConvertI64UInstr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_demote_f64){
  std::vector<char> data(create_char_vector("f32.demote_f64"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32DemoteF64Instr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_promote_f32){
  std::vector<char> data(create_char_vector("f64.promote_f32"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64PromoteF32Instr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i32_reinterpret_f32){
  std::vector<char> data(create_char_vector("i32.reinterpret_f32"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I32ReinterpretF32Instr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, i64_reinterpret_f64){
  std::vector<char> data(create_char_vector("i64.reinterpret_f64"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<I64ReinterpretF64Instr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f32_reinterpret_i32){
  std::vector<char> data(create_char_vector("f32.reinterpret_i32"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F32ReinterpretI32Instr>(&result), nullptr);
}

TEST(unittest_ParserNumericInstr, f64_reinterpret_i64){
  std::vector<char> data(create_char_vector("f64.reinterpret_i64"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_NE(std::get_if<F64ReinterpretI64Instr>(&result), nullptr);
}
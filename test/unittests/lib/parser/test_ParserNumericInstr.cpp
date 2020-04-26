#include <gtest/gtest.h>

#include <vector>
#include <Error.hpp>
#include <parser/ParserContext.hpp>
#include <parser/ParserNumericInstr.hpp>
#include <structure/Instr.hpp>
#include <Helper.hpp>

TEST(unittest_ParserNumericInstr, i32_clz){
  std::vector<char> data(create_char_vector("i32.clz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Clz>));
}

TEST(unittest_ParserNumericInstr, i32_ctz){
  std::vector<char> data(create_char_vector("i32.ctz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Ctz>));
}

TEST(unittest_ParserNumericInstr, i32_add){
  std::vector<char> data(create_char_vector("i32.add"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Add>));
}

TEST(unittest_ParserNumericInstr, i32_sub){
  std::vector<char> data(create_char_vector("i32.sub"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Sub>));
}

TEST(unittest_ParserNumericInstr, i32_mul){
  std::vector<char> data(create_char_vector("i32.mul"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Mul>));
}

TEST(unittest_ParserNumericInstr, i32_div_s){
  std::vector<char> data(create_char_vector("i32.div_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32DivS>));
}

TEST(unittest_ParserNumericInstr, i32_div_u){
  std::vector<char> data(create_char_vector("i32.div_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32DivU>));
}

TEST(unittest_ParserNumericInstr, i32_rem_s){
  std::vector<char> data(create_char_vector("i32.rem_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32RemS>));
}

TEST(unittest_ParserNumericInstr, i32_rem_u){
  std::vector<char> data(create_char_vector("i32.rem_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32RemU>));
}

TEST(unittest_ParserNumericInstr, i32_and){
  std::vector<char> data(create_char_vector("i32.and"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32And>));
}

TEST(unittest_ParserNumericInstr, i32_or){
  std::vector<char> data(create_char_vector("i32.or"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Or>));
}

TEST(unittest_ParserNumericInstr, i32_xor){
  std::vector<char> data(create_char_vector("i32.xor"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Xor>));
}

TEST(unittest_ParserNumericInstr, i32_shl){
  std::vector<char> data(create_char_vector("i32.shl"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Shl>));
}

TEST(unittest_ParserNumericInstr, i32_shr_s){
  std::vector<char> data(create_char_vector("i32.shr_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32ShrS>));
}

TEST(unittest_ParserNumericInstr, i32_shr_u){
  std::vector<char> data(create_char_vector("i32.shr_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32ShrU>));
}

TEST(unittest_ParserNumericInstr, i32_rotl){
  std::vector<char> data(create_char_vector("i32.rotl"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Rotl>));
}

TEST(unittest_ParserNumericInstr, i32_rotr){
  std::vector<char> data(create_char_vector("i32.rotr"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Rotr>));
}

TEST(unittest_ParserNumericInstr, i64_clz){
  std::vector<char> data(create_char_vector("i64.clz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Clz>));
}

TEST(unittest_ParserNumericInstr, i64_ctz){
  std::vector<char> data(create_char_vector("i64.ctz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Ctz>));
}

TEST(unittest_ParserNumericInstr, i64_add){
  std::vector<char> data(create_char_vector("i64.add"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Add>));
}

TEST(unittest_ParserNumericInstr, i64_sub){
  std::vector<char> data(create_char_vector("i64.sub"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Sub>));
}

TEST(unittest_ParserNumericInstr, i64_mul){
  std::vector<char> data(create_char_vector("i64.mul"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Mul>));
}

TEST(unittest_ParserNumericInstr, i64_div_s){
  std::vector<char> data(create_char_vector("i64.div_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64DivS>));
}

TEST(unittest_ParserNumericInstr, i64_div_u){
  std::vector<char> data(create_char_vector("i64.div_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64DivU>));
}

TEST(unittest_ParserNumericInstr, i64_rem_s){
  std::vector<char> data(create_char_vector("i64.rem_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64RemS>));
}

TEST(unittest_ParserNumericInstr, i64_rem_u){
  std::vector<char> data(create_char_vector("i64.rem_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64RemU>));
}

TEST(unittest_ParserNumericInstr, i64_and){
  std::vector<char> data(create_char_vector("i64.and"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64And>));
}

TEST(unittest_ParserNumericInstr, i64_or){
  std::vector<char> data(create_char_vector("i64.or"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Or>));
}

TEST(unittest_ParserNumericInstr, i64_xor){
  std::vector<char> data(create_char_vector("i64.xor"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Xor>));
}

TEST(unittest_ParserNumericInstr, i64_shl){
  std::vector<char> data(create_char_vector("i64.shl"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Shl>));
}

TEST(unittest_ParserNumericInstr, i64_shr_s){
  std::vector<char> data(create_char_vector("i64.shr_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64ShrS>));
}

TEST(unittest_ParserNumericInstr, i64_shr_u){
  std::vector<char> data(create_char_vector("i64.shr_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64ShrU>));
}

TEST(unittest_ParserNumericInstr, i64_rotl){
  std::vector<char> data(create_char_vector("i64.rotl"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Rotl>));
}

TEST(unittest_ParserNumericInstr, i64_rotr){
  std::vector<char> data(create_char_vector("i64.rotr"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Rotr>));
}

TEST(unittest_ParserNumericInstr, f32_abs){
  std::vector<char> data(create_char_vector("f32.abs"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Abs>));
}

TEST(unittest_ParserNumericInstr, f32_neg){
  std::vector<char> data(create_char_vector("f32.neg"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Neg>));
}

TEST(unittest_ParserNumericInstr, f32_ceil){
  std::vector<char> data(create_char_vector("f32.ceil"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Ceil>));
}

TEST(unittest_ParserNumericInstr, f32_floor){
  std::vector<char> data(create_char_vector("f32.floor"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Floor>));
}

TEST(unittest_ParserNumericInstr, f32_trunc){
  std::vector<char> data(create_char_vector("f32.trunc"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Trunc>));
}

TEST(unittest_ParserNumericInstr, f32_nearest){
  std::vector<char> data(create_char_vector("f32.nearest"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Nearest>));
}

TEST(unittest_ParserNumericInstr, f32_sqrt){
  std::vector<char> data(create_char_vector("f32.sqrt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Sqrt>));
}

TEST(unittest_ParserNumericInstr, f32_add){
  std::vector<char> data(create_char_vector("f32.add"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Add>));
}

TEST(unittest_ParserNumericInstr, f32_sub){
  std::vector<char> data(create_char_vector("f32.sub"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Sub>));
}

TEST(unittest_ParserNumericInstr, f32_mul){
  std::vector<char> data(create_char_vector("f32.mul"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Mul>));
}

TEST(unittest_ParserNumericInstr, f32_div){
  std::vector<char> data(create_char_vector("f32.div"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Div>));
}

TEST(unittest_ParserNumericInstr, f32_min){
  std::vector<char> data(create_char_vector("f32.min"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Min>));
}

TEST(unittest_ParserNumericInstr, f32_max){
  std::vector<char> data(create_char_vector("f32.max"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Max>));
}

TEST(unittest_ParserNumericInstr, f32_copysign){
  std::vector<char> data(create_char_vector("f32.copysign"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Copysign>));
}

TEST(unittest_ParserNumericInstr, f64_abs){
  std::vector<char> data(create_char_vector("f64.abs"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Abs>));
}

TEST(unittest_ParserNumericInstr, f64_neg){
  std::vector<char> data(create_char_vector("f64.neg"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Neg>));
}

TEST(unittest_ParserNumericInstr, f64_ceil){
  std::vector<char> data(create_char_vector("f64.ceil"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Ceil>));
}

TEST(unittest_ParserNumericInstr, f64_floor){
  std::vector<char> data(create_char_vector("f64.floor"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Floor>));
}

TEST(unittest_ParserNumericInstr, f64_trunc){
  std::vector<char> data(create_char_vector("f64.trunc"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Trunc>));
}

TEST(unittest_ParserNumericInstr, f64_nearest){
  std::vector<char> data(create_char_vector("f64.nearest"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Nearest>));
}

TEST(unittest_ParserNumericInstr, f64_sqrt){
  std::vector<char> data(create_char_vector("f64.sqrt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Sqrt>));
}

TEST(unittest_ParserNumericInstr, f64_add){
  std::vector<char> data(create_char_vector("f64.add"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Add>));
}

TEST(unittest_ParserNumericInstr, f64_sub){
  std::vector<char> data(create_char_vector("f64.sub"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Sub>));
}

TEST(unittest_ParserNumericInstr, f64_mul){
  std::vector<char> data(create_char_vector("f64.mul"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Mul>));
}

TEST(unittest_ParserNumericInstr, f64_div){
  std::vector<char> data(create_char_vector("f64.div"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Div>));
}

TEST(unittest_ParserNumericInstr, f64_min){
  std::vector<char> data(create_char_vector("f64.min"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Min>));
}

TEST(unittest_ParserNumericInstr, f64_max){
  std::vector<char> data(create_char_vector("f64.max"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Max>));
}

TEST(unittest_ParserNumericInstr, f64_copysign){
  std::vector<char> data(create_char_vector("f64.copysign"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Copysign>));
}

TEST(unittest_ParserNumericInstr, i32_eqz){
  std::vector<char> data(create_char_vector("i32.eqz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Eqz>));
}

TEST(unittest_ParserNumericInstr, i32_eq){
  std::vector<char> data(create_char_vector("i32.eq"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Eq>));
}

TEST(unittest_ParserNumericInstr, i32_ne){
  std::vector<char> data(create_char_vector("i32.ne"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32Ne>));
}

TEST(unittest_ParserNumericInstr, i32_lt_s){
  std::vector<char> data(create_char_vector("i32.lt_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32LtS>));
}

TEST(unittest_ParserNumericInstr, i32_lt_u){
  std::vector<char> data(create_char_vector("i32.lt_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32LtU>));
}

TEST(unittest_ParserNumericInstr, i32_gt_s){
  std::vector<char> data(create_char_vector("i32.gt_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32GtS>));
}

TEST(unittest_ParserNumericInstr, i32_gt_u){
  std::vector<char> data(create_char_vector("i32.gt_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32GtU>));
}

TEST(unittest_ParserNumericInstr, i32_le_s){
  std::vector<char> data(create_char_vector("i32.le_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32LeS>));
}

TEST(unittest_ParserNumericInstr, i32_le_u){
  std::vector<char> data(create_char_vector("i32.le_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32LeU>));
}

TEST(unittest_ParserNumericInstr, i32_ge_s){
  std::vector<char> data(create_char_vector("i32.ge_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32GeS>));
}

TEST(unittest_ParserNumericInstr, i32_ge_u){
  std::vector<char> data(create_char_vector("i32.ge_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32GeU>));
}

TEST(unittest_ParserNumericInstr, i64_eqz){
  std::vector<char> data(create_char_vector("i64.eqz"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Eqz>));
}

TEST(unittest_ParserNumericInstr, i64_eq){
  std::vector<char> data(create_char_vector("i64.eq"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Eq>));
}

TEST(unittest_ParserNumericInstr, i64_ne){
  std::vector<char> data(create_char_vector("i64.ne"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64Ne>));
}

TEST(unittest_ParserNumericInstr, i64_lt_s){
  std::vector<char> data(create_char_vector("i64.lt_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64LtS>));
}

TEST(unittest_ParserNumericInstr, i64_lt_u){
  std::vector<char> data(create_char_vector("i64.lt_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64LtU>));
}

TEST(unittest_ParserNumericInstr, i64_gt_s){
  std::vector<char> data(create_char_vector("i64.gt_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64GtS>));
}

TEST(unittest_ParserNumericInstr, i64_gt_u){
  std::vector<char> data(create_char_vector("i64.gt_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64GtU>));
}

TEST(unittest_ParserNumericInstr, i64_le_s){
  std::vector<char> data(create_char_vector("i64.le_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64LeS>));
}

TEST(unittest_ParserNumericInstr, i64_le_u){
  std::vector<char> data(create_char_vector("i64.le_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64LeU>));
}

TEST(unittest_ParserNumericInstr, i64_ge_s){
  std::vector<char> data(create_char_vector("i64.ge_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64GeS>));
}

TEST(unittest_ParserNumericInstr, i64_ge_u){
  std::vector<char> data(create_char_vector("i64.ge_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64GeU>));
}

TEST(unittest_ParserNumericInstr, f32_eq){
  std::vector<char> data(create_char_vector("f32.eq"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Eq>));
}

TEST(unittest_ParserNumericInstr, f32_ne){
  std::vector<char> data(create_char_vector("f32.ne"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Ne>));
}

TEST(unittest_ParserNumericInstr, f32_lt){
  std::vector<char> data(create_char_vector("f32.lt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Lt>));
}

TEST(unittest_ParserNumericInstr, f32_gt){
  std::vector<char> data(create_char_vector("f32.gt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Gt>));
}

TEST(unittest_ParserNumericInstr, f32_le){
  std::vector<char> data(create_char_vector("f32.le"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Le>));
}

TEST(unittest_ParserNumericInstr, f32_ge){
  std::vector<char> data(create_char_vector("f32.ge"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32Ge>));
}

TEST(unittest_ParserNumericInstr, f64_eq){
  std::vector<char> data(create_char_vector("f64.eq"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Eq>));
}

TEST(unittest_ParserNumericInstr, f64_ne){
  std::vector<char> data(create_char_vector("f64.ne"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Ne>));
}

TEST(unittest_ParserNumericInstr, f64_lt){
  std::vector<char> data(create_char_vector("f64.lt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Lt>));
}

TEST(unittest_ParserNumericInstr, f64_gt){
  std::vector<char> data(create_char_vector("f64.gt"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Gt>));
}

TEST(unittest_ParserNumericInstr, f64_le){
  std::vector<char> data(create_char_vector("f64.le"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Le>));
}

TEST(unittest_ParserNumericInstr, f64_ge){
  std::vector<char> data(create_char_vector("f64.ge"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64Ge>));
}

TEST(unittest_ParserNumericInstr, i32_wrap_i64){
  std::vector<char> data(create_char_vector("i32.wrap_i64"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32WrapI64>));
}

TEST(unittest_ParserNumericInstr, i32_trunc_f32_s){
  std::vector<char> data(create_char_vector("i32.trunc_f32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32TruncF32S>));
}

TEST(unittest_ParserNumericInstr, i32_trunc_f32_u){
  std::vector<char> data(create_char_vector("i32.trunc_f32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32TruncF32U>));
}

TEST(unittest_ParserNumericInstr, i32_trunc_f64_s){
  std::vector<char> data(create_char_vector("i32.trunc_f64_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32TruncF64S>));
}

TEST(unittest_ParserNumericInstr, i32_trunc_f64_u){
  std::vector<char> data(create_char_vector("i32.trunc_f64_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32TruncF64U>));
}

TEST(unittest_ParserNumericInstr, i64_trunc_f32_s){
  std::vector<char> data(create_char_vector("i64.trunc_f32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64TruncF32S>));
}

TEST(unittest_ParserNumericInstr, i64_trunc_f32_u){
  std::vector<char> data(create_char_vector("i64.trunc_f32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64TruncF32U>));
}

TEST(unittest_ParserNumericInstr, i64_trunc_f64_s){
  std::vector<char> data(create_char_vector("i64.trunc_f64_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64TruncF64S>));
}

TEST(unittest_ParserNumericInstr, i64_trunc_f64_u){
  std::vector<char> data(create_char_vector("i64.trunc_f64_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64TruncF64U>));
}

TEST(unittest_ParserNumericInstr, i64_extend_i32_s){
  std::vector<char> data(create_char_vector("i64.extend_i32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64ExtendI32S>));
}

TEST(unittest_ParserNumericInstr, i64_extend_i32_u){
  std::vector<char> data(create_char_vector("i64.extend_i32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64ExtendI32U>));
}

TEST(unittest_ParserNumericInstr, f32_convert_i32_s){
  std::vector<char> data(create_char_vector("f32.convert_i32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32ConvertI32S>));
}

TEST(unittest_ParserNumericInstr, f32_convert_i32_u){
  std::vector<char> data(create_char_vector("f32.convert_i32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32ConvertI32U>));
}

TEST(unittest_ParserNumericInstr, f32_convert_i64_s){
  std::vector<char> data(create_char_vector("f32.convert_i64_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32ConvertI64S>));
}

TEST(unittest_ParserNumericInstr, f32_convert_i64_u){
  std::vector<char> data(create_char_vector("f32.convert_i64_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32ConvertI64U>));
}

TEST(unittest_ParserNumericInstr, f64_convert_i32_s){
  std::vector<char> data(create_char_vector("f64.convert_i32_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64ConvertI32S>));
}

TEST(unittest_ParserNumericInstr, f64_convert_i32_u){
  std::vector<char> data(create_char_vector("f64.convert_i32_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64ConvertI32U>));
}

TEST(unittest_ParserNumericInstr, f64_convert_i64_s){
  std::vector<char> data(create_char_vector("f64.convert_i64_s"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64ConvertI64S>));
}

TEST(unittest_ParserNumericInstr, f64_convert_i64_u){
  std::vector<char> data(create_char_vector("f64.convert_i64_u"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64ConvertI64U>));
}

TEST(unittest_ParserNumericInstr, f32_demote_f64){
  std::vector<char> data(create_char_vector("f32.demote_f64"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32DemoteF64>));
}

TEST(unittest_ParserNumericInstr, f64_promote_f32){
  std::vector<char> data(create_char_vector("f64.promote_f32"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64PromoteF32>));
}

TEST(unittest_ParserNumericInstr, i32_reinterpret_f32){
  std::vector<char> data(create_char_vector("i32.reinterpret_f32"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I32ReinterpretF32>));
}

TEST(unittest_ParserNumericInstr, i64_reinterpret_f64){
  std::vector<char> data(create_char_vector("i64.reinterpret_f64"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::I64ReinterpretF64>));
}

TEST(unittest_ParserNumericInstr, f32_reinterpret_i32){
  std::vector<char> data(create_char_vector("f32.reinterpret_i32"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F32ReinterpretI32>));
}

TEST(unittest_ParserNumericInstr, f64_reinterpret_i64){
  std::vector<char> data(create_char_vector("f64.reinterpret_i64"));
  ParserContext context(data);
  ParserNumericInstr result(context);
  EXPECT_EQ(context.cursor, data.end());
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(result.type(), typeid(Instr<InstrType::F64ReinterpretI64>));
}
#ifndef GUARD_wass_structure_NumericInstr
#define GUARD_wass_structure_NumericInstr

#include <structure/BaseInstr.hpp>

using I32ClzInstr = BaseInstr<InstrType::I32Clz>;
using I32CtzInstr = BaseInstr<InstrType::I32Ctz>;
using I32PopcntInstr = BaseInstr<InstrType::I32Popcnt>;
using I32AddInstr = BaseInstr<InstrType::I32Add>;
using I32SubInstr = BaseInstr<InstrType::I32Sub>;
using I32MulInstr = BaseInstr<InstrType::I32Mul>;
using I32DivSInstr = BaseInstr<InstrType::I32DivS>;
using I32DivUInstr = BaseInstr<InstrType::I32DivU>;
using I32RemSInstr = BaseInstr<InstrType::I32RemS>;
using I32RemUInstr = BaseInstr<InstrType::I32RemU>;
using I32AndInstr = BaseInstr<InstrType::I32And>;
using I32OrInstr = BaseInstr<InstrType::I32Or>;
using I32XorInstr = BaseInstr<InstrType::I32Xor>;
using I32ShlInstr = BaseInstr<InstrType::I32Shl>;
using I32ShrSInstr = BaseInstr<InstrType::I32ShrS>;
using I32ShrUInstr = BaseInstr<InstrType::I32ShrU>;
using I32RotlInstr = BaseInstr<InstrType::I32Rotl>;
using I32RotrInstr = BaseInstr<InstrType::I32Rotr>;
using I64ClzInstr = BaseInstr<InstrType::I64Clz>;
using I64CtzInstr = BaseInstr<InstrType::I64Ctz>;
using I64PopcntInstr = BaseInstr<InstrType::I64Popcnt>;
using I64AddInstr = BaseInstr<InstrType::I64Add>;
using I64SubInstr = BaseInstr<InstrType::I64Sub>;
using I64MulInstr = BaseInstr<InstrType::I64Mul>;
using I64DivSInstr = BaseInstr<InstrType::I64DivS>;
using I64DivUInstr = BaseInstr<InstrType::I64DivU>;
using I64RemSInstr = BaseInstr<InstrType::I64RemS>;
using I64RemUInstr = BaseInstr<InstrType::I64RemU>;
using I64AndInstr = BaseInstr<InstrType::I64And>;
using I64OrInstr = BaseInstr<InstrType::I64Or>;
using I64XorInstr = BaseInstr<InstrType::I64Xor>;
using I64ShlInstr = BaseInstr<InstrType::I64Shl>;
using I64ShrSInstr = BaseInstr<InstrType::I64ShrS>;
using I64ShrUInstr = BaseInstr<InstrType::I64ShrU>;
using I64RotlInstr = BaseInstr<InstrType::I64Rotl>;
using I64RotrInstr = BaseInstr<InstrType::I64Rotr>;
using F32AbsInstr = BaseInstr<InstrType::F32Abs>;
using F32NegInstr = BaseInstr<InstrType::F32Neg>;
using F32CeilInstr = BaseInstr<InstrType::F32Ceil>;
using F32FloorInstr = BaseInstr<InstrType::F32Floor>;
using F32TruncInstr = BaseInstr<InstrType::F32Trunc>;
using F32NearestInstr = BaseInstr<InstrType::F32Nearest>;
using F32SqrtInstr = BaseInstr<InstrType::F32Sqrt>;
using F32AddInstr = BaseInstr<InstrType::F32Add>;
using F32SubInstr = BaseInstr<InstrType::F32Sub>;
using F32MulInstr = BaseInstr<InstrType::F32Mul>; 
using F32DivInstr = BaseInstr<InstrType::F32Div>;
using F32MinInstr = BaseInstr<InstrType::F32Min>;
using F32MaxInstr = BaseInstr<InstrType::F32Max>;
using F32CopysignInstr = BaseInstr<InstrType::F32Copysign>;
using F64AbsInstr = BaseInstr<InstrType::F64Abs>;
using F64NegInstr = BaseInstr<InstrType::F64Neg>;
using F64CeilInstr = BaseInstr<InstrType::F64Ceil>;
using F64FloorInstr = BaseInstr<InstrType::F64Floor>;
using F64TruncInstr = BaseInstr<InstrType::F64Trunc>;
using F64NearestInstr = BaseInstr<InstrType::F64Nearest>;
using F64SqrtInstr = BaseInstr<InstrType::F64Sqrt>;
using F64AddInstr = BaseInstr<InstrType::F64Add>;
using F64SubInstr = BaseInstr<InstrType::F64Sub>;
using F64MulInstr = BaseInstr<InstrType::F64Mul>; 
using F64DivInstr = BaseInstr<InstrType::F64Div>;
using F64MinInstr = BaseInstr<InstrType::F64Min>;
using F64MaxInstr = BaseInstr<InstrType::F64Max>;
using F64CopysignInstr = BaseInstr<InstrType::F64Copysign>;
using I32EqzInstr = BaseInstr<InstrType::I32Eqz>;
using I32EqInstr = BaseInstr<InstrType::I32Eq>;
using I32NeInstr = BaseInstr<InstrType::I32Ne>;
using I32LtSInstr = BaseInstr<InstrType::I32LtS>;
using I32LtUInstr = BaseInstr<InstrType::I32LtU>;
using I32GtSInstr = BaseInstr<InstrType::I32GtS>;
using I32GtUInstr = BaseInstr<InstrType::I32GtU>;
using I32LeSInstr = BaseInstr<InstrType::I32LeS>;
using I32LeUInstr = BaseInstr<InstrType::I32LeU>;
using I32GeSInstr = BaseInstr<InstrType::I32GeS>;
using I32GeUInstr = BaseInstr<InstrType::I32GeU>;
using I64EqzInstr = BaseInstr<InstrType::I64Eqz>;
using I64EqInstr = BaseInstr<InstrType::I64Eq>;
using I64NeInstr = BaseInstr<InstrType::I64Ne>;
using I64LtSInstr = BaseInstr<InstrType::I64LtS>;
using I64LtUInstr = BaseInstr<InstrType::I64LtU>;
using I64GtSInstr = BaseInstr<InstrType::I64GtS>;
using I64GtUInstr = BaseInstr<InstrType::I64GtU>;
using I64LeSInstr = BaseInstr<InstrType::I64LeS>;
using I64LeUInstr = BaseInstr<InstrType::I64LeU>;
using I64GeSInstr = BaseInstr<InstrType::I64GeS>;
using I64GeUInstr = BaseInstr<InstrType::I64GeU>;
using F32EqInstr = BaseInstr<InstrType::F32Eq>;
using F32NeInstr = BaseInstr<InstrType::F32Ne>;
using F32LtInstr = BaseInstr<InstrType::F32Lt>;
using F32GtInstr = BaseInstr<InstrType::F32Gt>;
using F32LeInstr = BaseInstr<InstrType::F32Le>;
using F32GeInstr = BaseInstr<InstrType::F32Ge>;
using F64EqInstr = BaseInstr<InstrType::F64Eq>;
using F64NeInstr = BaseInstr<InstrType::F64Ne>;
using F64LtInstr = BaseInstr<InstrType::F64Lt>;
using F64GtInstr = BaseInstr<InstrType::F64Gt>;
using F64LeInstr = BaseInstr<InstrType::F64Le>;
using F64GeInstr = BaseInstr<InstrType::F64Ge>;
using I32WrapI64Instr = BaseInstr<InstrType::I32WrapI64>;
using I32TruncF32SInstr = BaseInstr<InstrType::I32TruncF32S>;
using I32TruncF32UInstr = BaseInstr<InstrType::I32TruncF32U>;
using I32TruncF64SInstr = BaseInstr<InstrType::I32TruncF64S>;
using I32TruncF64UInstr = BaseInstr<InstrType::I32TruncF64U>;
using I64ExtendI32SInstr = BaseInstr<InstrType::I64ExtendI32S>;
using I64ExtendI32UInstr = BaseInstr<InstrType::I64ExtendI32U>;
using I64TruncF32SInstr = BaseInstr<InstrType::I64TruncF32S>;
using I64TruncF32UInstr = BaseInstr<InstrType::I64TruncF32U>;
using I64TruncF64SInstr = BaseInstr<InstrType::I64TruncF64S>;
using I64TruncF64UInstr = BaseInstr<InstrType::I64TruncF64U>;
using F32ConvertI32SInstr = BaseInstr<InstrType::F32ConvertI32S>;
using F32ConvertI32UInstr = BaseInstr<InstrType::F32ConvertI32U>;
using F32ConvertI64SInstr = BaseInstr<InstrType::F32ConvertI64S>;
using F32ConvertI64UInstr = BaseInstr<InstrType::F32ConvertI64U>;
using F32DemoteF64Instr = BaseInstr<InstrType::F32DemoteF64>;
using F64ConvertI32SInstr = BaseInstr<InstrType::F64ConvertI32S>;
using F64ConvertI32UInstr = BaseInstr<InstrType::F64ConvertI32U>;
using F64ConvertI64SInstr = BaseInstr<InstrType::F64ConvertI64S>;
using F64ConvertI64UInstr = BaseInstr<InstrType::F64ConvertI64U>;
using F64PromoteF32Instr = BaseInstr<InstrType::F64PromoteF32>;
using I32ReinterpretF32Instr = BaseInstr<InstrType::I32ReinterpretF32>;
using I64ReinterpretF64Instr = BaseInstr<InstrType::I64ReinterpretF64>;
using F32ReinterpretI32Instr = BaseInstr<InstrType::F32ReinterpretI32>;
using F64ReinterpretI64Instr = BaseInstr<InstrType::F64ReinterpretI64>;

#endif
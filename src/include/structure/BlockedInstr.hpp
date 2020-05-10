#ifndef GUARD_wass_structure_BlockedInstr
#define GUARD_wass_structure_BlockedInstr

#include <vector>
#include <variant>
#include <string>
#include <optional>
#include <structure/Value.hpp>
#include <structure/BaseInstr.hpp>
#include <structure/ConstInstr.hpp>
#include <structure/ControlInstr.hpp>
#include <structure/MemoryInstr.hpp>
#include <structure/NumericInstr.hpp>
#include <structure/ParamInstr.hpp>
#include <structure/VariableInstr.hpp>


template<InstrType T> class BlockedInstr;

class IfInstr;

using InstrVariant = std::variant<
  std::monostate,
  BlockedInstr<InstrType::Block>,
  BlockedInstr<InstrType::Loop>,
  IfInstr,
  UnreachableInstr,
  NopInstr,
  BrInstr,
  BrIfInstr,
  BrTableInstr,
  ReturnInstr,
  CallInstr,
  CallIndirectInstr,
  DropInstr,
  SelectInstr,
  LocalGetInstr,
  LocalSetInstr,
  LocalTeeInstr,
  GlobalGetInstr,
  GlobalSetInstr,
  I32LoadInstr,
  I32Load8SInstr,
  I32Load8UInstr,
  I32Load16SInstr,
  I32Load16UInstr,
  I32StoreInstr,
  I32Store8Instr,
  I32Store16Instr,
  I64LoadInstr,
  I64Load8SInstr,
  I64Load8UInstr,
  I64Load16SInstr,
  I64Load16UInstr,
  I64Load32SInstr,
  I64Load32UInstr,
  I64StoreInstr,
  I64Store8Instr,
  I64Store16Instr,
  I64Store32Instr,
  F32LoadInstr,
  F32StoreInstr,
  F64LoadInstr,
  F64StoreInstr,
  MemorySizeInstr,
  MemoryGrowInstr,
  I32ConstInstr,
  I64ConstInstr,
  F32ConstInstr,
  F64ConstInstr,
  I32ClzInstr,
  I32CtzInstr,
  I32PopcntInstr,
  I32AddInstr,
  I32SubInstr,
  I32MulInstr,
  I32DivSInstr,
  I32DivUInstr,
  I32RemSInstr,
  I32RemUInstr,
  I32AndInstr,
  I32OrInstr,
  I32XorInstr,
  I32ShlInstr,
  I32ShrSInstr,
  I32ShrUInstr,
  I32RotlInstr,
  I32RotrInstr,
  I64ClzInstr,
  I64CtzInstr,
  I64PopcntInstr,
  I64AddInstr,
  I64SubInstr,
  I64MulInstr,
  I64DivSInstr,
  I64DivUInstr,
  I64RemSInstr,
  I64RemUInstr,
  I64AndInstr,
  I64OrInstr,
  I64XorInstr,
  I64ShlInstr,
  I64ShrSInstr,
  I64ShrUInstr,
  I64RotlInstr,
  I64RotrInstr,
  F32AbsInstr,
  F32NegInstr,
  F32CeilInstr,
  F32FloorInstr,
  F32TruncInstr,
  F32NearestInstr,
  F32SqrtInstr,
  F32AddInstr,
  F32SubInstr,
  F32MulInstr,
  F32DivInstr,
  F32MinInstr,
  F32MaxInstr,
  F32CopysignInstr,
  F64AbsInstr,
  F64NegInstr,
  F64CeilInstr,
  F64FloorInstr,
  F64TruncInstr,
  F64NearestInstr,
  F64SqrtInstr,
  F64AddInstr,
  F64SubInstr,
  F64MulInstr,
  F64DivInstr,
  F64MinInstr,
  F64MaxInstr,
  F64CopysignInstr,
  I32EqzInstr,
  I32EqInstr,
  I32NeInstr,
  I32LtSInstr,
  I32LtUInstr,
  I32GtSInstr,
  I32GtUInstr,
  I32LeSInstr,
  I32LeUInstr,
  I32GeSInstr,
  I32GeUInstr,
  I64EqzInstr,
  I64EqInstr,
  I64NeInstr,
  I64LtSInstr,
  I64LtUInstr,
  I64GtSInstr,
  I64GtUInstr,
  I64LeSInstr,
  I64LeUInstr,
  I64GeSInstr,
  I64GeUInstr,
  F32EqInstr,
  F32NeInstr,
  F32LtInstr,
  F32GtInstr,
  F32LeInstr,
  F32GeInstr,
  F64EqInstr,
  F64NeInstr,
  F64LtInstr,
  F64GtInstr,
  F64LeInstr,
  F64GeInstr,
  I32WrapI64Instr,
  I32TruncF32SInstr,
  I32TruncF32UInstr,
  I32TruncF64SInstr,
  I32TruncF64UInstr,
  I64ExtendI32SInstr,
  I64ExtendI32UInstr,
  I64TruncF32SInstr,
  I64TruncF32UInstr,
  I64TruncF64SInstr,
  I64TruncF64UInstr,
  F32ConvertI32SInstr,
  F32ConvertI32UInstr,
  F32ConvertI64SInstr,
  F32ConvertI64UInstr,
  F32DemoteF64Instr,
  F64ConvertI32SInstr,
  F64ConvertI32UInstr,
  F64ConvertI64SInstr,
  F64ConvertI64UInstr,
  F64PromoteF32Instr,
  I32ReinterpretF32Instr,
  I64ReinterpretF64Instr,
  F32ReinterpretI32Instr,
  F64ReinterpretI64Instr
>;

template<InstrType T>
class BlockedInstr: public BaseInstr<T>{
public:
  std::optional<std::string> id;
  std::vector<ValueType> resultTypes;
  std::vector<InstrVariant> instrs;
};

class IfInstr: public BlockedInstr<InstrType::If>{
public:
  std::vector<InstrVariant> elseInstrs;
};

using BlockInstr = BlockedInstr<InstrType::Block>;
using LoopInstr = BlockedInstr<InstrType::Loop>;

#endif
#ifndef GUARD_wass_structure_MemoryInstr
#define GUARD_wass_structure_MemoryInstr

#include <cstdint>
#include <structure/BaseInstr.hpp>

template<InstrType T>
class MemoryInstr: public BaseInstr<T>{
public:
  int64_t align;
  int64_t offset;
};

using I32LoadInstr = MemoryInstr<InstrType::I32Load>;
using I32Load8SInstr = MemoryInstr<InstrType::I32Load8S>;
using I32Load8UInstr = MemoryInstr<InstrType::I32Load8U>;
using I32Load16SInstr = MemoryInstr<InstrType::I32Load16S>;
using I32Load16UInstr = MemoryInstr<InstrType::I32Load16U>;
using I32StoreInstr = MemoryInstr<InstrType::I32Store>;
using I32Store8Instr = MemoryInstr<InstrType::I32Store8>;
using I32Store16Instr = MemoryInstr<InstrType::I32Store16>;
using I64LoadInstr = MemoryInstr<InstrType::I64Load>;
using I64Load8SInstr = MemoryInstr<InstrType::I64Load8S>;
using I64Load8UInstr = MemoryInstr<InstrType::I64Load8U>;
using I64Load16SInstr = MemoryInstr<InstrType::I64Load16S>;
using I64Load16UInstr = MemoryInstr<InstrType::I64Load16U>;
using I64Load32SInstr = MemoryInstr<InstrType::I64Load32S>;
using I64Load32UInstr = MemoryInstr<InstrType::I64Load32U>;
using I64StoreInstr = MemoryInstr<InstrType::I64Store>;
using I64Store8Instr = MemoryInstr<InstrType::I64Store8>;
using I64Store16Instr = MemoryInstr<InstrType::I64Store16>;
using I64Store32Instr = MemoryInstr<InstrType::I64Store32>;
using F32LoadInstr = MemoryInstr<InstrType::F32Load>;
using F32StoreInstr = MemoryInstr<InstrType::F32Store>;
using F64LoadInstr = MemoryInstr<InstrType::F64Load>;
using F64StoreInstr = MemoryInstr<InstrType::F64Store>;
using MemorySizeInstr = MemoryInstr<InstrType::MemorySize>;
using MemoryGrowInstr = MemoryInstr<InstrType::MemoryGrow>;

#endif
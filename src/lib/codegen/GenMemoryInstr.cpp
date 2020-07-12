#include <codegen/CodeGenVisitor.hpp>

#include <structure/MemoryInstr.hpp>
#include <Util.hpp>

#define GenMemoryInstr(InstrType,OpCode) \
BinaryCode CodeGenVisitor::operator()(InstrType&& target){ \
  return BinaryCode({OpCode}) + Util::toLEB128((uint32_t) target.align) + Util::toLEB128((uint32_t) target.offset); \
}

GenMemoryInstr(I32LoadInstr, '\x28');
GenMemoryInstr(I32Load8SInstr, '\x2C');
GenMemoryInstr(I32Load8UInstr, '\x2D');
GenMemoryInstr(I32Load16SInstr, '\x2E');
GenMemoryInstr(I32Load16UInstr, '\x2F');
GenMemoryInstr(I32StoreInstr, '\x36');
GenMemoryInstr(I32Store8Instr, '\x3A');
GenMemoryInstr(I32Store16Instr, '\x3B');
GenMemoryInstr(I64LoadInstr, '\x29');
GenMemoryInstr(I64Load8SInstr, '\x30');
GenMemoryInstr(I64Load8UInstr, '\x31');
GenMemoryInstr(I64Load16SInstr, '\x32');
GenMemoryInstr(I64Load16UInstr, '\x33');
GenMemoryInstr(I64Load32SInstr, '\x34');
GenMemoryInstr(I64Load32UInstr, '\x35');
GenMemoryInstr(I64StoreInstr, '\x37');
GenMemoryInstr(I64Store8Instr, '\x3C');
GenMemoryInstr(I64Store16Instr, '\x3D');
GenMemoryInstr(I64Store32Instr, '\x3E');
GenMemoryInstr(F32LoadInstr, '\x2A');
GenMemoryInstr(F32StoreInstr, '\x38');
GenMemoryInstr(F64LoadInstr, '\x2B');
GenMemoryInstr(F64StoreInstr, '\x39');

BinaryCode CodeGenVisitor::operator()(MemorySizeInstr&& target){
  return BinaryCode({'\x3F', '\x00'});
}

BinaryCode CodeGenVisitor::operator()(MemoryGrowInstr&& target){
  return BinaryCode({'\x40', '\x00'});
}
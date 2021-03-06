#include <codegen/CodeGenVisitor.hpp>

#include <structure/NumericInstr.hpp>

#define GenNumericInstr(InstrType,OpCode) \
BinaryCode CodeGenVisitor::operator()(InstrType&&){ \
  return BinaryCode({ OpCode }); \
}

GenNumericInstr(I32ClzInstr, '\x67');
GenNumericInstr(I32CtzInstr, '\x68');
GenNumericInstr(I32PopcntInstr, '\x69');
GenNumericInstr(I32AddInstr, '\x6A');
GenNumericInstr(I32SubInstr, '\x6B');
GenNumericInstr(I32MulInstr, '\x6C');
GenNumericInstr(I32DivSInstr, '\x6D');
GenNumericInstr(I32DivUInstr, '\x6E');
GenNumericInstr(I32RemSInstr, '\x6F');
GenNumericInstr(I32RemUInstr, '\x70');
GenNumericInstr(I32AndInstr, '\x71');
GenNumericInstr(I32OrInstr, '\x72');
GenNumericInstr(I32XorInstr, '\x73');
GenNumericInstr(I32ShlInstr, '\x74');
GenNumericInstr(I32ShrSInstr, '\x75');
GenNumericInstr(I32ShrUInstr, '\x76');
GenNumericInstr(I32RotlInstr, '\x77');
GenNumericInstr(I32RotrInstr, '\x78');
GenNumericInstr(I64ClzInstr, '\x79');
GenNumericInstr(I64CtzInstr, '\x7A');
GenNumericInstr(I64PopcntInstr, '\x7B');
GenNumericInstr(I64AddInstr, '\x7C');
GenNumericInstr(I64SubInstr, '\x7D');
GenNumericInstr(I64MulInstr, '\x7E');
GenNumericInstr(I64DivSInstr, '\x7F');
GenNumericInstr(I64DivUInstr, '\x80');
GenNumericInstr(I64RemSInstr, '\x81');
GenNumericInstr(I64RemUInstr, '\x82');
GenNumericInstr(I64AndInstr, '\x83');
GenNumericInstr(I64OrInstr, '\x84');
GenNumericInstr(I64XorInstr, '\x85');
GenNumericInstr(I64ShlInstr, '\x86');
GenNumericInstr(I64ShrSInstr, '\x87');
GenNumericInstr(I64ShrUInstr, '\x88');
GenNumericInstr(I64RotlInstr, '\x89');
GenNumericInstr(I64RotrInstr, '\x8A');
GenNumericInstr(F32AbsInstr, '\x8B');
GenNumericInstr(F32NegInstr, '\x8C');
GenNumericInstr(F32CeilInstr, '\x8D');
GenNumericInstr(F32FloorInstr, '\x8E');
GenNumericInstr(F32TruncInstr, '\x8F');
GenNumericInstr(F32NearestInstr, '\x90');
GenNumericInstr(F32SqrtInstr, '\x91');
GenNumericInstr(F32AddInstr, '\x92');
GenNumericInstr(F32SubInstr, '\x93');
GenNumericInstr(F32MulInstr, '\x94');
GenNumericInstr(F32DivInstr, '\x95');
GenNumericInstr(F32MinInstr, '\x96');
GenNumericInstr(F32MaxInstr, '\x97');
GenNumericInstr(F32CopysignInstr, '\x98');
GenNumericInstr(F64AbsInstr, '\x99');
GenNumericInstr(F64NegInstr, '\x9A');
GenNumericInstr(F64CeilInstr, '\x9B');
GenNumericInstr(F64FloorInstr, '\x9C');
GenNumericInstr(F64TruncInstr, '\x9D');
GenNumericInstr(F64NearestInstr, '\x9E');
GenNumericInstr(F64SqrtInstr, '\x9F');
GenNumericInstr(F64AddInstr, '\xA0');
GenNumericInstr(F64SubInstr, '\xA1');
GenNumericInstr(F64MulInstr, '\xA2');
GenNumericInstr(F64DivInstr, '\xA3');
GenNumericInstr(F64MinInstr, '\xA4');
GenNumericInstr(F64MaxInstr, '\xA5');
GenNumericInstr(F64CopysignInstr, '\xA6');
GenNumericInstr(I32EqzInstr, '\x45');
GenNumericInstr(I32EqInstr, '\x46');
GenNumericInstr(I32NeInstr, '\x47');
GenNumericInstr(I32LtSInstr, '\x48');
GenNumericInstr(I32LtUInstr, '\x49');
GenNumericInstr(I32GtSInstr, '\x4A');
GenNumericInstr(I32GtUInstr, '\x4B');
GenNumericInstr(I32LeSInstr, '\x4C');
GenNumericInstr(I32LeUInstr, '\x4D');
GenNumericInstr(I32GeSInstr, '\x4E');
GenNumericInstr(I32GeUInstr, '\x4F');
GenNumericInstr(I64EqzInstr, '\x50');
GenNumericInstr(I64EqInstr, '\x51');
GenNumericInstr(I64NeInstr, '\x52');
GenNumericInstr(I64LtSInstr, '\x53');
GenNumericInstr(I64LtUInstr, '\x54');
GenNumericInstr(I64GtSInstr, '\x55');
GenNumericInstr(I64GtUInstr, '\x56');
GenNumericInstr(I64LeSInstr, '\x57');
GenNumericInstr(I64LeUInstr, '\x58');
GenNumericInstr(I64GeSInstr, '\x59');
GenNumericInstr(I64GeUInstr, '\x5A');
GenNumericInstr(F32EqInstr, '\x5B');
GenNumericInstr(F32NeInstr, '\x5C');
GenNumericInstr(F32LtInstr, '\x5D');
GenNumericInstr(F32GtInstr, '\x5E');
GenNumericInstr(F32LeInstr, '\x5F');
GenNumericInstr(F32GeInstr, '\x60');
GenNumericInstr(F64EqInstr, '\x61');
GenNumericInstr(F64NeInstr, '\x62');
GenNumericInstr(F64LtInstr, '\x63');
GenNumericInstr(F64GtInstr, '\x64');
GenNumericInstr(F64LeInstr, '\x65');
GenNumericInstr(F64GeInstr, '\x66');
GenNumericInstr(I32WrapI64Instr, '\xA7');
GenNumericInstr(I32TruncF32SInstr, '\xA8');
GenNumericInstr(I32TruncF32UInstr, '\xA9');
GenNumericInstr(I32TruncF64SInstr, '\xAA');
GenNumericInstr(I32TruncF64UInstr, '\xAB');
GenNumericInstr(I64ExtendI32SInstr, '\xAC');
GenNumericInstr(I64ExtendI32UInstr, '\xAD');
GenNumericInstr(I64TruncF32SInstr, '\xAE');
GenNumericInstr(I64TruncF32UInstr, '\xAF');
GenNumericInstr(I64TruncF64SInstr, '\xB0');
GenNumericInstr(I64TruncF64UInstr, '\xB1');
GenNumericInstr(F32ConvertI32SInstr, '\xB2');
GenNumericInstr(F32ConvertI32UInstr, '\xB3');
GenNumericInstr(F32ConvertI64SInstr, '\xB4');
GenNumericInstr(F32ConvertI64UInstr, '\xB5');
GenNumericInstr(F32DemoteF64Instr, '\xB6');
GenNumericInstr(F64ConvertI32SInstr, '\xB7');
GenNumericInstr(F64ConvertI32UInstr, '\xB8');
GenNumericInstr(F64ConvertI64SInstr, '\xB9');
GenNumericInstr(F64ConvertI64UInstr, '\xBA');
GenNumericInstr(F64PromoteF32Instr, '\xBB');
GenNumericInstr(I32ReinterpretF32Instr, '\xBC');
GenNumericInstr(I64ReinterpretF64Instr, '\xBD');
GenNumericInstr(F32ReinterpretI32Instr, '\xBE');
GenNumericInstr(F64ReinterpretI64Instr, '\xBF');

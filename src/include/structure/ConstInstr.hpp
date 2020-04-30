#ifndef GUARD_wass_structure_ConstInstr
#define GUARD_wass_structure_ConstInstr

#include <cstdint>
#include <structure/Instr.hpp>

class I32ConstInstr: public Instr<InstrType::I32Const>{
public:
  I32ConstInstr(int32_t value);
  int32_t value;
};

class I64ConstInstr: public Instr<InstrType::I64Const>{
public:
  I64ConstInstr(int64_t value);
  int64_t value;
};

class F32ConstInstr: public Instr<InstrType::F32Const>{
public:
  F32ConstInstr(float value);
  float value;
};

class F64ConstInstr: public Instr<InstrType::F64Const>{
public:
  F64ConstInstr(double value);
  double value;
};

#endif
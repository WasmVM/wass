#ifndef GUARD_wass_structure_ControlInstr
#define GUARD_wass_structure_ControlInstr

#include <vector>
#include <cstdint>
#include <structure/Instr.hpp>
#include <structure/TypeUse.hpp>

class BrInstr: public Instr<InstrType::Br>{
public:
  BrInstr(uint32_t label);
  uint32_t label;
};

class BrIfInstr: public Instr<InstrType::BrIf>{
public:
  BrIfInstr(uint32_t label);
  uint32_t label;
};

class BrTableInstr: public Instr<InstrType::BrTable>{
public:
  BrTableInstr() = default;
  BrTableInstr(std::vector<uint32_t>& labels);
  std::vector<uint32_t> labels;
};

class CallInstr: public Instr<InstrType::Call>{
public:
  CallInstr(uint32_t funcidx);
  uint32_t funcidx;
};

class CallIndirectInstr: public Instr<InstrType::CallIndirect>{
public:
  CallIndirectInstr() = default;
  CallIndirectInstr(TypeUse& type);
  TypeUse type;
};

#endif
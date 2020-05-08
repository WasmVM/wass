#ifndef GUARD_wass_structure_ControlInstr
#define GUARD_wass_structure_ControlInstr

#include <vector>
#include <cstdint>
#include <structure/BaseInstr.hpp>
#include <structure/TypeUse.hpp>

using UnreachableInstr = BaseInstr<InstrType::Unreachable>;
using NopInstr = BaseInstr<InstrType::Nop>;
using ReturnInstr = BaseInstr<InstrType::Return>;

class BrInstr: public BaseInstr<InstrType::Br>{
public:
  BrInstr(uint32_t label);
  uint32_t label;
};

class BrIfInstr: public BaseInstr<InstrType::BrIf>{
public:
  BrIfInstr(uint32_t label);
  uint32_t label;
};

class BrTableInstr: public BaseInstr<InstrType::BrTable>{
public:
  BrTableInstr() = default;
  BrTableInstr(std::vector<uint32_t>& labels);
  std::vector<uint32_t> labels;
};

class CallInstr: public BaseInstr<InstrType::Call>{
public:
  CallInstr(uint32_t funcidx);
  uint32_t funcidx;
};

class CallIndirectInstr: public BaseInstr<InstrType::CallIndirect>{
public:
  CallIndirectInstr() = default;
  CallIndirectInstr(TypeUse& type);
  TypeUse type;
};

#endif
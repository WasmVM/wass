#ifndef GUARD_wass_structure_ControlInstr
#define GUARD_wass_structure_ControlInstr

#include <vector>
#include <cstdint>
#include <structure/BaseInstr.hpp>
#include <structure/TypeUse.hpp>
#include <structure/Index.hpp>

using UnreachableInstr = BaseInstr<InstrType::Unreachable>;
using NopInstr = BaseInstr<InstrType::Nop>;
using ReturnInstr = BaseInstr<InstrType::Return>;

class BrInstr: public BaseInstr<InstrType::Br>{
public:
  BrInstr(Index label);
  Index label;
};

class BrIfInstr: public BaseInstr<InstrType::BrIf>{
public:
  BrIfInstr(Index label);
  Index label;
};

class BrTableInstr: public BaseInstr<InstrType::BrTable>{
public:
  BrTableInstr() = default;
  BrTableInstr(std::vector<Index>& labels);
  std::vector<Index> labels;
};

class CallInstr: public BaseInstr<InstrType::Call>{
public:
  CallInstr(Index funcidx);
  Index funcidx;
};

class CallIndirectInstr: public BaseInstr<InstrType::CallIndirect>{
public:
  CallIndirectInstr() = default;
  CallIndirectInstr(TypeUse& type);
  TypeUse type;
};

#endif
#ifndef GUARD_wass_structure_VariableInstr
#define GUARD_wass_structure_VariableInstr

#include <cstdint>
#include <structure/BaseInstr.hpp>
#include <structure/Index.hpp>

template<InstrType T>
class VariableInstr: public BaseInstr<T>{
public:
  Index index;
};

using LocalGetInstr = VariableInstr<InstrType::LocalGet>;
using LocalSetInstr = VariableInstr<InstrType::LocalSet>;
using LocalTeeInstr = VariableInstr<InstrType::LocalTee>;
using GlobalGetInstr = VariableInstr<InstrType::GlobalGet>;
using GlobalSetInstr = VariableInstr<InstrType::GlobalSet>;

#endif
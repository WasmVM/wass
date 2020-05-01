#ifndef GUARD_wass_structure_VariableInstr
#define GUARD_wass_structure_VariableInstr

#include <cstdint>
#include <structure/Instr.hpp>

template<InstrType T>
class VariableInstr: public Instr<T>{
public:
  int32_t index;
};

#endif
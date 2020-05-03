#ifndef GUARD_wass_structure_MemoryInstr
#define GUARD_wass_structure_MemoryInstr

#include <cstdint>
#include <structure/Instr.hpp>

template<InstrType T>
class MemoryInstr: public Instr<T>{
public:
  int64_t align;
  int64_t offset;
};

#endif
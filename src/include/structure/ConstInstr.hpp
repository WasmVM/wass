#ifndef GUARD_wass_structure_ConstInstr
#define GUARD_wass_structure_ConstInstr

#include <variant>
#include <cstdint>
#include <structure/BaseInstr.hpp>

template<InstrType T, typename V>
class ConstInstr: public BaseInstr<T>{
public:
  V value;
};

using I32ConstInstr = ConstInstr<InstrType::I32Const, int32_t>;
using I64ConstInstr = ConstInstr<InstrType::I64Const, int64_t>;
using F32ConstInstr = ConstInstr<InstrType::F32Const, float>;
using F64ConstInstr = ConstInstr<InstrType::F64Const, double>;

#endif
#ifndef GUARD_wass_structure_Value
#define GUARD_wass_structure_Value

#include <cstdint>

namespace Value {

enum ValueType{
  i32,
  i64,
  f32,
  f64,
};

class ValueBase {
public:
  ValueType type;
};

template<typename T, ValueType V>
class ValueClass : ValueBase{
  ValueClass(T value) : type(V), value(value){};
  T value;
};

using Int32 = ValueClass<int32_t, i32>;
using Int64 = ValueClass<int64_t, i64>;
using Float32 = ValueClass<float, f32>;
using Float64 = ValueClass<double, f64>;

}

#endif
#ifndef GUARD_wass_structure_Value
#define GUARD_wass_structure_Value

#include <cstdint>

namespace Value {

enum class ValueType{
  i32,
  i64,
  f32,
  f64,
};

class ValueBase {
public:
  ValueBase(ValueType type): type(type){};
  ValueType type;
};

template<typename T, ValueType V>
class ValueClass : public ValueBase {
public:
  ValueClass(T value) : ValueBase(V), value(value){};
  T value;
};

using Int32 = ValueClass<int32_t, ValueType::i32>;
using Int64 = ValueClass<int64_t, ValueType::i64>;
using Float32 = ValueClass<float, ValueType::f32>;
using Float64 = ValueClass<double, ValueType::f64>;

}

#endif
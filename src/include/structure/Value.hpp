#ifndef GUARD_wass_structure_Value
#define GUARD_wass_structure_Value

#include <any>
#include <cstdint>

enum ValueType{
  none,
  i32,
  i64,
  f32,
  f64,
};

class Value : public std::any {
public:
  Value() = default;
  explicit Value(int32_t value);
  explicit Value(int64_t value);
  explicit Value(float value);
  explicit Value(double value);
  ValueType type();
};

#endif
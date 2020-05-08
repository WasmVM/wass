#include <structure/Value.hpp>

#include <variant>

Value::Value(){
  emplace<std::monostate>();
}
Value::Value(int32_t value){
  emplace<int32_t>(value);
}
Value::Value(int64_t value){
  emplace<int64_t>(value);
}
Value::Value(float value){
  emplace<float>(value);
}
Value::Value(double value){
  emplace<double>(value);
}
ValueType Value::type(){
  if(std::get_if<int32_t>(this) != nullptr){
    return ValueType::i32;
  }else if(std::get_if<int64_t>(this) != nullptr){
    return ValueType::i64;
  }else if(std::get_if<float>(this) != nullptr){
    return ValueType::f32;
  }else if(std::get_if<double>(this) != nullptr){
    return ValueType::f64;
  }else{
    return ValueType::none;
  }
}
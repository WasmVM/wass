#include <structure/Value.hpp>

Value::Value(int32_t value){
  this->std::any::operator=(value);
}
Value::Value(int64_t value){
  this->std::any::operator=(value);
}
Value::Value(float value){
  this->std::any::operator=(value);
}
Value::Value(double value){
  this->std::any::operator=(value);
}
ValueType Value::type(){
  if(this->std::any::type() == typeid(int32_t)){
    return ValueType::i32;
  }else if(this->std::any::type() == typeid(int64_t)){
    return ValueType::i64;
  }else if(this->std::any::type() == typeid(float)){
    return ValueType::f32;
  }else if(this->std::any::type() == typeid(double)){
    return ValueType::f64;
  }else{
    return ValueType::none;
  }
}
#include <structure/GlobalType.hpp>

GlobalType::GlobalType():
  type(ValueType::none), immutable(true){
}

GlobalType::GlobalType(ValueType type, bool immutable):
  type(type), immutable(immutable){
}
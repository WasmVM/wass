#include <structure/ConstInstr.hpp>

#include <cstdint>

I32ConstInstr::I32ConstInstr(int32_t value):value(value){
}

I64ConstInstr::I64ConstInstr(int64_t value):value(value){
}

F32ConstInstr::F32ConstInstr(float value):value(value){
}

F64ConstInstr::F64ConstInstr(double value):value(value){
}
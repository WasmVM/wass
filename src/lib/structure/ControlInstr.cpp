#include <structure/ControlInstr.hpp>

#include <cstdint>
#include <structure/TypeUse.hpp>

BrInstr::BrInstr(uint32_t label):label(label){
}

BrIfInstr::BrIfInstr(uint32_t label):label(label){
}

BrTableInstr::BrTableInstr(std::vector<uint32_t>& labels):labels(labels){
}

CallInstr::CallInstr(uint32_t funcidx):funcidx(funcidx){
}

CallIndirectInstr::CallIndirectInstr(TypeUse& type):type(type){
}
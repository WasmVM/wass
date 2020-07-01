#include <structure/ControlInstr.hpp>

#include <cstdint>
#include <structure/TypeUse.hpp>

BrInstr::BrInstr(Index label):label(label){
}

BrIfInstr::BrIfInstr(Index label):label(label){
}

BrTableInstr::BrTableInstr(std::vector<Index>& labels):labels(labels){
}

CallInstr::CallInstr(Index funcidx):funcidx(funcidx){
}

CallIndirectInstr::CallIndirectInstr(TypeUse& type):type(type){
}
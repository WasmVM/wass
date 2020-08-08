#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/ControlInstr.hpp>
#include <Util.hpp>

BinaryCode CodeGenVisitor::operator()(UnreachableInstr&&){
  return BinaryCode({'\x00'});
}
BinaryCode CodeGenVisitor::operator()(NopInstr&&){
  return BinaryCode({'\x01'});
}
BinaryCode CodeGenVisitor::operator()(ReturnInstr&&){
  return BinaryCode({'\x0F'});
}
BinaryCode CodeGenVisitor::operator()(BrInstr&& instr){
  return BinaryCode({'\x0C'}) + std::visit<BinaryCode>(*this, CodeGenVariant(instr.label));
}
BinaryCode CodeGenVisitor::operator()(BrIfInstr&& instr){
  return BinaryCode({'\x0D'}) + std::visit<BinaryCode>(*this, CodeGenVariant(instr.label));
}
BinaryCode CodeGenVisitor::operator()(BrTableInstr&& instr){
  BinaryCode result({'\x0E'});
  if(instr.labels.size() > 1){
    result += Util::toLEB128((uint32_t)instr.labels.size() - 1);
  }
  for(std::vector<Index>::iterator it = instr.labels.begin(); it != instr.labels.end(); it = std::next(it)){
    result += std::visit<BinaryCode>(*this, CodeGenVariant(*it));
  }
  return result;
}
BinaryCode CodeGenVisitor::operator()(CallInstr&& instr){
  return BinaryCode({'\x10'}) + std::visit<BinaryCode>(*this, CodeGenVariant(instr.funcidx));
}
BinaryCode CodeGenVisitor::operator()(CallIndirectInstr&& instr){
  return BinaryCode({'\x11'}) + std::visit<BinaryCode>(*this, CodeGenVariant(instr.type)) + '\x00';
}
BinaryCode CodeGenVisitor::operator()(BlockInstr&& instr){
  BinaryCode result({'\x02'});
  if(instr.blockType.has_value()){
    result += std::visit<BinaryCode>(*this, BlockType(*(instr.blockType)));
  }else{
    result += '\x40';
  }
  for(std::vector<InstrVariant>::iterator it = instr.instrs.begin(); it != instr.instrs.end(); it = std::next(it)){
    result += std::visit<BinaryCode>(*this, InstrVariant(*it));
  }
  return result + '\x0B';
}
BinaryCode CodeGenVisitor::operator()(LoopInstr&& instr){
  BinaryCode result({'\x03'});
  if(instr.blockType.has_value()){
    result += std::visit<BinaryCode>(*this, BlockType(*(instr.blockType)));
  }else{
    result += '\x40';
  }
  for(std::vector<InstrVariant>::iterator it = instr.instrs.begin(); it != instr.instrs.end(); it = std::next(it)){
    result += std::visit<BinaryCode>(*this, InstrVariant(*it));
  }
  return result + '\x0B';
}
BinaryCode CodeGenVisitor::operator()(IfInstr&& instr){
  BinaryCode result;
  for(std::vector<InstrVariant>::iterator it = instr.foldedInstrs.begin(); it != instr.foldedInstrs.end(); it = std::next(it)){
    result += std::visit<BinaryCode>(*this, InstrVariant(*it));
  }
  result += '\x04';
  if(instr.blockType.has_value()){
    result += std::visit<BinaryCode>(*this, BlockType(*(instr.blockType)));
  }else{
    result += '\x40';
  }
  for(std::vector<InstrVariant>::iterator it = instr.instrs.begin(); it != instr.instrs.end(); it = std::next(it)){
    result += std::visit<BinaryCode>(*this, InstrVariant(*it));
  }
  if(instr.elseInstrs.size() > 0){
    result += '\x05';
    for(std::vector<InstrVariant>::iterator it = instr.elseInstrs.begin(); it != instr.elseInstrs.end(); it = std::next(it)){
      result += std::visit<BinaryCode>(*this, InstrVariant(*it));
    }
  }
  return result + '\x0B';
}

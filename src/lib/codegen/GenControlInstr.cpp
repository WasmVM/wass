#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/ControlInstr.hpp>
#include <Util.hpp>
#include <Error.hpp>

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
  BinaryCode result({'\x0C'});
  if(std::holds_alternative<std::string>(instr.label)){
    std::string& index = std::get<std::string>(instr.label);
    if(context.identifierMap.contains(index)){
      result += Util::toLEB128(context.blockDepth - context.identifierMap[index] - 1);
    }else{
      throw Error<ErrorType::GenerateError>("identifier should be declared before use as index");
    }
  }else{
    result += std::visit<BinaryCode>(*this, CodeGenVariant(instr.label));
  }
  return result;
}
BinaryCode CodeGenVisitor::operator()(BrIfInstr&& instr){
  BinaryCode result({'\x0D'});
  if(std::holds_alternative<std::string>(instr.label)){
    std::string& index = std::get<std::string>(instr.label);
    if(context.identifierMap.contains(index)){
      result += Util::toLEB128(context.blockDepth - context.identifierMap[index] - 1);
    }else{
      throw Error<ErrorType::GenerateError>("identifier should be declared before use as index");
    }
  }else{
    result += std::visit<BinaryCode>(*this, CodeGenVariant(instr.label));
  }
  return result;
}
BinaryCode CodeGenVisitor::operator()(BrTableInstr&& instr){
  BinaryCode result({'\x0E'});
  if(instr.labels.size() > 1){
    result += Util::toLEB128((uint32_t)instr.labels.size() - 1);
  }
  for(std::vector<Index>::iterator it = instr.labels.begin(); it != instr.labels.end(); it = std::next(it)){
    if(std::holds_alternative<std::string>(*it)){
      std::string& index = std::get<std::string>(*it);
      if(context.identifierMap.contains(index)){
        result += Util::toLEB128(context.blockDepth - context.identifierMap[index] - 1);
      }else{
        throw Error<ErrorType::GenerateError>("identifier should be declared before use as index");
      }
    }else{
      result += std::visit<BinaryCode>(*this, CodeGenVariant(*it));
    }
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
  if(instr.label.has_value()){
    context.identifierMap[*(instr.label)] = context.blockDepth;
  }
  ++context.blockDepth;
  for(std::vector<InstrVariant>::iterator it = instr.instrs.begin(); it != instr.instrs.end(); it = std::next(it)){
    result += std::visit<BinaryCode>(*this, InstrVariant(*it));
  }
  --context.blockDepth;
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

#include <parser/ParserParamInstr.hpp>

#include <Util.hpp>
#include <structure/Instr.hpp>

ParserParamInstr::ParserParamInstr(ParserContext& context){
  if(Util::matchString(context.cursor, context.end, "select")){
    context.cursor += 6;
    this->std::any::operator=(Instr<InstrType::Select>());
  }else if(Util::matchString(context.cursor, context.end, "drop")){
    context.cursor += 4;
    this->std::any::operator=(Instr<InstrType::Drop>());
  }
}

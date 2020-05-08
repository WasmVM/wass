#include <parser/ParserParamInstr.hpp>

#include <Util.hpp>
#include <structure/BaseInstr.hpp>

ParserParamInstr::ParserParamInstr(ParserContext& context){
  if(Util::matchString(context.cursor, context.end, "select")){
    context.cursor += 6;
    emplace<SelectInstr>(SelectInstr());
  }else if(Util::matchString(context.cursor, context.end, "drop")){
    context.cursor += 4;
    emplace<DropInstr>(DropInstr());
  }
}

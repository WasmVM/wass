#include <parser/ParserValueType.hpp>

#include <Util.hpp>

ParserValueType::ParserValueType(ParserContext& context){
  if(Util::matchString(context.cursor, context.end, "i32")){
    context.cursor += 3;
    std::any::operator=(ValueType::i32);
  }else if(Util::matchString(context.cursor, context.end, "i64")){
    context.cursor += 3;
    std::any::operator=(ValueType::i64);
  }else if(Util::matchString(context.cursor, context.end, "f32")){
    context.cursor += 3;
    std::any::operator=(ValueType::f32);
  }else if(Util::matchString(context.cursor, context.end, "f64")){
    context.cursor += 3;
    std::any::operator=(ValueType::f64);
  }
}
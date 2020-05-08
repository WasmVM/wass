#ifndef GUARD_wass_parser_ParserMemoryInstr
#define GUARD_wass_parser_ParserMemoryInstr

#include <variant>
#include <structure/MemoryInstr.hpp>
#include <parser/ParserContext.hpp>

class ParserMemoryInstr: public std::variant<
  std::monostate,
  I32LoadInstr,
  I32Load8SInstr,
  I32Load8UInstr,
  I32Load16SInstr,
  I32Load16UInstr,
  I32StoreInstr,
  I32Store8Instr,
  I32Store16Instr,
  I64LoadInstr,
  I64Load8SInstr,
  I64Load8UInstr,
  I64Load16SInstr,
  I64Load16UInstr,
  I64Load32SInstr,
  I64Load32UInstr,
  I64StoreInstr,
  I64Store8Instr,
  I64Store16Instr,
  I64Store32Instr,
  F32LoadInstr,
  F32StoreInstr,
  F64LoadInstr,
  F64StoreInstr,
  MemorySizeInstr,
  MemoryGrowInstr
>{
public:
  ParserMemoryInstr(ParserContext& context);
};

#endif
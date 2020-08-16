#ifndef GUARD_wass_codegen_CodeGenVisitor
#define GUARD_wass_codegen_CodeGenVisitor

#include <variant>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <string>
#include <utility>
#include <optional>
#include <any>
#include <BinaryCode.hpp>
#include <structure/Type.hpp>
#include <structure/Module.hpp>
#include <structure/FuncType.hpp>
#include <structure/ValueType.hpp>
#include <structure/TypeUse.hpp>
#include <structure/Import.hpp>
#include <structure/Limit.hpp>
#include <structure/GlobalType.hpp>
#include <structure/Function.hpp>
#include <structure/Table.hpp>
#include <structure/Memory.hpp>
#include <structure/Global.hpp>
#include <structure/ConstInstr.hpp>
#include <structure/VariableInstr.hpp>
#include <structure/ParamInstr.hpp>
#include <structure/ControlInstr.hpp>
#include <structure/NumericInstr.hpp>
#include <structure/MemoryInstr.hpp>
#include <structure/Index.hpp>
#include <structure/Export.hpp>
#include <structure/Element.hpp>
#include <structure/ControlInstr.hpp>
#include <structure/InstrVariant.hpp>
#include <structure/Data.hpp>

using CodeGenVariant = std::variant<
  Module,
  FuncType,
  ValueType,
  Type,
  TypeUse,
  Import,
  Limit,
  GlobalType,
  Function,
  Table,
  Memory,
  Global,
  Index,
  Export,
  Element,
  Function::Content,
  Data
>;

class CodeGenVisitor{
public:
  CodeGenVisitor();

  BinaryCode operator()(std::monostate&&);
  BinaryCode operator()(Module&&);
  BinaryCode operator()(Type&&);
  BinaryCode operator()(FuncType&&);
  BinaryCode operator()(ValueType&&);
  BinaryCode operator()(TypeUse&&);
  BinaryCode operator()(Import&&);
  BinaryCode operator()(Limit&&);
  BinaryCode operator()(GlobalType&&);
  BinaryCode operator()(Function&&);
  BinaryCode operator()(Table&&);
  BinaryCode operator()(Memory&&);
  BinaryCode operator()(Global&&);
  BinaryCode operator()(Index&&);
  BinaryCode operator()(Export&&);
  BinaryCode operator()(Element&&);
  BinaryCode operator()(Function::Content&&);
  BinaryCode operator()(Data&&);

  BinaryCode operator()(I32ConstInstr&&);
  BinaryCode operator()(I64ConstInstr&&);
  BinaryCode operator()(F32ConstInstr&&);
  BinaryCode operator()(F64ConstInstr&&);

  BinaryCode operator()(DropInstr&&);
  BinaryCode operator()(SelectInstr&&);

  BinaryCode operator()(GlobalGetInstr&&);
  BinaryCode operator()(GlobalSetInstr&&);
  BinaryCode operator()(LocalGetInstr&&);
  BinaryCode operator()(LocalSetInstr&&);
  BinaryCode operator()(LocalTeeInstr&&);

  BinaryCode operator()(UnreachableInstr&&);
  BinaryCode operator()(NopInstr&&);
  BinaryCode operator()(ReturnInstr&&);
  BinaryCode operator()(BrInstr&&);
  BinaryCode operator()(BrIfInstr&&);
  BinaryCode operator()(BrTableInstr&&);
  BinaryCode operator()(CallInstr&&);
  BinaryCode operator()(CallIndirectInstr&&);
  BinaryCode operator()(BlockInstr&&);
  BinaryCode operator()(LoopInstr&&);
  BinaryCode operator()(IfInstr&&);

  BinaryCode operator()(I32LoadInstr&&);
  BinaryCode operator()(I32Load8SInstr&&);
  BinaryCode operator()(I32Load8UInstr&&);
  BinaryCode operator()(I32Load16SInstr&&);
  BinaryCode operator()(I32Load16UInstr&&);
  BinaryCode operator()(I32StoreInstr&&);
  BinaryCode operator()(I32Store8Instr&&);
  BinaryCode operator()(I32Store16Instr&&);
  BinaryCode operator()(I64LoadInstr&&);
  BinaryCode operator()(I64Load8SInstr&&);
  BinaryCode operator()(I64Load8UInstr&&);
  BinaryCode operator()(I64Load16SInstr&&);
  BinaryCode operator()(I64Load16UInstr&&);
  BinaryCode operator()(I64Load32SInstr&&);
  BinaryCode operator()(I64Load32UInstr&&);
  BinaryCode operator()(I64StoreInstr&&);
  BinaryCode operator()(I64Store8Instr&&);
  BinaryCode operator()(I64Store16Instr&&);
  BinaryCode operator()(I64Store32Instr&&);
  BinaryCode operator()(F32LoadInstr&&);
  BinaryCode operator()(F32StoreInstr&&);
  BinaryCode operator()(F64LoadInstr&&);
  BinaryCode operator()(F64StoreInstr&&);
  BinaryCode operator()(MemorySizeInstr&&);
  BinaryCode operator()(MemoryGrowInstr&&);

  BinaryCode operator()(I32ClzInstr&&);
  BinaryCode operator()(I32CtzInstr&&);
  BinaryCode operator()(I32PopcntInstr&&);
  BinaryCode operator()(I32AddInstr&&);
  BinaryCode operator()(I32SubInstr&&);
  BinaryCode operator()(I32MulInstr&&);
  BinaryCode operator()(I32DivSInstr&&);
  BinaryCode operator()(I32DivUInstr&&);
  BinaryCode operator()(I32RemSInstr&&);
  BinaryCode operator()(I32RemUInstr&&);
  BinaryCode operator()(I32AndInstr&&);
  BinaryCode operator()(I32OrInstr&&);
  BinaryCode operator()(I32XorInstr&&);
  BinaryCode operator()(I32ShlInstr&&);
  BinaryCode operator()(I32ShrSInstr&&);
  BinaryCode operator()(I32ShrUInstr&&);
  BinaryCode operator()(I32RotlInstr&&);
  BinaryCode operator()(I32RotrInstr&&);
  BinaryCode operator()(I64ClzInstr&&);
  BinaryCode operator()(I64CtzInstr&&);
  BinaryCode operator()(I64PopcntInstr&&);
  BinaryCode operator()(I64AddInstr&&);
  BinaryCode operator()(I64SubInstr&&);
  BinaryCode operator()(I64MulInstr&&);
  BinaryCode operator()(I64DivSInstr&&);
  BinaryCode operator()(I64DivUInstr&&);
  BinaryCode operator()(I64RemSInstr&&);
  BinaryCode operator()(I64RemUInstr&&);
  BinaryCode operator()(I64AndInstr&&);
  BinaryCode operator()(I64OrInstr&&);
  BinaryCode operator()(I64XorInstr&&);
  BinaryCode operator()(I64ShlInstr&&);
  BinaryCode operator()(I64ShrSInstr&&);
  BinaryCode operator()(I64ShrUInstr&&);
  BinaryCode operator()(I64RotlInstr&&);
  BinaryCode operator()(I64RotrInstr&&);
  BinaryCode operator()(F32AbsInstr&&);
  BinaryCode operator()(F32NegInstr&&);
  BinaryCode operator()(F32CeilInstr&&);
  BinaryCode operator()(F32FloorInstr&&);
  BinaryCode operator()(F32TruncInstr&&);
  BinaryCode operator()(F32NearestInstr&&);
  BinaryCode operator()(F32SqrtInstr&&);
  BinaryCode operator()(F32AddInstr&&);
  BinaryCode operator()(F32SubInstr&&);
  BinaryCode operator()(F32MulInstr&&);
  BinaryCode operator()(F32DivInstr&&);
  BinaryCode operator()(F32MinInstr&&);
  BinaryCode operator()(F32MaxInstr&&);
  BinaryCode operator()(F32CopysignInstr&&);
  BinaryCode operator()(F64AbsInstr&&);
  BinaryCode operator()(F64NegInstr&&);
  BinaryCode operator()(F64CeilInstr&&);
  BinaryCode operator()(F64FloorInstr&&);
  BinaryCode operator()(F64TruncInstr&&);
  BinaryCode operator()(F64NearestInstr&&);
  BinaryCode operator()(F64SqrtInstr&&);
  BinaryCode operator()(F64AddInstr&&);
  BinaryCode operator()(F64SubInstr&&);
  BinaryCode operator()(F64MulInstr&&);
  BinaryCode operator()(F64DivInstr&&);
  BinaryCode operator()(F64MinInstr&&);
  BinaryCode operator()(F64MaxInstr&&);
  BinaryCode operator()(F64CopysignInstr&&);
  BinaryCode operator()(I32EqzInstr&&);
  BinaryCode operator()(I32EqInstr&&);
  BinaryCode operator()(I32NeInstr&&);
  BinaryCode operator()(I32LtSInstr&&);
  BinaryCode operator()(I32LtUInstr&&);
  BinaryCode operator()(I32GtSInstr&&);
  BinaryCode operator()(I32GtUInstr&&);
  BinaryCode operator()(I32LeSInstr&&);
  BinaryCode operator()(I32LeUInstr&&);
  BinaryCode operator()(I32GeSInstr&&);
  BinaryCode operator()(I32GeUInstr&&);
  BinaryCode operator()(I64EqzInstr&&);
  BinaryCode operator()(I64EqInstr&&);
  BinaryCode operator()(I64NeInstr&&);
  BinaryCode operator()(I64LtSInstr&&);
  BinaryCode operator()(I64LtUInstr&&);
  BinaryCode operator()(I64GtSInstr&&);
  BinaryCode operator()(I64GtUInstr&&);
  BinaryCode operator()(I64LeSInstr&&);
  BinaryCode operator()(I64LeUInstr&&);
  BinaryCode operator()(I64GeSInstr&&);
  BinaryCode operator()(I64GeUInstr&&);
  BinaryCode operator()(F32EqInstr&&);
  BinaryCode operator()(F32NeInstr&&);
  BinaryCode operator()(F32LtInstr&&);
  BinaryCode operator()(F32GtInstr&&);
  BinaryCode operator()(F32LeInstr&&);
  BinaryCode operator()(F32GeInstr&&);
  BinaryCode operator()(F64EqInstr&&);
  BinaryCode operator()(F64NeInstr&&);
  BinaryCode operator()(F64LtInstr&&);
  BinaryCode operator()(F64GtInstr&&);
  BinaryCode operator()(F64LeInstr&&);
  BinaryCode operator()(F64GeInstr&&);
  BinaryCode operator()(I32WrapI64Instr&&);
  BinaryCode operator()(I32TruncF32SInstr&&);
  BinaryCode operator()(I32TruncF32UInstr&&);
  BinaryCode operator()(I32TruncF64SInstr&&);
  BinaryCode operator()(I32TruncF64UInstr&&);
  BinaryCode operator()(I64ExtendI32SInstr&&);
  BinaryCode operator()(I64ExtendI32UInstr&&);
  BinaryCode operator()(I64TruncF32SInstr&&);
  BinaryCode operator()(I64TruncF32UInstr&&);
  BinaryCode operator()(I64TruncF64SInstr&&);
  BinaryCode operator()(I64TruncF64UInstr&&);
  BinaryCode operator()(F32ConvertI32SInstr&&);
  BinaryCode operator()(F32ConvertI32UInstr&&);
  BinaryCode operator()(F32ConvertI64SInstr&&);
  BinaryCode operator()(F32ConvertI64UInstr&&);
  BinaryCode operator()(F32DemoteF64Instr&&);
  BinaryCode operator()(F64ConvertI32SInstr&&);
  BinaryCode operator()(F64ConvertI32UInstr&&);
  BinaryCode operator()(F64ConvertI64SInstr&&);
  BinaryCode operator()(F64ConvertI64UInstr&&);
  BinaryCode operator()(F64PromoteF32Instr&&);
  BinaryCode operator()(I32ReinterpretF32Instr&&);
  BinaryCode operator()(I64ReinterpretF64Instr&&);
  BinaryCode operator()(F32ReinterpretI32Instr&&);
  BinaryCode operator()(F64ReinterpretI64Instr&&);

protected:
  struct Context{
    std::vector<FuncType> typeDescs;
    std::unordered_map<std::string, uint32_t> identifierMap;
    uint32_t funcCount;
    uint32_t tableCount;
    uint32_t memCount;
    uint32_t globalCount;
  } context;
  struct Sections{
    std::any type;
    std::any import;
    std::any func;
    std::any table;
    std::any memory;
    std::any global;
    std::any exports;
    std::any elem;
    std::any code;
  } sections;
};

#endif
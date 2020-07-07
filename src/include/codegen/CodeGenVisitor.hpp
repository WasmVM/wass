#ifndef GUARD_wass_codegen_CodeGenVisitor
#define GUARD_wass_codegen_CodeGenVisitor

#include <variant>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <string>
#include <utility>
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
#include <structure/Index.hpp>
#include <structure/Export.hpp>
#include <structure/Element.hpp>

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
  Element
>;

class CodeGenVisitor{
public:
  CodeGenVisitor();
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
  BinaryCode operator()(std::monostate&&);
  BinaryCode operator()(I32ConstInstr&&);
  BinaryCode operator()(I64ConstInstr&&);
  BinaryCode operator()(F32ConstInstr&&);
  BinaryCode operator()(F64ConstInstr&&);
  BinaryCode operator()(GlobalGetInstr&&);
  BinaryCode operator()(Index&&);
  BinaryCode operator()(Export&&);
  BinaryCode operator()(Element&&);

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
  } sections;
};

#endif
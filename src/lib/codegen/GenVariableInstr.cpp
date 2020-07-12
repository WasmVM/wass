#include <codegen/CodeGenVisitor.hpp>

#include <variant>
#include <structure/VariableInstr.hpp>
#include <Util.hpp>

#define GenVariableInstr(TYPE,CODE) \
BinaryCode CodeGenVisitor::operator()(TYPE&& target){ \
  return BinaryCode({CODE}) + std::visit<BinaryCode>(*this, CodeGenVariant(target.index)); \
}

GenVariableInstr(LocalGetInstr, '\x20');
GenVariableInstr(LocalSetInstr, '\x21');
GenVariableInstr(LocalTeeInstr, '\x22');
GenVariableInstr(GlobalGetInstr, '\x23');
GenVariableInstr(GlobalSetInstr, '\x24');

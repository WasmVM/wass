include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_library(wass-core
  lib/BinaryCode.cpp
  lib/Error.cpp
  lib/Util.cpp
  lib/structure/Function.cpp
  lib/structure/Limit.cpp
  lib/structure/FuncType.cpp
  lib/structure/GlobalType.cpp
  lib/structure/ControlInstr.cpp
  lib/structure/TypeUse.cpp
)

add_subdirectory(lib/parser)
add_subdirectory(lib/codegen)
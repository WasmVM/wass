add_library(test_codegen OBJECT
  test_GenModule.cpp
  test_GenFuncType.cpp
  test_GenValueType.cpp
  test_GenType.cpp
  test_GenTypeUse.cpp
  test_GenImport.cpp
)
add_dependencies(test_codegen
  googletest
)
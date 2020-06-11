add_library(test_codegen OBJECT
  test_GenModule.cpp
)
add_dependencies(test_codegen
  googletest
)
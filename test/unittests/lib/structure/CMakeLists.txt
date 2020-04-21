add_library(test_structure OBJECT
  test_Value.cpp
  test_FuncType.cpp
)
add_dependencies(test_structure
  googletest
)
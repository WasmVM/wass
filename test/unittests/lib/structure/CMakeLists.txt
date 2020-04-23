add_library(test_structure OBJECT
  test_Value.cpp
  test_FuncType.cpp
  test_Limit.cpp
  test_GlobalType.cpp
)
add_dependencies(test_structure
  googletest
)
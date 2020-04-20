add_library(test_structure OBJECT
  test_Value.cpp
)
add_dependencies(test_structure
  googletest
)
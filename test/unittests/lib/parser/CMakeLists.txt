add_library(test_parser OBJECT
  test_Comment.cpp
  test_Literal_integer.cpp
)
add_dependencies(test_parser
  googletest
)
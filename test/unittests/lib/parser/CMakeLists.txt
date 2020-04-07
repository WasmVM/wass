add_library(test_parser OBJECT
  test_Comment.cpp
  test_IntegerLiteral.cpp
)
add_dependencies(test_parser
  googletest
)
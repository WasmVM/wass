add_library(test_parser OBJECT
  test_Comment.cpp
  test_IntegerLiteral.cpp
  test_FloatLiteral.cpp
  test_StringLiteral.cpp
  test_Name.cpp
)
add_dependencies(test_parser
  googletest
)
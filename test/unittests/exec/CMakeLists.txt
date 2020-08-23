include_directories(${PROJECT_SOURCE_DIR}/src/exec)

add_executable(test_exec
  test_CommandLine.cpp
  ${PROJECT_SOURCE_DIR}/src/exec/CommandLine.cpp
)
add_dependencies(test_exec
  googletest
)

target_link_libraries(test_exec
  wass-codegen
  wass-parser
  wass-core
  gtest
  gtest_main
  pthread
  unittest_helper
)
gtest_discover_tests(test_exec)
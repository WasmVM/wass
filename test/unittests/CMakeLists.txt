add_subdirectory(lib)

add_executable(unittest
  $<TARGET_OBJECTS:test_parser>
)
target_link_libraries(unittest
  gtest
  gtest_main
  pthread
)
gtest_discover_tests(unittest)
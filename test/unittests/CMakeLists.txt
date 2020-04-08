include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(lib)

add_executable(unittest
  Helper.cpp
  $<TARGET_OBJECTS:test_parser>
)
target_link_libraries(unittest
  wass-parser
  gtest
  gtest_main
  pthread
)
gtest_discover_tests(unittest)
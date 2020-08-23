include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${CMAKE_CURRENT_LIST_DIR})

add_library(unittest_helper
  Helper.cpp
)
add_dependencies(unittest_helper
  googletest
)

add_subdirectory(exec)
add_subdirectory(lib)
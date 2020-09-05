cmake_minimum_required(VERSION 3.10)
project(wass)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(src)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  include(ExternalProject)
  ExternalProject_add(googletest
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/external/googletest
    SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/external/googletest
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/external/googletest
    CONFIGURE_COMMAND cmake -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> <SOURCE_DIR>
  )
  include_directories(${CMAKE_CURRENT_BINARY_DIR}/external/googletest/include)
  link_directories(${CMAKE_CURRENT_BINARY_DIR}/external/googletest/lib)
  include(GoogleTest)
  enable_testing()
  add_subdirectory(test/unittests)
else()
  enable_testing()
  add_subdirectory(test/regression)
endif()
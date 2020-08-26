include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/lib/structure structure_sources)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/lib core_sources)

add_library(wass-core
  ${core_sources}
  ${structure_sources}
)

add_subdirectory(lib/parser)
add_subdirectory(lib/codegen)

add_executable(wass
  exec/wass.cpp
  exec/CommandLine.cpp
)
target_link_libraries(wass
  wass-core
  wass-parser
  wass-codegen
)
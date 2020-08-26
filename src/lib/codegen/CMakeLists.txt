aux_source_directory(${CMAKE_CURRENT_LIST_DIR} codegen_sources)
add_library(wass-codegen
  ${codegen_sources}
)
target_link_libraries(wass-codegen
  wass-core
)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} parser_sources)
add_library(wass-parser
  ${parser_sources}
)
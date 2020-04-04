include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_library(wass-parser
  lib/parser/Parser.cpp
  lib/parser/ParserContext.cpp
  lib/parser/Comment.cpp
)
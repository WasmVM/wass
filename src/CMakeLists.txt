include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_library(wass-parser
  lib/Error.cpp
  lib/Util.cpp
  lib/parser/ParserContext.cpp
  lib/parser/Comment.cpp
  lib/parser/IntegerLiteral.cpp
  lib/parser/FloatLiteral.cpp
)
add_library(${PROJECT_NAME}_lib STATIC
  Expression.cpp
  File.cpp
  Operation.cpp
  Parser.cpp
  Set.cpp
)

target_include_directories(${PROJECT_NAME}_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)


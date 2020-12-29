
include( FindPkgConfig )

find_package( GTest REQUIRED ) # Creates targets GTest::GTest, GTest::Main

include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()

add_executable( ${PROJECT_NAME}_test
  main_test.cpp
  CalcTest.cpp
  OperationTest.cpp 
  ParserTest.cpp 
)

add_test(
    CalcTest CalcTest.cpp
    OperationTest OperationTest.cpp
    ParserTest ParserTest.cpp
)

target_link_libraries( ${PROJECT_NAME}_test
  PUBLIC
    GTest::GTest
    ${PROJECT_NAME}_lib
)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/.test_data_copied
  COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/test_data
  COMMAND cp -rT ${CMAKE_CURRENT_SOURCE_DIR}/test_data ${CMAKE_CURRENT_BINARY_DIR}/test_data
  COMMAND touch ${CMAKE_CURRENT_BINARY_DIR}/.test_data_copied
  VERBATIM
)

add_custom_target(${PROJECT_NAME}_test-copy-testdata
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/.test_data_copied)

add_dependencies(${PROJECT_NAME}_test ${PROJECT_NAME}_test-copy-testdata)

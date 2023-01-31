cmake_minimum_required(VERSION 3.16)

set(PROJECT_VERSION 0.0.1)

project(lab2 VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(ip_filter.tsv ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME}
    main.cpp
    filters.h
    processing.h
    filterFunctions.h
)

add_executable(customTie
    tie.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -pedantic
    -Werror
)

enable_testing()
find_package(GTest REQUIRED)

set(TESTS_SOURCES
    tests.cc
)

add_executable(tests
  ${TESTS_SOURCES}
)

target_link_libraries(tests
   GTest::GTest
   GTest::Main
)

include(GoogleTest)
gtest_discover_tests(tests)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

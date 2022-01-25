cmake_minimum_required(VERSION 3.14)

project(branches)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)
add_library(branches "src/geometry.cpp" "src/branches.cpp")
add_executable(tree_builder "src/tree_builder.cpp")
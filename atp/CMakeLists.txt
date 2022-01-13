cmake_minimum_required(VERSION 3.14)

project(atp)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(../include)
add_library(branches ../build/lib/Debug/branches.lib)
set_target_properties(branches PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
add_executable(constructor src/constructor.cpp)
add_executable(children src/children.cpp)

target_link_libraries(constructor branches gtest_main)
target_link_libraries(children branches gtest_main)
include(GoogleTest)
gtest_discover_tests(constructor)
gtest_discover_tests(children)
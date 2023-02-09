# ./branches/CMakeLists.txt
cmake_minimum_required( VERSION 3.15 )

add_library( branches )
target_include_directories( branches
    PRIVATE
        headers 
)
target_sources( branches
    PUBLIC
        headers/branch.hpp
        headers/geom.hpp
    PRIVATE
        src/geom.cpp
        src/branch.cpp
)

add_executable( test_run )
target_include_directories( test_run
    PRIVATE
        headers
)
target_sources( test_run
    PRIVATE
        src/test_run.cpp
)
target_link_libraries( test_run PRIVATE branches )

enable_testing()
add_executable( geom_test )
target_sources( geom_test
    PRIVATE
        test/geom_tests.cpp
)
target_link_libraries( geom_test PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(geom_test)

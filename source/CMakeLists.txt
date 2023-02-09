# ./CMakeLists.txt
cmake_minimum_required( VERSION 3.15 )

# load meta information
include( "${CMAKE_CURRENT_SOURCE_DIR}/project_meta_info.in" )
project( trees
    VERSION         ${project_version}
    DESCRIPTION     ${project_description}
    HOMEPAGE_URL    ${project_homepage}
    LANGUAGES       ${project_languages}
)

function( print_meta_info )
    message( "" )
    message( "project_version:      ${project_version}" )
    message( "project_description:  ${project_description}" )
    message( "project_homepage:     ${project_homepage}" )
    message( "project_languages:    ${project_languages}" )
    message( "" )
endfunction()
print_meta_info()

# set default binary symbol visibilities to hidden
if( NOT DEFINED CMAKE_CXX_VISIBILITY_PRESET AND
    NOT DEFINED CMAKE_VISIBILITY_INLINES_HIDDEN
)
    set( CMAKE_CXX_VISIBILITY_PRESET        hidden )
    set( CMAKE_VISIBILITY_INLINES_HIDDEN    YES )
endif()

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# provided libraries
add_subdirectory( branches )

# installation
include( GNUInstallDirs )
install(
    TARGETS branches
    EXPORT  branches_targets

    INCLUDES    DESTINATION         "${CMAKE_INSTALL_INCLUDEDIR}"

    RUNTIME     DESTINATION         "${CMAKE_INSTALL_BINDIR}"
                COMPONENT           branches_runtime
    LIBRARY     DESTINATION         "${CMAKE_INSTALL_LIBDIR}"
                COMPONENT           branches_runtime
                NAMELINK_COMPONENT  branches_development
    ARCHIVE     DESTINATION         "${CMAKE_INSTALL_LIBDIR}"
                COMPONENT           branches_development
)
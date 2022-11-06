# ./branchesConfig.cmake
cmake_minimum_required( VERSION 3.15 )

# component variables
set( branches_known_comps static shared )
set( branches_comp_static NO )
set( branches_comp_shared NO )

# check that "find_package" is looking for existing component
foreach( branches_comp IN LISTS ${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS )
    if( branches_comp IN_LIST branches_known_comps )
        set( branches_comp_${branches_comp} YES )
    else()
        set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
            "branches does not recognize component '${branches_comp}'"
        )
        set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE )
        return()
    endif()
endforeach()

# if both components requested, returns error
if( branches_comp_static AND branches_comp_shared )
    set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
        "branches 'static' and 'shared' componends are mutually exclusive"
    )
    set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE )
    return()
endif()

# load target scripts
set( branches_static_targets
    "${CMAKE_CURRENT_LIST_DIR}/branches-static-targets.cmake"
)
set( branches_shared_targets
    "${CMAKE_CURRENT_LIST_DIR}/branches-shared-targets.cmake"
)

# load targets macro
macro( branches_load_targets type )
    if( NOT EXISTS "${branches_${type}_targets" )
        set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
            "branches '${type}' libraries were requested but not found"
        )
        set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE )
        return()
    endif()
    include( "${branches_${type}_targets" )
endmacro()

# default static before shared unless requested or BUILD_SHARED_LIBS set
# if requested doesn't exist, revert to available
if( branches_comp_static )
    branches_load_targets( static )
elseif( branches_comp_shared )
    branches_load_targets( shared )
elseif( DEFINED branches_SHARED_LIBS AND branches_SHARED_LIBS )
    branches_load_targets( shared )
elseif( DEFINED branches_SHARED_LIBS AND NOT branches_SHARED_LIBS )
    branches_load_targets( static )
elseif( BUILD_SHARED_LIBS )
    if( EXISTS "${branches_shared_targets}" )
        branches_load_targets( shared )
    else()
        branches_load_targets( static )
    endif()
else()
    if( EXISTS "${branches_static_targets}" )
        branches_load_targets( static )
    else()
        branches_load_targets( shared )
    endif()
endif()
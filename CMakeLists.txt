cmake_minimum_required(VERSION 3.5)
project(Math)

#Version Number
set(Math_VERSION_MAJOR 1)
set(Math_Version_MINOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/MathConfig.h.in"
        "${PROJECT_BINARY_DIR}/MathConfig.h"
        )

include_directories("${PROJECT_BINARY_DIR}")
#end Version Number

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp )
#add_library(Vector Vector/Math.cpp Vector/Math.h Vector/Vector.cpp Vector/Vector.h )



# should we use our own math functions?
option (USE_VECTORS
        "Use tutorial provided math implementation" ON)

# add the Vectors library?
#
if (USE_VECTORS)
    include_directories("${PROJECT_SOURCE_DIR}/Vector")
    add_subdirectory(Vector)
    set (EXTRA_LIBS ${EXTRA_LIBS} Vector)
endif (USE_VECTORS)

add_executable(Math ${SOURCE_FILES})
target_link_libraries(Math ${EXTRA_LIBS})

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()

# Trivial example using gtest and gmock
add_executable(example example.cpp)
target_link_libraries(example gtest gmock_main)
add_test(NAME example_test COMMAND example)
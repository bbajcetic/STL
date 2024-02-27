#set the project name
cmake_minimum_required(VERSION 3.10)
project(Vector)

## No in-source build
#if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
#  message(FATAL_ERROR "In-source builds are not allowed.")
#endif()
#
#if(NOT CMAKE_BUILD_TYPE)
#  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
#  message("-- No build mode chosen - using Debug by default")
#endif()

enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pthread -DPAGE_SIZE=4096")

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(vector)
#add_subdirectory(list)
#add_subdirectory(queue)
#add_subdirectory(stack)

add_subdirectory(tests)

add_subdirectory(external/gtest)
add_subdirectory(external/benchmark)
option(CXXFEATURECHECK_DEBUG "Enable debug output for feature checking" ON)

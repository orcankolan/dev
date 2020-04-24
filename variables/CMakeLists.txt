cmake_minimum_required (VERSION 3.5)

project(variables VERSION 1.0.1 DESCRIPTION "using variables")

# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

set (source_dir "${PROJECT_SOURCE_DIR}/src")

#include dirs
set (include_dir "${PROJECT_SOURCE_DIR}/src/include/")

#message(STATUS "Compiler is: ${CMAKE_CXX_COMPILER}")

# Find source files
file (GLOB source_files "${source_dir}/*.cpp")

# create executables
add_executable (${PROJECT_NAME} ${source_files})

# include dir for header files
target_include_directories (${PROJECT_NAME} PUBLIC ${include_dir})

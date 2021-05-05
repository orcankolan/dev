cmake_minimum_required (VERSION 3.5)

project(usinglibs VERSION 1.0.1 DESCRIPTION "using static libs")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set (source_dir "${PROJECT_SOURCE_DIR}/src")

#include dirs
set (include_dir "${PROJECT_SOURCE_DIR}/src/include/")
set (dep_include_dir "${PROJECT_SOURCE_DIR}/dependencies/mystatic/include/")

#library dirs
set (lib_dir "${PROJECT_SOURCE_DIR}/dependencies/mystatic/lib")

# a message
# to change compiler do not use set() command, instead:
# cmake -DCMAKE_CXX_COMPILER="/usr/bin/g++" ..

message(STATUS "Compiler is: ${CMAKE_CXX_COMPILER}")

# Find source files
file (GLOB source_files "${source_dir}/*.cpp")


# create executables
add_executable (usinglibs ${source_files})

# include dir for header files
target_include_directories (usinglibs PUBLIC ${include_dir} ${dep_include_dir})

# libraries for linking 
target_link_libraries (usinglibs ${lib_dir}/libmystatic.a)


# install binary
install (TARGETS usinglibs
  RUNTIME DESTINATION "~/.local/bin")

cmake_minimum_required (VERSION 3.5)

project(mystatic VERSION 1.0.1 DESCRIPTION "mystatic lib description")


set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (include_dir "${PROJECT_SOURCE_DIR}/src/include/")
set (CMAKE_BUILD_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
set (LIBRARY_OUTPUT_PATH "${CMAKE_BUILD_DIRECTORY}/lib")
set (INCLUDE_OUTPUT_PATH "${CMAKE_BUILD_DIRECTORY}/include")

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files for compilation
# include_directories(${include_dir})

# Create library with source files
add_library(mystatic STATIC
    ${SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER src/include/mystatic.h)

# target_include_directories(mystaticlib PRIVATE include)

# Create an install rule for your library. I suggest to use variables CMAKE_INSTALL_*DIR defined in GNUInstallDirs
# include(GNUInstallDirs)

# Install library
install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${LIBRARY_OUTPUT_PATH} 
    LIBRARY DESTINATION ${LIBRARY_OUTPUT_PATH}
    PUBLIC_HEADER DESTINATION ${INCLUDE_OUTPUT_PATH})

# file(GLOB HEADERS include/*.h)
# install(FILES ${HEADERS} DESTINATION ${INCLUDE_OUTPUT_PATH})

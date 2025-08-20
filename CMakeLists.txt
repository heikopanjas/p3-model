cmake_minimum_required(VERSION 4.0)

# Read version from file
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/version.in" PROJECT_VERSION)
string(STRIP "${PROJECT_VERSION}" PROJECT_VERSION)

# Project configuration
project(p3-model
    VERSION ${PROJECT_VERSION}
    DESCRIPTION "C++ object model library for podcast production and publishing (P3)"
    LANGUAGES CXX
)

# Set C++23 as mandatory
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Create the library target
add_library(p3-model STATIC
    p3-model.cpp
)

# Compiler-specific options
if(MSVC)
    target_compile_options(p3-model PRIVATE /W4)
else()
    target_compile_options(p3-model PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Set target properties
set_target_properties(p3-model PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Include directories
target_include_directories(p3-model
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# Installation configuration
include(GNUInstallDirs)

# Install the library
install(TARGETS p3-model
    EXPORT p3-model-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install headers
install(FILES p3-model.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Export targets for use by other projects
install(EXPORT p3-model-targets
    FILE p3-model-targets.cmake
    NAMESPACE ultralove::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/p3-model
)

# Create and install package config files
include(CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/p3-model-config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/p3-model-config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/p3-model
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/p3-model-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/p3-model-config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/p3-model-config-version.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/p3-model
)

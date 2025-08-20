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
    model.cpp
)

# Add headers for IDE support and installation
set(P3_MODEL_HEADERS
    model.h
    runtimestring.h
    runtimeguid.h
    runtimetimestamp.h
    runtimetimespan.h
)

target_sources(p3-model PRIVATE ${P3_MODEL_HEADERS})

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

# Documentation with Doxygen
find_package(Doxygen REQUIRED COMPONENTS dot)
if(DOXYGEN_FOUND)
    # Doxygen configuration
    set(DOXYGEN_PROJECT_NAME "P3 Model Library")
    set(DOXYGEN_PROJECT_BRIEF "C++ object model library for podcast production and publishing")
    set(DOXYGEN_PROJECT_VERSION ${PROJECT_VERSION})
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs")
    set(DOXYGEN_GENERATE_LATEX YES)
    set(DOXYGEN_GENERATE_HTML NO)
    set(DOXYGEN_LATEX_OUTPUT "latex")
    set(DOXYGEN_LATEX_REFMAN_FILE_NAME "p3-model")
    set(DOXYGEN_USE_PDFLATEX YES)
    set(DOXYGEN_PDF_HYPERLINKS YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_EXTRACT_PRIVATE NO)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
    set(DOXYGEN_WARN_IF_UNDOCUMENTED YES)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_FILE_PATTERNS "*.h;*.cpp")
    set(DOXYGEN_EXCLUDE_PATTERNS "*/_build/*")
    set(DOXYGEN_HAVE_DOT YES)
    set(DOXYGEN_ENABLE_PREPROCESSING YES)    # Create documentation target
    doxygen_add_docs(docs
        ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generate LaTeX documentation with Doxygen"
    )

    # Add custom target to build PDF from LaTeX
    add_custom_target(docs-pdf
        COMMAND ${CMAKE_COMMAND} -E chdir ${DOXYGEN_OUTPUT_DIRECTORY}/latex make
        COMMAND ${CMAKE_COMMAND} -E copy ${DOXYGEN_OUTPUT_DIRECTORY}/latex/refman.pdf ${DOXYGEN_OUTPUT_DIRECTORY}/latex/p3-model.pdf
        DEPENDS docs
        COMMENT "Building PDF documentation from LaTeX"
        VERBATIM
    )
else()
    message(STATUS "Doxygen not found, documentation target will not be available")
endif()

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
install(FILES ${P3_MODEL_HEADERS}
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

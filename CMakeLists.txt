cmake_minimum_required(VERSION 3.21)

project(SLD.Strings VERSION 0.1.0 LANGUAGES CXX)

option(SLD_STRINGS_STATIC "Build SLD.Strings as a static library instead of a DLL" OFF)

# exceptions are disabled, so drop the /EHsc that cmake adds by default
if(MSVC)
    string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

# SLD.Core is a submodule; skip it if a parent project already provides it
if(NOT TARGET SLD::Core)
    add_subdirectory(SLD.Core)
endif()

if(SLD_STRINGS_STATIC)
    add_library(sld_strings STATIC)
else()
    add_library(sld_strings SHARED)
endif()
add_library(SLD::Strings ALIAS sld_strings)

# unity build: sld-strings.cpp includes the other source files
target_sources(sld_strings PRIVATE
    src/sld-strings.cpp
    src/cstr-nvar.cpp
    src/cstr-c8.cpp
    src/cstr-c16.cpp
    src/cstr-c32.cpp
    src/cstr-c64.cpp
    src/cstr-c128.cpp
    src/cstr-c256.cpp
    src/cstr.cpp
    include/sld-strings.hpp
)
set_source_files_properties(
    src/cstr-nvar.cpp
    src/cstr-c8.cpp
    src/cstr-c16.cpp
    src/cstr-c32.cpp
    src/cstr-c64.cpp
    src/cstr-c128.cpp
    src/cstr-c256.cpp
    src/cstr.cpp
    PROPERTIES HEADER_FILE_ONLY ON
)

target_include_directories(sld_strings
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# sld-strings.hpp includes sld.hpp, so consumers need it too
target_link_libraries(sld_strings PUBLIC SLD::Core)

target_compile_features(sld_strings PUBLIC cxx_std_17)
set_target_properties(sld_strings PROPERTIES
    CXX_EXTENSIONS           OFF
    OUTPUT_NAME              "SLD.Strings"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

if(SLD_STRINGS_STATIC)
    target_compile_definitions(sld_strings PUBLIC SLD_STRINGS_STATIC)
endif()

target_compile_definitions(sld_strings PRIVATE _HAS_EXCEPTIONS=0)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(sld_strings PRIVATE /EHs-)
endif()

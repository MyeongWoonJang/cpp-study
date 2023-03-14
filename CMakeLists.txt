# *************************************************
# Copyright @Woon2
# cmake script for building ascii-art project
#
# TODO:
# - [ ] add external libiraries.
# - [ ] improve temporary code.
# - [ ] add more platform-specific configuration.
# - [ ] (only Windows' configuration exists currently.)
# - [ ] write resource directory configuration script.
# - [ ] make installation customizable
# *************************************************

# cmake version is not hard limited.
# author of this script has cmake version higher than 3.18.
# the author habitually put the version require statement of 3.18.
cmake_minimum_required(VERSION 3.18)

# ======
# default settings
# ======
if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT DEFINED CMAKE_CONFIGURE_TYPE)
    message(STATUS "setting CMAKE_BUILD_TYPE to 'Debug'(default build type)
        as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of field" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE
        PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
    message(STATUS "setting CMAKE_INSTALL_PREFIX to
        '${CMAKE_CURRENT_SOURCE_DIR}/install'(default install path)
        as none was specified.")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install"
        CACHE STRING "Path to install" FORCE)
endif()
# end of default settings

project(ASCIIArt VERSION 1.0.0 LANGUAGES CXX)
message(STATUS "Ascii-Art project (version ${PROJECT_VERSION})")
message(STATUS "Authors: @Woon2(wkdauddns9@gmail.com),")
message(STATUS "@Lcat12345(ljj3640@gmail.com)")
message(STATUS "@orange2458(dntkdgns1039@gmail.com)")

# ======
# process dependencies
# ======

if (NOT DEFINED OpenCV_DIR
    AND NOT DEFINED ENV{OpenCV_DIR})

    message(WARNING "OpenCV_DIR was not defined.")
    message(STATUS "searching OpenCV_DIR from PATH...")

    find_path(OpenCV_DIR
        NAMES   OpenCVConfig.cmake
        PATHS   $ENV{Path}
    )

    if (OpenCV_DIR STREQUAL OpenCV_DIR-NOTFOUND)
        message(FATAL_ERROR "OpenCV not found.")
    endif()

endif()

find_package(OpenCV REQUIRED)

# Below code is temporary.
# have to consider cross-platform.
find_path(OpenCV_BINDIR
NAMES   opencv_version.exe
PATHS   $ENV{Path}
)

if (OpenCV_BINDIR STREQUAL OpenCV_BINDIR-NOTFOUND)
    message(FATAL_ERROR "OpenCV Binary not found (Add to PATH.)")
endif()

file(GLOB OpenCV_BINARY
  "${OpenCV_BINDIR}/*.dll"
  "${OpenCV_BINDIR}/*.pdb"
)

# Confused: Current? or Not?
file(COPY ${OpenCV_BINARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

message("Dependency check done")

# ======
# Configure this project
# ***
# Firstly set compile & link options, properties
# Secondly adjust dependencies
# ***
# ======

message("Configuring Ascii-Art project...")

add_executable(ascii)

# ***
# Firstly set compile & link options, properties
# ***

set_target_properties(ascii PROPOERTIES
    CXX_STANDARD 20
)

# See below link for finding gcc options.
# https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    target_compile_options(ascii
    INTERFACE
    -fconcepts
    -Wall
    -pedantic
    -Wextra
    )

# See below link for finding clang options.
# https://clang.llvm.org/docs/ClangCommandLineReference.html
elseif(CMAKE_CXX_COMPILER_ID MATCHES CLANG)
    # clang options differ by platform.
    if(WIN32)  # clang-cl
        target_compile_options(ascii
        INTERFACE
            "/clang:-fcoroutines-ts"
            -fms-compatibility
        )
    else()  # AppleClang or Clang on linux
        target_compile_options(ascii
        INTERFACE
            -std=c++2a
        )
    endif()

# See below link for finding msvc options.
# https://docs.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=msvc-160
elseif(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    target_compile_options(ascii
    INTERFACE
        /Wall
        /wd4668
        /wd4464
        /wd4514
        /wd5045
        /JMC-
        /Zc:__cplusplus
        /Zc:preprocessor
    )
endif()

# Shared settings for targets on each platform

# WIN32
target_compile_definitions(ascii
INTERFACE
    WIN32_LEAN_AND_MIN NOMINMAX
)

set_target_properties(ascii
PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS OFF
)

# Other platforms' setup is to be updated.

# ***
# Secondly adjust dependencies
# ***

target_include_directories(ascii PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(ascii PRIVATE ${OpenCV_LIBS})

# ======
# Installation
# ======

install(TARGETS ascii
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    INCLUDES DESTINATION ${CMAKE_INSTALL_PREFIX}/inc
)

# Below code is temporary.
# have to consider cross-platform.
install(FILES ${OpenCV_BINARY} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

# ======
# Git log custom target
# ======

find_package(Git)
if (GIT_FOUND)
    add_custom_target(log
        COMMENT "Git Commit Log:"
        COMMAND "${GIT_EXECUTABLE} log --pretty=reference -6"
    )
endif()
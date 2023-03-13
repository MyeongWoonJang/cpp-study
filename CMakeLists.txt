# *************************************************
# Copyright @Woon2
# cmake script for building ascii-art project
# *************************************************

# cmake version is not hard limited.
# author of this script has cmake version higher than 3.18.
# the author habitually put the version require statement of 3.18.
cmake_minimum_required(VERSION 3.18)

# default settings
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURE_TYPE)
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
message(STATUS "=================================================")
message(STATUS "Ascii-Art project (version ${PROJECT_VERSION})")
message(STATUS "=================================================")
message(STATUS "Authors: @Woon2(wkdauddns9@gmail.com),")
message(STATUS "@Lcat12345(ljj3640@gmail.com)")
message(STATUS "@orange2458(dntkdgns1039@gmail.com)")
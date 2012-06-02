# Preamble
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

# Project Settings
PROJECT(OpenGMS)

# Version number setting
SET(OpenGMS_MAJOR_VERSION 0)
SET(OpenGMS_MINOR_VERSION 1)
SET(OpenGMS_PATCH_VERSION 0)
SET(OpenGMS_VERSION ${OpenGMS_MAJOR_VERSION}.${OpenGMS_MINOR_VERSION}.${OpenGMS_PATCH_VERSION})

# Architecture detection
IF(CYGWIN)
    OPTION(OpenGMS_FORCE_CYGWIN "Set this to ON to enable building on Cygwin. This is not guaranteed to work in the slightest," OFF)
    MARK_AS_ADVANCED(OpenGMS_FORCE_CYGWIN)
    IF(${OpenGMS_FORCE_CYGWIN)
        MESSAGE(WARNING "Cygwin is not a supported build environment -- use at own risk.")
    ELSE()
        MESSAGE(FATAL_ERROR "Cygwin is not a supported build environment.")
    ENDIF()
ELSEIF(APPLE)
    OPTION(OpenGMS_FORCE_APPLE "Set this to ON to enable building on Apple. This is not guaranteed to work in the slightest," OFF)
    MARK_AS_ADVANCED(OpenGMS_FORCE_APPLE)
    IF(${OpenGMS_FORCE_APPLE)
        MESSAGE(WARNING "Apple is not a supported build environment -- use at own risk.")
    ELSE()
        MESSAGE(FATAL_ERROR "Apple is not a supported build environment.")
    ENDIF()
ELSEIF(WIN32)
    # Windows has been found
    SET(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/win)
ELSEIF(UNIX)
    # Linux has been found
    SET(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/lin)
ELSE()
    MESSAGE(FATAL_ERROR "Your build system (${CMAKE_SYSTEM_NAME}) is not recognised.")
ENDIF()

# Determine architecture bitness
IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
    MESSAGE(STATUS "Building for 32-Bit System")
    SET(ARCH_BITNESS "32")
    SET(LIB_ARCH "")
ELSEIF(CMAKE_SIZEOF_VOID_P EQUAL 8)
    MESSAGE(STATUS "Building for 64-Bit System")
    SET(ARCH_BITNESS "64")
    SET(LIB_ARCH "64")
ELSE()
    MESSAGE(FATAL_ERROR "Could not determine bitness (32 or 64) of architecture.")
ENDIF()

# Add the custom .cmake file path
SET(CMAKE_MODULE_PATH ${OpenGMS_SOURCE_DIR}/cmake_modules;${CMAKE_MODULE_PATH})

# Add some custom directories

# Find Required Libraries

# Include Directories

# Definitions for Debug Mode
IF(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    SET(CMAKE_DEBUG_POSTFIX "d")
    ADD_DEFINITIONS(-DDEBUG)
ELSE()
    SET(CMAKE_RELEASE_POSTFIX "")
    ADD_DEFINITIONS(-DNDEBUG) 
ENDIF()

# The Code
SET(OpenGMS_SOURCE_FILES Main.cpp)
SET(OpenGMS_HEADER_FILES Main.h)

ADD_EXECUTABLE(OpenGMS WIN32 ${OpenGMS_SOURCE_FILES} ${OpenGMS_HEADER_FILES})

# uninstall target
CONFIGURE_FILE(
  "${OpenGMS_SOURCE_DIR}/../cmake_modules/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")





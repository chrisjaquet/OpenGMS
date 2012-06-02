# Preamble
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

PROJECT(OpenGMS)
SET(CMAKE_VERBOSE_MAKEFILE ON)

# Set below to true for debugging
#SET(CMAKE_CXX_FLAGS_DEBUG "-frtti -fexceptions -mthreads -Wall")
#IF(WIN32)
#    SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "-g -mthreads -Wl,-subsystem,windows")
#ELSE()
#    SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "-mthreads")
#ENDIF()
#ADD_DEFINITIONS(-DUNICODE -DQT_NEEDS_QMAIN -D__GNUC__ -DQT_THREAD_SUPPORT -DWIN32 -DQT_LARGEFILE_SUPPORT)


# Version number setting
SET(OpenGMS_MAJOR_VERSION 0)
SET(OpenGMS_MINOR_VERSION 1)
SET(OpenGMS_PATCH_VERSION 0)
SET(OpenGMS_VERSION ${OpenGMS_MAJOR_VERSION}.${OpenGMS_MINOR_VERSION}.${OpenGMS_PATCH_VERSION})

# Convenience Override Flag
OPTION(BUILD_DONT_MODIFY_INSTALL_PREFIX "Set this to ON to force the install prefix to not be modified based on the architecture and operating system." OFF)

# Architecture detection
SET(OS_NAME "")
IF(CYGWIN)
    # Cygwin has been found
    SET(OS_NAME "cyg")
    OPTION(BUILD_FORCE_CYGWIN "Set this to ON to enable building on Cygwin. This is not guaranteed to work in the slightest." OFF)
    MARK_AS_ADVANCED(BUILD_FORCE_CYGWIN)
    IF(${BUILD_FORCE_CYGWIN})
        MESSAGE(WARNING "Cygwin is not a supported build environment -- use at own risk.")
    ELSE()
        MESSAGE(FATAL_ERROR "Cygwin is not a supported build environment.")
    ENDIF()
    ADD_DEFINITIONS(-DOS_CYGWIN=1)
ELSEIF(APPLE)
    # Apple has been found
    SET(OS_NAME "apl")
    OPTION(BUILD_FORCE_APPLE "Set this to ON to enable building on Apple. This is not guaranteed to work in the slightest." OFF)
    MARK_AS_ADVANCED(BUILD_FORCE_APPLE)
    IF(${BUILD_FORCE_APPLE})
        MESSAGE(WARNING "Apple is not a supported build environment -- use at own risk.")
    ELSE()
        MESSAGE(FATAL_ERROR "Apple is not a supported build environment.")
    ENDIF()
    ADD_DEFINITIONS(-DOS_APPLE=1)
ELSEIF(WIN32)
    # Windows has been found
    SET(OS_NAME "win")
    ADD_DEFINITIONS(-DOS_WINDOWS=1)
ELSEIF(UNIX)
    # Linux has been found
    SET(OS_NAME "lin")
    ADD_DEFINITIONS(-DOS_LINUX=1)
ELSE()
    MESSAGE(FATAL_ERROR "Your build system (${CMAKE_SYSTEM_NAME}) is not recognised.")
ENDIF()

# Determine architecture bitness
IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
    MESSAGE(STATUS "Building for 32-Bit System")
    SET(ARCH_BITNESS "32")
    SET(LIB_ARCH "")
    ADD_DEFINITIONS(-DARCH_BITNESS=32)
ELSEIF(CMAKE_SIZEOF_VOID_P EQUAL 8)
    MESSAGE(STATUS "Building for 64-Bit System")
    SET(ARCH_BITNESS "64")
    SET(LIB_ARCH "64")
    ADD_DEFINITIONS(-DARCH_BITNESS=64)
ELSE()
    MESSAGE(FATAL_ERROR "Could not determine bitness (32 or 64) of architecture.")
ENDIF()

# Final Installation Prefix
IF(${BUILD_DONT_MODIFY_INSTALL_PREFIX})
    MESSAGE(STATUS "Installation prefix will not be modified based on the architecture and operating system.")
ELSE()
    SET(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${OS_NAME}${ARCH_BITNESS}/)
    MESSAGE(STATUS "Installation prefix is "${CMAKE_INSTALL_PREFIX})
ENDIF()

# Add the custom .cmake file path
SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH})

# Definitions for Debug Mode
IF(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    SET(CMAKE_DEBUG_POSTFIX "d")
    ADD_DEFINITIONS(-DDEBUG)
ELSE()
    SET(CMAKE_RELEASE_POSTFIX "")
    ADD_DEFINITIONS(-DNDEBUG=1)
ENDIF()

# Extra Definitions
IF(${CMAKE_COMPILER_IS_GNUCXX})
    IF(WIN32)
        ADD_DEFINITIONS(-DCMP_WIN_GNU=1)
    ENDIF()
    SET(STDCPLUSPLUS_LIBRARY -lstdc++)
ENDIF()

# Some Extra Options
OPTION(BUILD_SHARED_LIBRARIES "Set this to ON to build shared libraries, rather than static libraries." ON)

## Project Specific Settings Start #################################################################
    # Dependency Root Dir
    # SET(DEP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../deps/${OS_NAME}${ARCH_BITNESS})
    # SET(CMAKE_PREFIX_PATH ${DEP_DIR})
    
    # Extra Include Directories
    # INCLUDE_DIRECTORIES(${DEP_DIR}/include/)

    # Extra Library Directories
    # LINK_DIRECTORIES(${DEP_DIR}/lib${LIB_ARCH}/)

    # Extra Package-defined Libraries
    # FIND_PACKAGE(PythonLibs 2.7 REQUIRED)
    # FIND_PACKAGE(GSL 1.15 REQUIRED)
    # FIND_PACKAGE(Qt4 4.7.4 REQUIRED QtGui QtCore QtOpenGL)
    # SET(QT_USE_QTMAIN TRUE)
    # INCLUDE(${QT_USE_FILE})
    # FIND_PACKAGE(SWIG 2.0.4 REQUIRED)
    # INCLUDE(UseSWIG_Mine)
    # SET(SWIG_PYTHON_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../swig_py_modules)
    # FIND_PACKAGE(OpenSceneGraph REQUIRED osgQt osgViewer osgDB osgGA)

    # Header and Library Directories from Packages
    # INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})
    # INCLUDE_DIRECTORIES(${GSL_INCLUDE_DIRS})
    # LINK_DIRECTORIES(${GSL_LIBRARY_DIRS})
    # INCLUDE_DIRECTORIES(${OPENSCENEGRAPH_INCLUDE_DIRS})
    
    # Other custom libraries
    # IF(${CMAKE_BUILD_TYPE} MATCHES "Debug")
        # FIND_LIBRARY(GSLMATRIX_LIB GSLMatrix REQUIRED)
        # FIND_LIBRARY(EKFSLAMv2_LIB EKFSLAMv2 REQUIRED)
        # FIND_LIBRARY(PYTHONQT_LIB PythonQt REQUIRED)
        # FIND_LIBRARY(PYTHONQT_ALL_LIB PythonQt_QtAll REQUIRED)
    # ELSE()
        # FIND_LIBRARY(GSLMATRIX_LIB GSLMatrixd REQUIRED)    
        # FIND_LIBRARY(EKFSLAMv2_LIB EKFSLAMv2d REQUIRED)    
        # FIND_LIBRARY(PYTHONQT_LIB PythonQtd REQUIRED)    
        # FIND_LIBRARY(PYTHONQT_ALL_LIB PythonQt_QtAlld REQUIRED)    
    # ENDIF()    
## Project Specific Settings End ###################################################################

# Sub-directories
ADD_SUBDIRECTORY(src)

# uninstall target
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

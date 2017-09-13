#
# cmake configuration file
#
# This file is part of the IRCAM SDIF Library (http://www.ircam.fr/sdif)
#
# Copyright (C) 2006 by IRCAM - Centre Pompidou, Paris, France.
#
# created by Axel Roebel                     7.12.2006
#
# This file computes/replaces some default values:
#
# CMAKE_BUILD_TYPE     : default value is "release" other selectable value is "debug"
# PKGCONFIGDIR         : /u/formes/share/lib/$ENV{SYS}/pkgconfig 
#
# The default values can be disabled by means of setting USECMAKEDEFAULTS:BOOL=ON on the command line
# if you choose this you are expected to provide reasonable values for all of the above
# variables or you are happy with the cmake defaults.
#
# On macosx and if the SDKs are available it replaces gcc/c++ by an script that sets
# an environment variable MACOSX_DEPLOYMENT_TARGET to 10.3 (for ppc architectures)
# and 10.4 (for intel architectures) 
#
# For partly replacing the default values you may run cmake twice, first to create
# a CMakeCache.txt with the above default values and second to override some of the default values
# by means of command line arguments.
#
# default values can be reestablished if the related variable is set to the value "default"
#
#  OPTIONS provided
#  USE_THREADS:BOOL=ON/OFF enable disable use of threads
#  BUILD_MING:BOOL=ON/OFF  if cygwin add -mno-cygwin to compiler commands

PROJECT(SDIF)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)

# for cmake 2.6
IF(COMMAND cmake_policy)
  CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)


FILE(READ ${PROJECT_SOURCE_DIR}/configure.in CONFIGIN)
STRING(REGEX REPLACE ".*SDIF_VERSION_MAJOR=\([0-9]+\).*" "\\1" SDIF_VERSION_MAJOR ${CONFIGIN})
STRING(REGEX REPLACE ".*SDIF_VERSION_MINOR=\([0-9]+\).*" "\\1" SDIF_VERSION_MINOR ${CONFIGIN})
STRING(REGEX REPLACE ".*SDIF_VERSION_RELEASE=\([0-9]+\).*" "\\1" SDIF_VERSION_RELEASE ${CONFIGIN})

SET(VERSION  ${SDIF_VERSION_MAJOR}.${SDIF_VERSION_MINOR}.${SDIF_VERSION_RELEASE})
SET(SDIF_VERSION  ${SDIF_VERSION_MAJOR}.${SDIF_VERSION_MINOR}.${SDIF_VERSION_RELEASE})

MESSAGE(STATUS "===============================================================")
MESSAGE(STATUS "== Configuring SDIF   ${VERSION} ")
MESSAGE(STATUS "===============================================================")

SET(PACKAGE "\"SDIF\"")

SET(CMAKE_VERBOSE_MAKEFILE false)
SET(CMAKE_SKIP_RPATH OFF)
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmModules)


# # prevent the use of the autoconf default values 
# # we impose our own handling
# EXTERNAL_CXXFLAGS=$CXXFLAGS

# AM_INIT_AUTOMAKE($PACKAGE,$VERSION)

# AM_CONFIG_HEADER(easdif/easdif_config.hpp)

INCLUDE(GET_ARCH)

IF(APPLE)
  INCLUDE(REDIRECT_COMPILERS_TO_SYSROOT OPTIONAL)
ENDIF(APPLE)

IF("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
  IF (WIN32)
    IF(CMAKE_COMPILER_IS_CYGWIN)
      OPTION(BUILD_MINGW "Build MingW Version" ON)
      IF(BUILD_MINGW)
        ADD_DEFINITIONS (-mno-cygwin )
        #SET(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -mno-cygwin")
        #SET(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -mno-cygwin")
        LIST(APPEND CMAKE_REQUIRED_DEFINITIONS -mno-cygwin)
        LIST(APPEND CMAKE_REQUIRED_FLAGS -mno-cygwin)
        LINK_LIBRARIES(-mno-cygwin)
      ENDIF(BUILD_MINGW)
    ENDIF(CMAKE_COMPILER_IS_CYGWIN)
    IF(MSVC)
      # for visual c++ 2005, don't show deprecated function warnings
      ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE=1 -D_SCL_SECURE_NO_WARNINGS=1 -D_SECURE_SCL=0 /arch:SSE)
    ENDIF(MSVC)
  ENDIF(WIN32)
  
  # set default values for build type and install prefix
  INCLUDE(SET_LOCAL_DEFAULTS OPTIONAL)
  
  IF(CMAKE_COMPILER_IS_GNUCXX )

    IF(NOT WIN32)
      INCLUDE( CheckCXXCompilerFlag)
      CHECK_CXX_COMPILER_FLAG("-fvisibility=hidden" GCC_HAS_VISIBILITY)
      IF(GCC_HAS_VISIBILITY)
        ADD_DEFINITIONS(-DGCC_HAS_VISIBILITY -fvisibility=hidden)
      ENDIF(GCC_HAS_VISIBILITY)
    ENDIF(NOT WIN32)
    # many gcc implementations enable large file support when the 
    # macro _FILE_OFFSET_BITS is compiled. We set it here, it will not harm if gcc does 
    # honor it. In that case we are using the default large file support of the compiler
    ADD_DEFINITIONS(-D_FILE_OFFSET_BITS=64)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX)
ENDIF("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")

IF   ( "$ENV{SYS}" STREQUAL "" )
  # if you set archdir then it needs to include a leading directory divider like "/i386"
  # otherwise the install_name tool on mac will not manage to fix the install_name of dynamique libraries
  SET(ARCHDIR)
  SET(INSTALL_LIB_DIR  lib)
  SET(INSTALL_BIN_DIR  bin)
ELSE ( "$ENV{SYS}" STREQUAL "" )
  # if you set archdir then it needs to include a leading directory divider like "/i386"
  # otherwise the install_name tool on mac will not manage to fix the install_name of dynamique libraries
  SET(ARCHDIR)
  SET(INSTALL_LIB_DIR lib/$ENV{SYS})
  SET(INSTALL_BIN_DIR bin/$ENV{SYS})
ENDIF( "$ENV{SYS}" STREQUAL "" )

SET(INSTALL_INC_DIR include)

SET(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR})
SET(CMAKE_INSTALL_NAME_DIR ${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR})

IF(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin${ARCHDIR})
ENDIF(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)

IF(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib${ARCHDIR})
ENDIF(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)

IF(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  IF(WIN32)
    # dlls are libraries and need to be present in the bin dir
    # so we merge library and bin output     
    SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
  ELSE(WIN32)
    SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
  ENDIF(WIN32)
ENDIF(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  

############################################################
# Checks for programs.

FIND_PROGRAM(HAVEDOT NAMES dot )

OPTION(SDIF_BUILD_STATIC "build static versions of the library" off)

## Configure SDIF

MESSAGE(STATUS "CHECK FOR HEADERS")
INCLUDE(CheckIncludeFile)

CHECK_INCLUDE_FILE(stdint.h    HAVE_STDINT_H)
CHECK_INCLUDE_FILE(stdlib.h    HAVE_STDLIB_H)
CHECK_INCLUDE_FILE(stdarg.h    HAVE_STDARG_H)
CHECK_INCLUDE_FILE(dlfcn.h     HAVE_DLFCN_H)
CHECK_INCLUDE_FILE(string.h    HAVE_STRING_H)
CHECK_INCLUDE_FILE(strings.h   HAVE_STRINGS_H)
CHECK_INCLUDE_FILE(inttypes.h  HAVE_INTTYPES_H)
CHECK_INCLUDE_FILE(memory.h    HAVE_MEMORY_H)
CHECK_INCLUDE_FILE(float.h     HAVE_FLOAT_H)
CHECK_INCLUDE_FILE(sys/stat.h  HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILE(sys/types.h HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILE(errno.h     HAVE_ERRNO_H)
CHECK_INCLUDE_FILE(unistd.h    HAVE_UNISTD_H)

# only very rough test
IF(HAVE_STDLIB_H AND HAVE_STDARG_H AND HAVE_STRING_H AND HAVE_FLOAT_H)
SET(STDC_HEADERS 1)
ENDIF(HAVE_STDLIB_H AND HAVE_STDARG_H AND HAVE_STRING_H AND HAVE_FLOAT_H)

INCLUDE(CheckFunctionExists)
CHECK_FUNCTION_EXISTS(getenv HAVE_GETENV)
CHECK_FUNCTION_EXISTS(ftruncate HAVE_FTRUNCATE)

INCLUDE(FindThreads)
OPTION(USE_THREADS "Enable threads" ON)

IF(USE_THREADS)
  IF(CMAKE_USE_PTHREADS_INIT)
    ADD_DEFINITIONS(-DHAVE_PTHREAD)
    SET(HAVE_PTHREAD 1)
    LINK_LIBRARIES (${CMAKE_THREAD_LIBS_INIT})
  ENDIF(CMAKE_USE_PTHREADS_INIT)
ENDIF(USE_THREADS)


############################################################
# Particular compiler characteristics
MESSAGE(STATUS "PARTICULAR COMPILER CHARACTERISTICS")
#dnl Check for BigEndian (WORDS_BIGENDIAN)
INCLUDE(TestBigEndian)
IF(APPLE)
  CHECK_INCLUDE_FILE(machine/endian.h    HAVE_MACHINE_ENDIAN_H)
ENDIF(APPLE)

IF(NOT HAVE_MACHINE_ENDIAN_H)  
  TEST_BIG_ENDIAN(WORDS_BIGENDIAN)
ENDIF(NOT HAVE_MACHINE_ENDIAN_H)  


#dnl Check for Long 64 bits
INCLUDE(CHECK_SIZEOF)
CHECK_SIZEOF(long 4)
#AC_CHECK_SIZEOF(long)
	

# EaSDIF Configure
IF   (CMAKE_BUILD_TYPE MATCHES debug)
  SET(DEBUGEXT _debug)
ELSE (CMAKE_BUILD_TYPE MATCHES debug)
  SET(DEBUGEXT )
ENDIF(CMAKE_BUILD_TYPE MATCHES debug)

############################################################
# dnl find SDIF objects that have to be included into Easdif
# AC_MSG_RESULT(FIND SDIF FILES)
# AC_SUBST(SDIFCPPLIB)
# SDIFCPPLIB=../SDIF/sdifcpp/libsdif-cpp.la


#CONFIGURE_FILE(SDIF/sdif/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config/config.h)
FILE(READ ${PROJECT_SOURCE_DIR}/sdif/config.h.in CONFIG)
STRING(REGEX REPLACE "#undef[ \t]*\([^ \t\n\r]*\)" "#cmakedefine \\1 @\\1@" SDIFCMCONFIG ${CONFIG})
STRING(CONFIGURE ${SDIFCMCONFIG} SDIFCMCONFIGURED)

IF(EXISTS ${PROJECT_BINARY_DIR}/sdifconfig/config.h)
  FILE(READ ${PROJECT_BINARY_DIR}/sdifconfig/config.h CURRENTCONFIG)
ENDIF(EXISTS ${PROJECT_BINARY_DIR}/sdifconfig/config.h)

IF(NOT "${CURRENTCONFIG}" STREQUAL "${SDIFCMCONFIGURED}")
  MESSAGE(STATUS "Writing sdif config")
  FILE(WRITE ${PROJECT_BINARY_DIR}/sdifconfig/config.h ${SDIFCMCONFIGURED})
ENDIF(NOT "${CURRENTCONFIG}" STREQUAL "${SDIFCMCONFIGURED}")


#select 64bit int type for position type
CHECK_SIZEOF(int64_t 0)
CHECK_SIZEOF(__int64 0)
CHECK_SIZEOF(INT64 0)
CHECK_SIZEOF("long long" 0)
CHECK_SIZEOF(loff_t 0)	# Fake default value.
CHECK_SIZEOF(off64_t 0)	# Fake default value.
CHECK_SIZEOF(off_t 1)	# Fake default value.

IF(SIZEOF_INT64_T EQUAL 8)
  MESSAGE(STATUS "use 64bit type int64_t")
  SET(SDIF_POS_TYPE "int64_t")
ELSE(SIZEOF_INT64_T EQUAL 8)
  IF( SIZEOF_OFF64_T EQUAL 8)
    MESSAGE(STATUS "use 64bit type off64_t")
    SET(SDIF_POS_TYPE   "off64_t")
  ELSE( SIZEOF_OFF64_T EQUAL 8)
    IF( SIZEOF_INT64 EQUAL 8)
      MESSAGE(STATUS "use 64bit type INT64")
      SET(SDIF_POS_TYPE   "INT64")
    ELSE( SIZEOF_INT64 EQUAL 8)
      IF( SIZEOF___INT64 EQUAL 8)
        MESSAGE(STATUS "use 64bit type __int64")
	SET(SDIF_POS_TYPE   "__int64")
      ELSE( SIZEOF___INT64 EQUAL 8)
        # Check for common 64 bit file offset types.
        IF( SIZEOF_LOFF_T EQUAL 8)
          MESSAGE(STATUS "use 64bit type loff_t")
          SET(SDIF_POS_TYPE "loff_t")
        ELSE( SIZEOF_LOFF_T EQUAL 8)
          IF( SIZEOF_LONG_LONG EQUAL 8)
            SET(SDIF_POS_TYPE   "long long")
          ELSE( SIZEOF_LONG_LONG EQUAL 8)
            IF( SIZEOF_OFF_T EQUAL 8)
              # this one may change size with compiler options
              MESSAGE(STATUS "use 64bit type off_t")
              SET(SDIF_POS_TYPE   "off_t")
            ELSE( SIZEOF_OFF_T EQUAL 8)
              MESSAGE(STATUS "no 64bit integer type found ... use long ")
              SET(SDIF_POS_TYPE   "long")              
            ENDIF( SIZEOF_OFF_T EQUAL 8)
          ENDIF( SIZEOF_LONG_LONG EQUAL 8)
        ENDIF( SIZEOF_LOFF_T EQUAL 8)
      ENDIF( SIZEOF___INT64 EQUAL 8)
    ENDIF( SIZEOF_INT64 EQUAL 8)
  ENDIF( SIZEOF_OFF64_T EQUAL 8)
ENDIF(SIZEOF_INT64_T EQUAL 8 )  


CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/include/sdif_version.h.in ${PROJECT_BINARY_DIR}/sdifconfig/sdif_version.h)
CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/include/sdif.h.in ${PROJECT_BINARY_DIR}/sdifconfig/sdif.h)

# include special traget to remove cache, system and compiler info
IF(CMAKE_GENERATOR MATCHES "^Unix Makefiles")
  INCLUDE(CLEAN_CMAKE)
  INCLUDE(CVS_Targets)
  INCLUDE(BuildTypeTargets)
ENDIF(CMAKE_GENERATOR MATCHES "^Unix Makefiles")

INCLUDE(CREATE_CVSTAGS_MACRO)
# create cvstags for current version
CREATE_CVSTAG_TARGET("SDIF_${SDIF_VERSION_MAJ}_${SDIF_VERSION_MIN}_${SDIF_VERSION_RELEASE}")

INCLUDE(SET_COMPILER_FLAGS)

ADD_DEFINITIONS("-DHAVE_CONFIG_H")

INCLUDE_DIRECTORIES( ${PROJECT_BINARY_DIR}/sdifconfig ${PROJECT_BINARY_DIR}/sdif ${PROJECT_SOURCE_DIR}/include  )

ADD_SUBDIRECTORY( sdif ) 


########### install files ###############
FILE(TO_CMAKE_PATH "${PKGCONFIGDIR}" tmp)

IF(NOT "${tmp}" STREQUAL  "")
  IF("${tmp}" MATCHES "/.*")
    SET(PKGCONFIGPATH "${tmp}" CACHE PATH "install path for pkg config files" FORCE)
    MESSAGE(STATUS "pkgconfig  abs    : ${PKGCONFIGPATH}")
  ELSE("${tmp}" MATCHES "/.*")
    IF("${tmp}" STREQUAL "default" )
      SET(PKGCONFIGPATH "${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR}/pkgconfig" CACHE PATH "install path for pkg config files" FORCE)
      MESSAGE(STATUS "pkgconfig  rel   : ${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR}/pkgconfig")
    ELSE("${tmp}" STREQUAL "default" )
      SET(PKGCONFIGPATH "${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR}/${tmp}" CACHE PATH "install path for pkg config files" FORCE)
    ENDIF("${tmp}" STREQUAL "default" )
    MESSAGE(STATUS "pkgconfig  rel   : ${PKGCONFIGPATH}")  
  ENDIF("${tmp}" MATCHES "/.*")
ENDIF(NOT "${tmp}" STREQUAL  "")

# if install path is empty set to default
IF("${PKGCONFIGPATH}" STREQUAL  "")
  SET(PKGCONFIGPATH "${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR}/pkgconfig" CACHE PATH "install path for pkg config files" FORCE)
ENDIF("${PKGCONFIGPATH}" STREQUAL  "")


IF(NOT CMAKE_BUILD_TYPE MATCHES debug)
  SET(prefix ${CMAKE_INSTALL_PREFIX})
  SET(exec_prefix ${CMAKE_INSTALL_PREFIX})
  SET(libdir ${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR})
  SET(includedir ${CMAKE_INSTALL_PREFIX}/include)
  CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/sdif.pc.in   ${PROJECT_BINARY_DIR}/sdif.pc )
  INSTALL(FILES  ${PROJECT_BINARY_DIR}/sdif.pc DESTINATION ${PKGCONFIGPATH} )
ENDIF(NOT CMAKE_BUILD_TYPE MATCHES debug)


# install sdif headers
INSTALL(FILES  ${PROJECT_BINARY_DIR}/sdifconfig/sdif_version.h DESTINATION ${INSTALL_INC_DIR})
INSTALL(FILES  ${PROJECT_BINARY_DIR}/sdifconfig/sdif.h DESTINATION ${INSTALL_INC_DIR})


ADD_SUBDIRECTORY( tools ) 
ADD_SUBDIRECTORY( test ) 


IF("${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  MESSAGE(STATUS "===================================================================")
  MESSAGE(STATUS "Option summary:")
  MESSAGE(STATUS "install prefix (CMAKE_INSTALL_PREFIX)         : ${CMAKE_INSTALL_PREFIX}")
  MESSAGE(STATUS "build static sdif lib (SDIF_BUILD_STATIC)     : ${SDIF_BUILD_STATIC}")
  MESSAGE(STATUS "enable thread support (USE_THREADS)           : ${USE_THREADS}")
  IF(APPLE)
    IF(CMAKE_OSX_SYSROOT)
      MESSAGE(STATUS "enable universal (DOUNIVERSAL)                : ${DOUNIVERSAL}" )
      IF(DOUNIVERSAL)
        MESSAGE(STATUS "Architectures                                   : ${CMAKE_OSX_ARCHITECTURES} ")
      ENDIF(DOUNIVERSAL)
    ENDIF(CMAKE_OSX_SYSROOT)
  ENDIF(APPLE)
  IF(CMAKE_COMPILER_IS_CYGWIN)
    MESSAGE(STATUS "Use mingw (BUILD_MINGW)                         : ${BUILD_MINGW}")
  ENDIF(CMAKE_COMPILER_IS_CYGWIN)

  MESSAGE(STATUS "sdif installation summary:")
  MESSAGE(STATUS "bin            : ${CMAKE_INSTALL_PREFIX}/${INSTALL_BIN_DIR}")
  MESSAGE(STATUS "lib            : ${CMAKE_INSTALL_PREFIX}/${INSTALL_LIB_DIR}")
  MESSAGE(STATUS "includes       : ${CMAKE_INSTALL_PREFIX}/${INSTALL_INC_DIR}")
  MESSAGE(STATUS "pkgconfig      : ${PKGCONFIGPATH}")
  MESSAGE(STATUS "===================================================================")
ENDIF("${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")


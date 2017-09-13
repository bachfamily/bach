#
# cmake configuration file
#
# This file is part of the IRCAM SDIF Library (http://www.ircam.fr/sdif)
#
# Copyright (C) 2006 by IRCAM - Centre Pompidou, Paris, France.
#
# created by Axel Roebel                     7.12.2006
#

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../sdif)

IF(MSVC  OR CMAKE_CXX_COMPILER_ID STREQUAL "Intel" )
  SET(MLIB)
ELSE(MSVC  OR CMAKE_CXX_COMPILER_ID STREQUAL "Intel" )
  SET(MLIB m)
ENDIF(MSVC  OR CMAKE_CXX_COMPILER_ID STREQUAL "Intel" )

ADD_EXECUTABLE(querysdif${DEBUGEXT} querysdif.c)
TARGET_LINK_LIBRARIES(querysdif${DEBUGEXT} sdif${DEBUGEXT} ${MLIB})

ADD_EXECUTABLE(sdifextract${DEBUGEXT} sdifextract.c)
TARGET_LINK_LIBRARIES(sdifextract${DEBUGEXT} sdif${DEBUGEXT} ${MLIB})

ADD_EXECUTABLE(sdiftotext${DEBUGEXT} sdiftotext.c)
TARGET_LINK_LIBRARIES(sdiftotext${DEBUGEXT} sdif${DEBUGEXT} ${MLIB})

ADD_EXECUTABLE(tosdif${DEBUGEXT} tosdif.c)
TARGET_LINK_LIBRARIES(tosdif${DEBUGEXT} sdif${DEBUGEXT} ${MLIB})

IF(CMAKE_BUILD_TYPE MATCHES release)
  INSTALL(TARGETS querysdif${DEBUGEXT} sdifextract${DEBUGEXT} sdiftotext${DEBUGEXT} tosdif${DEBUGEXT} DESTINATION ${INSTALL_BIN_DIR} )
ENDIF(CMAKE_BUILD_TYPE MATCHES release)

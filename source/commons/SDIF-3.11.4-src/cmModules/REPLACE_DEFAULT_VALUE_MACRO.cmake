# Replace default values of variable given in VARIABLE
# default will be replaced by value given in INIT and put in chache as type given as type
# value will be replaced if the cache does not yet exist and the variable given in
# USE_CMAKE_DEFAULTS is not true or if the varibale VARIABLE has the value default

MACRO (REPLACE_DEFAULT_VALUE VARIABLE TYPE INIT USE_CMAKE_DEFAULTS DOCSTRING )
  IF ( "${VARIABLE}"  STREQUAL "default")
     SET(${VARIABLE}  ${INIT}  CACHE ${TYPE} ${DOCSTRING}  FORCE)
  ELSE  ( "${VARIABLE}"  STREQUAL "default")
    IF (NOT ${USE_CMAKE_DEFAULTS})
      IF (NOT ${VARIABLE}_DEFAULTS_INIT)
        SET(${VARIABLE}  ${INIT}  CACHE ${TYPE} ${DOCSTRING}  FORCE)
        SET(${VARIABLE}_DEFAULTS_INIT  1  CACHE INTERNAL "Variable ${VARIABLE} has been initialized with default value")
      ENDIF(NOT ${VARIABLE}_DEFAULTS_INIT)
    ENDIF(NOT ${USE_CMAKE_DEFAULTS})
  ENDIF ( "${VARIABLE}"  STREQUAL "default")
ENDMACRO (REPLACE_DEFAULT_VALUE)

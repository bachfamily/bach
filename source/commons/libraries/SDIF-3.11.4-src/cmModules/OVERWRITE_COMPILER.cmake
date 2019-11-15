# Set default compiler 
MACRO(OVERWRITE_COMPILER TAG COMP)

  REPLACE_DEFAULT_VALUE(CMAKE_${TAG}_COMPILER STRING ${COMP} 0 "${TAG} compiler" )

  IF(EXISTS "${CMAKE_BINARY_DIR}/CMakeFiles/CMake${TAG}Compiler.cmake")
    FILE(READ ${CMAKE_BINARY_DIR}/CMakeFiles/CMake${TAG}Compiler.cmake TMP)
    SET(TMP2 "SET[(]CMAKE_${TAG}_COMPILER ${CMAKE_${TAG}_COMPILER}[)]")
    STRING(REPLACE "+" "[+]" TMP2 ${TMP2})
    
    IF(NOT "${TMP}" MATCHES ".*${TMP2}[ \n\r\t]*$")
      MESSAGE("APPENDING compiler info")
      EXEC_PROGRAM(echo ARGS "SET\\(CMAKE_${TAG}_COMPILER ${CMAKE_${TAG}_COMPILER}\\)"  >> ${CMAKE_BINARY_DIR}/CMakeFiles/CMake${TAG}Compiler.cmake OUTPUT_VARIABLE TMPOUT)
    ENDIF(NOT  "${TMP}" MATCHES ".*${TMP2}[ \n\r\t]*$")
  ENDIF(EXISTS "${CMAKE_BINARY_DIR}/CMakeFiles/CMake${TAG}Compiler.cmake")

ENDMACRO(OVERWRITE_COMPILER TAG COMP)

# include special targets
# cmclean to remove cache, system and compiler info
# reinit  to reinit the cache to the default values either given in CMakeLists.txt
#         or if available in ${CMAKE_SOURCE_DIR}/Modules/CMAKE_INIT_CACHE.cmake

IF(NOT CLEAN_CMAKE_INIT)

  ADD_CUSTOM_TARGET(cmclean ${CMAKE_COMMAND} -E remove ${CMAKE_CACHEFILE_DIR}/CMakeCache.txt ${CMAKE_CACHEFILE_DIR}/CMakeFiles/CMakeSystem.cmake ${CMAKE_CACHEFILE_DIR}/CMakeFiles/CMakeCXXCompiler.cmake ${CMAKE_CACHEFILE_DIR}/CMakeFiles/CMakeCCompiler.cmake)
  
  #IF  (EXISTS ${CMAKE_SOURCE_DIR}/Modules/CMAKE_CACHE_INIT.cmake)
  #ADD_CUSTOM_TARGET(reinit ${CMAKE_COMMAND} -C${CMAKE_SOURCE_DIR}/Modules/CMAKE_CACHE_INIT.cmake ${CMAKE_SOURCE_DIR})
  #ELSE(EXISTS ${CMAKE_SOURCE_DIR}/Modules/CMAKE_CACHE_INIT.cmake)
  ADD_CUSTOM_TARGET(reinit ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR})
  #ENDIF(EXISTS ${CMAKE_SOURCE_DIR}/Modules/CMAKE_CACHE_INIT.cmake)
  ADD_DEPENDENCIES(reinit cmclean)
  SET(CLEAN_CMAKE_INIT 1)
ENDIF(NOT CLEAN_CMAKE_INIT)

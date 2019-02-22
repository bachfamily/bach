# Install script for directory: /Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE DIRECTORY FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework" USE_SOURCE_PERMISSIONS)
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmusicxml2.framework/Versions/3.1.4/libmusicxml2")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -id "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmusicxml2.framework/Versions/3.1.4/libmusicxml2")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmusicxml2.framework/Versions/3.1.4/libmusicxml2")
      endif()
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2guido")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2guido" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2guido")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2guido")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2guido")
      endif()
    endif()
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2guido")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2guido" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2guido")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2guido")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2guido")
      endif()
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2ly")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2ly" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2ly")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2ly")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2ly")
      endif()
    endif()
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2ly")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2ly" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2ly")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2ly")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xml2ly")
      endif()
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlread")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlread" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlread")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlread")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlread")
      endif()
    endif()
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlread")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlread" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlread")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlread")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlread")
      endif()
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmltranspose")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmltranspose" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmltranspose")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmltranspose")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmltranspose")
      endif()
    endif()
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmltranspose")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmltranspose" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmltranspose")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmltranspose")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmltranspose")
      endif()
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlversion")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlversion" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlversion")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlversion")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlversion")
      endif()
    endif()
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlversion")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlversion" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlversion")
      execute_process(COMMAND "/opt/local/bin/install_name_tool"
        -change "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2" "libmusicxml2.framework/Versions/3.1.4/libmusicxml2"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlversion")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/xmlversion")
      endif()
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/libmusicxml/dtds/3.1")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/libmusicxml/dtds" TYPE DIRECTORY PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ DIR_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/dtds/3.1" REGEX "/\\.ds\\_store$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/libmusicxml/schema/3.1;/usr/local/share/libmusicxml/schema/3.1")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/libmusicxml/schema" TYPE DIRECTORY PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ DIR_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/dtds/3.1"
    "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/schema/3.1"
    REGEX "/\\.ds\\_store$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/libmusicxml/doc/libmusicxml2.pdf")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/libmusicxml/doc" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/doc/presentation/libmusicxml2.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/libmusicxml/CHANGELOG.txt")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/libmusicxml" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/CHANGELOG.txt")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/andreaagostini/Documents/Max 7/Packages/bach/source/commons/libmusicxml/build/libdir/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

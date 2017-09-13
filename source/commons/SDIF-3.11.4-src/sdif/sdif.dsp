# Microsoft Developer Studio Project File - Name="sdif" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=sdif - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "sdif.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sdif.mak" CFG="sdif - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sdif - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "sdif - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sdif - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /Za /W3 /GX /O2 /I "..\include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "_SdifTypesFileName %SDIFTYPES%" /YX /FD /c
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x40c /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "sdif - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /Za /W3 /Gm /GX /ZI /Od /I "..\include" /D "_DEBUG" /D "_SdifTypesFileName %SDIFTYPES%" /D "WIN32" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x40c /i "..\include" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "sdif - Win32 Release"
# Name "sdif - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\SdifCheck.c
# End Source File
# Begin Source File

SOURCE=.\SdifConvToText.c
# End Source File
# Begin Source File

SOURCE=.\SdifErrMess.c
# End Source File
# Begin Source File

SOURCE=.\SdifError.c
# End Source File
# Begin Source File

SOURCE=.\SdifFGet.c
# End Source File
# Begin Source File

SOURCE=.\SdifFile.c
# End Source File
# Begin Source File

SOURCE=.\SdifFPrint.c
# End Source File
# Begin Source File

SOURCE=.\SdifFPut.c
# End Source File
# Begin Source File

SOURCE=.\SdifFrame.c
# End Source File
# Begin Source File

SOURCE=.\SdifFrameType.c
# End Source File
# Begin Source File

SOURCE=.\SdifFRead.c
# End Source File
# Begin Source File

SOURCE=.\SdifFScan.c
# End Source File
# Begin Source File

SOURCE=.\SdifFWrite.c
# End Source File
# Begin Source File

SOURCE=.\SdifGlobals.c
# End Source File
# Begin Source File

SOURCE=.\SdifHard_OS.c
# End Source File
# Begin Source File

SOURCE=.\SdifHash.c
# End Source File
# Begin Source File

SOURCE=.\SdifHighLevel.c
# End Source File
# Begin Source File

SOURCE=.\SdifList.c
# End Source File
# Begin Source File

SOURCE=.\SdifMatrix.c
# End Source File
# Begin Source File

SOURCE=.\SdifMatrixType.c
# End Source File
# Begin Source File

SOURCE=.\SdifMemory.c
# End Source File
# Begin Source File

SOURCE=.\SdifNameValue.c
# End Source File
# Begin Source File

SOURCE=.\SdifPreTypes.c
# End Source File
# Begin Source File

SOURCE=.\SdifPrint.c
# End Source File
# Begin Source File

SOURCE=.\SdifRWLowLevel.c
# End Source File
# Begin Source File

SOURCE=.\SdifSelect.c
# End Source File
# Begin Source File

SOURCE=.\SdifSignatureTab.c
# End Source File
# Begin Source File

SOURCE=.\SdifStreamID.c
# End Source File
# Begin Source File

SOURCE=.\SdifString.c
# End Source File
# Begin Source File

SOURCE=.\SdifTest.c
# End Source File
# Begin Source File

SOURCE=.\SdifTextConv.c
# End Source File
# Begin Source File

SOURCE=.\SdifTimePosition.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\project_preinclude.h
# End Source File
# Begin Source File

SOURCE=.\SdifCheck.h
# End Source File
# Begin Source File

SOURCE=.\SdifConvToText.h
# End Source File
# Begin Source File

SOURCE=.\SdifErrMess.h
# End Source File
# Begin Source File

SOURCE=.\SdifError.h
# End Source File
# Begin Source File

SOURCE=.\SdifFGet.h
# End Source File
# Begin Source File

SOURCE=.\SdifFile.h
# End Source File
# Begin Source File

SOURCE=.\SdifFPrint.h
# End Source File
# Begin Source File

SOURCE=.\SdifFPut.h
# End Source File
# Begin Source File

SOURCE=.\SdifFrame.h
# End Source File
# Begin Source File

SOURCE=.\SdifFrameType.h
# End Source File
# Begin Source File

SOURCE=.\SdifFRead.h
# End Source File
# Begin Source File

SOURCE=.\SdifFScan.h
# End Source File
# Begin Source File

SOURCE=.\SdifFWrite.h
# End Source File
# Begin Source File

SOURCE=.\SdifGlobals.h
# End Source File
# Begin Source File

SOURCE=.\SdifHard_OS.h
# End Source File
# Begin Source File

SOURCE=.\SdifHash.h
# End Source File
# Begin Source File

SOURCE=.\SdifHighLevel.h
# End Source File
# Begin Source File

SOURCE=.\SdifList.h
# End Source File
# Begin Source File

SOURCE=.\SdifMatrix.h
# End Source File
# Begin Source File

SOURCE=.\SdifMatrixType.h
# End Source File
# Begin Source File

SOURCE=.\SdifMemory.h
# End Source File
# Begin Source File

SOURCE=.\SdifNameValue.h
# End Source File
# Begin Source File

SOURCE=.\SdifPreTypes.h
# End Source File
# Begin Source File

SOURCE=.\SdifPrint.h
# End Source File
# Begin Source File

SOURCE=.\SdifRWLowLevel.h
# End Source File
# Begin Source File

SOURCE=.\SdifSelect.h
# End Source File
# Begin Source File

SOURCE=.\SdifSignatureTab.h
# End Source File
# Begin Source File

SOURCE=.\SdifStreamID.h
# End Source File
# Begin Source File

SOURCE=.\SdifString.h
# End Source File
# Begin Source File

SOURCE=.\SdifTest.h
# End Source File
# Begin Source File

SOURCE=.\SdifTextConv.h
# End Source File
# Begin Source File

SOURCE=.\SdifTimePosition.h
# End Source File
# Begin Source File

SOURCE=.\sdiftypes.h
# End Source File
# Begin Source File

SOURCE=.\SdifVersion.h
# End Source File
# End Group
# End Target
# End Project

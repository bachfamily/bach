# $Id: Makefile.am,v 1.8 2005/05/23 19:17:53 schwarz Exp $
#
# ./sdifcpp/Makefile.am		March 2003		Axel Roebel
#
# Source file for GNU automake, generates Makefile.in.
#
#
# This file is part of the IRCAM SDIF Library (http://www.ircam.fr/sdif)
#
# Copyright (C) 1998-2003 by IRCAM - Centre Pompidou, Paris, France.
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# See file COPYING for further informations on licensing terms.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
# For any information regarding this and other IRCAM software, please
# send email to:  sdif@ircam.fr


# $Log: Makefile.am,v $
# Revision 1.8  2005/05/23 19:17:53  schwarz
# - Sdiffread*/Sdiffwrite* functions with SdifFileT instead of FILE *
#   -> eof error reporting makes more sense
# - more cleanup of sdif.h, above functions are private in SdifRWLowLevel.h
# - eEof becomes error 4 to be distinguishable from ascii chars
# - SdifFScanNameValueLCurrNVT reimplemented for ascii only
#
# Revision 1.7  2005/05/23 17:52:54  schwarz
# Unified error handling:
# - SdifErrorEnum (global errors) integrated into SdifErrorTagET (file errors)
# - no more SdifError.[ch], everything done by SdifErrMess.[ch]
#
# Revision 1.6  2005/04/19 15:30:14  schwarz
# make sdifcpp compile again for easdif:
# - removed deleted files from makefiles
# - fixed some includes that were missing (but only for C++ compilation!?)
#
# Revision 1.5  2003/11/07 21:47:19  roebel
# removed XpGuiCalls.h and replaced preinclude.h  by local files
#
# Revision 1.4  2003/08/07 16:20:44  roebel
# Fixed the fix: we do not want to install the cpp version of libsdif and we only want a static library!
#
# Revision 1.3  2003/07/21 13:41:35  tisseran
# Fixed conditionnal compilation/installation of libsdif-cpp.
#
# Revision 1.2  2003/03/18 14:56:52  roebel
# Use libtool to built conveniance library.
#
# Revision 1.1  2003/03/07 17:34:09  roebel
# cplusplus compilation is moved in its own directory.


EXTRA_LTLIBRARIES = libsdif-cpp.la 
noinst_LTLIBRARIES = @SELLIBCPP@

SDIF_H = ../include/sdif_version.h $(top_srcdir)/include/sdif.h \
	$(addprefix $(top_srcdir)/sdif/, SdifErrMess.h		\
	SdifFGet.h 	SdifSelect.h 	SdifMatrixType.h	\
	SdifFPut.h 	SdifFRead.h	SdifFScan.h 		\
	SdifFWrite.h 	SdifFile.h	SdifTest.h	 	\
	SdifFrame.h 	SdifFrameType.h SdifGlobals.h 		\
	SdifHard_OS.h 	SdifHash.h	SdifHighLevel.h 	\
	SdifList.h 	SdifMatrix.h 	SdifRWLowLevel.h	\
	sdiftypes.h	sdif_portability.h host_architecture.h )\
	../sdif/config.h 


noinst_HEADERS = $(SDIF_H) 

libsdif_cpp_la_SOURCES = \
	SdifHash.cpp       SdifGlobals.cpp      SdifSignatureTab.cpp   \
	SdifPreTypes.cpp   SdifNameValue.cpp    SdifMatrixType.cpp     \
	SdifStreamID.cpp   SdifMatrix.cpp       SdifFrame.cpp          \
	SdifTest.cpp       SdifTimePosition.cpp SdifFile.cpp           \
	SdifFGet.cpp       SdifFRead.cpp        SdifFScan.cpp          \
	SdifFPrint.cpp     SdifFWrite.cpp       SdifTextConv.cpp       \
	SdifHard_OS.cpp    SdifErrMess.cpp      SdifList.cpp           \
	SdifSelect.cpp     SdifHighLevel.cpp    SdifCheck.cpp          \
	SdifString.cpp     SdifFrameType.cpp    SdifConvToText.cpp     \
	SdifPrint.cpp      SdifRWLowLevel.cpp   SdifFPut.cpp


CLEANFILES = $(libsdif_cpp_la_SOURCES) SdifVersion.h
sdiftype = $(datadir)/SdifTypes.STYP

INCLUDES = -I../include -I$(top_srcdir)/include -I../sdif -I$(top_srcdir)/sdif -D_SdifTypesFileName=\"$(sdiftype)\" -DUSE_CONFIGURE



$(libsdif_cpp_la_SOURCES) : %.cpp : ../sdif/%.c 
	cp  $< $@

BUILT_SOURCES = $(libsdif_cpp_la_SOURCES) 

# dont use c compiler implicite rule which would override use of c++ 
%.o : %.c


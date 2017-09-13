# $Id: Makefile.am,v 1.38 2006/12/10 17:23:32 roebel Exp $
#
# ./sdif/Makefile.am		September 2000		Patrice Tisserand
#
# Source file for GNU automake, generates Makefile.in.
#
#
# This file is part of the IRCAM SDIF Library (http://www.ircam.fr/sdif)
#
# Copyright (C) 1998, 1999, 2000 by IRCAM - Centre Pompidou, Paris, France.
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
# Revision 1.38  2006/12/10 17:23:32  roebel
# Added cmake support
#
# Revision 1.37  2005/05/23 19:17:53  schwarz
# - Sdiffread*/Sdiffwrite* functions with SdifFileT instead of FILE *
#   -> eof error reporting makes more sense
# - more cleanup of sdif.h, above functions are private in SdifRWLowLevel.h
# - eEof becomes error 4 to be distinguishable from ascii chars
# - SdifFScanNameValueLCurrNVT reimplemented for ascii only
#
# Revision 1.36  2005/05/23 17:52:53  schwarz
# Unified error handling:
# - SdifErrorEnum (global errors) integrated into SdifErrorTagET (file errors)
# - no more SdifError.[ch], everything done by SdifErrMess.[ch]
#
# Revision 1.35  2005/04/07 15:56:46  schwarz
# removed some now empty local include files,
# added include of <sdif.h> and "SdifGlobals.h"
#
# Revision 1.34  2004/08/23 17:37:32  roebel
# Fixed for dist target!
#
# Revision 1.33  2004/06/03 11:18:00  schwarz
# Profiling showed some waste of cycles in byte swapping and signature reading:
# - byte swapping now array-wise, not element-wise in SdifSwap<N>[Copy] routines:   -> from 0.24 s (18.5%) to 0.14s
# - ASCII signature reading function SdiffGetSignature replaced by new binary
#   function SdiffReadSignature (also in SdifFGetSignature, so the change is
#   mostly transparent):
#   -> from 0.11 s (9.6%)  to 0.01 s
# - overall run time improvement with test case sdifextractall_a01:
#   -> from 1.20 s         to 0.86 s (40% faster)
#
# Revision 1.32  2003/11/07 21:47:18  roebel
# removed XpGuiCalls.h and replaced preinclude.h  by local files
#
# Revision 1.31  2003/11/07 15:27:33  tisseran
# Removed CKSUM computing.
# Removed generation of SdifFile.h
#
# Revision 1.30  2003/06/24 15:24:21  roebel
# Removed UniversalEnvVar.h which in fact has never been used in SDIF.
#
# Revision 1.29  2003/05/26 08:15:50  tisseran
# Added sdif.dsp in EXTRA_DIST
#
# Revision 1.28  2003/03/18 14:56:02  roebel
# Removed remaining references to cpp compilation.
#
# Revision 1.27  2003/03/07 17:33:27  roebel
# Improved handling of IRCAM include files.
#
# Revision 1.26  2002/10/30 15:48:46  schwarz
# Fixed dependency for SdifVersion.h: target is SdifFile.lo and not SdifFile.o
#
# Revision 1.25  2002/10/28 18:03:26  roebel
# Removed non portable --quiet flag of cmd. Use output redirection instead.
#
# Revision 1.24  2002/10/24 16:21:19  tisseran
# Add rpath flag to lib*_LDFLAGS (need when libraries are determined at configure time)
# See Automake Manual 9.3
#
# Revision 1.23  2002/10/24 15:48:35  tisseran
# Fix release autoconf variable name
# Add dependency between lib_sdif_*_la and SdifVersion.h
#
# Revision 1.22  2002/10/24 13:51:09  tisseran
# First version of SDIF library using libtool.
# It hasn't been tested since I can't compile at home.
# So I need to commit, for testing after logging on an ircam host....
#
# Revision 1.21  2002/10/07 12:24:14  roebel
# Fixed dependence with respect to include files in /u/formes/share/include for non ircam configuration
#
# Revision 1.20  2002/10/04 13:14:04  roebel
# Changed update check of formes include files from date comparison
# to comparison with cmp.
#
# Revision 1.19  2002/10/03 08:54:25  tisseran
# Try a fix to keep formesutils header uptodate in cvs working directory
#
# Revision 1.18  2002/09/24 13:23:08  schwarz
# Added forgotten host_configure.h to dist.
#
# Revision 1.17  2002/09/17 09:52:21  schwarz
# Added cpp-compiled library.
#
# Revision 1.16  2002/06/18 16:31:27  tisseran
# Change cp -p to cp for copying ircam header, because cp -p preserves file attributes and so keep owner of the file.
#
# Revision 1.15  2001/07/12 14:11:48  roebel
# Added include file holding library version defines to the distribution.
#
# Revision 1.14  2001/05/02 09:34:40  tisseran
# Change License from GNU Public License to GNU Lesser Public License.
#
# Revision 1.13  2001/04/20 14:04:07  tisseran
# SDIF VERSION 3.3
# Create function: SdifTakeCodedPredefinedTypesfromString (SdifFile.[hc])
# This function is use to read types from the define string SDIFTYPES_STRING
# This string is generated by perl script xmltostyp.pl
# Types definition are in the sdiftypes.xml file.
# Change in preincluded.h to NOT INCLUDE host_architecture.h when using configure
# script.
# project_preinclude.h and configure.in have been changed according to new version number.
#
# Revision 1.12  2000/12/07 13:42:21  roebel
# small reorganization of sdif/Makefile.am
#
# Revision 1.11  2000/12/06 15:01:14  roebel
# removed host_configure.h from makefiles
#
# Revision 1.10  2000/11/21 14:51:47  schwarz
# - sdif.h is now included by all sdif/Sdif*.c files.
# - Removed all public typedefs, enums, structs, and defines from the
#   individual sdif/Sdif*.h files, because they were duplicated in sdif.h.
# - Todo: Do the same for the function prototypes, decide which types and
#   prototypes really need to be exported.
# - Removed SdifFileStruct.h.
# - Preliminary new version of SdiffGetPos, SdiffSetPos.  They used the
#   type fpos_t, which is no longer a long on RedHat 7 Linux.
#
# Revision 1.9  2000/11/21 09:04:30  roebel
# Changed Makefile.am  in tools and sdif to properly use
# include files in $(topsrcdir)/sdif
#
# Revision 1.8  2000/10/31 11:22:25  roebel
# Added SDIF to Chksum/date identifier for improved retrieval
#
# Revision 1.7  2000/10/31  10:56:56  roebel
# Adjusted make file paths such that auto cksum version generation works with VPATH
#
# Revision 1.6  2000/10/30  20:28:33  roebel
# removed config.h from version cksum
#
# Revision 1.5  2000/10/30  19:05:48  roebel
# Added support for relative path compilation (VPATH)
# Added support for debugging feature in configure.in and Makefiles
#
# Revision 1.4  2000/10/30  14:28:16  roebel
# removed sdif.h from Makefile.am
#
# Revision 1.3  2000/10/30  13:54:22  roebel
# Added missing includes to SDIF_H
#
# Revision 1.2  2000/10/27  20:03:23  roebel
# autoconf merged back to main trunk
#
# Revision 1.1.2.5  2000/10/26  17:27:39  schwarz
# Added header with copyright and links to all Makefile.am and configure.in.


#EXTRA_LIBRARIES   = libsdif.a  libsdif-debug.a  libsdif-profile.a
EXTRA_LTLIBRARIES = libsdif.la libsdif-debug.la libsdif-profile.la

# lib_LIBRARIES = @SELLIB@
lib_LTLIBRARIES = @SELLIB@

SDIF_H = ../include/sdif_version.h $(top_srcdir)/include/sdif.h \
	SdifFGet.h 	SdifErrMess.h 	SdifMatrix.h		\
	SdifTest.h 	SdifStreamID.h  SdifMatrixType.h 	\
	SdifFPut.h 	SdifFRead.h	SdifFScan.h 		\
	SdifFWrite.h 	SdifFile.h      SdifSelect.h	 	\
	SdifFrame.h 	SdifFrameType.h SdifGlobals.h 		\
	SdifHard_OS.h 	SdifHash.h	SdifHighLevel.h 	\
	SdifList.h 	SdifRWLowLevel.h			\
	config.h	sdiftypes.h				\
	sdif_portability.h host_architecture.h

noinst_HEADERS = $(SDIF_H) 

libsdif_la_SOURCES = SdifHash.c       SdifGlobals.c      SdifSignatureTab.c \
		     SdifConvToText.c SdifNameValue.c    SdifMatrixType.c   \
		     SdifStreamID.c   SdifMatrix.c       SdifFrame.c        \
		     SdifTest.c       SdifTimePosition.c SdifFile.c         \
		     SdifFGet.c       SdifFRead.c        SdifFScan.c        \
		     SdifFPrint.c     SdifFWrite.c       SdifTextConv.c     \
		     SdifHard_OS.c    SdifErrMess.c      SdifList.c         \
		     SdifSelect.c     SdifHighLevel.c    SdifCheck.c        \
		     SdifString.c     SdifFrameType.c    SdifPreTypes.c     \
		     SdifPrint.c      SdifRWLowLevel.c   SdifFPut.c
 

libsdif_debug_la_SOURCES   = $(libsdif_la_SOURCES)
libsdif_profile_la_SOURCES = $(libsdif_la_SOURCES)

libsdif_la_LDFLAGS         = -no-undefined -release @VERSION@ -rpath $(libdir)
libsdif_debug_la_LDFLAGS   = $(libsdif_la_LDFLAGS) -rpath $(libdir)
libsdif_profile_la_LDFLAGS = $(libsdif_la_LDFLAGS) -rpath $(libdir) -pg

sdiftype   = $(datadir)/SdifTypes.STYP

EXTRA_DIST = sdif.dsp CMakeLists.txt


INCLUDES   = -I../include -I$(top_srcdir)/include -D_SdifTypesFileName=\"$(sdiftype)\" -DUSE_CONFIGURE


$(libsdif_a_SOURCES) :  $(FORMES_H:%=$(top_srcdir)/sdif/%)
$(libsdif_la_SOURCES) : $(FORMES_H:%=$(top_srcdir)/sdif/%)

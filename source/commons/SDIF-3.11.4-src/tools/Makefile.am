# $Id: Makefile.am,v 1.14 2006/12/10 17:24:11 roebel Exp $
#
# ./tools/Makefile.am		September 2000		Patrice Tisserand
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
#
# $Log: Makefile.am,v $
# Revision 1.14  2006/12/10 17:24:11  roebel
# Added cmake support
#
# Revision 1.13  2004/06/03 11:34:17  schwarz
# Enable profiling compilation.
# Don't read padding when skipping matrices!
#
# Revision 1.12  2003/05/26 08:16:17  tisseran
# Added Visual C++ project files for SDIF tools.
#
# Revision 1.11  2002/12/02 17:33:50  tisseran
# Fix link in debug mode
#
# Revision 1.10  2002/10/10 10:40:10  roebel
# Added support for c++ compilation.
#
# Revision 1.9  2002/09/24 13:36:25  schwarz
# Need to define VERSION for tools.
#
# Revision 1.8  2001/07/12 14:11:47  roebel
# Added include file holding library version defines to the distribution.
#
# Revision 1.7  2001/05/02 09:34:54  tisseran
# Change License from GNU Public License to GNU Lesser Public License.
#
# Revision 1.6  2000/11/21 09:04:32  roebel
# Changed Makefile.am  in tools and sdif to properly use
# include files in $(topsrcdir)/sdif
#
# Revision 1.5  2000/10/31 11:46:32  roebel
# Added makefile dependency of all progs from generated library
#
# Revision 1.4  2000/10/30  19:05:54  roebel
# Added support for relative path compilation (VPATH)
# Added support for debugging feature in configure.in and Makefiles
#
# Revision 1.3  2000/10/30  14:44:02  roebel
# Moved all tool sources into central tools directory and added config.h to sources
#
# Revision 1.2  2000/10/27  20:04:17  roebel
# autoconf merged back to main trunk
#
# Revision 1.1.2.2  2000/10/26  17:27:47  schwarz
# Added header with copyright and links to all Makefile.am and configure.in.


# tell automake all programs possibly built 
# (literally, no macro substitutions at this stage!)
EXTRA_PROGRAMS = \
	querysdif	  sdifextract	      sdiftotext	 tosdif \
	querysdif-debug   sdifextract-debug   sdiftotext-debug   tosdif-debug \
	querysdif-profile sdifextract-profile sdiftotext-profile tosdif-profile

# these are actually built (set by configure)
bin_PROGRAMS = @PROGLIST@


querysdif_debug_SOURCES=querysdif.c
sdifextract_debug_SOURCES=sdifextract.c
sdiftotext_debug_SOURCES=sdiftotext.c
tosdif_debug_SOURCES=tosdif.c

querysdif_profile_SOURCES=querysdif.c
sdifextract_profile_SOURCES=sdifextract.c
sdiftotext_profile_SOURCES=sdiftotext.c
tosdif_profile_SOURCES=tosdif.c

querysdif_debug_LDADD = ../sdif/libsdif-debug.la
querysdif_debug_DEPENDENCIES= ../sdif/libsdif-debug.la
querysdif_debug_LDFLAGS = -static
sdifextract_debug_LDADD = ../sdif/libsdif-debug.la
sdifextract_debug_LDFLAGS = -static
sdifextract_debug_DEPENDENCIES=../sdif/libsdif-debug.la
sdiftotext_debug_LDADD = ../sdif/libsdif-debug.la
sdiftotext_debug_LDFLAGS = -static
sdiftotext_debug_DEPENDENCIES=../sdif/libsdif-debug.la
tosdif_debug_LDADD = ../sdif/libsdif-debug.la
tosdif_debug_LDFLAGS = -static
tosdif_debug_DEPENDENCIES=../sdif/libsdif-debug.la

querysdif_profile_LDADD = ../sdif/libsdif-profile.la
querysdif_profile_DEPENDENCIES= ../sdif/libsdif-profile.la
querysdif_profile_LDFLAGS = -static
sdifextract_profile_LDADD = ../sdif/libsdif-profile.la
sdifextract_profile_LDFLAGS = -static
sdifextract_profile_DEPENDENCIES=../sdif/libsdif-profile.la
sdiftotext_profile_LDADD = ../sdif/libsdif-profile.la
sdiftotext_profile_LDFLAGS = -static
sdiftotext_profile_DEPENDENCIES=../sdif/libsdif-profile.la
tosdif_profile_LDADD = ../sdif/libsdif-profile.la
tosdif_profile_LDFLAGS = -static
tosdif_profile_DEPENDENCIES=../sdif/libsdif-profile.la

querysdif_LDADD = -l$(basename $(subst lib,,@SELLIB@))
querysdif_LDFLAGS = -L../sdif
querysdif_DEPENDENCIES=../sdif/@SELLIB@
sdifextract_LDADD = -l$(basename $(subst lib,,@SELLIB@))
sdifextract_LDFLAGS = -L../sdif
sdifextract_DEPENDENCIES=../sdif/@SELLIB@
sdiftotext_LDADD = -l$(basename $(subst lib,,@SELLIB@))
sdiftotext_LDFLAGS = -L../sdif
sdiftotext_DEPENDENCIES=../sdif/@SELLIB@
tosdif_LDADD = -l$(basename $(subst lib,,@SELLIB@))
tosdif_LDFLAGS = -L../sdif
tosdif_DEPENDENCIES=../sdif/@SELLIB@

INCLUDES  = -I../include -I$(top_srcdir)/include -I$(top_srcdir)/sdif
CFLAGS   = @CFLAGS@ '-DVERSION="$(VERSION)"'

EXTRA_DIST=querysdif.dsp sdifextract.dsp sdiftotext.dsp sdifusage.dsp tosdif.dsp CMakeLists.txt


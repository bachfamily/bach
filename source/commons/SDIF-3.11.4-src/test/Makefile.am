# $Id: Makefile.am,v 1.15 2006/12/10 17:24:11 roebel Exp $
#
# ./test/Makefile.am		September 2000		Patrice Tisserand
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
# Revision 1.15  2006/12/10 17:24:11  roebel
# Added cmake support
#
# Revision 1.14  2004/06/03 11:33:05  schwarz
# Complete profiling harness with a list of test cases with variable
# arguments, pre-/postprocessing, logging, etc.
# All output is saved into the prof directory.  The .mon.out files should
# be kept for reference, the .gprof files can be regenerated from that.
#
# Revision 1.13  2004/06/02 14:46:27  schwarz
# Added profiling target to check runtime spent in which functions
#
# Revision 1.12  2002/10/10 10:39:06  roebel
# Removed configure-variable @TESTLIB@ which can be derived from @SELLIB@.
#
# Revision 1.11  2002/09/24 13:20:34  schwarz
# Added forgotten test programs to dist.
#
# Revision 1.10  2002/06/18 16:56:00  tisseran
# Create two shell script to launch headerTest and NVTTest binary.
# I do this to call script shell with an explicit shell ( $(SHELL) in TESTS_ENVIRONMENT).
# It prevents to search how to change execution right on files.
#
# Revision 1.9  2001/07/12 14:11:48  roebel
# Added include file holding library version defines to the distribution.
#
# Revision 1.8  2001/05/02 09:34:52  tisseran
# Change License from GNU Public License to GNU Lesser Public License.
#
# Revision 1.7  2000/12/07 13:42:21  roebel
# small reorganization of sdif/Makefile.am
#
# Revision 1.6  2000/12/07 12:59:58  roebel
# Reorganized test suite to be sensitive to wrong endianness
#
# Revision 1.5  2000/10/31 11:46:28  roebel
# Added makefile dependency of all progs from generated library
#
# Revision 1.4  2000/10/30  19:05:49  roebel
# Added support for relative path compilation (VPATH)
# Added support for debugging feature in configure.in and Makefiles
#
# Revision 1.3  2000/10/30  16:30:00  roebel
# Added INCLUDES variable:
#    INCLUDES = -I../include
# to find user level sdif.h
#
# Revision 1.2  2000/10/27  20:04:01  roebel
# autoconf merged back to main trunk
#
# Revision 1.1.2.2  2000/10/26  17:27:40  schwarz
# Added header with copyright and links to all Makefile.am and configure.in.


SUBDIRS = files
EXTRA_DIST = $(TESTS) xpianoRes.m5.FIL.sdif CMakeLists.txt

noinst_PROGRAMS = headerTest NVTTest testcheck testselect
noinst_HEADERS = utils.h
headerTest_SOURCES = test1.c utils.c
headerTest_DEPENDENCIES = ../sdif/@SELLIB@
NVTTest_SOURCES = test2.c utils.c
NVTTest_DEPENDENCIES = ../sdif/@SELLIB@
testcheck_SOURCES = testcheck.c
testcheck_DEPENDENCIES = ../sdif/@SELLIB@
testselect_SOURCES = testselect.c
testselect_DEPENDENCIES = ../sdif/@SELLIB@

LDADD = -l$(basename $(subst lib,,@SELLIB@))
LDFLAGS = -L../sdif
INCLUDES = -I../include -I$(top_srcdir)/include

SDIFTYPES	  = $(top_srcdir)/data/SdifTypes.STYP 
TESTS_ENVIRONMENT = SDIFTYPES=$(SDIFTYPES) $(SHELL)
#TESTS = test_conv2  headerTest NVTTest cmd_testcheck
TESTS = test_conv2  test_Header test_NVT cmd_testcheck



#
# profiling targets
#

# settings and paths
prof     = gprof -b
proffile = a01
profdata = /net/slentem/data2/caterpillar/sounds/bach-menuhin/$(proffile).sdif
profarg  = -T $(SDIFTYPES) $(profdata)

# list of programs to profile (prof_<tag>) and with which args (parg_<tag>)

# copy sdif through sdifextract without selection, verify file identicality
prep_sdifextractall_a01 = -rm /tmp/$(proffile).sdif
prof_sdifextractall_a01 = sdifextract
parg_sdifextractall_a01 = $(profarg)		    /tmp/$(proffile).sdif
post_sdifextractall_a01 = diff -s $(profdata) /tmp/$(proffile).sdif

# copy with frame selection
prof_sdifextractfrm_a01 = sdifextract
parg_sdifextractfrm_a01 = $(profarg)::1FQ0@0-139.42 /tmp/$(proffile)frm.sdif

# copy with matrix row selection
prof_sdifextractmtx_a01 = sdifextract
parg_sdifextractmtx_a01 = $(profarg)::/1TRI_2       /tmp/$(proffile)mtx.sdif

# query
prof_querysdif_a01	= querysdif
parg_querysdif_a01	= -t $(SDIFTYPES) -d $(profdata)

# to text conversion, to test text output
prof_sdiftotext_a01	= sdiftotext
parg_sdiftotext_a01	= -t $(SDIFTYPES) -i $(profdata) -o /tmp/$(proffile).txt
# from text conversion, test text input
prof_tosdif_a01		= tosdif
parg_tosdif_a01		= -t $(SDIFTYPES) -i /tmp/$(proffile).txt -o /tmp/$(proffile).txt.sdif


PROFEXE		  = ../tools/$(prof_$*)-profile
PROFTAG		  = prof/$*-$(VERSION)$(descr)

prof: prof_sdifextractfrm_a01 prof_sdifextractmtx_a01 prof_sdifextractall_a01 \
      prof_querysdif_a01 prof_sdiftotext_a01 prof_tosdif_a01

# copy sdif
prof_%:
	@echo; echo; echo "[profiling $(PROFTAG)]"
	$(prep_$*) # preparations of $*
	/usr/bin/time -p $(PROFEXE) $(parg_$*) | tee $(PROFTAG).log | head -30
	$(post_$*) # postprocessing of $*
#
	@echo; echo "[generating reports for $(PROFTAG)]"; echo
	@$(prof)    $(PROFEXE) gmon.out >$(PROFTAG).gprof   # flat + call graph
	@$(prof) -l $(PROFEXE) gmon.out >$(PROFTAG).gprof-l # line by line
	@$(prof) -A $(PROFEXE) gmon.out >$(PROFTAG).gprof-A # ann. prog listing
	@mv gmon.out $(PROFTAG).mon.out

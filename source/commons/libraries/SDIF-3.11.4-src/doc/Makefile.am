# $Id: Makefile.am,v 1.10 2009/08/11 14:16:55 diemo Exp $
#
# ./doc/Makefile.am             September 2000          Patrice Tisserand
#
# Source file for GNU automake, generates Makefile.in.
#
# now merged with:
#
# doc/Makefile			4. November 1998	Diemo Schwarz
#
# Makefile for automatic documentation.


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
# Revision 1.10  2009/08/11 14:16:55  diemo
# Remove standards doc and publication make rule, since
# SDIF documentation has moved to the sdif-website CVS module
#
# Revision 1.9  2009/08/10 17:20:35  diemo
# new server for web files,
# update standards doc also
#
# Revision 1.8  2008/09/18 14:04:48  diemo
# publish doc on sourceforge
# N.B.: DON'T USE THIS, BUT USE THE SDIF-WEBSITE MODULE
#
# Revision 1.7  2003/03/18 14:22:52  roebel
# Fixed trailing backslash before empty line
#
# Revision 1.6  2003/03/07 17:33:00  roebel
# Removed wildcard by explicite list of files. Automake does not handle
# wildcards correctly.
#
# Revision 1.5  2001/10/26 15:04:18  schwarz
# Made Makefile.am output the old, carefully hand-crafted Makefile, plus
# the automake blabber.  Had to change some variable names (no '-'),
# remove ifs, fix gcc -E who suddenly doesn't like unbalanced comments
# in strings any more, and take care of CVS and Makefiles when cleaning.
#
# This is the first step to a true autoconf'ed doc generation, where the
# install host and directory are user-configurable, and the doc
# generation program's version and existence is checked for by
# configure.  (Maybe that will no longer be cocoon then --- it refuses
# to run and is awkward anyway.)
#
# Revision 1.4  2001/05/02 09:34:38  tisseran
# Change License from GNU Public License to GNU Lesser Public License.
#
# Revision 1.3  2000/10/30 11:35:08  roebel
# mv from state dead to state up-to-date to override cvs bg
#
# Revision 1.1.2.2  2000/10/26  17:27:32  schwarz
# Added header with copyright and links to all Makefile.am and configure.in.


# This is the old Log: Makefile,v:
#
# Revision 3.9  2000/10/27 20:02:49  roebel
# autoconf merged back to main trunk
#
# Revision 3.8  2000/08/27  15:21:22  schwarz
# Added standards dir, local install option when on installhost.
#
# Revision 3.7  2000/08/22  16:34:16  schwarz
# Added tutorial.
#
# Revision 3.6  2000/08/07  15:12:04  schwarz
# Cocoon is installed for groups now, more docs.
#
# Revision 3.5  2000/07/19  18:10:13  schwarz
# Added todo section to internal doc.
#
# Revision 3.4  1999/10/07  15:22:10  schwarz
# Added trademark notice in index.
#
# Revision 3.3  1999/08/26  15:29:23  schwarz
# Cocoon (3.2) works only on fresh dir.
# Simplified installation: Don't rely on make on install host (and
# that all the generating programs work there), but generate locally,
# then copy on install host and postprocess cocoon, replacing local links.
#
# Revision 3.2  1999/04/30  13:45:53  schwarz
# Don't blurp horrible perl code, rather lightly put decent
# "Gendoc from to" message.
#
# Revision 3.1  1999/03/14  10:54:42  virolle
# SdifStdErr add
#
# Revision 2.3  1999/01/21  16:36:23  schwarz
# Beefed up the SDIF library user manual.  It now has the sections
# User Manual		(as before, but with navigating toc frame and
# 			 crosslinked to the function reference)
# Function Reference	(automatic cocoon doc with navigating toc)
# Tutorial		(coming soon, a quick introduction to get started)
# Utilities		(description of the utility programs coming with
# 			 the library)
#
# Revision 2.2  1999/01/06  14:50:13  schwarz
# Automatic Cocoon documentation of the sdif library in one single web
# page.  It comes in two flavours: intern and extern.  Intern
# describes ALL functions and data structures, extern describes only
# the API that users of the library should use.
#
# Revision 2.1  1998/12/21  18:26:48  schwarz
# Inserted copyright message.
#
# Revision 2.0  1998/11/29  11:20:51  virolle
# english documentation for SDIF norm.
#
# Revision 1.1  1998/11/10  14:56:40  schwarz
# Added makefile to generate cocoon documentation.


# this is for automake
EXTRA_DIST = Patch.html          SdifNormBar.html    SdifProgBar.html \
	 download.html     indexNorm.html SdifManuelBar.html \
	 SdifNormDoc.html    SdifProgDoc.html  index.html  \
	 indexProg.html SdifManuelDoc.html  SdifNormDocFr.html  Todo.html   \
         indexManuel.html

SUBDIRS = pics extern


# this is the original hand-crafted Makefile

# web pages are accessible from INSTALLHOST and to be placed to INSTALLDIR
INSTALLHOST	= maelzel
INSTALLDIR	= /usr/local/www/ircam/equipes/analyse-synthese/sdif
INSTALLURLBASE	= /equipes/analyse-synthese/sdif

# files and directories to copy to webserver
INSTALLSRC	= Makefile $(wildcard *.html) $(INSTALLDIRS)
INSTALLDIRS	= pics standard extern intern


# these are all overriden when installing
HERE		= $(subst /a/,/net/,$(PWD))
ABS_ROOT	= $(HERE)/..
WEBBASE		= $(HERE)
URLBASE		= $(HERE)

# ($* is what matches % in a pattern rule)
COCOONDIR	= $*/cocoon
WEBROOT		= $(WEBBASE)/$(COCOONDIR)
URLROOT		= $(URLBASE)/$(COCOONDIR)
#INSTALLURL	= cocoon
INSTALLURL	= $(INSTALLURLBASE)/$(COCOONDIR)
#		  http://www.ircam.fr/$(INSTALLURLBASE)/$(COCOONDIR)

COCOON		= cocoon	# /u/formes/schwarz/bin/$(ARCH)/cocoon
PREPROC		= gcc -E -P -ansi -x c 
INSTALLHTML	= perl -pi -e '$$c+=s|(href="*)$(URLROOT)|$$1$(INSTALLURL)|ig;'\
			   -e 'END { print STDERR "$$c substitutions\nof   $(URLROOT)\nwith $(INSTALLURL)\n"; }'

#ifneq ($(HOST), $(INSTALLHOST))
	rsh	= rsh $(INSTALLHOST)
	sep	= \;
#else
#	rsh	=
#	sep	= ;
#endif

makedependency	= # Makefile # when changing preprocessor options
headerdir	= $(ABS_ROOT)/sdif
headerfiles	= $(wildcard $(headerdir)/*.h)	# same as $(shell ls .../*.h)

matlabdlarch 	= download/sdif-matlab.tar.gz
matlabdldir	= $(HOME)/src/formesutils/matlab
matlabdlbase	= loadsdif writesdif
matlabdlfiles	= $(foreach sufx,m mexaxp mexlx,$(matlabdlbase:%=%.$(sufx))) \
		  loadsdiffile.m loadsdifflat.m sdifexist.m

VPATH		= pics intern extern

.PHONY:		tutorial

%.html:		%.tex
		hevea -fix -exec xxdate.exe $< -o $@

all:		cocoon html
html:		eframes iframes
.PHONY:		cocoon eframes iframes abc new clean iclean eclean

tut:		tutc tutorial reload
tutc:		extern/tutorial.c $(HOME)/src/SDIF/autoconf/SDIF-3.2.0/include/sdif.h
		gcc -I$(HOME)/src/SDIF/autoconf/SDIF-3.2.0/include \
		    -L$(HOME)/src/SDIF/autoconf/SDIF-3.2.0/sdif \
		    $< -lsdif
#		gcc -I/u/formes/include/sdif -L$(HOME)/lib/i686/Linux_2.2.5 

tutorial:	extern/tutorial-doc.html
extern/tutorial-doc.html:	extern/tutorial-doc.tex

#
# cocoon
#

cocoon:		ext extern/alpha-toc.html int intern/alpha-toc.html 
abc:		extern/alpha-toc.html intern/alpha-toc.html
new:		clean all

reload:
		netscape -remote 'reload()'
show:		showintern
show%:		%
		netscape -remote 'openURL(file:$(WEBROOT)/SDIF.html)'

int: 		intern/cocoon/SDIF.lnk
ext: 		extern/cocoon/SDIF.lnk


intern_defs	= "-DSENTINELS=nosentinels" \
		  "-DMEMBERSENTINEL=librarysentinel xxxnosentinelxxx" \
		  "-DCUSTOMIZE="

extern_defs	= "-DSENTINELS="  "-DMEMBERSENTINEL=membersentinel /EMPTY*DOC:" \
		  "-DCUSTOMIZE=librarysentinel xxxnosentinelxxx"


%/cocoon/SDIF.lnk:	sdif.%.cocoon
		-find $(@D) -type f \! -name M\* -ls -exec $(RM) '{}' \; 	# cocoon 3.2 works only on clean dir
		$(COCOON) -s -x $<	# -s: leave SDIF.lnk 

# generate cocoon config file for one big web page with all defs
sdif.%.cocoon:	sdif.src $(headerfiles) $(makedependency)
		@echo Generating cocoon config file $@ from $<
		$(PREPROC) $< -o $@  $($*_defs) \
			-DWEBROOT=$(WEBROOT) -DURLROOT=$(URLROOT) \
			"-DLIBRARY=library SDIF $(ABS_ROOT)/sdif/ ."


# alphabetical list of all declarations

ahead_extern	= <a href="$(URLROOT)/SDIF.html\#data" target=doc><strong>Data Structures</strong></a><br>\
		  <a href="$(URLROOT)/SDIF.html\#functions" target=doc><strong>Function Prototypes</strong></a><br><br>

ahead_intern	= $(ahead_extern)

%/alpha-toc.html:	%/cocoon/SDIF.lnk Makefile
		@echo Gendoc $< $@
		@sort $< | perl -n -e '\
		BEGIN { print qq|<body bgcolor=white>\n$(ahead-$*)\n\
				 <strong>All Declarations:</strong><br>\n|; } \
		END {print "</body>";} \
		s|\\#|$(URLROOT)/SDIF.html#|; s|<a href=|<a target=doc href=|;\
		split "%";  print "$$_[2]<br>\n"' >$@

# make substitution file for anchor to replace function names in
# SdifManuelDoc.html by bold link to def in cocoon doc 
%/linkit.lnk:	%/cocoon/SDIF.lnk Makefile
		@echo Gendoc $< $@
		@perl -n -e '\
		s|\\#|cocoon/SDIF.html\\#|;  s|<a href=|<a href=|; \
		split "%";  print "%$$_[1]%<b>$$_[2]</b>%\n"' $< >$@


#
# augmented HTML
#

eindsuf		= by-subject alpha tutorial utilities
iindsuf		= by-subject alpha todo
emain		= $(eindsuf:%=extern/%-main.html)
esec		= $(eindsuf:%=extern/%-sec.html)
egenerated	= $(emain) $(esec) extern/by-subject-doc.html \
				   extern/tutorial-doc.html
imain		= $(iindsuf:%=intern/%-main.html)
isuf		= $(iindsuf:%=intern/%-sec.html)
igenerated	= $(imain) $(isuf) intern/by-subject-doc.html

var_by_subject	= SUBJECT
var_alpha	= ALPHA
var_tutorial	= TUTORIAL
var_utilities	= UTILITIES
var_todo	= TODO
doc_by_subject	= by-subject-doc.html
doc_alpha	= cocoon/SDIF.html\#functions
doc_tutorial	= tutorial-doc.html
doc_utilities	= utilities-doc.html
doc_todo	= ../Todo.html
src_extern	= SdifManuelDoc.html
src_intern	= SdifProgDoc.html

selcolor	= bgcolor="yellow"
ewarn		= 's"(\$$Id.*\$$)"DO NOT EDIT!!!\n     This file $@ is generated from $<\n     $$1\n     by the Makefile target eframes.\n";'


eframes:	$(egenerated)
iframes:	$(igenerated)

# dependencies
$(emain):	extern/default-main.html
$(esec):	extern/default-sec.html
$(imain):	intern/default-main.html
$(isec):	intern/default-sec.html

# avoid making (thus destroying) these source files!
%/default-sec.html %/default-main.html:
		@echo Preserving $@

%-sec.html:	default-sec.html Makefile
		@echo Gendoc $(@D)/$(<F) $@
		@perl -p -e $(ewarn) -e 's!$(var_$(*F))!$(selcolor)!;' $(@D)/$(<F) >$@

%-main.html:	default-main.html Makefile
		@echo Gendoc $(@D)/$(<F) $@
		@perl -p -e $(ewarn) -e 's!default-doc\.html!$(doc_$(*F))!;' \
		     -e 's!default-(sec|toc)\.html!$(*F)-$$1.html!;' $(@D)/$(<F) >$@


# use cocoon's anchor to replace function names in
# SdifManuelDoc.html by bold link to def in cocoon doc 
%/by-subject-doc.html:	%/linkit.lnk $(src-$*)
		@echo Gendoc $(src-$(*F)) $@
		@anchor $< $(src-$(*F)) $@
		@perl -pi -e $(ewarn) -e 's|(src="*)pics|$$1../pics|;' $@


#
# Install
#

install:	$(INSTALLSRC) 
		$(rsh) 	cp -rf $(INSTALLSRC:%=$(PWD)/%) $(INSTALLDIR) $(sep) \
		  	$(MAKE) -C $(INSTALLDIR) URLBASE=$(URLBASE) \
				postinst_intern postinst_extern
#\				$(matlabdlarch)

installdl:
		$(rsh)  cp -rf $(PWD)/Makefile $(INSTALLDIR) $(sep) \
		  	$(MAKE) -C $(INSTALLDIR) URLBASE=$(URLBASE)
#\				$(matlabdlarch)


# this is running on INSTALLHOST!
postinst-%:
		@echo ----- replacing links in $(INSTALLDIR)/$*
		@find $(INSTALLDIR)/$* -name \*.html -print \
		| xargs $(INSTALLHTML)

#$(matlabdlarch): download $(matlabdlfiles:%=$(matlabdldir)/%)
#		tar cvf - -C $(matlabdldir) $(matlabdlfiles) | gzip -9 >$@

# DON'T! publish standards doc on sourceforge, this has moved to the sdif-website module
pub-sf:
		@echo The SDIF documentation has moved to the sdif-website CVS module

# cvs -z3 -d:ext:developername@sdif.cvs.sourceforge.net:/cvsroot/sdif co -P -d cvsroot-sdif CVSROOT
# cvs -z3 -d:ext:diemo@sdif.cvs.sourceforge.net:/cvsroot/sdif co -P -d cvsroot-sdif CVSROOT

#
# Misc
#

clean:		eclean iclean
		rm -f intern/cocoon/* extern/cocoon/* sdif.*.cocoon

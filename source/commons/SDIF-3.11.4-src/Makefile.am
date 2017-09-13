# $Id: Makefile.am,v 1.38 2009/10/19 17:02:02 diemo Exp $
#
# ./Makefile.am		September 2000			Patrice Tisserand
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
# Revision 1.38  2009/10/19 17:02:02  diemo
# new upload host and dir, again
#
# Revision 1.37  2009/08/10 16:57:26  diemo
# frs changed again...
#
# Revision 1.36  2009/01/07 16:10:27  diemo
# include examples dir in target and dist
#
# Revision 1.35  2008/09/18 16:08:35  diemo
# include Info.plist, update readme, remove zip before uploading, remove SdifVersion.h
#
# Revision 1.34  2008/09/18 15:29:37  diemo
# clarified last misunderstanding between autotools and me:
#
# TO MAKE A FILE RELEASE ON SOURCEFORGE, DO:
#
#    make pub
#
# Revision 1.33  2008/09/18 15:19:50  diemo
# include current updated SDIF.xcodeproj, generated sdif_version.h for mac building out of the box
# TO MAKE A FILE RELEASE ON SOURCEFORGE, DO:
#
#    make -k pub
#
# Revision 1.32  2008/09/18 14:03:53  diemo
# adapt to sf frs, publish src and mac ub framework only
#
# Revision 1.31  2006/12/10 17:13:40  roebel
# Added cmake e.support
#
# Revision 1.30  2006/05/11 16:39:13  schwarz
# publish standard
#
# Revision 1.29  2005/05/13 16:28:57  schwarz
# new host
#
# Revision 1.28  2004/08/26 17:13:19  schwarz
# ReleaseNotes
# some echo's don't know -e, is it needed?
#
# Revision 1.27  2004/08/26 17:12:54  schwarz
# ReleaseNotes
# some echo's don't know -e, is it needed?
#
# Revision 1.26  2004/07/13 15:28:16  roebel
# Fixed cvstag target to be able to use it from working directories that are not the top
# source directory.
#
# Revision 1.25  2004/02/02 19:09:28  schwarz
# Fix rpm build target, thanks to Patrice.
# Build ALL archs.
#
# Revision 1.24  2004/01/29 14:20:16  schwarz
# update ChangeLog
# use rpmbuild -ba for rpm -ba on RH 9, should be configured
#
# Revision 1.23  2003/07/21 13:40:45  tisseran
# Fixed conditionnalk compilation/installation of libsdif-cpp.
#
# Revision 1.22  2003/06/13 10:05:40  schwarz
# Added latest projectbuilder mac os X project to cvs and dist.
# Library version is 3.8.0-beta until we decide to announce the official release,
# to avoid confusion.
#
# Revision 1.21  2003/05/23 17:28:40  schwarz
# Dammit! win and mac build directories winbuild and maxosxbuild,
# 	not yet used since you have to change the projects first.
#
# Revision 1.20  2003/05/01 18:51:59  roebel
# Fixed double declaration of EXTRA_DIST variable.
#
# Revision 1.19  2003/04/09 16:36:11  roebel
# Fixed publish-ftp target.
#
# Revision 1.18  2003/04/09 12:28:25  roebel
# Changed default configuration back to enable-shared but added
# README.MacOSX to announce problems with shared libraries to users.
#
# Revision 1.17  2003/04/06 16:28:57  roebel
# Added to CVS
#
# Revision 1.16  2003/03/07 17:55:01  roebel
# Added switch for doc compilation.
#
# Revision 1.15  2003/03/07 17:31:37  roebel
# cplusplus compilation is moved in its own directory.
#
# Revision 1.14  2002/10/31 16:35:36  schwarz
# Added sdif.vcproj
# More info for dist.
#
# Revision 1.13  2002/10/30 17:25:33  schwarz
# Ouf, finally proper distribution building: a src.tar.gz and a binary
# rpm (thanks to Patrice, but use with caution).
# publish-ftp doesn't actually work...
#
# Revision 1.12  2002/10/30 16:09:20  schwarz
# Better src dependency.
# No doc included in dist (wants to make old cocoon doc...)
#
# Revision 1.11  2002/10/30 15:54:01  schwarz
# Added necessary files to dist.
# Added src distribution target.
# Updated publish method (not tested).
#
# Revision 1.10  2002/08/29 16:07:09  tisseran
# Add support of pkg-config for SDIF library.
# After installation, now you can use:
# pkg-config --cflags --libs sdif
# to have correct compilation flags
#
# Revision 1.9  2001/05/04 14:07:26  tisseran
# Liitle fix:
# - Change a c++ commentary in a c one (sdif.h line:1532)
# - Change publihs rules of main Makefile, now name of asrc archive on www.ircam.fr/sdif/download
# is SDIF-(version)-src.tar.gz
#
# Revision 1.8  2001/05/02 09:34:36  tisseran
# Change License from GNU Public License to GNU Lesser Public License.
#
# Revision 1.7  2001/04/26 14:51:59  tisseran
# ARRGGHHH how can I remove all this stupid log@!@!@@!
#
# Revision 1.6  2001/04/26 14:47:01  tisseran
# Correct a stupid error in previous log (arrggghh DON'T USE C COMMENTARY in cvs log).
# Correct Makefile.am, change cvstag rules:
# cvstags:
# 	cvs -F tags $(CVSTAGS)
# Add some explication in file ChangeLog
#
# Revision 1.5  2001/04/20 17:55:07  schwarz
# Added publish target that sets the cvs tag, generates the distribution
# and copies it to the download directory on the web host.
# Call as "make DISTHOST=yourwebhost publish"
#
# Revision 1.4  2001/04/20 17:35:45  schwarz
# Oops, make doesn't like a rule and a variable of the same name.
#
# Revision 1.3  2001/04/20 17:33:35  schwarz
# Added cvstag target and publish target to publish a new version.
# Removed all Makefile.in from CVS.
#
# Revision 1.2  2000/10/27 20:02:42  roebel
# autoconf merged back to main trunk
#
# Revision 1.1.2.4  2000/10/26  17:27:16  schwarz
# Added header with copyright and links to all Makefile.am and configure.in.

if COND_COMPILE_DOC
DOC_SRC_DIR = doc
else
DOC_SRC_DIR =
endif 

if ENABLECPP
SDIF_CPP_DIR=sdifcpp
else
SDIF_CPP_DIR=
endif

SUBDIRS = sdif include tools data examples test $(SDIF_CPP_DIR) macosxbuild $(DOC_SRC_DIR)

DIST_SUBDIRS = sdif include tools data examples test  macosxbuild doc sdifcpp cmModules

sdifincdir = @top_srcdir@/include

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = sdif.pc

grep:
	grep $a sdif/*.[ch] /dev/null

doc: 
	cd doc; $(MAKE) -f Makefile.doc

ircam_deps:
	@cd sdif; $(MAKE) ircam_deps

test:	check



#
# DISTRIBUTION
#

# more files to include in dist
EXTRA_DIST	  = ReleaseNotes sdif.vcproj sdif.dsw CMakeLists.txt 


# base name of distribution (override automake generated variable to make source distribution!)
distbase	  = $(PACKAGE)-$(VERSION)
distdir		  = $(distbase)-src
PUBLISH_DIST      = $(distdir).zip
PUBLISH_FRAMEWORK = $(distbase)-MacOSX-framework-ub.zip
PUBLISH_RPM	  = $(distbase)-1.*.rpm
PUBLISH_SRPM	  = $(distbase)-1.src.rpm

# build optimised for these platforms:
PUBLISH_ARCH	  = i386,i486,i586,i686,athlon


$(PUBLISH_DIST):  $(distdir)
		  -rm $@
		  -zip -r $@ $^

# this is where the xcode project leaves the framework
MAC_BUILD_DIR	  = macosxbuild/build/Deployment
MAC_FRAMEWORK	  = SDIF.framework

framework:	$(PUBLISH_FRAMEWORK)	
$(PUBLISH_FRAMEWORK): $(MAC_BUILD_DIR)/$(MAC_FRAMEWORK)
		cd $(MAC_BUILD_DIR); \
		zip -r $@ $(MAC_FRAMEWORK)
		mv $(MAC_BUILD_DIR)/$@ .

# make a binary rpm (experimental)
rpm:		$(rpmdir) sdif.spec dist
		cp $(PUBLISH_DIST) $(rpmdir)/SOURCES
		rpmbuild --define="_topdir $(rpmdir)" --target $(PUBLISH_ARCH) \
			 -ba $(top_builddir)/sdif.spec
		cp $(rpmdir)/RPMS/{$(PUBLISH_ARCH)}/$(PUBLISH_RPM) $(top_builddir)
		cp $(rpmdir)/SRPMS/$(PUBLISH_SRPM) $(top_builddir)

# create directory structure necessary for rpmbuild to work
rpmdir = /tmp/$(USER)-rpm
$(rpmdir):
		mkdir -p $@/{BUILD,RPMS/{noarch,$(PUBLISH_ARCH)},SOURCES,SPECS,SRPMS}


#
# PUBLISH (on server)
#

# use this to check if the distribution works, tag the cvs project, 
# make a source distribution and rpm, and copy it to the web server
pub:		distdir publish-sf
publish pub-src: distcheck cvstag dist publish-sf
publish-rpm:	distcheck cvstag dist rpm publish-sf

# more files to publish (on server)
EXTRA_PUBLISH     = README COPYING AUTHORS INSTALL ChangeLog ReleaseNotes # doc

# call this as "make PW=<yourpassword> PUBLISH_HOST=<yourwebhost> publish" 
# to publish a new version on an ftp server
# this might work differently for other places
# todo: configure PUBLISH_HOST
PUBLISH_ROOT      = sdif
PUBLISH_FILES_DL  = $(EXTRA_PUBLISH) \
		    $(PUBLISH_DIST) $(PUBLISH_RPM) $(PUBLISH_SRPM) 

# sourceforge user name!
PUBLISH_USER      = diemo
PUBLISH_HOST      = frs.sourceforge.net
PUBLISH_DIR	  = /home/frs/project/s/sd/sdif/sdif/$(distbase)


# upload only source dist to sourceforge file release system
publish-sf:	$(PUBLISH_DIST) $(PUBLISH_FRAMEWORK) ReleaseNotes
		rsync -auv $^ $(PUBLISH_USER),sdif@$(PUBLISH_HOST):$(PUBLISH_DIR)

# tag the cvsrepository with the current version 
# (to exactly reconstitute a published version)
CVSTAG	      = $(shell echo $(PACKAGE)_lib_version_$(VERSION) | tr . _)
cvstag:
		cd  @top_srcdir@;cvs tag -F $(CVSTAG)


.PHONY:		grep doc ircam_deps test publish publish-ftp rpm cvstag
.PRECIOUS:	$(distdir)

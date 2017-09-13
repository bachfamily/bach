# $Id: Makefile.am,v 1.6 2008/12/18 11:56:37 diemo Exp $
#
# SDIF/macosxbuild/Makefile.am	
#
# just to include Mac ProjectBuilder compilation project to source
# distribution
#
# $Log: Makefile.am,v $
# Revision 1.6  2008/12/18 11:56:37  diemo
# add some plist files to distribution
#
# Revision 1.5  2008/09/18 16:08:35  diemo
# include Info.plist, update readme, remove zip before uploading, remove SdifVersion.h
#
# Revision 1.4  2008/09/18 15:19:51  diemo
# include current updated SDIF.xcodeproj, generated sdif_version.h for mac building out of the box
# TO MAKE A FILE RELEASE ON SOURCEFORGE, DO:
#
#    make -k pub
#
# Revision 1.3  2004/01/29 13:36:27  schwarz
# add xcode to dist
# redefinition of distdir seems no longer necessary
#
# Revision 1.2  2003/07/08 14:54:14  schwarz
# seemed to need an all: target
#
# Revision 1.1  2003/06/13 10:05:41  schwarz
# Added latest projectbuilder mac os X project to cvs and dist.
# Library version is 3.8.0-beta until we decide to announce the official release,
# to avoid confusion.


SUBDIRS		=  SDIF.xcodeproj

# distdir		= $(PACKAGE)-$(VERSION)-src

# more files to include in dist
EXTRA_DIST 	= README.MacOSX Info.plist texttosdif-Info.plist sdiftotext-Info.plist

all:
		echo "Use Apple build tools to build for Mac OS X"

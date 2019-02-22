# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.RandomMusic.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/RandomMusic
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/RandomMusic:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/RandomMusic


PostBuild.countnotes.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/countnotes
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/countnotes:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/countnotes


PostBuild.musicxml2.Debug:
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/libmusicxml2:
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/libmusicxml2


PostBuild.partsummary.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/partsummary
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/partsummary:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/partsummary


PostBuild.readunrolled.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/readunrolled
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/readunrolled:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/readunrolled


PostBuild.xml2guido.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2guido
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2guido:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2guido


PostBuild.xml2ly.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2ly
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2ly:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2ly


PostBuild.xml2midi.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2midi
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2midi:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xml2midi


PostBuild.xmlclone.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlclone
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlclone:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlclone


PostBuild.xmlfactory.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlfactory
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlfactory:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlfactory


PostBuild.xmliter.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmliter
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmliter:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmliter


PostBuild.xmlread.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlread
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlread:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlread


PostBuild.xmltranspose.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmltranspose
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmltranspose:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmltranspose


PostBuild.xmlversion.Debug:
PostBuild.musicxml2.Debug: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlversion
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlversion:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/xmlversion


PostBuild.RandomMusic.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/RandomMusic
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/RandomMusic:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/RandomMusic


PostBuild.countnotes.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/countnotes
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/countnotes:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/countnotes


PostBuild.musicxml2.Release:
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/libmusicxml2:
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/libmusicxml2


PostBuild.partsummary.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/partsummary
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/partsummary:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/partsummary


PostBuild.readunrolled.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/readunrolled
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/readunrolled:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/readunrolled


PostBuild.xml2guido.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2guido
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2guido:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2guido


PostBuild.xml2ly.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2ly
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2ly:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2ly


PostBuild.xml2midi.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2midi
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2midi:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xml2midi


PostBuild.xmlclone.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlclone
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlclone:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlclone


PostBuild.xmlfactory.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlfactory
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlfactory:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlfactory


PostBuild.xmliter.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmliter
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmliter:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmliter


PostBuild.xmlread.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlread
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlread:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlread


PostBuild.xmltranspose.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmltranspose
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmltranspose:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmltranspose


PostBuild.xmlversion.Release:
PostBuild.musicxml2.Release: /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlversion
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlversion:\
	/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2
	/bin/rm -f /Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/xmlversion




# For each target create a dummy ruleso the target does not have to exist
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Debug/libmusicxml2.framework/Versions/3.1.4/libmusicxml2:
/Users/andreaagostini/Documents/Max\ 7/Packages/bach/source/commons/libmusicxml/build/libdir/Release/libmusicxml2.framework/Versions/3.1.4/libmusicxml2:

# $Id: Makefile.am,v 1.5 2009/04/09 09:54:11 diemo Exp $
#
# examples/Makefile.am             December 2008          Diemo Schwarz
#
# build and distribute example source code
#
# $Log: Makefile.am,v $
# Revision 1.5  2009/04/09 09:54:11  diemo
# force linking with freshly built lib
#
# Revision 1.4  2009/01/07 16:12:14  diemo
# link list-nvt example with freshly built lib
#
# Revision 1.3  2009/01/07 11:40:04  diemo
# added nvt listing example
#
# Revision 1.2  2009/01/05 16:00:58  diemo
# trying to add source code to dist, not working yet
#

INCLUDES  = -I../include -I$(top_srcdir)/include -I$(top_srcdir)/sdif
CFLAGS   = @CFLAGS@ '-DVERSION="$(VERSION)"'

libsdif = $(top_srcdir)/sdif/.libs/libsdif.a

# this is for automake
EXTRA_DIST = list-types.c list-nvt.c

all:		list-types list-nvt

list-types: 	list-types.c $(libsdif)
		gcc -I../include -g  -o $@ $^

list-nvt: 	list-nvt.c  $(libsdif)
		gcc $(LDFLAGS) -I../include -g  -o $@ $^

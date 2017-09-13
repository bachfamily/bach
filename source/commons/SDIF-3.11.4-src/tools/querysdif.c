/* $Id: querysdif.c,v 1.17 2011/04/12 14:20:17 roebel Exp $
 
                Copyright (c) 1998 by IRCAM - Centre Pompidou
                           All rights reserved.
 
   For any information regarding this and other IRCAM software, please
   send email to:
                             sdif@ircam.fr
 

   querysdif.c		10.12.1998	Diemo Schwarz
   
   View summary of data in an SDIF-file.  
   

   $Log: querysdif.c,v $
   Revision 1.17  2011/04/12 14:20:17  roebel
   Removed unused variable, and fixed return code to be nonzero in case file is empty.

   Revision 1.16  2009/08/10 16:24:24  diemo
   - added flags to switch header, nvt, and type def printing

   Revision 1.15  2009/08/10 16:16:18  diemo
   - reimplemented querysdif using SdifQuery for consistency
   - added header printing

   Revision 1.14  2008/12/10 19:22:45  bogaards
   support for frames that do not contain any matrix

   Revision 1.13  2007/11/27 12:21:02  roebel
   prevent compiler warnings.

   Revision 1.12  2006/12/08 18:11:49  roebel
   Use configured version instead of compiler command line switch.

   Revision 1.11  2006/05/05 10:31:40  schwarz
   exit on invalid sdif header

   Revision 1.10  2006/05/03 15:46:51  schwarz
   added brief output option

   Revision 1.9  2004/06/03 11:34:17  schwarz
   Enable profiling compilation.
   Don't read padding when skipping matrices!

   Revision 1.8  2003/11/07 22:12:45  roebel
   Removed XpGuiCalls remainings.

   Revision 1.7  2003/11/07 21:47:19  roebel
   removed XpGuiCalls.h and replaced preinclude.h  by local files

   Revision 1.6  2003/06/04 20:32:25  schwarz
   Finally: do statistics about matrix sizes.

   Revision 1.5  2002/05/24 19:41:51  ftissera
   Change code to be compatible with C++

   Revision 1.4  2000/12/06 13:43:43  lefevre
   Mix HostArchiteture and AutoConfigure mechanisms

   Revision 1.3  2000/11/16  12:02:23  lefevre
   no message
  
   Revision 1.2  2000/11/15  14:53:40  lefevre
   no message
  
   Revision 1.1  2000/10/30  14:44:03  roebel
   Moved all tool sources into central tools directory and added config.h to sources
  
   Revision 1.2  2000/10/27  20:04:18  roebel
   autoconf merged back to main trunk
  
   Revision 1.1.2.3  2000/08/21  18:48:49  tisseran
   Use SdifFSkipFrameData
  
   Revision 1.1.2.2  2000/08/21  16:42:12  tisseran
   *** empty log message ***
  
   Revision 1.1.2.1  2000/08/21  13:42:24  tisseran
   *** empty log message ***
  
   Revision 3.2  1999/06/18  16:20:28  schwarz
   In SigEqual: SdifSignatureCmpNoVersion (s, sigs [i].sig) dropped LAST byte
   on alpha (this is fixed now), and anyway, we want to compare the whole sig.

   Revision 3.1  1999/03/14  10:56:24  virolle
   SdifStdErr add

   Revision 1.3  1999/02/28  12:16:31  virolle
   memory report

   Revision 1.2  1998/12/21  18:26:54  schwarz
   Inserted copyright message.

   Revision 1.1  1998/12/10  18:55:40  schwarz
   Added utility program querysdif to view the summary of data in
   an SDIF-file.
*/


#include "sdif_portability.h"

#include "sdif.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void usage (void)
{
    fprintf (SdifStdErr, "\nquerysdif, %s\n\n", SDIF_VERSION_STRING);
    SdifPrintVersion();
    fprintf (SdifStdErr, "\n"
"Usage: querysdif [options] [sdif-file]\n"
"\n"
"Options: (no options mean: show all information)\n"
"	-a	view ASCII chunks\n"
"	-d	view data\n"
"	-b	view data brief (output in SDIF selection syntax)\n"
"	-n	view NVTs (name value tables)\n"
"	-T	view type declarations in sdif-file\n"
/* todo:
"	-D	view all type declarations in effect\n"
*/
"	-H	view file header info\n"
"	-t <sdif types file>  specify file with additional sdif types\n"
"	-V	print SDIF library version\n"
"	-h	this help\n"
"\n"
"View summary of data in an SDIF-file.  Per default, all ASCII chunks are\n"
"printed, followed by a count of the frames and the matrices occuring in\n"
"the file.\n"
"\n");

    exit(1);
}

/* flags with default values */
int		vall	  = 1,
 		vascii	  = 0,
		vdata	  = 0,
		vbrief	  = 0,
		vnvt	  = 0,
		vtypes	  = 0,
		valltypes = 0,
		vheader	  = 0; 

static int PrintHeaders (SdifFileT *file, void *userdata)
{
    file->TextStream = stdout;	/* SdifFPrint* functions need this */

    if (vall || vheader)
    {
	printf("Header info of file %s:\n\n", file->Name);
	printf("Format version: %d\n", file->FormatVersion);
	printf("Types version:  %d\n\n", file->TypesVersion);
    }

    if (vall || vascii)
    {
	printf("Ascii chunks of file %s:\n\n", file->Name);
	SdifFPrintAllASCIIChunks(file);
    }

    if (vnvt && SdifNameValuesLIsNotEmpty(file->NameValues))
    {
	SdifFPrintAllNameValueNVT(file);
	printf("\n");
    }

    if (vtypes  &&  (SdifExistUserMatrixType(file->MatrixTypesTable)  ||
		     SdifExistUserFrameType(file->FrameTypesTable)))
    {
      SdifFPrintAllType(file);
      printf("\n");
    }

    return vall || vdata;	/* continue reading data? */
}


/*--------------------------------------------------------------------------*/
/*	KERmain / main															*/
/*--------------------------------------------------------------------------*/

#if HOST_OS_MAC

int KERmain(int argc, char** argv);
int KERmain(int argc, char** argv)

#else

int main(int argc, char** argv);
int main(int argc, char** argv)

#endif
{
    SdifQueryTreeT *sigs;
    int             nread, i, m;

    /* arguments with default values */
    char 	   *infile = NULL, 
		   *types  = NULL;

    SdifStdErr = stderr;
    for (i = 1; i < argc; i++)
    {
	if (argv [i][0] == '-')
	{
	    char *arg = argv [i] + 1;

	    while (*arg)
		switch (*arg++)
		{
		  case 'a': vall = 0;  vascii    = 1;  break;
		  case 'd': vall = 0;  vdata     = 1;  break;
		  case 'b': vall = 0;  vdata = vbrief = 1;  break;
		  case 'n': vall = 0;  vnvt      = 1;  break;
		  case 'T': vall = 0;  vtypes    = 1;  break;
/* todo:	  case 'D': vall = 0;  valltypes = 1;  break;
 */		  case 'H': vall = 0;  vheader   = 1;  break;
		  case 't': /* no arg after last option, complain */
			    if (i == argc - 1)   
				usage ();
			    types = argv [++i];	       break;
		  case 'V':  SdifPrintVersion();       break;
		  default :  usage();		       break;
		}
	}
	else if (!infile)
	    infile = argv [i];
	else
	    usage();
    }


    /* do inits, open files */
    if (!types)
    {
	char types2[2] = "";
	SdifGenInit (types2);
    }
    else
    {
	SdifGenInit (types);
    }

    if (!infile)   
    	infile  = "stdin";

    /* init query tree struct */
    sigs = SdifCreateQueryTree(1024);
    
    /* perform query */
    nread = SdifQuery(infile, PrintHeaders, sigs);

    if (vall || vdata)
    {	/* print data content */
	if (vbrief)
	{   /* brief selection-syntax output without counts */
	    for (i = 0; i < sigs->num; i++)
	    {
		if (sigs->elems[i].parent == -1)
		{   /* search children matrices of this frame */
		    int numChildMatrices = 0;
		    for (m = 0; m < sigs->num; m++)
		    {
			if (sigs->elems[m].parent == i){
			    printf ("#%d:%s/%s@%f-%f\n", 
				    sigs->elems[i].stream,
				    SdifSignatureToString (sigs->elems[i].sig),
				    SdifSignatureToString (sigs->elems[m].sig),
				    sigs->elems[i].time.min,
				    sigs->elems[i].time.max);
			    numChildMatrices++;
			}
		    }
		    if(numChildMatrices == 0){
			// frame had no child matrix. This can be the case for 1MRK frames that consist of only a time
			printf ("#%d:%s@%f-%f\n", 
				sigs->elems[i].stream,
				SdifSignatureToString (sigs->elems[i].sig),
				sigs->elems[i].time.min,
				sigs->elems[i].time.max);
		    }
		} 
	    }
	}
	else
	{
	    printf ("Data in file %s (%u bytes):\n", infile, (unsigned int) nread);

	    for (i = 0; i < sigs->num; i++)
	    {
		if (sigs->elems[i].parent == -1)
		{   /* frames */
		    printf ("%5d %s frames in stream %d between time %f and %f containing\n", 
			    sigs->elems[i].count, 
			    SdifSignatureToString (sigs->elems[i].sig),
			    sigs->elems[i].stream,
			    sigs->elems[i].time.min,
			    sigs->elems[i].time.max);

		    /* search children matrices of this frame */
		    for (m = 0; m < sigs->num; m++)
		    {
			if (sigs->elems[m].parent == i)
			    printf ("   %5d %s matrices with %3g --%3g rows, %3g --%3g columns\n",
				    sigs->elems[m].count, 
				    SdifSignatureToString (sigs->elems[m].sig),
				    sigs->elems[m].nrow.min,
				    sigs->elems[m].nrow.max,
				    sigs->elems[m].ncol.min,
				    sigs->elems[m].ncol.max);
		    }
		}
	    }
	    printf ("\n");
	}
    }

    /* cleanup */
    SdifFreeQueryTree(sigs);
    SdifGenKill ();

    return nread == 0;
}    

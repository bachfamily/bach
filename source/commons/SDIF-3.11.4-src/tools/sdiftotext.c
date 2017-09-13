/* $Id: sdiftotext.c,v 1.8 2009/08/10 16:41:26 diemo Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * sdiftotext.c
 *
 * $Log: sdiftotext.c,v $
 * Revision 1.8  2009/08/10 16:41:26  diemo
 * accept in/outfile without -i/-o also
 *
 * Revision 1.7  2006/01/09 10:21:01  ellis
 * minimal set of files to add XP-gui to the sdif tools
 *
 * Revision 1.6  2003/11/07 22:25:20  roebel
 * Removed last remainings of XpGuiCalls from tools files.
 *
 * Revision 1.5  2003/11/07 21:47:20  roebel
 * removed XpGuiCalls.h and replaced preinclude.h  by local files
 *
 * Revision 1.4  2003/11/07 12:09:09  ellis
 * Added the declaration of of two functions in the header file
 * SdifFAllFrameTypeToSdifString and SdifFAllMatrixTypeToSdifString
 *
 * Revision 1.3  2000/12/06 13:43:44  lefevre
 * Mix HostArchiteture and AutoConfigure mechanisms
 *
 * Revision 1.2  2000/11/16  12:02:23  lefevre
 * no message
 *
 * Revision 1.1  2000/10/30  14:44:04  roebel
 * Moved all tool sources into central tools directory and added config.h to sources
 *
 * Revision 1.2  2000/10/27  20:04:21  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.3  2000/08/21  17:08:44  tisseran
 * *** empty log message ***
 *
 * Revision 1.1.2.2  2000/08/21  16:18:39  tisseran
 * *** empty log message ***
 *
 * Revision 1.1.2.1  2000/08/21  13:42:38  tisseran
 * *** empty log message ***
 *
 * Revision 3.1  1999/03/14  10:57:56  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/02/28  12:17:03  virolle
 * memory report
 *
 * Revision 2.2  1998/12/21  18:28:01  schwarz
 * Inserted copyright message.
 *
 * Revision 2.1  1998/12/09  15:05:50  virolle
 * no segmentation fault when opening failed.
 *
 * Revision 2.0  1998/11/29  11:44:33  virolle
 * Use of new function names (SdifCurr... --> SdifFCurr...).
 *
 * Revision 1.3  1998/05/04  15:33:15  schwarz
 * Added option -t to specify types file to load for sdiftotext.
 * Increased version to 1.01.01.
 *
 */


#include "sdif_portability.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sdif.h"


void
usage(void)
{
  fprintf(SdifStdErr, "\nsdiftotext, %s\n\n", SDIF_VERSION_STRING);
  SdifPrintVersion();
  fprintf(SdifStdErr, "\n\
Usage: sdiftotext [options] infile [outfile (default is \"stdout\")]\n\
options:\n\
 -e <file>:   error file (default is \"stderr\")\n\
 -t <file>:   sdif types file (default is env SDIFTYPES\n\t\tor \"SdifTypes.STYP\" in current dir)\n");
  exit(1);
}



char *
GetArgOfOption(int *iArg, int argc, char**argv)
{
    if (argv[*iArg][2] == '\0')  /* argument of option is the next argv : : -<option><spaces><argofoption> */
    {
	(*iArg)++;
	if (*iArg < argc)
	    return &(argv[*iArg][0]);
	else
	    usage();
    }
    else  /* argument of option is just after the option : -<option><argofoption> */
    {
	return &(argv[*iArg][2]);
    }
    return NULL;
}




/*--------------------------------------------------------------------------*/
/*	KERmain / main															*/
/*--------------------------------------------------------------------------*/

#ifdef USE_XPGUI

int KERmain(int argc, char** argv);
int KERmain(int argc, char** argv)

#else

int main(int argc, char** argv);
int main(int argc, char** argv)

#endif
{
    int
	SizeR = 0,
	iArg = 1,
	result = 0;

    char
	*PreSdifTypes	= NULL,
	*InF		= NULL,
	*OutF		= NULL,
	*ErrF		= NULL;

    SdifFileT *SdifF;

    SdifStdErr = stderr;

    iArg = 1;
    while (iArg < argc)
    {
	if (argv[iArg][0] == '-'  &&  argv[iArg][1] != 0)
	{
	    switch (argv[iArg][1])
	    {
	    case 'i' :
		InF = GetArgOfOption(&iArg, argc, argv);
		break;
	    case 'o' :
		OutF = GetArgOfOption(&iArg, argc, argv);
		break;
	    case 'e':
		ErrF = GetArgOfOption(&iArg, argc, argv);
		SdifStdErr = fopen(ErrF, "wb");
		break;
	    case 't':
		PreSdifTypes = GetArgOfOption(&iArg, argc, argv);
		break;
	    default:
		usage();
	    }
	}
	else if (argc - iArg > 2)
	{   /* more than 2 non-option args given: complain */
	    usage();
	}
	else
	{
	    if (!InF)
		InF = argv[iArg];
	    else
		OutF = argv[iArg];
	}
	iArg++;
    }


    if (!OutF)		OutF = "stdout";
    if (!InF)		InF  = "stdin";
    if (!PreSdifTypes)	PreSdifTypes  = "";

    SdifGenInit (PreSdifTypes);

    SdifF = SdifFOpen (InF, eReadFile);
    if (SdifF)
    {
	SizeR = SdifToText (SdifF, OutF);
	/* check for error */
	if (SdifFLastError(SdifF) == NULL)
	    result = 0;
	else
	    result = 1;
	SdifFClose (SdifF);
    }
    fprintf(SdifStdErr, "%16.1d bytes have been read from \"%s\".\n", SizeR, InF);

    SdifGenKill (); 

    if (ErrF) fclose(SdifStdErr);

    return(result);
}




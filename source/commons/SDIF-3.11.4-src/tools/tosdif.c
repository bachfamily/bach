/* $Id: tosdif.c,v 1.6 2006/12/08 18:11:57 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 *
 * $Log: tosdif.c,v $
 * Revision 1.6  2006/12/08 18:11:57  roebel
 * Use configured version instead of compiler command line switch.
 *
 * Revision 1.5  2003/11/07 22:25:27  roebel
 * Removed last remainings of XpGuiCalls from tools files.
 *
 * Revision 1.4  2003/11/07 21:47:20  roebel
 * removed XpGuiCalls.h and replaced preinclude.h  by local files
 *
 * Revision 1.3  2000/12/06 13:43:44  lefevre
 * Mix HostArchiteture and AutoConfigure mechanisms
 *
 * Revision 1.2  2000/11/16  12:02:24  lefevre
 * no message
 *
 * Revision 1.1  2000/10/30  14:44:04  roebel
 * Moved all tool sources into central tools directory and added config.h to sources
 *
 * Revision 1.2  2000/10/27  20:04:22  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.3  2000/08/21  16:42:24  tisseran
 * *** empty log message ***
 *
 * Revision 1.1.2.2  2000/08/21  16:18:42  tisseran
 * *** empty log message ***
 *
 * Revision 1.1.2.1  2000/08/21  13:42:44  tisseran
 * *** empty log message ***
 *
 * Revision 3.2  2000/03/01  10:41:30  schwarz
 * New matrix data type eText -> rename eText to eTextIn
 *
 * Revision 3.1  1999/03/14  10:58:15  virolle
 * SdifStdErr add
 *
 * Revision 2.5  1999/02/28  12:17:06  virolle
 * memory report
 *
 * Revision 2.4  1999/01/23  15:56:13  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.3  1999/01/23  13:58:04  virolle
 * General Lists, and special chunk preparation to become frames
 *
 *
 *
 */


#include "sdif_portability.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sdif.h"

enum TypeInE
{
  eTextIn
};


void
usage(void)
{
  fprintf(SdifStdErr, "\ntosdif, %s\n\n", SDIF_VERSION_STRING);
  SdifPrintVersion();
  fprintf(SdifStdErr, "\nUsage : tosdif [-i <file>] [-o <file>] [-e <file>] [-t <file>] [-T]\n\
 i :   input file (default is \"stdin\")\n\
 o :   output file (default is \"stdout\")\n\
 e :   error file (default is \"stderr\")\n\
 t :   sdif types file (default is env SDIFTYPES\n\t\tor \"SdifTypes.STYP\" in current dir)\n\
 T :   input is a pseudo-sdif text file\n");
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

#if HOST_OS_MAC

int KERmain(int argc, char** argv);
int KERmain(int argc, char** argv)

#else

int main(int argc, char** argv);
int main(int argc, char** argv)

#endif
{
    int
	TypeIn = eTextIn,
	SizeW,
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
	if (argv[iArg][0] == '-')
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
	    case 'T' :
		TypeIn = eTextIn;
		break;
	    default:
		usage();
	    }
	}
	else
	    usage();
	iArg++;
    }


    if (!OutF)		OutF = "stdout";
    if (!InF)		InF  = "stdin";
    if (!PreSdifTypes)	PreSdifTypes  = "";


    SdifGenInit (PreSdifTypes);


    SdifF = SdifFOpen (OutF, eWriteFile);

    if (SdifF)
    {
      switch (TypeIn)
      {
      case eTextIn :
      default :
	  SizeW = SdifTextToSdif (SdifF, InF);
	  break;
      }
      /* check for error */
      if (SdifFLastError(SdifF) == NULL)
	  result = 0;
      else
	  result = 1;
      SdifFClose (SdifF);
      fprintf(SdifStdErr, "%16.1d bytes have been written into \"%s\".\n", SizeW, OutF);
    }

    SdifGenKill ();


    if (ErrF) fclose(SdifStdErr);
    
    return result;
}


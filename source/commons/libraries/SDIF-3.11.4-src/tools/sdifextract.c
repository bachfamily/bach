/* $Id: sdifextract.c,v 1.18 2012/01/02 23:49:08 roebel Exp $
 
                Copyright (c) 1998 by IRCAM - Centre Pompidou
                           All rights reserved.
 
   For any information regarding this and other IRCAM software, please
   send email to:
                             manager@ircam.fr
 

   sdifextract.c		9.11.1998	Diemo Schwarz
   
   Extract data from an SDIF-file.  
   
   $Log: sdifextract.c,v $
   Revision 1.18  2012/01/02 23:49:08  roebel
   Base selection of WIN32 specific implementation on definition of macros  WIN32 OR _WIN32. The latter being standard in
   Visual C++ it is most important to have it.

   Revision 1.17  2006/05/03 15:47:25  schwarz
   added data only output option

   Revision 1.16  2005/05/13 16:04:59  schwarz
   more rows/columns

   Revision 1.15  2005/04/05 15:58:23  bogaards
   added time ouput format to extract only the times of selected frames

   Revision 1.14  2004/06/17 18:30:05  roebel
   Fixed padding calculation. Only count bytes read for  matrices, because
   frames are by default aligned.

   Revision 1.13  2003/11/07 22:25:16  roebel
   Removed last remainings of XpGuiCalls from tools files.

   Revision 1.12  2003/11/07 21:47:19  roebel
   removed XpGuiCalls.h and replaced preinclude.h  by local files

   Revision 1.11  2003/03/18 14:20:59  roebel
   Fixed seg fault on MacOSX - large arrays are now global

   Revision 1.10  2002/05/24 19:41:51  ftissera
   Change code to be compatible with C++

   Revision 1.9  2001/09/11 13:04:27  roebel
   sdifextract sdif output bug fixed

   Revision 1.8  2001/07/19 14:24:36  lefevre
   Macintosh Compilation

 * Revision 1.7  2001/07/02  15:31:16  lambert
 * Added frame types table to the output file header cpoied from the input
 * file.
 *
   Revision 1.6  2001/05/04 11:32:40  lambert
   Little modifications for Win32:
     - <io.h> included for this platform.
     - <get> define renamed to <hard_defined_get>.
     - <maxintsel> defined to 32768 (overflow on Windows NT with the old value,
       65536).

   => TODO: get rid of theses defines.

   Revision 1.5  2001/02/08 15:26:56  tisseran
   Add a test on memory allocation in SdifStringNew (call perror if malloc return a NULL pointer).
   Note on sdifextract.c:
   	- Rechange SdifSkipFrameData to SdifFSkipFrameData (change by axel have disappeared)

   Revision 1.4  2000/12/06 13:43:43  lefevre
   Mix HostArchiteture and AutoConfigure mechanisms

 * Revision 1.3  2000/11/16  12:02:23  lefevre
 * no message
 *
 * Revision 1.2  2000/10/30  16:22:11  roebel
 * Merge changes proposed by Schwarz:
 * Removed _SdifFError by fprintf to remove dependency on low-level
 *    function.
 * Using CVS revision as version for sdifextract.
 * Use SdifFSkipFrameData for SdifSkipFrameData.
 *
 * Revision 1.1  2000/10/30  14:44:03  roebel
 * Moved all tool sources into central tools directory and added config.h to sources
 *
 * Revision 1.2  2000/10/27  20:04:20  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.4  2000/08/21  21:36:11  tisseran
 * *** empty log message ***
 *
 * Revision 1.1.2.3  2000/08/21  16:42:19  tisseran
 * *** empty log message ***
 *
 * Revision 1.1.2.1  2000/08/21  13:42:32  tisseran
 * *** empty log message ***
 *
   Revision 3.6  2000/06/02  12:57:30  schwarz
   Fixed crash-on-XpExit bug.

   Revision 3.5  2000/05/15  16:22:10  schwarz
   Changed prototypes of existing functions (we apologize for the inconvenience)
   SdifFCurrFrameIsSelected and SdifFCurrMatrixIsSelected.
   They now take only an SdifFileT as parameter, no longer a selection.
   If you don't want to test the file selection (automatically
   parsed from the filename), use these new functions like this:
   SdifFrameIsSelected  (file->CurrFramH, myselection) and
   SdifMatrixIsSelected (file->CurrMtrxH, myselection).

   Revision 3.4  2000/04/18  10:47:31  schwarz
   Output in SDIF!  Is now default, but not to tty.
   Much better help message.

   Revision 3.3  1999/10/07  15:21:27  schwarz
   sdifextract can now use also the sdif selection to specify what to extract.

   Revision 3.2  1999/08/08  02:27:08  schwarz
   Added selection of time range to extract: <begin> to <end> or
   <begin>-<delta> to <begin>+<delta>.

   Revision 3.1  1999/03/14  10:57:43  virolle
   SdifStdErr add

   Revision 2.4  1999/02/28  12:17:01  virolle
   memory report

   Revision 2.3  1998/12/21  18:27:58  schwarz
   Inserted copyright message.

   Revision 2.2  1998/12/09  15:05:43  virolle
   no segmentation fault when opening failed.

   Revision 2.1  1998/12/03  18:04:16  schwarz
   Better help message.

   Revision 2.0  1998/11/29  11:44:02  virolle
   Use of new function names (SdifCurr... --> SdifFCurr...).

   Revision 1.2  1998/11/27  10:21:47  schwarz
   Intruduced output function (*output) (OutAction act, float data) and
   its first use for .format file output.

   Revision 1.1  1998/11/10  14:10:04  schwarz
   Added program to extract data from an SDIF-file.  You can choose the
   stream, frame type, matrix type, row and column to be written to an
   ascii file.
*/

/*
  done:
  - sdif output
  - sdif out only if no tty
  - cut after time passed (if time > last selected time, stop reading (break))

  todo: 
  - verbose to be requested specifically (print selection+summary)
  - warn if no data selected
  - column selector gives new order
  - signatures in/out mapping, if singleton
  - warn if structure changes
  - put flatten_list into SdifSelectFlattenIntList
  sdifout:
  - remove non-selected stream NVTs
  - use sdif memory buffer to write correct frame size/no. matrices 
    -> no seek -> stdout possible
*/


#include "sdif_portability.h"

#include "sdif.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#ifndef HAVE_CONFIG_H

#if defined(HOST_OS_UNIX)
#include <unistd.h>
#elif defined(HOST_OS_MAC)
#include <unistd.h>
#elif defined(HOST_OS_WIN32)
#include <io.h>
#endif

#else /* HAVE_CONFIG_H */

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif /* HAVE_UNISTD_H */

#endif /* HAVE_CONFIG_H */

#define  DB	0	/* heavy debugging level 0, 1, 2 */


/* action type for output functions */
typedef enum {OpenFile,    CloseFile, 
	      BeginFrame,  EndFrame, 
	      BeginMatrix, EndMatrix, 
	      BeginRow, InRow, EndRow} OutAction;

/* output functions */
void outsdif   (OutAction what, double data);
void outbpf    (OutAction what, double data);
void outtime   (OutAction what, double data);
void outdata   (OutAction what, double data);
void outformat (OutAction what, double data);

/* support functions */
void usage (char *msg, char *arg, int longhelp);
int  flatten_list (SdifListT *list, int maxmax, int flat [], int cumul []);
int  list_to_set  (SdifListT *list, int maxmax, int set []);

/* globally used arguments/variables accessible from usage and the
   output functions */
#define        PROG	     "sdifextract: "
int	       verb     = 0;	/* verbosity: -1=quiet, 0=normal, 1=verbose */
int	       force    = 0;	/* allow iffy selections */
char	       *types   = NULL;
SdifFileT      *in      = NULL;
char	       *outfile = NULL;



void usage (char *msg, char *arg, int longhelp)
{
    if (msg)
    {
        fprintf (SdifStdErr, "\n" PROG "ERROR: ");
	fprintf (SdifStdErr, msg, arg);
    }
    if (longhelp)
    {
    	fprintf (SdifStdErr, "\n" PROG "version $Revision: 1.18 $\n\n");
    
    	if (types)
    	{
    	    SdifFileT *dummy;
    
    	    SdifGenInit (types);
	    dummy = SdifFOpen ("stdout", eWriteFile);
	    SdifPrintAllType (SdifStdErr, dummy);
	    SdifFClose (dummy);
	    SdifGenKill ();
    	}
    
	SdifPrintVersion();
    }

    fprintf (SdifStdErr, "\n\n"
"Usage: sdifextract [options] [infile [outfile]]\n"
"\n" 
"Extract data in the time range, stream, frame type, matrix type, row\n"
"and column given by the SDIF selection or by the selection options,\n"
"and write it to the output file in one of 3 formats.\n"
"If one of the six selections is not specified, all data matches.\n"
"\n"
"The input filename can be in the form of an SDIF selection:\n\n"
"\tinfile::[#stream][:frame][/matrix][.column][_row][@time]\n\n"
"where all values can be comma-separated lists of single values,\n"
"or absolute ranges \"begin-end\", or delta ranges \"begin+delta\" for\n"
"matching a range of width delta around begin.\n"
"For details and tips on using the selection, see long help and\n"
"http://www.ircam.fr/sdif/extern/utilities-doc.html#selectspec\n"
"\nOptions:\n"
"	-T <sdif types file>  specify file with additional sdif types\n"
"	-v		      be verbose\n"
"	-q		      be quiet\n"
"	-h		      short help\n"
"	-help		      long help, prints sdif types if -T given,\n"
"			      format details and remarks.\n"
"\nFormat options (see long help for format details):\n"
"	-sdif                 output data in SDIF (default)\n"
"	-bpf                  output data as ASCII multi-bpf\n"
"	-format               output data as ASCII .format file\n"
"	-time                 output only frame-times as ASCII\n"
"	-data                 output data only (without frame-times) as ASCII\n"
"\nSelection options:\n"
"	-t <begin>[-<end>|+<delta>]  select time range <begin> to <end> or \n"
"                             <begin>-<delta> to <begin>+<delta>\n"
"	-s <stream id>	      select stream to extract\n"
"	-f <frame signature>  select frame  to extract\n"
"	-m <matrix signature> select matrix to extract\n"
"	-r <row>	      select row    to extract\n"
"	-c <column>	      select column to extract\n\n"
"These are added to the SDIF selection.  Here, only a single value is\n"
"allowed, but they can occur several times to extend the selection.\n"
"See long help for remarks on selection.\n\n"
);
    if (longhelp)   fprintf (SdifStdErr, 
"\nFormats:\n\n"
"-sdif   In SDIF output, the structure of the input file is kept if no\n"
"	columns or rows are selected.  Otherwise, the output may not\n"
"	conform to the SDIF description types, e.g. if columns are missing.\n"
"\n"
"-bpf    In multi-bpf format, every matrix row is printed as one line\n"
"	of text in the format:\n"
"\n"
"		frame-time  matrix-row...\n"
"\n"
"	If one column is selected, or all selected matrices contain only\n"
"	one column, the output file can be used as a break-point-function.\n"
"\n"
"-format In the ASCII .format file format (as used with additive),\n"
"	each matrix is printed in the format:\n"
"\n"
"		number-of-rows  frame-time\n"
"		matrix-row-1\n"
"		...\n"
"		matrix-row-n\n"
"\n"
"-time   In time format, only the frame-times of the selected frames are\n"
"	printed, where every time is printed on a new line\n" 
"\n"
"-data   In data-only format, output is like bpf but without time (the first column)\n"
"\n"
"\nRemarks:\n\n"
"--     Watch out for possible ambiguities between floating point time spec and\n"
"       column spec: @1.2 will be time 1.2, not time 1, column 2. It is advisable\n"
"       to put the time spec last to avoid this (.2@1 is ok) or use spaces (@1 .2\n"
"       is also ok).\n"
"--     To select one frame only, given its time, use a delta range of epsilon\n"
"       around the time, e.g.:  blurb.sdif::@0.5+0.001\n"
"       This is, because you will have a hard time specifying a frame time in\n"
"       ASCII with sufficient precision to be exactly equal to the double value\n"
"       in the SDIF-file.\n"
"\n");
    exit (0);
}



/*
 *  output functions
 */

/* template to write new output funtions: explains the meaning of data
void outtemplate (OutAction what, double data)
{
    static FILE	  *out = NULL;
    static double time;

    switch (what)
    {
	case OpenFile:				break;
	case BeginFrame:	time = data;	break;
	case BeginMatrix:	rows = data;	break;
	case BeginRow:		cols = data;	break;
	case InRow:		value = data;	break;
	case EndRow:		nil  = data;	break;
	case EndMatrix:		nil  = data;	break;
	case EndFrame:		nil  = data;	break;
	case CloseFile:				break;
    }
}
*/


void 
outsdif (OutAction what, double data)
{
    static SdifFileT	*out, save;
    static size_t	numbytes = 0;
    static int		rows = 0, col, nummatrix, mustwriteheader = 0;

    switch (what)
    {
	case OpenFile:
	    if (!(out = SdifFOpen (outfile, eWriteFile)))
		fprintf (SdifStdErr, PROG "can't open SDIF output file %s.\n", 
			 outfile), exit (2);

	    if (isatty (fileno (out->Stream)))
		fprintf (SdifStdErr, PROG "won't write SDIF to your screen.\n"
			 "(hint: use an ascii output format like -bpf or -format, or output to SDIF file)\n"),
		exit (3);

	    if (!(SdifListIsEmpty(in->Selection->row)  &&  
		  SdifListIsEmpty(in->Selection->column)))
	    {
		if (!out->isSeekable)
		    fprintf (SdifStdErr, PROG "can't use row or column selection with SDIF output to stdout.\n"),
		    exit (4);
		else if (verb > 0)
		    fprintf (SdifStdErr, PROG "warning: row or column selection might produce invalid SDIF output types.\n");
	    }

	    /* save original out and copy in header pointer (ugh, hairy!) */
	    save = *out;
	    out->NameValues       = in->NameValues;
	    out->MatrixTypesTable = in->MatrixTypesTable;
	    out->FrameTypesTable  = in->FrameTypesTable; 
	    out->StreamIDsTable   = in->StreamIDsTable;

	    /* write header information.  
	       todo: remove non-selected stream NVTs */
	    SdifFWriteGeneralHeader  (out);
	    SdifFWriteAllASCIIChunks (out);
	break;

	case BeginFrame:
	  if (out->CurrFramH == NULL)
	    out->CurrFramH = (SdifFrameHeaderT *)calloc(1,sizeof(*out->CurrFramH));
	  
	  *out->CurrFramH           = *in->CurrFramH;
	  /* leave original data in case we don't change frame structure
	     out->CurrFramH->Size     = _SdifUnknownSize;
	     out->CurrFramH->NbMatrix = _SdifUnknownSize; */
	  out->CurrFramH->Signature = 
	    SdifSelectGetFirstSignature (out->Selection->frame,
					 SdifFCurrFrameSignature (in));
	  out->CurrFramH->NumID     =
	    SdifSelectGetFirstInt       (out->Selection->stream,
					 SdifFCurrID (in));
	  numbytes		      = SdifFWriteFrameHeader (out);
	  nummatrix		      = 0;
	break;

	case BeginMatrix:  
	    mustwriteheader = 1;
	    nummatrix++;	
	    rows = (int)data;
	    if (rows > 0) break; 
	    else	  data = SdifFCurrNbCol (in);
	    /* FALLTHROUGH! (matrix has no rows->write header nevertheless) */

	case BeginRow:
	    if (mustwriteheader)
	    {
	        SdifFSetCurrMatrixHeader (out, 
		    SdifSelectGetFirstSignature (out->Selection->matrix, 
						 SdifFCurrMatrixSignature(in)),
		    SdifFCurrDataType (in), rows, (unsigned int)data);
		numbytes += SdifFWriteMatrixHeader (out);
		mustwriteheader = 0;
	    }
	    col = 1;	/* columns start at 1 */
	break;

	case InRow:	SdifFSetCurrOneRowCol (out, col++, data);	 break;

	case EndRow:	numbytes += SdifFWriteOneRow (out);		 break;

	case EndMatrix: numbytes += SdifFWritePadding (out, 
			  SdifFPaddingCalculate(out->Stream, numbytes)); break;

	case EndFrame:  /* correct frame size, nbmatrix */
	    if ((numbytes - 8  !=  out->CurrFramH->Size  ||
		 nummatrix     !=  out->CurrFramH->NbMatrix)
		&&  SdifUpdateFrameHeader (out, numbytes - 8, nummatrix) == -1)
	    {
	        fprintf (SdifStdErr, PROG "severe: can't update frame header %s at time %g%s\n(size or no. of matrices has changed)!\n", 
			 SdifSignatureToString (SdifFCurrFrameSignature(out)), 
			 SdifFCurrTime(out), 
			 !out->isSeekable ? " (output is not seekable)" : "");
		exit (5);
	    }
	break;

        case CloseFile: /* restore original NVT, etc. pointers */
	    *out = save; 
	    SdifFClose (out);				 
	break;
    }
}


void 
outbpf (OutAction what, double data)
{
    static FILE	  *out = NULL;
    static double time = -1;

    switch (what)
    {
	case OpenFile:
	    if (outfile)
	    {
		if (!(out = fopen (outfile, "w")))
		    fprintf (SdifStdErr, "Can't open bpf output file %s.\n", 
			     outfile), exit (0);
	    }
	    else
		out = stdout;
	break;

	case BeginFrame:    time = data;			break;
			    
	case BeginMatrix:   
	case EndMatrix:     
	case EndFrame:	    
	default:	    /* do nothing */			break;
			    
	case BeginRow:	    fprintf (out, "%f\t", time);	break;
	case InRow:	    fprintf (out, "%10f\t", data);	break;
	case EndRow:	    fprintf (out, "\n");		break;
	case CloseFile:	    fclose (out);			break;
    }
}



void 
outdata (OutAction what, double data)
{
    static FILE	  *out = NULL;
    static double time = -1;

    switch (what)
    {
	case OpenFile:
	    if (outfile)
	    {
		if (!(out = fopen (outfile, "w")))
		    fprintf (SdifStdErr, "Can't open bpf output file %s.\n", 
			     outfile), exit (0);
	    }
	    else
		out = stdout;
	break;

	case BeginFrame:    time = data;			break;
			    
	case BeginMatrix:   
	case EndMatrix:     
	case EndFrame:	    
	case BeginRow:
	default:	    /* do nothing */			break;
			    
	case InRow:	    fprintf (out, "%10f\t", data);	break;
	case EndRow:	    fprintf (out, "\n");		break;
	case CloseFile:	    fclose (out);			break;
    }
}


void
outtime (OutAction what, double data)
{
    static FILE	  *out = NULL;
    static double time = -1;

    switch (what)
    {
	case OpenFile:
	    if (outfile)
	    {
		if (!(out = fopen (outfile, "w")))
		    fprintf (SdifStdErr, "Can't open bpf output file %s.\n", 
			     outfile), exit (0);
	    }
	    else
		out = stdout;
	break;

	case BeginFrame:    time = data;			break;
			    
	case BeginMatrix:   
	case EndMatrix:     
	case InRow:	    
	case EndFrame:	    
	default:	    /* do nothing */			break;
			    
	case BeginRow:	    fprintf (out, "%f\t", time);	break;
	case EndRow:	    fprintf (out, "\n");		break;
	case CloseFile:	    fclose (out);			break;
    }
}


void 
outformat (OutAction what, double data)
{
    static FILE	  *out	   = NULL;
    static double time     = -1;
    static int	  rowcount = 0;	/* num of rows actually printed */

    switch (what)
    {
	case OpenFile:
	    if (outfile)
	    {
		if (!(out = fopen (outfile, "w")))
		    fprintf (SdifStdErr, "Can't open format output file %s.\n",
			     outfile), exit (0);
	    }
	    else
		out = stdout;
	break;

	case BeginFrame:   time = data;					 break;
	case BeginMatrix:  fprintf (out, "%d %f\n", (int) data, time);	 break;
			   
	case BeginRow:	   rowcount = 0;				 break;
	case InRow:	   rowcount++;	 fprintf(out, "%-12g ", data);	 break;
	case EndRow:	   if (rowcount) fprintf(out, "\n");		 break;
			  	 
	case CloseFile:	   fclose (out);				 break;
	case EndMatrix:   	 
	case EndFrame:    	 
	default:	   /* do nothing */				 break;
    }
}

/*--------------------------------------------------------------------------*/
/*	KERmain / main															*/
/*--------------------------------------------------------------------------*/

#if HOST_OS_MAC

int KERmain(int argc, char** argv);
int KERmain(int argc, char** argv)
{
	fprintf(SdifStdErr, "Nothing for the moment (Arien 11 May 2000)\n");
   return (0);
}

#else


/* 65536 crashes under Win NT */
/* use global arrays to prevent crash on MacOSX 
 * no need to have the arrays local !*/

#   define	maxintsel	(256*1024)	/* todo: make dynamic */
#   define	hard_defined_get(arr, ind)	((ind) < maxintsel  ?  arr [ind]  :  	      \
		   (fprintf(stderr, PROG "Number of rows/columns out of bounds, exiting\n"), exit (9), 0))


    int		flatcol[maxintsel], cumulcol[maxintsel+1], numcolsel,
    		flatrow[maxintsel], cumulrow[maxintsel+1], numrowsel;

int main(int argc, char** argv);
int main(int argc, char** argv)
{
    int		i, m, r, c;
    int		eof = 0;
    void	(*output) (OutAction act, double data) = outsdif;
    char	*after;
    SdifSelectionT *isel;



    /* selection arguments with default values */
    char	*infile  	= NULL, 
		*framestr	= NULL,
		*matrixstr	= NULL;
    SdifSignature
		frame		= eEmptySignature, 
		matrix		= eEmptySignature;
    int		stream	 	= -1,
		row		= -1,
		column		= -1;
    double	timefrom	= DBL_MIN,  /* -t arg and min/max selections */
		timeto		= DBL_MAX;

    /* for summary */
    int		eframe = 0, ematrix = 0;
    double	emint = DBL_MAX, emaxt = DBL_MIN;


    /*
     *  handle arguments
     */

    SdifStdErr = stderr;
    for (i = 1; i < argc; i++)
    {
	if (argv [i][0] == '-')
	{
	    if (strlen (argv [i]) > 2)
	    {	/* do long args */
	        if      (SdifStrEq (argv [i], "-sdif"))   output = outsdif;
		else if (SdifStrEq (argv [i], "-bpf"))    output = outbpf; 
		else if (SdifStrEq (argv [i], "-format")) output = outformat;
		else if (SdifStrEq (argv [i], "-time"))   output = outtime;
		else if (SdifStrEq (argv [i], "-data"))   output = outdata;
		else if (SdifStrEq (argv [i], "-help")  || 
			 SdifStrEq (argv [i], "--help"))
		    usage (NULL, NULL, 1);
		else
		    usage ("Unknown option '%s'", argv [i], 0);
	    }
	    else
	    {	/* do short args */
#		define boolopt  "hqvF"	/* flags with no arguments */
		if (i == argc - 1  &&  !strchr (boolopt, argv [i][1]))
		    /* no arg after last option, complain */
		    usage ("Argument to option %s missing", argv [i], 0);

		switch (argv [i][1])
		{	/* todo: accept range x-y and lists x,y,z for
			   ALL numerical values */
		    case 't':	 
		    	timefrom   = strtod (argv [++i], &after);
		    	if (after == argv [i])
			    usage ("Can't parse time value %s", argv [i], 0);
		    	if (*after == '-')
			    timeto = strtod (after + 1, &after);
		    	else if (*after == '+')
		    	{
			    timeto = strtod (after + 1, &after);
			    timefrom -= timeto;
			    timeto = timefrom + 2 * timeto;
		    	}
		    	else
			    timeto = timefrom;
		    break;
	      	    case 's':  stream	 = atoi (argv [++i]);		 break;
	      	    case 'r':  row       = atoi (argv [++i]);		 break;
	      	    case 'c':  column    = atoi (argv [++i]);      	 break;
	      	    case 'f':  framestr  = argv [++i];			 break;
	      	    case 'm':  matrixstr = argv [++i];			 break;
	      	    case 'T':  types     = argv [++i];			 break;
	      	    case 'F':  force     =  1;				 break;
	      	    case 'q':  verb	 = -1;			   	 break;
	      	    case 'v':  verb	 =  1;			   	 break;
	      	    case 'h':  usage(NULL, NULL, 0);		   	 break;
	      	    default :  usage("Unknown option '%s'", argv[i], 0); break;
		}
	    }
	}
	else if (!infile)
	    infile  = argv [i];
	else if (!outfile)
	    outfile = argv [i];
	else
	    usage ("Can't take more than two file arguments, %s is too much",
		   argv [i], 0);
    }


    /* 
     *  do inits 
     */

    if (!types)
    {
	char types2[2] = "";
	SdifGenInit (types2);
    }
    else
    {
	SdifGenInit (types);
    }

    /* open in file (parses selection from filename into in->Selection) */
    in = SdifFOpen (infile, eReadFile);
    if (!in)
    {
        SdifGenKill ();
        exit (1);
    }
    isel = in->Selection;

    if (framestr)   frame  = SdifStringToSignature (framestr);
    if (matrixstr)  matrix = SdifStringToSignature (matrixstr);

    /* add  selection from options */
#   define addif(unset, name, type) \
    { if (name != unset)   SdifSelectAdd##type (isel->name, name); }
    
    addif (-1,			stream, Int);
    addif (eEmptySignature,     frame,  Signature);
    addif (eEmptySignature,     matrix, Signature);
    addif (-1,			row,    Int);
    addif (-1,			column, Int);
    if (timefrom > DBL_MIN  ||  timeto < DBL_MAX)
        SdifSelectAddRealRange (isel->time, timefrom, sst_range, timeto);

    /* to avoid expensive column loop and to know how many rows are selected */
    numrowsel = flatten_list (isel->row,    maxintsel, flatrow, cumulrow);
    numcolsel = flatten_list (isel->column, maxintsel, flatcol, cumulcol);

    if (SdifListInitLoop (isel->time))
    {
        SdifSelectElementRealT range;

	timefrom = DBL_MAX;
	timeto   = DBL_MIN;
	while (SdifSelectGetNextRealRange (isel->time, &range, 1))
	{
            if (range.value < timefrom)	timefrom = range.value;
	    if (range.range > timeto)	timeto   = range.range;
	}
    }



    /* 
     *  give some feedback: print selection and format
     */

    if (verb > 0)
    {
	SdifPrintSelection (SdifStdErr, in->Selection, 0);
	fprintf (SdifStdErr, "writing as %s\n", 
		 output == outsdif    ?  "SDIF"         :
		 output == outbpf     ?  "multi-bpf"    :
		 output == outtime    ?  "time"    :
		 output == outdata    ?  "data"    :
		 output == outformat  ?  "format file"  :  "");
    }

    SdifFReadGeneralHeader  (in);
    SdifFReadAllASCIIChunks (in);
    if (SdifFLastError(in))
    {   /* error has already been printed by the library, just clean
           up and exit */
        SdifGenKill ();
        exit (1);
    }
    output (OpenFile, 0);


    /* 
     *  main loop: read, filter, write frame 
     */

    while (!eof)
    {
	size_t	bytesread = 0,dontcnt=0;
	double  time;

	/* Read frame header.  Current signature has already been read
	   by SdifFReadAllASCIIChunks or the last loop.) */
	SdifFReadFrameHeader (in);
	time = SdifFCurrTime (in);
#if DB
  fprintf(SdifStdErr, "@frame\t%s  matrices %d  stream %d  time %f\n",
    SdifSignatureToString (SdifFCurrFrameSignature (in)), 
    SdifFCurrNbMatrix (in), SdifFCurrID (in), time);
#endif
	
	/* Check frame time, type, and stream id */
	if (!SdifFCurrFrameIsSelected (in))
	{
	    /* first check if we want any more data from this file at all */
	    if (time > timeto)
	    {   /* because of ascending time ordering we know now that
		   we're finished.  (Consume input if reading from
		   stdin or pipe doesn't seem to be necessary?) */
	        break;		/* EXIT MAIN LOOP */
	    }
	    
	    /* a frame type we're not interested in, so we skip it */
	    SdifFSkipFrameData (in);
	    eof = SdifFGetSignature (in, &dontcnt) == eEof;
	    continue;		/* START NEXT ITERATION of while frames loop */
	}

	/* output and count frame */
	output (BeginFrame, time);
	eframe++;
	if (time < emint)   emint = time;
	if (time > emaxt)   emaxt = time;
	
	/* if a frame has no matrices it can still be selected, and we want to just output the frame */
	if(output == outtime && (SdifFCurrNbMatrix (in) == 0 || (numrowsel == 0 && numcolsel == 0))){
		/* BeginRow is the code that leads to the actual writing of the frame time */
		output (BeginRow,0.);
		/* EndRow writes the newline */
		output (EndRow,0.);
	}else{
	
		/* for matrices loop */
		for (m = 0; m < SdifFCurrNbMatrix (in); m++)
		{
		    int nbrows, nbcols, selrow;

		    /* Read matrix header */
		    bytesread = SdifFReadMatrixHeader (in);
	#if DB
	  fprintf (SdifStdErr, "@matrix\t%s  rows %d  cols %d  cumulcol %d\n", 
	    SdifSignatureToString (SdifFCurrMatrixSignature (in)), 
	    SdifFCurrNbRow(in), SdifFCurrNbCol(in), hard_defined_get(cumulcol, SdifFCurrNbCol(in)));
	#endif
		    /* Check matrix type */
		    if (!SdifFCurrMatrixIsSelected (in))
		    {   /* a matrix type we're not interested in, so we skip it */
			SdifFSkipMatrixData (in);
			continue;	/* START NEXT ITERATION of for matrices loop */
		    }

		    ematrix++;
		    nbrows = SdifFCurrNbRow (in);
		    nbcols = SdifFCurrNbCol (in);
		    selrow = 0;

		    /* TODO: output row only when there is a selected column,
		       when there is no selected column, output num. of rows 0 */
		    output (BeginMatrix, hard_defined_get (cumulrow, nbrows));
		
		    /* read matrix data: for rows */
		    for (r = 1; r <= nbrows; r++)
		    {
			bytesread += SdifFReadOneRow (in);
	#if DB > 2
	  fprintf (SdifStdErr, "@row\t%d  selrow %d flatrow [%d] = %d\n", 
	    r, selrow, selrow, hard_defined_get (flatrow, selrow));
	#endif
			/*if (!SdifSelectTestInt (isel->row, r))*/
			if (hard_defined_get (flatrow, selrow) != r)
			    continue;	/* START NEXT ITERATION of for rows loop */
			selrow++;	/* the row we're waiting for */

			/* write selected column(s), but avoid expensive loop
			   using flattened column list */
			output (BeginRow, hard_defined_get (cumulcol, nbcols));

			for (c = 0; c < hard_defined_get (cumulcol, nbcols); c++)
			    output (InRow, SdifFCurrOneRowCol (in, hard_defined_get (flatcol, c)));

			output (EndRow, 0);
		    }	/* end for rows */

		    output (EndMatrix, 0);
		    SdifFReadPadding(in, SdifFPaddingCalculate(in->Stream, bytesread));
		}   /* end for matrices */
	}	/* end if SdifFCurrNbMatrix (in) == 0 */

	output (EndFrame, 0);
	eof = SdifFGetSignature (in, &bytesread) == eEof;
    }   /* end while frames */ 
    

    /* 
     *  print summary
     */

    if (eframe > 0  &&  verb > 0)
    {
        fprintf (SdifStdErr, "summary: %d frames containing %d matrices "
			     "between times %f and %f extracted.\n",
		 eframe, ematrix, emint, emaxt);
    }
    if (eframe == 0  &&  verb >= 0)
    {
        fprintf (SdifStdErr, PROG "warning: no frames were extracted.\n");
    }


    /* 
     *  cleanup 
     */

    output (CloseFile, 0);
    SdifFClose (in);
    SdifGenKill ();
    return (0);
}


#endif /* main */




/* flat  [i] = enumerates selected columns (sorted), i = 0..cumul [n]-1
   cumul [i] = how many of i columns are selected 
   e.g.: list = (3, 1)	set = (0, 1, 0, 1)  flat = (1, 3)  cumul = (0, 1, 1, 2)
         list = (2-3)	set = (0, 0, 1, 1)  flat = (2, 3)  cumul = (0, 0, 1, 2)
	 list = ()     [set = (1, 1, ...)]  flat = (1, ..) cumul = (0, 1, ..)
   (todo: put into SdifSelectFlattenIntList)
*/
int 
flatten_list (SdifListT *list, int maxmax, int flat [], int cumul [])
{
    int i = 0, j = 0, num;

    if (SdifListIsEmpty (list))
	while (j < maxmax)
	{
	    flat  [j] = j+1;
	    cumul [j] = j;
	    j++;
	}
    else
    {
	num = list_to_set (list, maxmax, flat);

	/* compact list */
	while (i < maxmax)
	{
	    if (flat [i])
	    {
		flat  [j] = flat [i];
		j++;
	    }
	    cumul [i] = j;
	    i++;
	}
    }
    return (j);
}


/* int selection list to array with 0 or i if i is selected */
int 
list_to_set (SdifListT *list, int maxmax, int set [])
{
    int			  i, realmax = 0;
    SdifSelectElementIntT range;

    /* clean list first (remember: columns start from 1!) */
    for (i = 0; i < maxmax; i++)
	set [i] = 0;

    SdifListInitLoop (list);
    while (SdifSelectGetNextIntRange (list, &range, 1))
    {
	if (range.value <= 0)
	    fprintf (SdifStdErr, PROG "integer selection must be greater than 0 (you specified %d)\n", range.value), 
	    exit (1);
	if (range.range >= maxmax)
	    fprintf (SdifStdErr, PROG "can't handle integer selections "
		     "greater than %d (you wanted %d)\n", maxmax, range.range),
	    exit (2);
	if (range.range >= realmax)
	    realmax = range.range;

	for (i = range.value; i <= range.range; i++)
	    set [i] = i;
    }

    return (realmax + 1);
}

/* $Id: SdifSelect.h,v 1.2 2000/10/27 20:03:03 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifSelect.c		27. August 1999		Diemo Schwarz
 */

/*

DESCRIPTION

  Standardize access path to a selection of data from an SDIF file.

  I repeat my suggestion for the syntax of the select specification ,
  which I sent to Matt on June 21:
  
  I think it's a good idea to include the filename in the selection.
  This would encourage programmers to use some parsing procedure
  SdifGetFilenameAndSelection, which splits a command-line argument up
  into the filename and the selection, thus transparently allowing SDIF
  readers to handle a specific part of an SDIF file only.
  
  For various problems with filename and shell metacharacters, I suggest
  to mark the start of the select spec with '::' (or '##' or '--').
  This way, there is no ambiguity with filenames containing the
  select-spec characters, and to specify a filename containing '::'
  itself, you just have to append '::'.
  
  The syntax for the select-spec would then be:
  
  [filename][::[[#stream]:][frame][/matrix][.column][_row][@time]]
  
  With these mnemonics:
  - #stream as with "number", 
  - frame/matrix as in a file system hierarchy,
  - .column as in a C-struct (with column name or number) 
    Watch out: "@1.2" will be parsed as time 1.2 seconds, not time 1 column 2!
    (use ".2@1" for that)
  - _row as in a LaTeX index.  
  (As .column_row may seem unnatural for people with a maths background
  these can also be given in inverse order as _row.column, which still 
  looks good.)
  - @time like in "at time ..."
  - @time+delta can have delta < 0, so we have "at time plus/minus delta"
  
  - Streams and columns can be given either as a number or as a name.  
  
  - All specifications can be comma-separated lists of values.
  Numerical specifications can also be ranges l-u (a missing value l or u 
  would be replaced by the respective min/max).
  
  - Whitespace between the specs is allowed (before the :: it is
    considered part of the filename).

  - Again, watch out for possible ambiguities between floating point
    time spec and column spec: @1.2 will be time 1.2, not time 1,
    column 2.  It is advisable to put the time spec last to avoid this
    (.2@1 is ok) or use spaces (@1 .2 is also ok.
  
TODO
  - handle quoted strings:
  - Allow quoting names for weird frame and matrix types.
  - One could later allow regular expressions for names. 
  - functions to set up specs (lists of ranges)

LOG
  $Log: SdifSelect.h,v $
  Revision 1.2  2000/10/27 20:03:03  roebel
  autoconf merged back to main trunk

 * Revision 1.1.2.1  2000/08/21  17:48:25  tisseran
 * *** empty log message ***
 *
  Revision 3.8  2000/05/15  16:22:04  schwarz
  Changed prototypes of existing functions (we apologize for the inconvenience)
  SdifFCurrFrameIsSelected and SdifFCurrMatrixIsSelected.
  They now take only an SdifFileT as parameter, no longer a selection.
  If you don't want to test the file selection (automatically
  parsed from the filename), use these new functions like this:
  SdifFrameIsSelected  (file->CurrFramH, myselection) and
  SdifMatrixIsSelected (file->CurrMtrxH, myselection).

  Revision 3.7  2000/05/12  16:55:31  schwarz
  Added prototype and doc for SdifBaseName.
  Avoid avoidable warnings.

  Revision 3.6  2000/03/01  11:18:46  schwarz
  Added SdifCreateSelection.
  Fixed Linux-only bug in SdifGetFilenameAndSelection (high addresses).
  SdifSelectTestReal first tests from current select element onwards.

  Revision 3.5  1999/10/13  16:05:58  schwarz
  Changed data type codes (SdifDataTypeET) to SDIF format version 3, as
  decided with Matt Wright June 1999, added integer data types.
  Added writing of 1NVT with real frame header (but data is still not in
  matrices).
  The data type handling makes heavy use of code-generating macros,
  called for all data types with the sdif_foralltypes macro, thus
  adding new data types is easy.

  Revision 3.4  1999/10/07  15:06:42  schwarz
  Added SdifSelectGetFirst<type>, SdifSelectGetNext(Int|Real).

  Revision 3.3  1999/09/28  13:09:12  schwarz
  Included #include <preincluded.h> for cross-platform uniformisation,
  which in turn includes host_architecture.h and SDIF's project_preinclude.h.

  Revision 3.2  1999/09/20  13:23:03  schwarz
  First finished version, API to be improved.

  Revision 3.1  1999/08/31  10:03:00  schwarz
  Added module SdifSelect which parses an access specification to a
  chosen part of SDIF data.  Can be added to a file name.  */


#ifndef _SdifSelect_
#define _SdifSelect_


#include "SdifHard_OS.h"	/* SdifSignature */
#include "SdifFrame.h"
#include "SdifMatrix.h"
#include "SdifList.h"


/* tokens (numerical ids) for sdifspec separators */
typedef enum { sst_specsep, sst_stream, sst_frame, sst_matrix, sst_column, 
	       sst_row,     sst_time,   sst_list,  sst_range,  sst_delta,
	       sst_num,	/* number of tokens */	   sst_norange = 0
} SdifSelectTokens;



/*DOC: 
  Selection element interface (returned by SdifGetNextSelection*):
  One basic data element value, with optional range.  
  The meaning of range is determined by rangetype: 

  [] 0		no range
  [] sst_range	range is value..range
  [] sst_delta	range is value-range..value+range
*/

typedef struct 
{
    int		       value, range;
    SdifSelectTokens   rangetype; /* 0 for not present, sst_range, sst_delta */
} SdifSelectElementIntT;

typedef struct 
{
    double	       value, range;
    SdifSelectTokens   rangetype; /* 0 for not present, sst_range, sst_delta */
} SdifSelectElementRealT;

/* no SdifSelectElementSignatureT or string range, since it makes no sense */



/*DOC:
  Internal: one value of different possible types in a selection
  element (the element list determines which type is actually used).  
*/
typedef union SdifSelectValueS 
{
    int            integer;
    double         real;
    char	   *string;
    SdifSignature  signature;
} SdifSelectValueT;

/*DOC: 
  Selection element internal data structure:
  One basic data element, with optional <ul>
  <li> range (value is lower, range is upper bound) or 
  <li> delta (value-range is lower, value+range is upper bound)
  </ul>
*/
typedef struct SdifSelectElementS
{
    SdifSelectValueT value;
    SdifSelectValueT range;
    SdifSelectTokens rangetype; /* 0 for not present, sst_range, sst_delta */
} SdifSelectElementT, *SdifSelectElementP;

/*DOC: 
  Holds a selection of what data to access in an SDIF file,
  parsed from a simple regular expression.  
*/
typedef struct
{
    char	*filename,	/* allocated / freed by 
				   SdifInitSelection / SdifFreeSelection */
		*basename;	/* points into filename */
    SdifListP	stream, frame, matrix, column, row, time;
} SdifSelectionT;
/* TODO: array of select elements
     struct { SdifListP list; SdifSelectElementT minmax; } elem [eSelNum];
   indexed by
     enum   { eTime, eStream, eFrame, eMatrix, eColumn, eRow, eSelNum }
   to use in all API functions instead of SdifListP.
*/


/*DOC:
  Return pointer to start of filename component in path inPathFileName.
 */
char *SdifBaseName (const char* inPathFileName);


/* 
// FUNCTION GROUP:	Init/Deinit
 */

/* init module, called by SdifGenInit */
int SdifInitSelect (void);

/*DOC: 
  Allocate space for an sdif selection.
*/
SdifSelectionT *SdifCreateSelection (void);

/*DOC: 
*/
int SdifInitSelection (SdifSelectionT *sel, const char *filename, int namelen);

/*DOC: 
*/
int SdifFreeSelection (SdifSelectionT *sel);

/*
// FUNCTION GROUP:	Parse and Set Selection
*/


/*DOC: 
  Returns pointer to first char of select spec (starting with ::), 
  or NULL if not found.
*/
char *SdifSelectFindSelection (const char *filename);


/*DOC: 
*/
char *SdifGetFilenameAndSelection (/*in*/  const char *filename, 
				   /*out*/ SdifSelectionT *sel);

/*DOC: 
*/
void SdifPrintSelection (FILE *out, SdifSelectionT *sel, int options);



/*
// FUNCTION GROUP:	Add Selections to Element Lists
*/

/* Give documentation and fake prototype for _add... macro generated functions.
   Cocoon ignores the #if 0.
*/
#if 0

/*DOC:
  Create and add one value to selection element list.  There are four 
  functions generated automatically, with the meta type-variables _type_ and 
  _datatype_:
  [] _type_ is one of:  <br> Int, Real,   Signature,     String, for
  [] _datatype_ of:	<br> int, double, SdifSignature, char *, respectively.
*/
void SdifSelectAdd_TYPE_ (SdifListT *list, _datatype_ value);

/*DOC:
  Create and add one range to selection element list.  There are four 
  functions generated automatically, with the meta type-variables _type_ and 
  _datatype_:
  [] _type_ is one of:  <br> Int, Real,   Signature,     String, for
  [] _datatype_ of:	<br> int, double, SdifSignature, char *, respectively.
*/
void SdifSelectAdd_TYPE_Range (SdifListT *list, 
			       _datatype_ value, 
			       SdifSelectTokens rt, 
			       _datatype_ range);

#endif	/* if 0 */


#ifdef __STDC__
/*#if defined (_ANSI_C_SOURCE)  ||  defined (__STDC__)*/

#define _addrangeproto(name, type, field) \
void SdifSelectAdd##name##Range (SdifListT *list, \
				 type value, SdifSelectTokens rt, type range)

#define _addsimpleproto(name, type, field) \
void SdifSelectAdd##name (SdifListT *list, type value)

#define _addproto(name, type, field) \
_addsimpleproto (name, type, field); \
_addrangeproto  (name, type, field);

_addproto (Int,	      int,		integer)
_addproto (Real,      double,		real)
_addproto (Signature, SdifSignature,	signature)
_addproto (String,    char *,		string)

#else

void SdifSelectAddInt (SdifListT *list, int value) ; 
void SdifSelectAddIntRange (SdifListT *list, int value, SdifSelectTokens rt, int range) ; 
void SdifSelectAddReal (SdifListT *list, double value) ; 
void SdifSelectAddRealRange (SdifListT *list,                                   double value, SdifSelectTokens rt, double range) ; 
void SdifSelectAddSignature (SdifListT *list, SdifSignature value) ; 
void SdifSelectAddSignatureRange (SdifListT *list, SdifSignature value, SdifSelectTokens rt,   SdifSignature range) ; 
void SdifSelectAddString (SdifListT *list, char * value) ; 
void SdifSelectAddStringRange (SdifListT *list, char * value, SdifSelectTokens rt,      char * range) ; 

#endif


/*
// FUNCTION GROUP:	Query parsed ranges (list of ranges).
*/

/*DOC:
  Query parsed ranges (list of ranges) for a selection element (one of
  the SdifListP lists in SdifSelectionT).  Init list traversal with
  SdifListInitLoop, then call SdifSelectGetNext<type>(list) until it
  returns 0.

  The number of selections in the list is SdifListGetNbData(list), if
  it is 0, or SdifListIsEmpty(list) is true, then there was no
  selection for that element.

  If force_range is 1, the out value is converted to a range in any
  case, with value <= range guaranteed.  
*/
int SdifSelectGetNextIntRange  (/*in*/  SdifListP list, 
				/*out*/ SdifSelectElementIntT  *range, 
				/*in*/  int force_range);

/*DOC: 
  See SdifSelectGetNextInt.
*/
int SdifSelectGetNextRealRange (/*in*/  SdifListP list, 
				/*out*/ SdifSelectElementRealT *range, 
				/*in*/  int force_range);

/*DOC: 
  Query list of parsed selection elements (one of the SdifListP
  lists in SdifSelectionT).  Init list traversal with
  SdifListInitLoop, then call SdifSelectGetNext<type>(list) until it
  returns 0.

  See also SdifSelectGetNextInt.  
*/
SdifSignature  SdifSelectGetNextSignature (/*in*/  SdifListP list);

/*DOC: 
  See SdifSelectGetNextSignature.
*/
char	      *SdifSelectGetNextString    (/*in*/  SdifListP list);


/*DOC: 
  Return value of first selection (ignoring range).
*/
int	       SdifSelectGetFirstInt       (SdifListP l, int defval);
double	       SdifSelectGetFirstReal      (SdifListP l, double defval);
char	      *SdifSelectGetFirstString    (SdifListP l, char *defval);
SdifSignature  SdifSelectGetFirstSignature (SdifListP l, SdifSignature defval);





/*
// FUNCTION GROUP:	Selection Testing Functions
*/

int SdifSelectTestIntRange  (SdifSelectElementT *elem, int cand);
int SdifSelectTestRealRange (SdifSelectElementT *elem, double cand);

int SdifSelectTestInt (SdifListT *list, int cand);
int SdifSelectTestReal (SdifListT *list, double cand);
int SdifSelectTestSignature (SdifListT *list, const SdifSignature cand);
int SdifSelectTestString (SdifListT *list, const char *cand);



/*
// FUNCTION GROUP:	Using a Selection in File I/O.
*/

#ifndef SdifFileT_
#define SdifFileT_
typedef struct SdifFileS SdifFileT;
#endif


/*DOC: 
  Test the selection elements from sel applicable to frame FramH:
  time, stream, frame type. */
int SdifFrameIsSelected (SdifFrameHeaderT *FramH, SdifSelectionT *sel);

/*DOC:
  Test the selection elements from sel applicable to matrix MtrxH: 
  the matrix signature. */
int SdifMatrixIsSelected (SdifMatrixHeaderT *MtrxH, SdifSelectionT *sel);


/*DOC: 
  Test if the current frame header is in the file selection
  (automatically parsed from the filename).  
  Can be called after SdifFReadFrameHeader(). */
int SdifFCurrFrameIsSelected (SdifFileT *file);

/*DOC:
  Test if the current matrix header is in the file selection
  (automatically parsed from the filename).  
  Can be called after SdifFReadMatrixHeader(). */
int SdifFCurrMatrixIsSelected (SdifFileT *file);


#endif /* _SdifSelect_ */

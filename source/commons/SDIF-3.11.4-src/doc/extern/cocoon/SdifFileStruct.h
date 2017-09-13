/* $Id: SdifFileStruct.h,v 1.2 2000/10/27 20:02:58 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifFileStruct.h
 *
 * Upper level structure
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifFileStruct.h,v $
 * Revision 1.2  2000/10/27 20:02:58  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:04  tisseran
 * *** empty log message ***
 *
 * Revision 3.6  2000/05/22  15:23:16  schwarz
 * Added functions to retrieve and inspect the stream ID table of a file.
 *
 * Revision 3.5  2000/05/04  15:06:42  schwarz
 * Moved SdifSignatureTab into separate file SdifSignatureTab
 *
 * Revision 3.4  1999/10/13  16:05:46  schwarz
 * Changed data type codes (SdifDataTypeET) to SDIF format version 3, as
 * decided with Matt Wright June 1999, added integer data types.
 * Added writing of 1NVT with real frame header (but data is still not in
 * matrices).
 * The data type handling makes heavy use of code-generating macros,
 * called for all data types with the sdif_foralltypes macro, thus
 * adding new data types is easy.
 *
 * Revision 3.3  1999/10/07  15:12:23  schwarz
 * Added isSeekable flag in SdifFileT struct.  This allows to simplify the
 * many tests for stdio on opening the stream.
 * Added SdifStrEq utility function.
 *
 * Revision 3.2  1999/09/20  13:22:00  schwarz
 * Introduced user data and access functions SdifFAddUserData/GetUserData.
 *
 * Revision 3.1  1999/03/14  10:56:51  virolle
 * SdifStdErr add
 *
 * Revision 2.4  1999/02/28  12:16:43  virolle
 * memory report
 *
 * Revision 2.3  1999/01/23  15:55:48  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:34  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:17  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:42  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.3  1998/11/10  15:31:45  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */

#ifndef _SdifFileStruct_
#define _SdifFileStruct_

#include "SdifGlobals.h"
#include "SdifSignatureTab.h"
#include "SdifList.h"
#include "SdifSelect.h"
#include "SdifNameValue.h"
#include "SdifHash.h"
#include "SdifMatrixType.h"
#include "SdifFrameType.h"
#include "SdifStreamID.h"
#include "SdifTimePosition.h"
#include "SdifMatrix.h"
#include "SdifFrame.h"
#include "SdifErrMess.h"
#include <stdio.h>


#define	MaxUserData	10


/*
// DATA GROUP:	SDIF File Structure
*/

/*DOC:
  File mode argument for SdifFOpen.
*/
typedef enum SdifFileModeE
{
  eUnknownFileMode,	/* 0 */
  eWriteFile,
  eReadFile,
  ePredefinedTypes,	/* 3 */

  eModeMask = 7,	/* get rid of flags */

  /* from here on we have flags that can be or'ed with the previous modes */
  eParseSelection = 8
} SdifFileModeET ;



enum SdifPassE
{
  eNotPass,
  eReadPass,
  eWritePass
};
  


#ifndef SdifFileT_
#define SdifFileT_
typedef struct SdifFileS SdifFileT;
#endif

struct SdifFileS
{
  char		     *Name;		/* Name of the file, can be "stdin, stdout, stderr */
  SdifFileModeET     Mode;		/* eWriteFile or eReadFile or ePredefinedTypes */
  int		     isSeekable;	/* file is neither standard i/o nor pipe i/o */

  SdifUInt4	     FormatVersion;	/* version of the SDIF format itself */
  SdifUInt4	     TypesVersion;	/* version of the description type collection */

  SdifNameValuesLT   *NameValues;       /* DataBase of Names Values */
  SdifHashTableT     *MatrixTypesTable; /* DataBase of Matrix Types */
  SdifHashTableT     *FrameTypesTable;  /* DataBase of Frame Types */
/*  SdifHashTableT     *StreamIDsTable;    DataBase of Stream IDs */
  SdifStreamIDTableT *StreamIDsTable;   /* DataBase of Stream IDs */
  SdifTimePositionLT *TimePositions;    /* List of (Time, Position in file) */
  SdifSelectionT     *Selection;	/* default selection parsed from Name */

  FILE *Stream;                         /* Stream to read or to write */

  SdifSignature      CurrSignature;
  SdifFrameHeaderT   *CurrFramH;        /* Current Frame Header can be NULL */
  SdifMatrixHeaderT  *CurrMtrxH;        /* Current Matrix Header can be NULL */

  SdifFrameTypeT     *CurrFramT;
  SdifMatrixTypeT    *CurrMtrxT;
  SdifFloat8         PrevTime;
  SdifSignatureTabT  *MtrxUsed;

  SdifOneRowT        *CurrOneRow;
  /* Current OneRow allocated memory in function
   * of _SdifGranule, use SdifReInitOneRow(SdifOneRowT *OneRow, SdifDataTypeET DataType, SdifUInt4 NbData)
   * to assure NbData (=NbColumns) objects memory allocated
   */

  size_t  FileSize;
  size_t  ChunkSize;

  SdiffPosT  CurrFramPos;
  SdiffPosT  StartChunkPos;
  SdiffPosT  Pos;
  
  SdifUInt2  TypeDefPass;
  SdifUInt2  StreamIDPass;

  char *TextStreamName;                 /* Name of the text file corresponding to the sdif file */
  FILE *TextStream;                     /* Stream text */

  unsigned int  NbOfWarning;
  SdifErrorLT  *Errors;

  int		NbUserData;		/* todo: hash table */
  void		*UserData [MaxUserData];
};	/* end struct SdifFileS */


#endif /* _SdifFileStruct_ */

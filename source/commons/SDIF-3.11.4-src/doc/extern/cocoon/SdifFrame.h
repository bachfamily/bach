/* $Id: SdifFrame.h,v 1.2 2000/10/27 20:02:59 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifFrame.h
 *
 * Frame Header, Frame Data structures management
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifFrame.h,v $
 * Revision 1.2  2000/10/27 20:02:59  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:06  tisseran
 * *** empty log message ***
 *
 * Revision 3.1  1999/03/14  10:56:54  virolle
 * SdifStdErr add
 *
 * Revision 2.1  1998/12/21  18:27:19  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:44  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.4  1998/11/10  15:31:46  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */

#ifndef _SdifFrame_
#define _SdifFrame_

#include "SdifGlobals.h"
#include "SdifHash.h"
#include "SdifMatrix.h"

#define _SdifFrameHeaderSize 16  /* (ID=4)+(size=4)+(time=8) */



typedef struct SdifFrameHeaderS SdifFrameHeaderT;
struct SdifFrameHeaderS
{
  SdifSignature Signature;
  SdifUInt4  Size;
  SdifUInt4  NbMatrix;
  SdifUInt4  NumID;
  SdifFloat8 Time;
} ;


typedef struct SdifFrameDataS SdifFrameDataT;
struct SdifFrameDataS
{
  SdifFrameHeaderT *Header;
  SdifMatrixDataT* *Matrix_s;
} ;


SdifFrameHeaderT* SdifCreateFrameHeader(SdifSignature Signature,
					       SdifUInt4 Size,
					       SdifUInt4 NbMatrix,
					       SdifUInt4 NumID,
					       SdifFloat8 Time);

SdifFrameHeaderT* SdifCreateFrameHeaderEmpty(SdifSignature Signature);

void              SdifKillFrameHeader  (SdifFrameHeaderT *FrameHeader);

SdifFrameDataT* SdifCreateFrameData(SdifHashTableT *FrameTypesTable,
					   SdifSignature FrameSignature,
					   SdifUInt4 NumID,
					   SdifFloat8 Time);

void            SdifKillFrameData   (SdifHashTableT *FrameTypesTable, SdifFrameDataT *FrameData);

SdifFrameDataT* SdifFrameDataPutNthMatrixData(SdifFrameDataT *FrameData, unsigned int NthMatrix,
						     SdifMatrixDataT *MatrixData);

SdifFrameDataT* SdifFrameDataPutComponentMatrixData(SdifHashTableT *FrameTypesTable,
							   SdifFrameDataT *FrameData,
							   char *CompoName, SdifMatrixDataT *MatrixData);

SdifMatrixDataT* SdifFrameDataGetNthMatrixData(SdifFrameDataT *FrameData, unsigned int NthMatrix);

SdifMatrixDataT* SdifFrameDataGetComponentMatrixData(SdifHashTableT *FrameTypesTable,
							    SdifFrameDataT *FrameData,
							    char *CompoName);

#endif /* _SdifFrame_ */



/* $Id: SdifFPut.h,v 1.2 2000/10/27 20:02:57 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifFPut.h
 *
 *
 * F : SdifFileT* SdifF, Put : write ascii frames into pseudo-sdif text file,
 * SdifF->TextStream or sdif file SdifF->Stream.
 * switch 'verbose'
 *
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifFPut.h,v $
 * Revision 1.2  2000/10/27 20:02:57  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:47:56  tisseran
 * *** empty log message ***
 *
 * Revision 3.4  2000/07/18  15:08:30  tisseran
 * This release implements the New SDIF Specification (june 1999):
 * - Name Values Table are written in a 1NVT frame which contains a 1NVT matrix
 * - Frame and matrix type declaration are written in a 1TYP frame which contains a 1TYP matrix.
 * - Stream ID are written in a 1IDS frame which contains a 1IDS matrix.
 *
 * Read function accept the previous version of the specification (read a text frame without matrix) to be compatible with older SDIF files.
 *
 * SdifString.h and SdifString.c implements some string mangement (creation, destruction, append, test of end of string, getc, ungetc).
 *
 * WATCH OUT:
 *      We don't care about the old SDIF Specification (_SdifFormatVersion < 3)
 * To use _SdifFormatVersion < 3, get the previous release.
 *
 * Revision 3.3  2000/07/06  19:01:46  tisseran
 * Add function for frame and matrix type declaration
 * Remove string size limitation for NameValueTable
 * TODO: 1TYP and 1IDS frame must contain an 1NVT (text) matrix
 *       Actually, data are written with fprintf.
 *
 * Revision 3.2  2000/04/11  14:31:22  schwarz
 * Read/write NVT as frame with 1 text matrix, conforming to SDIF spec.
 *
 * Revision 3.1  1999/03/14  10:56:42  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/01/23  15:55:42  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:26  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:09  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:32  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.2  1998/11/10  15:31:42  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */


#ifndef _SdifFPut_
#define _SdifFPut_

#include "SdifGlobals.h"
#include "SdifFileStruct.h"
#include <stdio.h>
#include "SdifNameValue.h"
#include "SdifMatrixType.h"
#include "SdifFrameType.h"
#include "SdifStreamID.h"

#include "SdifString.h"

size_t SdifFPutOneNameValue         (SdifFileT *SdifF, int Verbose, SdifNameValueT *NameValue);
size_t SdifFPutNameValueLCurrNVT    (SdifFileT *SdifF, int Verbose);

/* This function makes memory reallocation for extends the Name Value capacity
   In the previous release of this file, it was limited at a char[_SdifStringLen]
   with _SdifStringLen = 1024.
   Now, limits depend only on avaluable memory
*/
char * SdifFNameValueLCurrNVTtoString(SdifFileT *SdifF);


/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  This function put NameValue to SdifString
*/
int SdifFNameValueLCurrNVTtoSdifString(SdifFileT *SdifF, SdifStringT *SdifString);


size_t SdifFPutOneMatrixType        (SdifFileT *SdifF, int Verbose,
				     SdifMatrixTypeT *MatrixType);
/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Append matrix type declaration in SdifString
*/
int SdifFOneMatrixTypeToSdifString(SdifMatrixTypeT *MatrixType, SdifStringT *SdifString);

size_t SdifFPutAllMatrixType        (SdifFileT *SdifF, int Verbose);


/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Write all Matrix type in SdifString
*/
int SdifFAllMatrixTypeToSdifString(SdifFileT *SdifF, SdifStringT *SdifSTring);

size_t SdifFPutOneComponent(SdifFileT *SdifF, int Verbose, SdifComponentT *Component);


/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Append one Component to SdifString
*/
int SdifFOneComponentToSdifString(SdifComponentT *Component, SdifStringT *SdifString);

size_t SdifFPutOneFrameType(SdifFileT *SdifF, int Verbose, SdifFrameTypeT *FrameType);

/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Append one frame type to SdifString
*/
int SdifFOneFrameTypeToSdifString(SdifFrameTypeT *FrameType, SdifStringT *SdifString);

size_t SdifFPutAllFrameType         (SdifFileT *SdifF, int Verbose);


/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Write all frame type in SdifString
*/
int SdifFAllFrameTypeToSdifString   (SdifFileT *SdifF, SdifStringT *SdifString);

size_t SdifFPutAllType              (SdifFileT *SdifF, int Verbose);


size_t SdifFPutOneStreamID          (SdifFileT *SdifF, int Verbose, SdifStreamIDT *StreamID);


/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Append one StreamID to SdifString
*/
int SdifFOneStreamIDToSDifString (SdifStringT *SdifString, SdifStreamIDT *StreamID);

size_t SdifFPutAllStreamID          (SdifFileT *SdifF, int Verbose);


/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Write all StreamID in SdifString
*/
int SdifFAllStreamIDToSdifString (SdifFileT *SdifF, SdifStringT *SdifString);

/*
 * obsolete
 */
size_t SdifFPutNameValueCurrHT      (SdifFileT *SdifF, int Verbose);

#endif /* _SdifFPut_ */




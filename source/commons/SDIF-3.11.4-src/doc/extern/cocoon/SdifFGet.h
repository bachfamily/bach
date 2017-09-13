/* $Id: SdifFGet.h,v 1.2 2000/10/27 20:02:56 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr

LIBRARY
 * SdifFGet.h
 *
 * F : SdifFileT*, Get : ascii frames reading,
 * common to read a sdif file and a pseudo-sdif text file
 * 'verbose' allows to choise if the file is a sdif file or a pseudo-sdif text file
 *
 * author: Dominique Virolle 1997
 *

DESCRIPTION 

   LECTURE

   <strong>Remarque</strong>: En lecture, on a toujours une
   avance sur la signature des chunks ou des frames. Ceci permet
   d'orientée la lecture suivant le type de données: chunk ou frame.

LOG
 * $Log: SdifFGet.h,v $
 * Revision 1.2  2000/10/27 20:02:56  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:47:52  tisseran
 * *** empty log message ***
 *
 * Revision 3.5  2000/07/18  15:08:29  tisseran
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
 * Revision 3.4  2000/04/11  14:31:20  schwarz
 * Read/write NVT as frame with 1 text matrix, conforming to SDIF spec.
 *
 * Revision 3.3  1999/09/28  13:08:52  schwarz
 * Included #include <preincluded.h> for cross-platform uniformisation,
 * which in turn includes host_architecture.h and SDIF's project_preinclude.h.
 *
 * Revision 3.2  1999/08/25  18:32:34  schwarz
 * Added cocoon-able comments with sentinel "DOC:" (on a single line).
 *
 * Revision 3.1  1999/03/14  10:56:38  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/01/23  15:55:39  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:23  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:06  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:29  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.2  1998/11/10  15:31:40  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 */


#ifndef _SdifFGet_
#define _SdifFGet_

#include "SdifGlobals.h"
#include "SdifFileStruct.h"
#include "SdifString.h"
#include <stdio.h>


/*DOC: 
  Lit 4 bytes, les considère comme une signature qui est placée dans
  SdifF->CurrSignature, incrémente NbCharRead du nombre de bytes lus
  et renvoie le dernier caractère lu convert en int (-1 si erreur).  */
int    SdifFGetSignature	(SdifFileT *SdifF, size_t *NbCharRead);

int    SdifFGetOneNameValue     (SdifFileT *SdifF, int Verbose, size_t *NbCharRead);
size_t SdifFGetNameValueLCurrNVT(SdifFileT *SdifF, int Verbose);
int    SdifFNameValueLCurrNVTfromString (SdifFileT *SdifF, char *str);

/*DOC:
  Remark:
         This function implements the old SDIF Specification (before June 1999)
  Get the current matrix type from a file
*/
size_t SdifFGetOneMatrixType    (SdifFileT *SdifF, int Verbose);


/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Return the current matrix type from a SdifStringT
*/
size_t SdifFGetOneMatrixTypefromSdifString(SdifFileT *SdifF, SdifStringT *SdifString);

/*DOC:
  Remark:
         This function implements the old SDIF Specification (before June 1999)
  Get the current component from a file
*/
int    SdifFGetOneComponent     (SdifFileT *SdifF, int Verbose,
				 SdifSignature *MatrixSignature,
				 char *ComponentName,
				 size_t *NbCharRead);

/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Return the current component from a SdifStringT
*/
int    SdifFGetOneComponentfromSdifString(SdifFileT *SdifF,
					  SdifStringT *SdifString,
					  SdifSignature *MatrixSignature,
					  char *ComponentName);

/*DOC:
  Remark:
         This function implements the old SDIF Specification (before June 1999)
  Get the current Frame type from a file
*/
size_t SdifFGetOneFrameType     (SdifFileT *SdifF, int Verbose);

/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Return the current frame type from a SdifStringT
*/
size_t SdifFGetOneFrameTypefromSdifString(SdifFileT *SdifF, SdifStringT *SdifString);

/*DOC:
  Remark:
         This function implements the old SDIF Specification (before June 1999)
  Get all types from a file
*/
size_t SdifFGetAllType          (SdifFileT *SdifF, int Verbose);

/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Get all types from a SdifStringT
*/
size_t    SdifFGetAllTypefromSdifString   (SdifFileT *SdifF, SdifStringT *SdifString);

/*DOC:
  Remark:
         This function implements the old SDIF Specification (before June 1999)
  Get the current Stream ID from a file
*/
int    SdifFGetOneStreamID      (SdifFileT *SdifF, int Verbose, size_t *NbBytesRead);

/*DOC:
  Remark:
         This function is implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Get the current Stream ID from a SdifStringT
*/
int SdifFgetOneStreamIDfromSdifString(SdifFileT *SdifF, SdifStringT *SdifString);

/*DOC:
  Remark:
         This function implements the old SDIF Specification (before June 1999)
  Get all Stream ID from a file
*/
size_t SdifFGetAllStreamID      (SdifFileT *SdifF, int Verbose);

/*DOC:
  Remark:
         This function implements the new SDIF Specification (June 1999):
	 Name Value Table, Matrix and Frame Type declaration, Stream ID declaration are
	 defined in text matrix:
	 1NVT 1NVT
	 1TYP 1TYP
	 1IDS 1IDS
  Get the current Stream ID from a SdifStringT
*/
size_t SdifFGetAllStreamIDfromSdifString(SdifFileT *SdifF, SdifStringT *SdifString);

/*
 * obsolete
 */
size_t SdifFGetNameValueCurrHT (SdifFileT *SdifF, int Verbose);

#endif /* _SdifFGet_ */

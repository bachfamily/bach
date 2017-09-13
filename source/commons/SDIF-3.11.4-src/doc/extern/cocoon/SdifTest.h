/* $Id: SdifTest.h,v 1.2 2000/10/27 20:03:04 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
LIBRARY
 * SdifTest.h
 *
 * Tests with message on errors apply on a SdifFileT*
 * exit(1) is exceptional
 *
 *
 * author: Dominique Virolle 1997
 *
LOG
 * $Log: SdifTest.h,v $
 * Revision 1.2  2000/10/27 20:03:04  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:31  tisseran
 * *** empty log message ***
 *
 * Revision 3.3  1999/09/28  13:09:15  schwarz
 * Included #include <preincluded.h> for cross-platform uniformisation,
 * which in turn includes host_architecture.h and SDIF's project_preinclude.h.
 *
 * Revision 3.2  1999/08/25  18:32:37  schwarz
 * Added cocoon-able comments with sentinel "DOC:" (on a single line).
 *
 * Revision 3.1  1999/03/14  10:57:24  virolle
 * SdifStdErr add
 *
 * Revision 2.1  1998/12/21  18:27:42  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:42:09  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.4  1998/11/10  15:31:56  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */

#ifndef _SdifTest_
#define _SdifTest_

#include "SdifGlobals.h"
#include "SdifFileStruct.h"
#include "SdifMatrixType.h"
#include "SdifFrameType.h"

/*
typedef enum SdifInterpretationErrorE
{
  eTypeDataNotSupported= 300,
  eNameLength,
  eReDefined,
  eUnDefined,
  eSyntax,
  eRecursiveDetect,
  eBadTypesFile,
  eBadType,
  eBadHeader,
  eOnlyOneChunkOf,
  eUnInterpreted,
  eUserDefInFileYet,
  eBadMode,
  eBadStdFile,
  eBadNbData,
  eReadWriteOnSameFile
} SdifInterpretationErrorET;



void
SdifInterpretationError(SdifInterpretationErrorET Error, SdifFileT* SdifF, const void *ErrorMess);

#define _SdifFileMess(sdiff, error, mess) \
(SdifErrorFile = __FILE__, SdifErrorLine = __LINE__, SdifInterpretationError((error), (sdiff),(mess)))

*/

#define _SdifFileMess(sdiff, error, mess) 

/*DOC: 
  Cette fonction vérifie si le type de matrice est répertorié
  dans SdifF.<br> S'il ne l'est pas, alors elle vérifie si c'est un
  type prédéfinis. S'il est prédéfini, elle crée le lien de SdifF vers
  le type prédéfini. Sinon, elle envoie un message sur l'erreur
  standart.  */
SdifMatrixTypeT* SdifTestMatrixType (SdifFileT *SdifF, SdifSignature Signature);
SdifFrameTypeT*  SdifTestFrameType  (SdifFileT *SdifF, SdifSignature Signature);



short SdifFTestMatrixWithFrameHeader (SdifFileT* SdifF);
short SdifFTestDataType              (SdifFileT* SdifF);
short SdifFTestNbColumns             (SdifFileT* SdifF);
short SdifFTestNotEmptyMatrix        (SdifFileT* SdifF);
short SdifFTestMatrixHeader          (SdifFileT* SdifF);



SdifColumnDefT*  SdifTestColumnDef (SdifFileT *SdifF, SdifMatrixTypeT *MtrxT, char *NameCD);
SdifComponentT*  SdifTestComponent (SdifFileT* SdifF, SdifFrameTypeT *FramT, char *NameCD);

short SdifTestSignature            (SdifFileT *SdifF, int CharEnd, SdifSignature Signature, char *Mess);
short SdifTestCharEnd              (SdifFileT *SdifF, int CharEnd, char MustBe,
					   char *StringRead, short ErrCondition, char *Mess);


short SdifTestMatrixTypeModifMode  (SdifFileT *SdifF, SdifMatrixTypeT *MatrixType);
short SdifTestFrameTypeModifMode   (SdifFileT *SdifF, SdifFrameTypeT *FrameType);

#endif /* _ SdifTest_ */

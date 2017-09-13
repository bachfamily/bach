/* $Id: SdifFrameType.h,v 1.2 2000/10/27 20:02:59 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifFrameType.h
 *
 * Frame Types management (interpreted sdif frame types)
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifFrameType.h,v $
 * Revision 1.2  2000/10/27 20:02:59  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:07  tisseran
 * *** empty log message ***
 *
 * Revision 3.1  1999/03/14  10:56:56  virolle
 * SdifStdErr add
 *
 * Revision 2.1  1998/12/21  18:27:21  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:46  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.4  1998/11/10  15:31:47  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */


#ifndef _SdifFrameType_
#define _SdifFrameType_

#include "SdifGlobals.h"
#include "SdifHash.h"

typedef struct SdifComponentS SdifComponentT;
struct SdifComponentS
{
  SdifSignature MtrxS;
  char *Name;
  SdifUInt4  Num;
} ;



typedef struct SdifFrameTypeS SdifFrameTypeT;
struct SdifFrameTypeS
{
  SdifSignature Signature;

  SdifFrameTypeT* FrameTypePre;

  SdifHashTableT *ComponentUseHT;
  SdifUInt4       NbComponentUse;

  SdifUInt4       NbComponent;
  SdifModifModeET ModifMode;
};


SdifComponentT* SdifCreateComponent (SdifSignature MtrxS, char *Name, SdifUInt4 Num);
void            SdifKillComponent   (SdifComponentT *Component);
SdifFrameTypeT* SdifCreateFrameType (SdifSignature FramS, SdifFrameTypeT *PredefinedFrameType);

void            SdifKillFrameType               (SdifFrameTypeT *FrameType);
SdifComponentT* SdifFrameTypeGetComponent_MtrxS (SdifFrameTypeT *FrameType, SdifSignature MtrxS);
SdifComponentT* SdifFrameTypeGetComponent       (SdifFrameTypeT *FrameType, char *NameC);
SdifComponentT* SdifFrameTypeGetNthComponent    (SdifFrameTypeT *FrameType, SdifUInt4 NumC);
SdifFrameTypeT* SdifFrameTypePutComponent       (SdifFrameTypeT *FrameType, SdifSignature MtrxS, char *NameC);

SdifFrameTypeT* SdifGetFrameType       (SdifHashTableT *FrameTypeHT, SdifSignature FramS);
void            SdifPutFrameType       (SdifHashTableT *FrameTypeHT, SdifFrameTypeT *FrameType);
SdifUInt2       SdifExistUserFrameType (SdifHashTableT *FrameTypeHT);

#endif /* _SdifFrameType_  */

/* $Id: SdifTimePosition.h,v 1.2 2000/10/27 20:03:05 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifTimePosition.h
 *
 *  NOT INCLUDE IN THE SDIF PROJECT AT NOV 1997
 * author: Dominique Virolle 1997
 *
 * $Log: SdifTimePosition.h,v $
 * Revision 1.2  2000/10/27 20:03:05  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:33  tisseran
 * *** empty log message ***
 *
 * Revision 3.2  2000/05/15  16:22:37  schwarz
 * Avoid warning about KillerFT function pointer type (ANSI prototype given).
 * Argument to kill func is now void *.
 *
 * Revision 3.1  1999/03/14  10:57:28  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/01/23  15:56:03  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:50  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:45  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:42:12  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.3  1998/11/10  15:31:57  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */


#ifndef _SdifTimePosition_
#define _SdifTimePosition_



#include "SdifGlobals.h"
#include "SdifList.h"

#include <stdio.h>

typedef struct SdifTimePositionS SdifTimePositionT;

struct SdifTimePositionS
{
  SdifFloat8    Time;
  SdiffPosT     Position;
} ;

SdifTimePositionT* SdifCreateTimePosition(SdifFloat8 Time, SdiffPosT Position);
void               SdifKillTimePosition(void* TimePosition);



typedef struct SdifTimePositionLS SdifTimePositionLT;

struct SdifTimePositionLS
{
    SdifListT*          TimePosList;
} ;


SdifTimePositionLT* SdifCreateTimePositionL(void);
void                SdifKillTimePositionL  (SdifTimePositionLT *TimePositionL);

SdifTimePositionLT* SdifTimePositionLPutTail(SdifTimePositionLT* TimePositionL,
                                             SdifFloat8 Time, SdiffPosT Position);
SdifTimePositionT*  SdifTimePositionLGetTail(SdifTimePositionLT* TimePositionL);

#endif /* _SdifTimePosition_ */

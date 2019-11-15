/* $Id: SdifError.h,v 1.2 2000/10/27 20:02:56 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 * 
 * SdifError.h
 *
 * Fatal or program error management
 *
 * author: Dominique Virolle 1997
 * 
 * $Log: SdifError.h,v $
 * Revision 1.2  2000/10/27 20:02:56  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:47:51  tisseran
 * *** empty log message ***
 *
 * Revision 3.2  2000/03/01  11:17:34  schwarz
 * Configurable exit function on error.
 *
 * Revision 3.1  1999/03/14  10:56:36  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/02/28  12:16:38  virolle
 * memory report
 *
 * Revision 2.2  1999/01/23  13:57:21  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:03  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:26  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.4  1998/11/10  15:31:39  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 * Revision 1.3  1998/04/24  12:40:32  schwarz
 * Made char * arguments constant for SdifNameValuesLPut and functions called by it.
 *
 */


#ifndef _SdifError_
#define _SdifError_

#include <stdio.h>

typedef enum SdifErrorE
{
  eFalse = 0,
  eTrue = 1,
  eFreeNull = 256,
  eAllocFail,
  eArrayPosition,
  eEof,
  eFileNotFound,
  eInvalidPreType,
  eAffectationOrder,
  eNoModifErr,
  eNotInDataTypeUnion,
  eNotFound,
  eExistYet,
  eWordCut,
  eTokenLength
} SdifErrorEnum;

typedef void (*SdifExitFuncT) (void);

extern SdifExitFuncT gSdifExitFunc;
extern char *SdifErrorFile;
extern int SdifErrorLine;
extern FILE* SdifStdErr;

void SdifSetExitFunc (SdifExitFuncT func);
void SdifErrorWarning(SdifErrorEnum Error, const void *ErrorMess);

#define _SdifError(error, mess) \
(SdifErrorFile = __FILE__, SdifErrorLine = __LINE__, SdifErrorWarning((error), (mess)))


#define _Debug(mess) \
(SdifErrorFile = __FILE__, SdifErrorLine = __LINE__, \
fprintf(SdifStdErr, "*Sdif Debug* %s, %d:\n", SdifErrorFile, SdifErrorLine), \
fprintf(SdifStdErr, "%s\n",(mess)))

#define _SdifRemark(mess) \
fprintf(SdifStdErr, "*Sdif* %s\n", mess)

#endif /* _SdifError_ */

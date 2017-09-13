/* $Id: SdifErrMess.h,v 1.2 2000/10/27 20:02:56 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 * 
 * SdifErrMess.h
 *
 * high level (SdifF) error management
 *
 * author: Dominique Virolle 1998
 * 
 * $Log: SdifErrMess.h,v $
 * Revision 1.2  2000/10/27 20:02:56  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:47:50  tisseran
 * *** empty log message ***
 *
 * Revision 3.3  2000/05/15  16:22:30  schwarz
 * Avoid warning about KillerFT function pointer type (ANSI prototype given).
 * Argument to kill func is now void *.
 *
 * Revision 3.2  1999/09/28  10:35:43  schwarz
 * Added SdifEnableErrorOutput/SdifDisableErrorOutput to temporarily
 * switch off error messages when doing things that might fail.
 *
 * Revision 3.1  1999/03/14  10:56:34  virolle
 * SdifStdErr add
 *
 *
 */


#ifndef _SdifErrMess_
#define _SdifErrMess_

#include "SdifGlobals.h"
#include "SdifList.h"
#include <stdio.h>
#include "SdifError.h"


/*#include "SdifFile.h"
 */
#ifndef SdifFileT_
#define SdifFileT_
typedef struct SdifFileS SdifFileT;
#endif

typedef enum SdifErrorTagE
{
	eUnknow,
	eNoError,
	eTypeDataNotSupported,
	eNameLength,
	eReDefined,
	eUnDefined,
	eSyntax,
	eBadTypesFile,
	eBadType,
	eBadHeader,
	eRecursiveDetect,
	eUnInterpreted,
	eOnlyOneChunkOf,
	eUserDefInFileYet,
	eBadMode,
	eBadStdFile,
	eBadNbData,
	eReadWriteOnSameFile,
    eBadFormatVersion,
    eMtrxUsedYet,
    eMtrxNotInFrame
} SdifErrorTagET;


typedef enum SdifErrorLevelE
{
	eFatal,
	eError,
	eWarning,
	eRemark,
	eNoLevel
} SdifErrorLevelET;




typedef struct SdifErrorS SdifErrorT;
struct SdifErrorS
{
	SdifErrorTagET		Tag;
	SdifErrorLevelET	Level;
	char*				UserMess;
};

/* Table of error format for the fprintf */
extern const SdifErrorT gSdifErrMessFormat[];


typedef struct SdifErrorLS SdifErrorLT;
struct SdifErrorLS
{
  SdifListT*    ErrorList;
  SdifFileT*	SdifF; /* only a link */
};


SdifErrorT*	SdifCreateError		(SdifErrorTagET Tag,
					 SdifErrorLevelET Level, 
					 const char* UserMess);
void		SdifKillError		(void *Error);
SdifErrorLT*	SdifCreateErrorL	(SdifFileT* SdifF);
void		SdifKillErrorL		(SdifErrorLT *ErrorL);
SdifErrorLT*	SdifInsertTailError	(SdifErrorLT* ErrorL,
					 SdifErrorTagET Tag, 
					 const char* UserMess);
SdifErrorT*	SdifLastError		(SdifErrorLT *ErrorL);
SdifErrorTagET	SdifLastErrorTag	(SdifErrorLT *ErrorL);
SdifInt4	SdifFsPrintError	(char* oErrMess, SdifFileT* SdifF,
					 SdifErrorT* Error,
					 const char *LibFile, int LibLine);

/*DOC:
  Switch output of error messages on stderr by _SdifFError on. 
*/
void	SdifEnableErrorOutput  (void);

/*DOC:
  Switch output of error messages on stderr by _SdifFError off. 
*/
void	SdifDisableErrorOutput (void);


extern char	gSdifBufferError[4096];
extern int	gSdifErrorOutputEnabled;


#define _SdifFError(SdifF, ErrorTag, UserMess) \
(SdifInsertTailError(SdifF->Errors, ErrorTag, UserMess), \
 SdifFsPrintError(gSdifBufferError, SdifF, SdifLastError(SdifF->Errors), __FILE__, __LINE__), \
gSdifErrorOutputEnabled  ?  fprintf(SdifStdErr,"%s", gSdifBufferError)  :  0)

#endif  /* _SdifErrMess_ */

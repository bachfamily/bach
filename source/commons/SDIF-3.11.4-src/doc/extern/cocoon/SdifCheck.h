/* $Id: SdifCheck.h,v 1.2 2000/10/27 20:02:55 roebel Exp $
  
                 Copyright (c) 1998 by IRCAM - Centre Pompidou
                            All rights reserved.
  
    For any information regarding this and other IRCAM software, please
    send email to:
                              manager@ircam.fr

LIBRARY
    SdifCheck.h		2. May 2000		Diemo Schwarz

    File test functions.

LOG
    $Log: SdifCheck.h,v $
    Revision 1.2  2000/10/27 20:02:55  roebel
    autoconf merged back to main trunk

 * Revision 1.1.2.1  2000/08/21  17:47:47  tisseran
 * *** empty log message ***
 *
 * Revision 3.1  2000/05/04  14:59:34  schwarz
 * Added modules SdifCheck and SdifSignatureTab, containing functions
 * formerly in SdifFile.
 *
*/


#ifndef _SdifCheck_
#define _SdifCheck_

#include "SdifFileStruct.h"


/*DOC: 
  Test if file is an SDIF file.

  [] Returns:	0 if not an SDIF file (the first 4 chars are not "SDIF"),
		or file can not be opened, else 1.  

  Warning: This function doesn't work with stdio. */
int SdifCheckFileFormat (const char *name);


/*DOC: 
  Test if file contains frames of certain types.

  [in]  name	Filename + selection
	frames  Table of frame signatures to look for
  []	return	The first signature from frames found, or eEmptySignature if 
		no frames could be found (or if file is not SDIF).

  Warning: This function doesn't work with stdio. */
SdifSignature SdifCheckFileFramesTab   (const char		*name, 
					const SdifSignatureTabT *frames);

/*DOC: 
  Test if file contains frames of certain types.

  [in]  name	Filename + selection
	frames  Array of frame signatures to look for, terminated with 
		eEmptySignature.
  []	return	The index in frames of the first signature found, or -1
		if no frames could be found (or if file is not SDIF).

  Warning: This function doesn't work with stdio. */
int	      SdifCheckFileFramesIndex (const char	        *name, 
					const SdifSignature     *frames);

/*DOC: 
  Test if file contains frames of certain types.

  [in]  in	open SDIF file
	frames  Table of frame signatures to look for
  [out] index   If the int pointer index is not NULL, it will receive
		the index in frames of the first signature found, or -1
		if no frames could be found (or if file is not SDIF).
  []	return	The first signature from frames found, or eEmptySignature if 
		no frames could be found (or if file is not SDIF).

  Warning: This function doesn't work with stdio. */
SdifSignature SdifCheckNextFrame       (SdifFileT		*in, 
					const SdifSignatureTabT *frames,
					int			*index);

/*DOC: 
  TODO: Test if file is an SDIF file (only when opening for read or
  append) and open it.

  [Return] NULL if not an SDIF file (the first 4 chars are not "SDIF"),
  or file can not be opened.  */
SdifFileT*	   SdifFTryOpen			(const char *Name, SdifFileModeET Mode);

#endif /* _SdifCheck_ */

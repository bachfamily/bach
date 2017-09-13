/* $Id: SdifSignatureTab.h,v 1.2 2000/10/27 20:03:04 roebel Exp $
  
                 Copyright (c) 1998 by IRCAM - Centre Pompidou
                            All rights reserved.
  
    For any information regarding this and other IRCAM software, please
    send email to:
                              manager@ircam.fr

LIBRARY
    SdifSignatureTab.h		4. May 2000		Diemo Schwarz

    Handling of a Table of Signatures

LOG
    $Log: SdifSignatureTab.h,v $
    Revision 1.2  2000/10/27 20:03:04  roebel
    autoconf merged back to main trunk

 * Revision 1.1.2.1  2000/08/21  17:48:26  tisseran
 * *** empty log message ***
 *
 * Revision 3.1  2000/05/04  14:59:33  schwarz
 * Added modules SdifCheck and SdifSignatureTab, containing functions
 * formerly in SdifFile.
 *
*/



#ifndef _SdifSignatureTab_
#define _SdifSignatureTab_


#include "SdifGlobals.h"

/* Growth steps for reallocation */
#define _SdifSignatureTabGranule 16


typedef struct SdifSignatureTabS SdifSignatureTabT;
struct SdifSignatureTabS
{
  SdifUInt4 NbSignMax;
  SdifUInt4 NbSign;
  SdifSignature* Tab;
};


/*
// FUNCTION GROUP:	Handling of a Table of Signatures
*/

/*DOC:
  Create table for initially NbSignMax signatures. */
SdifSignatureTabT* SdifCreateSignatureTab (const SdifUInt4 NbSignMax);

/*DOC:
  Free signature table. */
void		   SdifKillSignatureTab   (SdifSignatureTabT *SignTab);

/*DOC:
  Reallocate table to hold NewNbSignMax signatures. */
SdifSignatureTabT* SdifReAllocSignatureTab(SdifSignatureTabT *SignTab, 
					   const SdifUInt4 NewNbSignMax);

/*DOC:
  Reallocate table to hold NewNbSignMax signatures and clear signatures. */
SdifSignatureTabT* SdifReInitSignatureTab (SdifSignatureTabT *SignTab, 
					   const SdifUInt4 NewNbSignMax);

/*DOC:
  Add signature Sign, no overflow check. */
SdifSignatureTabT* SdifPutInSignatureTab  (SdifSignatureTabT *SignTab, 
					   const SdifSignature Sign);

/*DOC:
  Add signature Sign, reallocate table if necessary. */
SdifSignatureTabT* SdifAddToSignatureTab  (SdifSignatureTabT *SignTab, 
					   const SdifSignature Sign);

/*DOC:
  Get signature at position index.  
  Returns eEmptySignature if index out of bounds. */
SdifSignature      SdifGetFromSignatureTab(const SdifSignatureTabT* SignTab, 
					   const int index);

/*DOC:
  Test if signature Sign is in table SignTab. 
  [] Returns Sign if yes, 0 (== eEmptySignature) if no. */
SdifSignature      SdifIsInSignatureTab   (const SdifSignatureTabT *SignTab, 
					   const SdifSignature Sign);

/*DOC:
  Test if signature Sign is in table SignTab. 
  [] Returns index of Sign if yes, -1 if no. */
int		   SdifFindInSignatureTab (const SdifSignatureTabT* SignTab, 
					   const SdifSignature Sign);


#endif /* _SdifSignatureTab_ */

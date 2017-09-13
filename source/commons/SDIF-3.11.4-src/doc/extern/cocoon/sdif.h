/* $Id: sdif.h,v 1.2 2000/10/27 20:03:06 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * sdif.h
 *
 * Sound Description Interchange Format
 *
 * sdif library for management.
 *
 *
 * author: Dominique Virolle 1997
 *
 * $Log: sdif.h,v $
 * Revision 1.2  2000/10/27 20:03:06  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:37  tisseran
 * *** empty log message ***
 *
 * Revision 3.6  2000/07/18  15:08:42  tisseran
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
 * Revision 3.5  2000/07/06  19:01:50  tisseran
 * Add function for frame and matrix type declaration
 * Remove string size limitation for NameValueTable
 * TODO: 1TYP and 1IDS frame must contain an 1NVT (text) matrix
 *       Actually, data are written with fprintf.
 *
 * Revision 3.4  2000/05/04  15:03:43  schwarz
 * Added modules SdifCheck and SdifSignatureTab.
 *
 * Revision 3.3  2000/03/01  11:20:20  schwarz
 * Added preliminary sketch of SdifHighLevel
 *
 * Revision 3.2  1999/08/31  10:02:58  schwarz
 * Added module SdifSelect which parses an access specification to a
 * chosen part of SDIF data.  Can be added to a file name.
 *
 * Revision 3.1  1999/03/14  10:57:29  virolle
 * SdifStdErr add
 *
 * Revision 2.1  1998/12/21  18:27:46  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:42:14  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.3  1998/11/10  15:31:58  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */

#ifndef _sdif_
#define _sdif_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
  
#include "SdifHash.h"
#include "SdifError.h"
#include "SdifGlobals.h"
#include "SdifRWLowLevel.h"

#include "SdifNameValue.h"
#include "SdifStreamID.h"
#include "SdifMatrixType.h"
#include "SdifFrameType.h"

#include "SdifMatrix.h"
#include "SdifFrame.h"

#include "SdifTimePosition.h"
#include "SdifSignatureTab.h"
#include "SdifFileStruct.h"
#include "SdifTest.h"
#include "SdifFile.h"

#include "SdifPrint.h"

#include "SdifFGet.h"
#include "SdifFRead.h"
#include "SdifFScan.h"

#include "SdifFPut.h"
#include "SdifFPrint.h"
#include "SdifFWrite.h"
#include "SdifHighLevel.h"

#include "SdifTextConv.h"
#include "SdifConvToText.h"

#include "SdifPreTypes.h"
#include "SdifSelect.h"
#include "SdifCheck.h"

#include "SdifString.h"
  
#ifdef __cplusplus
}
#endif

#endif /* _sdif_ */

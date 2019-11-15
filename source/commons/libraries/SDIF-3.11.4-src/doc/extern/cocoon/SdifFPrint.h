/* $Id: SdifFPrint.h,v 1.2 2000/10/27 20:02:57 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifFPrint.h
 *
 * F : SdifFileT* SdifF, Print : write only into the pseudo-sdif text file, SdifF->TextStream.
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifFPrint.h,v $
 * Revision 1.2  2000/10/27 20:02:57  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:47:54  tisseran
 * *** empty log message ***
 *
 * Revision 3.1  1999/03/14  10:56:40  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/01/23  15:55:41  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:24  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:07  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:30  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.2  1998/11/10  15:31:41  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */


#ifndef _SdifFPrint_
#define _SdifFPrint_


#include "SdifGlobals.h"
#include <stdio.h>
#include "SdifFileStruct.h"
#include "SdifMatrix.h"
#include "SdifFrame.h"


size_t SdifFPrintGeneralHeader      (SdifFileT *SdifF);
size_t SdifFPrintNameValueLCurrNVT  (SdifFileT *SdifF);
size_t SdifFPrintAllNameValueNVT    (SdifFileT *SdifF);
size_t SdifFPrintAllType            (SdifFileT *SdifF);
size_t SdifFPrintAllStreamID        (SdifFileT *SdifF);
size_t SdifFPrintAllASCIIChunks     (SdifFileT *SdifF);
size_t SdifFPrintMatrixHeader       (SdifFileT *SdifF);
size_t SdifFPrintFrameHeader        (SdifFileT *SdifF);
size_t SdifFPrintOneRow             (SdifFileT *SdifF);

size_t SdifFPrintMatrixType         (SdifFileT *SdifF, SdifMatrixTypeT *MatrixType);
size_t SdifFPrintFrameType          (SdifFileT *SdifF, SdifFrameTypeT  *FrameType);


/*
 * obsolete
 */
size_t SdifFPrintNameValueCurrHT (SdifFileT *SdifF);
size_t SdifFPrintAllNameValueHT  (SdifFileT *SdifF);

#endif /* _SdifFPrint_ */

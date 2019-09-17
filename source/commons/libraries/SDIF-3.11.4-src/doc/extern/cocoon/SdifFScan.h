/* $Id: SdifFScan.h,v 1.2 2000/10/27 20:02:57 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifFScan.h
 *
 * F : SdifFileT* SdifF, Scan : pseudo-sdif text file read (SdifF->TextStream)
 *
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifFScan.h,v $
 * Revision 1.2  2000/10/27 20:02:57  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:00  tisseran
 * *** empty log message ***
 *
 * Revision 3.1  1999/03/14  10:56:46  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/01/23  15:55:45  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:29  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:12  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:36  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.2  1998/11/10  15:31:43  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */


#ifndef _SdifFScan_
#define _SdifFScan_

#include "SdifGlobals.h"
#include "SdifFileStruct.h"
#include <stdio.h>
#include "SdifMatrix.h"
#include "SdifFrame.h"

size_t  SdifFScanGeneralHeader      (SdifFileT *SdifF);
size_t  SdifFScanNameValueLCurrNVT  (SdifFileT *SdifF);
size_t  SdifFScanAllType            (SdifFileT *SdifF);
size_t  SdifFScanAllStreamID        (SdifFileT *SdifF);
size_t  SdifFScanAllASCIIChunks     (SdifFileT *SdifF);
void    SdifFScanMatrixHeader       (SdifFileT *SdifF);
void    SdifFScanFrameHeader        (SdifFileT *SdifF);
void    SdifFScanOneRow             (SdifFileT *SdifF);

size_t  SdifFScanMatrixType         (SdifFileT *SdifF);
size_t  SdifFScanFrameType          (SdifFileT *SdifF);


/*
 * obsolete
 */
size_t  SdifFScanNameValueCurrHT    (SdifFileT *SdifF);

#endif /* _SdifFScan_ */

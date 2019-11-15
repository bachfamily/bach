/* $Id: SdifTextConv.h,v 1.2 2000/10/27 20:03:05 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr

LIBRARY
 * SdifTextConv.h
 *
 *
 * Convert a pseudo-sdif text file to a sdif file
 *
 *
 * author: Dominique Virolle 1997

DESCRIPTION
   La librairie possède deux fonctions permettant de faire des conversions
   de fichiers SDIF binaire vers du texte ou l'inverse.

LOG
 * $Log: SdifTextConv.h,v $
 * Revision 1.2  2000/10/27 20:03:05  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:32  tisseran
 * *** empty log message ***
 *
 * Revision 3.3  1999/09/28  13:09:16  schwarz
 * Included #include <preincluded.h> for cross-platform uniformisation,
 * which in turn includes host_architecture.h and SDIF's project_preinclude.h.
 *
 * Revision 3.2  1999/08/25  18:32:38  schwarz
 * Added cocoon-able comments with sentinel "DOC:" (on a single line).
 *
 * Revision 3.1  1999/03/14  10:57:26  virolle
 * SdifStdErr add
 *
 * Revision 2.1  1998/12/21  18:27:44  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:42:11  virolle
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
 */


#ifndef _SdifTextConv_
#define _SdifTextConv_

#include "SdifGlobals.h"
#include "SdifFileStruct.h"


size_t SdifFTextConvMatrixData     (SdifFileT *SdifF);
size_t SdifFTextConvMatrix         (SdifFileT *SdifF);
size_t SdifFTextConvFrameData      (SdifFileT *SdifF);
size_t SdifFTextConvFrameHeader    (SdifFileT *SdifF);
size_t SdifFTextConvFrame          (SdifFileT *SdifF);
size_t SdifFTextConvAllFrame       (SdifFileT *SdifF);
size_t SdifFTextConvFramesChunk    (SdifFileT *SdifF);
size_t SdifFTextConv               (SdifFileT *SdifF);

/* upper level : open the text in read mode */

/*DOC: 
  Converti un fichier SDIF ouvert en lecture (eReadFile) en un fichier
  texte pseudo-SDIF de nom TextStreamName.  */
size_t SdifTextToSdif (SdifFileT *SdifF, char *TextStreamName);

#endif   /* _SdifTextConv_ */

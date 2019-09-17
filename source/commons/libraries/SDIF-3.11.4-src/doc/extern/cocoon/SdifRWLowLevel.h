/* $Id: SdifRWLowLevel.h,v 1.2 2000/10/27 20:03:03 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifRWLowLevel.h
 *
 *
 * Read Write Low Level. Machine sex, little-big endian control
 *
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifRWLowLevel.h,v $
 * Revision 1.2  2000/10/27 20:03:03  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:23  tisseran
 * *** empty log message ***
 *
 * Revision 3.8  2000/07/18  15:08:39  tisseran
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
 * Revision 3.7  2000/05/15  16:23:11  schwarz
 * Avoided avoidable warnings.
 *
 * Revision 3.6  1999/10/15  12:23:48  schwarz
 * Added SdifStringToNV.
 *
 * Revision 3.5  1999/10/13  16:05:57  schwarz
 * Changed data type codes (SdifDataTypeET) to SDIF format version 3, as
 * decided with Matt Wright June 1999, added integer data types.
 * Added writing of 1NVT with real frame header (but data is still not in
 * matrices).
 * The data type handling makes heavy use of code-generating macros,
 * called for all data types with the sdif_foralltypes macro, thus
 * adding new data types is easy.
 *
 * Revision 3.4  1999/09/28  13:09:11  schwarz
 * Included #include <preincluded.h> for cross-platform uniformisation,
 * which in turn includes host_architecture.h and SDIF's project_preinclude.h.
 *
 * Revision 3.3  1999/09/20  13:23:35  schwarz
 * Optimized SdifStringToSignature.
 *
 * Revision 3.2  1999/08/31  10:05:48  schwarz
 * Extracted function SdifStringToSignature from SdiffGetSignature.
 *
 * Revision 3.1  1999/03/14  10:57:19  virolle
 * SdifStdErr add
 *
 * Revision 2.1  1998/12/21  18:27:38  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:42:05  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.5  1998/11/10  15:31:55  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */

#ifndef _SdifRWLowLevel_
#define _SdifRWLowLevel_


#include "SdifGlobals.h"
#include <stdio.h>
#include "SdifString.h"

#define _SdifBSLittleE 4096

#define _SdifPaddingChar  '\0'
#define _SdifReservedChars  ",;{}:"


size_t Sdiffread  (void *ptr, size_t size, size_t nobj, FILE *stream);
size_t Sdiffwrite (void *ptr, size_t size, size_t nobj, FILE *stream);

/* Read, return the number of objects */

size_t SdiffReadChar   (SdifChar   *ptr, size_t nobj, FILE *stream);
size_t SdiffReadInt2   (SdifInt2   *ptr, size_t nobj, FILE *stream);
size_t SdiffReadUInt2  (SdifUInt2  *ptr, size_t nobj, FILE *stream);
size_t SdiffReadInt4   (SdifInt4   *ptr, size_t nobj, FILE *stream);
size_t SdiffReadUInt4  (SdifUInt4  *ptr, size_t nobj, FILE *stream);
size_t SdiffReadFloat4 (SdifFloat4 *ptr, size_t nobj, FILE *stream);
size_t SdiffReadFloat8 (SdifFloat8 *ptr, size_t nobj, FILE *stream);

/*size_t SdiffReadSignature (SdifSignature *Signature, FILE *stream);*/



/* Write, return the number of objects */

size_t SdiffWriteChar   (SdifChar   *ptr, size_t nobj, FILE *stream);
size_t SdiffWriteInt2   (SdifInt2   *ptr, size_t nobj, FILE *stream);
size_t SdiffWriteUInt2  (SdifUInt2  *ptr, size_t nobj, FILE *stream);
size_t SdiffWriteInt4   (SdifInt4   *ptr, size_t nobj, FILE *stream);
size_t SdiffWriteUInt4  (SdifUInt4  *ptr, size_t nobj, FILE *stream);
size_t SdiffWriteFloat4 (SdifFloat4 *ptr, size_t nobj, FILE *stream);
size_t SdiffWriteFloat8 (SdifFloat8 *ptr, size_t nobj, FILE *stream);

size_t SdiffWriteSignature (SdifSignature *Signature, FILE *stream);
size_t SdiffWriteString (char* ptr, FILE *stream);

/*
 *size_t SdiffReadUInt8  (SdifUInt8  *ptr, size_t nobj, FILE *stream);
 *size_t SdiffWriteUInt8  (SdifUInt8  *ptr, size_t nobj, FILE *stream);
 */

/**Ascii**/
/* fGet --> return the last char
 */
size_t SdiffReadSpace   (FILE* fr);

size_t SdiffReadSpacefromSdifString(SdifStringT *SdifString);

/*DOC:
  Return c if it is a reserved char, -1 otherwise.
*/
int SdifIsAReservedChar (char c);

/*DOC: 
  Convert str <strong>in place</strong> so that it doesn't
  contain any reserved chars (these become '.') or spaces (these
  become '_').

  [] returns str
*/
char *SdifStringToNV (/*in out*/ char *str);

/* SdiffGetString lit un fichier jusqu'a un caractere reserve, ne
   rempli s que des caracteres non-espacement, renvoie le caractere
   reserve, saute les premiers caracteres espacement lus.  Il y a
   erreur si fin de fichier ou si un caractere non-espacement et
   non-reseve est lu apres un caractere espacement.  ncMax est
   typiquement strlen(s)+1.  
*/
int SdiffGetString      (FILE* fr, char* s, size_t ncMax, size_t *NbCharRead);

/* retourne le caractere d'erreur */
int SdiffGetSignature   (FILE* fr, SdifSignature *Signature, size_t *NbCharRead);
/*DOC:
  Function return the signature in a SdifStringT
*/
int SdiffGetSignaturefromSdifString(SdifStringT *SdifString, SdifSignature *Signature);

int SdiffGetWordUntil   (FILE* fr, char* s, size_t ncMax, size_t *NbCharRead, char *CharsEnd);
/*DOC:
  Function return the word until in a SdifStringT
*/
int SdiffGetWordUntilfromSdifString(SdifStringT *SdifString, char* s, size_t ncMax,char *CharsEnd);

int SdiffGetStringUntil (FILE* fr, char* s, size_t ncMax, size_t *NbCharRead, char *CharsEnd);
/*DOC:
  Function return the string until in a SdifStringT
 */
int SdiffGetStringUntilfromSdifString(SdifStringT *SdifString, char *s, size_t ncMax,
				      char *CharsEnd);

int SdiffGetStringWeakUntil(FILE* fr, char* s, size_t ncMax, size_t *NbCharRead, char *CharsEnd);
/*DOC:
  Return the weak string until in a SdifStringT
*/
int SdiffGetStringWeakUntilfromSdifString(SdifStringT *SdifString, char* s,
					  size_t ncMax, char *CharsEnd);

int SdifSkipASCIIUntil  (FILE* fr, size_t *NbCharRead, char *CharsEnd);


#if 0	/* for cocoon's eyes only */
/* scan nobj items of TYPE from stream, return number sucessfully read */
size_t SdiffScan_TYPE   (FILE *stream, Sdif_TYPE  *ptr, size_t nobj);
size_t SdiffScanFloat4  (FILE *stream, SdifFloat4 *ptr, size_t nobj);
size_t SdiffScanFloat8  (FILE *stream, SdifFloat8 *ptr, size_t nobj);
#endif


#ifdef __STDC__  /* Is the compiler ANSI? */

#define sdif_scanproto(type) \
size_t SdiffScan##type (FILE *stream, Sdif##type *ptr, size_t nobj)

sdif_proto_foralltypes (sdif_scanproto)

#endif /* __STDC__ */


/* Unsafe but optimized version of SdifStringToSignature:
   Exactly 4 chars are considered, so make sure *str has at least that many! 
   The str pointer MUST be word (at least 4 byte or so) aligned.
*/
SdifSignature _SdifStringToSignature (char *str);

/*DOC:
  Convert a string to an SDIF signature (in proper endianness).
  str can point to any string position of any length.  
*/
SdifSignature SdifStringToSignature (char *str);



#endif /* _SdifRWLowLevel_ */

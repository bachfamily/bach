/* $Id: SdifHighLevel.h,v 1.2 2000/10/27 20:03:01 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
LIBRARY
 *
 * SdifHighLevel.h	8.12.1999	Diemo Schwarz
 *
LOG
 * $Log: SdifHighLevel.h,v $
 * Revision 1.2  2000/10/27 20:03:01  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:13  tisseran
 * *** empty log message ***
 *
 * Revision 3.2  2000/04/11  14:44:28  schwarz
 * SdifFWriteTextMatrix, more docs.
 *
 * Revision 3.1  2000/03/01  11:20:21  schwarz
 * Added preliminary sketch of SdifHighLevel
 *
 */


#ifndef _SdifHighLevel_H_
#define _SdifHighLevel_H_


#include "SdifGlobals.h"
#include "SdifFileStruct.h"



#if 0	/* TBI */

/*
//FUNCTION GROUP: to be implemented / TBI
*/


/*DOC: 
  Write whole matrix, given as separate columns in array "columns" of
  pointer to "DataType".  Each columns [i], i = 0..NbCol-1, points to 
  NbRow * SdifSizeofDataType (DataType) bytes.  
  TBI 
*/
SdifFWriteMatrixColumns (SdifFileT     *file,
			 SdifSignature  Signature,
			 SdifDataTypeET DataType,
			 SdifUInt4      NbRow,
			 SdifUInt4      NbCol,
			 void	       *columns []);


SdifFWriteTextMatrix (SdifFileT f, SdifSignature matrixsig, const char *str)
{
    /* convert to UTF-8 */
    SdifConvertToUTF8 (str, utfstr);
    nbytes = strlen (utfstr);
    SdifFSetCurrMatrixHeader (f, matrixsig, eText, nbytes, 1);
    SdifFWriteMatrixHeader (f);

    /* write text data and padding */
}


/*DOC:
  Definition of the matrix callback function type, used for SdifReadSimple. 
  TBI 
*/
typedef int (*SdifMatrixCallbackT) (SdifFileT *file, 
				    int nummatrix, 
				    void *userdata);

/*DOC: 
  Reads an entire SDIF file, calling matrixfunc for each matrix in the
  SDIF selection taken from the filename.  Matrixfunc is called with
  the SDIF file pointer, the matrix count within the current frame,
  and the userdata unchanged. 
  TBI 
*/
SdifReadSimple (char		    *filename, 
		SdifMatrixCallbackT matrixfunc,
		void		    *userdata);


/* see SdifFRead */

SdifFReadMatrixAs_TYPE_ ();

#if 0
/* Alternative: extend SdifDataTypeET by */
  eTranslate = 0x1000, /* flag to be or'ed with data type: Translate on read */
  eTypeMask  = 0x0fff  /* mask to eliminate flags */
#endif


/*DOC: 
  Reads matrix header and data into memory allocated by the library,
  accessible by SdifFCurrMatrixData (). */
int SdifFReadMatrix (SdifFileT *file);

/* with type conversion */
int SdifFReadMatrixAs (SdifFileT *file, SdifDataTypeET as_type);

/*? text special: return allocated, decoded c-string, to be free'd by caller */
char *SdifFReadTextMatrix (SdifFileT *file);

/*DOC: 
  Reads matrix data into memory pointed to by target, which must point
  to at least nbrow * nbcol * size of datatype bytes of memory.  If
  target is NULL, the library will allocate enough space for the data
  of one matrix, accessible by SdifFCurrMatrixData ().

  [Precondition:] 
  Matrix header must have been read with SdifFReadMatrixHeader.  */
int SdifFReadMatrixData   (SdifFileT *file, void *target);

/* with type conversion */
int SdifFReadMatrixDataAs (SdifFileT *file, void *target,
			   SdifDataTypeET as_type);


/* --> SdifMatrix.h: add to SdifMatrixHeaderS not void *MatrixData, but:

   DataTypeUT Data;

   --> SdifFile.c: add void *SdifFCurrMatrixData (SdifFileT *);
*/

void *SdifFCurrMatrixData (SdifFileT *file)
{
  return file->CurrMtrxH->Data.Void;
}

void *SdifGetColumn ();



// Error handling


int /*bool*/ SdifFCheckStatus (SdifFileT *file)
{
  return (SdifLastError (file->ErrorList)) == NULL);
}


int /*bool*/ SdifFCheckStatusPrint (SdifFileT *file)
{
  SdifError err = SdifLastError (file->ErrorList));
  if (err != eNoError)
     print (SdifFsPrintFirstError (..., file, ...);
  return err == NULL;
}


/* --> test in SdifFReadGeneralHeader  (file) + SdifFReadAllASCIIChunks (file)
   if (!SdifFCheckStatus (file))
      SdifWarningAdd ("Followup error");
*/





#endif /* TBI */

#endif /* _SdifHighLevel_H_ */









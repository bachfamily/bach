/* $Id: SdifMatrix.h,v 1.2 2000/10/27 20:03:01 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifMatrix.h
 *
 * Matrix Header, Data, Rows structure management.
 *
 * Memory allocation of SdifOneRowT* depend on size of one granule.
 * if nb rows or data type (float4 or float8),
 * then SdifReInitOneRow makes a realloc. Then think to use it before write.
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifMatrix.h,v $
 * Revision 1.2  2000/10/27 20:03:01  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:15  tisseran
 * *** empty log message ***
 *
 * Revision 3.2  1999/10/13  16:05:52  schwarz
 * Changed data type codes (SdifDataTypeET) to SDIF format version 3, as
 * decided with Matt Wright June 1999, added integer data types.
 * Added writing of 1NVT with real frame header (but data is still not in
 * matrices).
 * The data type handling makes heavy use of code-generating macros,
 * called for all data types with the sdif_foralltypes macro, thus
 * adding new data types is easy.
 *
 * Revision 3.1  1999/03/14  10:57:07  virolle
 * SdifStdErr add
 *
 * Revision 2.1  1998/12/21  18:27:29  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:55  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.4  1998/11/10  15:31:51  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */

#ifndef _SdifMatrix_
#define _SdifMatrix_

#include "SdifGlobals.h"
#include "SdifMatrixType.h"



typedef struct SdifMatrixHeaderS SdifMatrixHeaderT;

struct SdifMatrixHeaderS
{
  SdifSignature  Signature;
  SdifDataTypeET DataType; /* Low level data type */
  SdifUInt4      NbRow;
  SdifUInt4      NbCol;
} ;




typedef union DataTypeU DataTypeUT;

union DataTypeU
{
  SdifFloat4 *Float4;
  SdifFloat8 *Float8;
  SdifInt2   *Int2  ;
  SdifInt4   *Int4  ;
/*SdifInt8   *Int8  ;*/
  SdifUInt2  *UInt2 ;
  SdifUInt4  *UInt4 ;
/*SdifUInt8  *UInt8 ;*/
  SdifChar   *Char  ;
  void	     *Void  ;	/* generic pointer */
} ;




typedef struct SdifOneRowS SdifOneRowT;

struct SdifOneRowS
{
  SdifDataTypeET DataType;
  SdifUInt4      NbData;
  DataTypeUT     Data;
  SdifUInt4      NbGranuleAlloc;
} ;



typedef struct SdifMatrixDataS SdifMatrixDataT;
struct SdifMatrixDataS
{
  SdifMatrixHeaderT *Header;
  SdifOneRowT       **Rows;
  SdifUInt4         Size;
} ;



SdifMatrixHeaderT* SdifCreateMatrixHeader    (SdifSignature Signature, 
					      SdifDataTypeET DataType,
					      SdifUInt4 NbRow, 
					      SdifUInt4 NbCol);

SdifMatrixHeaderT* SdifCreateMatrixHeaderEmpty (void);
void               SdifKillMatrixHeader        (SdifMatrixHeaderT *MatrixHeader);

SdifOneRowT*       SdifCreateOneRow          (SdifDataTypeET DataType, SdifUInt4  NbGranuleAlloc);
SdifOneRowT*       SdifReInitOneRow          (SdifOneRowT *OneRow, SdifDataTypeET DataType, SdifUInt4 NbData);
void               SdifKillOneRow            (SdifOneRowT *OneRow);
SdifOneRowT*       SdifOneRowPutValue        (SdifOneRowT *OneRow, SdifUInt4 numCol, SdifFloat8 Value);
SdifFloat8         SdifOneRowGetValue        (SdifOneRowT *OneRow, SdifUInt4 numCol);
SdifFloat8         SdifOneRowGetValueColName (SdifOneRowT *OneRow, SdifMatrixTypeT *MatrixType, char * NameCD);

SdifMatrixDataT*   SdifCreateMatrixData      (SdifSignature Signature, SdifDataTypeET DataType,
						     SdifUInt4 NbRow, SdifUInt4 NbCol);

void               SdifKillMatrixData        (SdifMatrixDataT *MatrixData);
SdifMatrixDataT*   SdifMatrixDataPutValue    (SdifMatrixDataT *MatrixData,
						     SdifUInt4  numRow, SdifUInt4  numCol, SdifFloat8 Value);

SdifFloat8         SdifMatrixDataGetValue    (SdifMatrixDataT *MatrixData,
						     SdifUInt4  numRow, SdifUInt4  numCol);

#endif /* _SdifMatrix_ */

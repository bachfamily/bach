/* $Id: SdifNameValue.h,v 1.2 2000/10/27 20:03:02 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifNameValue.h
 *
 * Name values management. For 1 SdifFileT*, we have one SdifNameValueLT*
 * which contains a list of hash tables. Each hach table contains name-values.
 *
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifNameValue.h,v $
 * Revision 1.2  2000/10/27 20:03:02  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:19  tisseran
 * *** empty log message ***
 *
 * Revision 3.6  2000/05/15  16:22:35  schwarz
 * Avoid warning about KillerFT function pointer type (ANSI prototype given).
 * Argument to kill func is now void *.
 *
 * Revision 3.5  1999/10/15  12:26:54  schwarz
 * No time parameter for name value tables and stream ID tables, since
 * this decision is better left to the library.  (It uses the _SdifNoTime
 * constant, which happens to be _Sdif_MIN_DOUBLE_.)
 *
 * Revision 3.4  1999/10/13  16:05:54  schwarz
 * Changed data type codes (SdifDataTypeET) to SDIF format version 3, as
 * decided with Matt Wright June 1999, added integer data types.
 * Added writing of 1NVT with real frame header (but data is still not in
 * matrices).
 * The data type handling makes heavy use of code-generating macros,
 * called for all data types with the sdif_foralltypes macro, thus
 * adding new data types is easy.
 *
 * Revision 3.3  1999/09/28  13:09:07  schwarz
 * Included #include <preincluded.h> for cross-platform uniformisation,
 * which in turn includes host_architecture.h and SDIF's project_preinclude.h.
 *
 * Revision 3.2  1999/08/25  18:32:36  schwarz
 * Added cocoon-able comments with sentinel "DOC:" (on a single line).
 *
 * Revision 3.1  1999/03/14  10:57:13  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/01/23  15:55:57  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:42  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:32  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:58  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.5  1998/11/10  15:31:52  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 * Revision 1.4  1998/07/23  17:02:57  virolle
 * *** empty log message ***
 *
 * Revision 1.3  1998/04/24  12:40:37  schwarz
 * Made char * arguments constant for SdifNameValuesLPut and functions called by it.
 *
 */

#ifndef _SdifNameValue_
#define _SdifNameValue_


#include "SdifGlobals.h"
#include "SdifHash.h"
#include "SdifList.h"

#define _SdifNameValueHashSize 31


/*
 * NameValue
 */


typedef struct SdifNameValueS SdifNameValueT;
struct SdifNameValueS
{
  char *Name;
  char *Value;
} ;



SdifNameValueT* SdifCreateNameValue(const char *Name,  const char *Value);
void            SdifKillNameValue(SdifNameValueT *NameValue);




/*
 * NameValueTable
 */

typedef struct SdifNameValueTableS SdifNameValueTableT;
struct SdifNameValueTableS
{
    SdifHashTableT* NVHT;
    SdifUInt4       NumTable;
    SdifUInt4       StreamID;	/* id of stream the table belongs to */
} ;


SdifNameValueTableT* SdifCreateNameValueTable(  SdifUInt4 StreamID, 
                                                SdifUInt4 HashSize, 
						SdifUInt4 NumTable);
void            SdifKillNameValueTable          (void* NVTable);
SdifNameValueT* SdifNameValueTableGetNV         (SdifNameValueTableT* NVTable, const char *Name);
SdifNameValueT* SdifNameValueTablePutNV         (SdifNameValueTableT* NVTable, const char *Name,  const char *Value);
SdifFloat8      SdifNameValueTableGetTime       (SdifNameValueTableT* NVTable);
SdifUInt4       SdifNameValueTableGetNumTable   (SdifNameValueTableT* NVTable);
SdifUInt4       SdifNameValueTableGetStreamID  (SdifNameValueTableT* NVTable);



/*
 * NameValueTableList
 */

typedef struct SdifNameValuesLS SdifNameValuesLT;
struct SdifNameValuesLS
{
    SdifListT*              NVTList;
    SdifNameValueTableT*    CurrNVT;
    SdifUInt4               HashSize;
};


SdifNameValuesLT*   SdifCreateNameValuesL       (SdifUInt4  HashSize);
void                SdifKillNameValuesL         (SdifNameValuesLT *NameValuesL);

/*DOC: 
  Cette fonction permet d'ajouter une nouvelle NVT dans la liste
  de tables passée par argument:
  <code>SdifNameValuesLNewHT(SdifF->NamefValues);</code><br>
  Attention, à l'ouverture de SdifF, il n'y a aucune table dans
  SdifF->NamefValues. Il faudra donc au moins en ajouter une pour
  pouvoir y mettre des NameValue.  */
SdifNameValuesLT*   SdifNameValuesLNewTable     (SdifNameValuesLT *NameValuesL, SdifUInt4 StreamID);

/*DOC: 
  Cette fonction permet de définir la nième NVT de la liste des
  tables comme NVT courante.  */
SdifNameValueTableT*SdifNameValuesLSetCurrNVT   (SdifNameValuesLT *NameValuesL, SdifUInt4 NumCurrNVT);

/*DOC: 
  Cette fonction permet de récupérer une Name-Value de la liste
  des NVTs en passant le Name en argument.  Dans le cas ou Name est
  référencé dans plusieurs NVT, alors c'est la première NVT le
  contenant qui sera prise en compte.  Le pointeur retourné est de
  type SdifNameValueT qui contient deux champs: Name et Value.  */
SdifNameValueT*     SdifNameValuesLGet          (SdifNameValuesLT *NameValuesL, char *Name);

/*DOC: 
  Cette fonction réalise aussi une requête en fonction de Name
  mais uniquement dans la NVT courante.  */
SdifNameValueT*     SdifNameValuesLGetCurrNVT   (SdifNameValuesLT *NameValuesL, const char *Name);

/*DOC: 
  Cette fonction permet d'ajouter une NameValue à table courante
  qui est la dernière table créée ou celle définie en tant que table
  courante. Name et Value doivent être des chaines caractères ASCII
  sans espacements.  */
SdifNameValueT*     SdifNameValuesLPutCurrNVT   (SdifNameValuesLT *NameValuesL, const char *Name,  const char *Value);
SdifUInt2           SdifNameValuesLIsNotEmpty   (SdifNameValuesLT *NameValuesL);


/*
 * Obsolete
 */
SdifNameValuesLT*   SdifNameValuesLNewHT    (SdifNameValuesLT *NameValuesL);
SdifHashTableT*     SdifNameValuesLSetCurrHT(SdifNameValuesLT *NameValuesL, SdifUInt4 NumCurrHT);
SdifNameValueT*     SdifNameValuesLGetCurrHT(SdifNameValuesLT *NameValuesL, char *Name);
SdifNameValueT*     SdifNameValuesLPutCurrHT(SdifNameValuesLT *NameValuesL, const char *Name,  const char *Value);


#endif /* _SdifNameValue_ */

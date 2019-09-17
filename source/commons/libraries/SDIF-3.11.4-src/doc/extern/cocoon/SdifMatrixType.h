/* $Id: SdifMatrixType.h,v 1.2 2000/10/27 20:03:01 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *

LIBRARY
 * SdifMatrixType.h
 *
 * Matrix Types management (interpreted sdif frame types)
 *
 * author: Dominique Virolle 1997
 *

EXAMPLE 
	On souhaite complèter le type de matrice des FOFs par une
	nouvelle colonne appelée NewCol et ensuite créer un type
	exclusif. 

<pre>{ SdifMatrixTypeT *MtrxTFOF, *NewMtrxT;
  
  // Mise à jour du lien sur le type prédéfini '1FOF' si nécessaire
  MtrxTFOF = SdifTestMatrixType(SdifF, '1FOF');
  // Maintenant le type de matrice '1FOF' est directement accessible par SdifF et
  // non uniquement par gSdifPredefinedTypes. 

  // ajout d'une nouvelle colonne (en complétion) 
  if (MtrxTFOF)
    SdifMatrixTypeInsertTailColumnDef(MtrxTFOF, "NewCol");
  else ; // un message d'erreur a été dans ce cas envoyer par SdifTestMatrixType

   // Création d'un type exclusif (le premier caractère de la signature doit donc
   // être 'E') 
   NewMtrxT = SdifCreateMatrixType('ENMT', NULL);
   // il n'y a pas de type prédéfini pour 'ENMT' donc le deuxième argument est NULL 
   SdifPutMatrixType (SdifF->MatrxTypesTable, NewMtrxT); // ajout à la base 
   // ajout des colonnes 
   SdifMatrixTypeInsertTailColumnDef(NewMtrxT, "Col1");
   SdifMatrixTypeInsertTailColumnDef(NewMtrxT, "Col2");
   SdifMatrixTypeInsertTailColumnDef(NewMtrxT, "Col3");
   SdifMatrixTypeInsertTailColumnDef(NewMtrxT, "Col4");
}</pre>


LOG
 * $Log: SdifMatrixType.h,v $
 * Revision 1.2  2000/10/27 20:03:01  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:17  tisseran
 * *** empty log message ***
 *
 * Revision 3.5  2000/07/18  15:08:37  tisseran
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
 * Revision 3.4  2000/05/15  16:22:33  schwarz
 * Avoid warning about KillerFT function pointer type (ANSI prototype given).
 * Argument to kill func is now void *.
 *
 * Revision 3.3  1999/09/28  13:09:05  schwarz
 * Included #include <preincluded.h> for cross-platform uniformisation,
 * which in turn includes host_architecture.h and SDIF's project_preinclude.h.
 *
 * Revision 3.2  1999/08/25  18:32:36  schwarz
 * Added cocoon-able comments with sentinel "DOC:" (on a single line).
 *
 * Revision 3.1  1999/03/14  10:57:09  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/01/23  15:55:55  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:41  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:31  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:41:57  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.4  1998/11/10  15:31:52  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */


#ifndef _SdifMatrixType_
#define _SdifMatrixType_

#include "SdifGlobals.h"
#include "SdifList.h"
#include "SdifHash.h"




typedef struct SdifColumnDefS SdifColumnDefT;

struct SdifColumnDefS
{
  char *Name;
  SdifUInt4 Num;
} ;





typedef struct SdifMatrixTypeS SdifMatrixTypeT;

struct SdifMatrixTypeS
{
  SdifSignature     Signature;

  SdifMatrixTypeT*  MatrixTypePre;

  SdifListT*        ColumnUserList; /* List of columns added by user: 
				       SdifMatrixTypeInsertTailColumn(MatrixTypeT *)
				    */

  SdifUInt4       NbColumnDef; /* Number of columns created by user:
				  SdifMatrixTypeInsertTailColumn(MatrixTypeT *)
			       */
  SdifModifModeET ModifMode;
};




SdifColumnDefT*  SdifCreateColumnDef (char *Name,  unsigned int Num);
void             SdifKillColumnDef   (void *ColumnDef);

/*DOC: 
  premet de créer un objet 'type de matrice'. Le premier argument
  est la signature de ce type. Le second est l'objet 'type de matrice'
  prédéfini dans SDIF.<p>
  
  <strong>Important: Tous les types de matrices ou de frames utilisés
  dans une instance de SdifFileT doivent être ajoutés aux tables de
  cette instance, de façon a créer le lien avec les types
  prédéfinis.</strong> L'hors de la lecture des entêtes avec les
  fonctions SdifFReadMatrixHeader et SdifFReadFrameHeader, cette mise
  à jour se fait automatiquement à l'aide des fonctions
  SdifTestMatrixType et SdifTestFrameType. */
SdifMatrixTypeT* SdifCreateMatrixType              (SdifSignature Signature,
                    							   SdifMatrixTypeT *PredefinedMatrixType);
void             SdifKillMatrixType                (SdifMatrixTypeT *MatrixType);

/*DOC: 
  permet d'ajouter une colonne à un type (toujours la dernière
  colonne).  */
SdifMatrixTypeT* SdifMatrixTypeInsertTailColumnDef (SdifMatrixTypeT *MatrixType, char *NameCD);

/*DOC: 
  renvoie la position de la colonne de nom NameCD.  (0 si elle
  n'existe pas) */
SdifUInt4        SdifMatrixTypeGetNumColumnDef     (SdifMatrixTypeT *MatrixType, char *NameCD);

/*DOC: 
  renvoie la définition de la colonne (numéro, nom) en fonction
  du nom.(NULL si introuvable) */
SdifColumnDefT*  SdifMatrixTypeGetColumnDef        (SdifMatrixTypeT *MatrixType, char *NameCD);

/*DOC: 
  renvoie la définition de la colonne (numéro, nom) en fonction
  du numero.(NULL si introuvable) */
SdifColumnDefT*  SdifMatrixTypeGetNthColumnDef     (SdifMatrixTypeT *MatrixType, SdifUInt4 NumCD);


/*DOC: 
  renvoie le type de matrice en fonction de la Signature. Renvoie
  NULL si le type est introuvable. Attention, si Signature est la
  signature d'un type prédéfini,
  SdifGetMatrixType(SdifF->MatrixTypeTable,Signature) renvoie NULL si
  le lien avec entre SdifF et gSdifPredefinedType n'a pas été mis à
  jour.  */
SdifMatrixTypeT* SdifGetMatrixType		   (SdifHashTableT *MatrixTypesTable, 
						    SdifSignature Signature);

/*DOC: 
  permet d'ajouter un type de matrice dans une table.  */
void             SdifPutMatrixType(SdifHashTableT *MatrixTypesTable, SdifMatrixTypeT* MatrixType);
SdifUInt2        SdifExistUserMatrixType(SdifHashTableT *MatrixTypesTable);

#endif /* _SdifMatrixType_  */

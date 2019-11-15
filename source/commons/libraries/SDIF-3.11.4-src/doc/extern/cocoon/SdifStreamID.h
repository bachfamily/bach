/* $Id: SdifStreamID.h,v 1.2 2000/10/27 20:03:04 roebel Exp $
 *
 *               Copyright (c) 1998 by IRCAM - Centre Pompidou
 *                          All rights reserved.
 *
 *  For any information regarding this and other IRCAM software, please
 *  send email to:
 *                            manager@ircam.fr
 *
 *
 * SdifStreamID.h
 *
 * StreamID structures management
 *
 *
 * author: Dominique Virolle 1997
 *
 * $Log: SdifStreamID.h,v $
 * Revision 1.2  2000/10/27 20:03:04  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.1  2000/08/21  17:48:28  tisseran
 * *** empty log message ***
 *
 * Revision 3.5  2000/05/22  15:23:18  schwarz
 * Added functions to retrieve and inspect the stream ID table of a file.
 *
 * Revision 3.4  1999/10/15  12:26:56  schwarz
 * No time parameter for name value tables and stream ID tables, since
 * this decision is better left to the library.  (It uses the _SdifNoTime
 * constant, which happens to be _Sdif_MIN_DOUBLE_.)
 *
 * Revision 3.3  1999/09/28  13:09:14  schwarz
 * Included #include <preincluded.h> for cross-platform uniformisation,
 * which in turn includes host_architecture.h and SDIF's project_preinclude.h.
 *
 * Revision 3.2  1999/08/25  18:32:37  schwarz
 * Added cocoon-able comments with sentinel "DOC:" (on a single line).
 *
 * Revision 3.1  1999/03/14  10:57:22  virolle
 * SdifStdErr add
 *
 * Revision 2.3  1999/01/23  15:56:01  virolle
 * add querysdif.dsp, delete '\r' chars from previous commit
 *
 * Revision 2.2  1999/01/23  13:57:47  virolle
 * General Lists, and special chunk preparation to become frames
 *
 * Revision 2.1  1998/12/21  18:27:40  schwarz
 * Inserted copyright message.
 *
 * Revision 2.0  1998/11/29  11:42:07  virolle
 * - New management of interpretation errors.
 * - Alignement of frames with CNMAT (execpt specials Chunk 1NVT, 1TYP, 1IDS).
 * _ Sdif Header File has a Sdif format version.
 * - Matrices order in frames is not important now. (only one occurence of
 *   a Matrix Type in a Frame Type declaration )
 * - Hard coded predefined types more dynamic management.
 * - Standart streams (stdin, stdout, stderr) set as binary for Windows32 to
 *   have exactly the same result on each plateforme.
 *
 * Revision 1.4  1998/11/10  15:31:55  schwarz
 * Removed all 'extern' keywords for prototypes, since this is redundant
 * (function prototypes are automatically linked extern), and it
 * prohibits cocoon from generating an entry in the HTML documentation
 * for this function.
 *
 */


#ifndef _SdifStreamID_
#define _SdifStreamID_

#include "SdifGlobals.h"
#include "SdifHash.h"



/*
// DATA GROUP:		Stream ID Table and Entries for 1IDS ASCII chunk
*/

/*DOC:
  Stream ID Table Entry */
typedef struct SdifStreamIDS SdifStreamIDT;
struct SdifStreamIDS
{
  SdifUInt4     NumID;
  char *Source;
  char *TreeWay; /* for the moment or to be general*/
} ;


/*DOC:
  Stream ID Table, holds SdifStreamIDT stream ID table entries */
typedef struct SdifStreamIDTableS SdifStreamIDTableT;
struct SdifStreamIDTableS
{
    SdifHashTableT* SIDHT;
    SdifUInt4       StreamID;
    SdifFloat8      Time;	/* always _SdifNoTime */
} ;


/*
// FUNCTION GROUP:	Stream ID Tables for 1IDS ASCII chunk
*/

/*DOC: 
  Permet de créer un pointeur sur un objet de type StreamIDT.  

<p>Exemple dans le cas d'un TreeWay pour chant (non fichier):

<pre>
void ConsOneStreamID(SdifFileT *SdifF,
		     int        NumID,
		     char      *PatchType,
		     int        NumPatch,
		     char      *ObjType,
		     int        NumObj,
		     int        NbSubObj,
		     float      StartTime,
		     float      EndTime)
{
  SdifStreamIDT* StreamID;
  char TreeWay[512];

  sprintf(TreeWay, "%s/%d/%s/%d/%d/%s/%f", PatchType, NumPatch, ObjType,
		    NumObj, NbSubObj, StartTime, EndTime);
  StreamID = SdifCreateStreamID(NumID, "Chant", TreeWay);

  SdifHashTablePut(SdifF->StreamIDsTable, &(StreamID->NumID), 1, StreamID);
}
</pre>

Pour recuperer un StreamID il faut utiliser la fonction SdifHashTableGet
<pre>
  SdifStreamIDT *StreamID = (SdifStreamIDT*) SdifHashTableGet (SdifF->StreamIDsTable, &NumID, 0);
</pre>
Le troisième argument n'est pas utilisé, car la table est indexée directement
par des entiers (création de la table avec l'option eInt4). 
*/
SdifStreamIDT* SdifCreateStreamID(SdifUInt4 NumID, char *Source, char *TreeWay);
void           SdifKillStreamID(SdifStreamIDT *StreamID);


/*DOC:
  Create a stream ID table.  <strong>The stream ID table of the SDIF
  file structure is created automatically by SdifFOpen().</strong> 
  It can be obtained by SdifFStreamIDTable(). */
SdifStreamIDTableT* SdifCreateStreamIDTable     (SdifUInt4 HashSize);

/*DOC:
  Deallocate a stream ID table.  <strong>The stream ID table of the SDIF
  file structure is killed automatically by SdifFClose.</strong>  
  It can be obtained by SdifFStreamIDTable. */
void                SdifKillStreamIDTable       (SdifStreamIDTableT *SIDTable);

/*DOC:
  Add an entry to a stream ID table.  The table will be written by
  SdifFWriteAllASCIIChunks.
  [in]  SIDTable pointer to stream ID table, e.g. obtained by SdifFStreamIDTable
  [in]	NumID	stream ID of the frames the stream ID table describes
  [in]	Source	Source identifier for the table (ex. "Chant")
  [in]	TreeWay	Routing and parameters, separated by slashes
  [return]
		The stream ID table entry just created and added */
SdifStreamIDT*      SdifStreamIDTablePutSID     (SdifStreamIDTableT *SIDTable,
						 SdifUInt4	     NumID, 
						 char 		    *Source, 
						 char 		    *TreeWay);

/*DOC:
  Retrieve an entry to a stream ID table.  The table has to have been
  read by SdifFReadAllASCIIChunks.

  [in]  SIDTable pointer to stream ID table, e.g. obtained by 
		 SdifFStreamIDTable
  [in]	NumID	 stream ID of the frames the stream ID table describes
  [return]
		 pointer to stream ID table entry, or NULL if no entry for 
		 stream ID NumID exists. */
SdifStreamIDT*      SdifStreamIDTableGetSID     (SdifStreamIDTableT *SIDTable, 
						 SdifUInt4	     NumID);

/*DOC:
  Return number of entries in stream ID table SIDTable */
SdifUInt4           SdifStreamIDTableGetNbData  (SdifStreamIDTableT *SIDTable);


/*DOC:
  Return stream ID field in stream ID table entry SID */
SdifUInt4	    SdifStreamIDEntryGetSID	(SdifStreamIDT *SID);

/*DOC:
  Return source field in stream ID table entry SID */
char		   *SdifStreamIDEntryGetSource	(SdifStreamIDT *SID);

/*DOC:
  Return "treeway" field in stream ID table entry SID */
char		   *SdifStreamIDEntryGetTreeWay	(SdifStreamIDT *SID);


#endif /* _SdifStreamID_ */

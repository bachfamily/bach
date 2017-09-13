/* $Id: testselect.c,v 1.3 2002/08/05 14:22:05 roebel Exp $
 *
 * testselect		30. August 1999		Diemo Schwarz
 *
 * Test functions from SdifSelect.c
 *
 * $Log: testselect.c,v $
 * Revision 1.3  2002/08/05 14:22:05  roebel
 * Fixed compiler warning.
 *
 * Revision 1.2  2000/10/27 20:04:03  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.2  2000/08/21  17:00:54  tisseran
 * *** empty log message ***
 *
 * Revision 1.1.2.1  2000/08/21  13:55:48  tisseran
 * *** empty log message ***
 *
 * Revision 1.3  1999/10/07  15:13:01  schwarz
 * Added SdifSelectGetFirst<type>, SdifSelectGetNext(Int|Real).
 *
 * Revision 1.2  1999/09/20  13:23:09  schwarz
 * First finished version, API to be improved.
 *
 * Revision 1.1  1999/08/31  10:03:38  schwarz
 * Added test code for module SdifSelect which parses an access specification to a
 * chosen part of SDIF data.  Can be added to a file name.
 *
 */

#include <stdio.h>
#include <sdif.h>

#if HAVE_UNISTD_H
#include <unistd.h>
#endif

int 
main (int argc, char *argv [])
{
    SdifSelectionT		sel;
    SdifSelectElementIntT	intrange;
    SdifSelectElementRealT	realrange;
    SdifSignature		sig;
    char			*arg = argc > 1  ?  argv [1]  :  NULL;

#if HAVE_UNISTD_H
    sleep(1); /* Wait one second */
#endif

    if (arg == NULL)
      {
	fprintf(stderr,"Need a file name as argument !!!\n");
	return 1;
      }
    
    printf ("%s %s\n", argv [0], arg);
    SdifGenInit ("");
    

    SdifGetFilenameAndSelection (arg, &sel);
    
    printf ("selection: file %s  basename %s", sel.filename, sel.basename);
    
    SdifListInitLoop (sel.stream);
    while (SdifSelectGetNextIntRange (sel.stream, &intrange, 1))
	printf ("\n  stream\t%d - %d ", intrange.value, intrange.range);

    SdifListInitLoop (sel.frame);
    while ((sig = SdifSelectGetNextSignature (sel.frame)))
	printf ("\n  frame\t'%s' ", SdifSignatureToString (sig));

    SdifListInitLoop (sel.matrix);
    while ((sig = SdifSelectGetNextSignature (sel.matrix)))
	printf ("\n  matrix\t'%s' ", SdifSignatureToString (sig));

    SdifListInitLoop (sel.column);
    while (SdifSelectGetNextIntRange (sel.column, &intrange, 1))
	printf ("\n  column\t%d - %d ", intrange.value, intrange.range);

    SdifListInitLoop (sel.row);
    while (SdifSelectGetNextIntRange (sel.row, &intrange, 1))
	printf ("\n  row\t%d - %d ", intrange.value, intrange.range);

    SdifListInitLoop (sel.time);
    while (SdifSelectGetNextRealRange (sel.time, &realrange, 1))
	printf ("\n  time\t%f - %f ", realrange.value, realrange.range);

    printf ("\n\n");

    SdifPrintSelection (stdout, &sel, 0);
	
    SdifGenKill ();

    return 0; 
}

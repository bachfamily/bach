/* $Id: testcheck.c,v 1.3 2001/05/04 11:37:20 lambert Exp $
 *
 * testcheck		2. May 2000		Diemo Schwarz
 *
 * Test functions from SdifCheck.
 *
 * $Log: testcheck.c,v $
 * Revision 1.3  2001/05/04 11:37:20  lambert
 * Added the <stdlib.h> include for the exit function.
 *
 * Revision 1.2  2000/10/27 20:04:03  roebel
 * autoconf merged back to main trunk
 *
 * Revision 1.1.2.2  2000/08/21  17:00:53  tisseran
 * *** empty log message ***
 *
 * Revision 1.1.2.1  2000/08/21  13:55:47  tisseran
 * *** empty log message ***
 *
 * Revision 1.1  2000/05/04  14:57:29  schwarz
 * test check for SdifCheckFrames funcs.
 *
 */

#include <stdio.h>
#include <sdif.h>
#include <stdlib.h>

int main (int argc, char *argv [])
{
    SdifSignature	result, sigi [100];
    SdifSignatureTabT   *sigs;
    char		*filename;
    int			i, resulti;

    if (argc < 3)
    {
	fprintf (stderr, "usage: testcheck filename[::selection] signature...\n");
	exit (0);
    }

    SdifGenInit ("");
    sigs = SdifCreateSignatureTab (1);

    filename = argv [1];
    for (i = 2; i < argc; i++)
    {
	SdifAddToSignatureTab (sigs, SdifStringToSignature (argv [i]));
	sigi [i - 2] = SdifStringToSignature (argv [i]);
    }
    sigi [i - 2] = eEmptySignature;

    result  = SdifCheckFileFramesTab   (filename, sigs);
    resulti = SdifCheckFileFramesIndex (filename, sigi);

    printf ("Found %s frame, index %d.\n", 
	    result  ?  SdifSignatureToString (result)  :  "no", resulti);

    SdifKillSignatureTab (sigs);
    SdifGenKill ();

    return 0;
}


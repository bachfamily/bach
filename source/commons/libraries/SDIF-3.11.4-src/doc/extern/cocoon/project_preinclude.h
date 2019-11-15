/* $Id: project_preinclude.h,v 1.3 2003/11/07 21:47:17 roebel Exp $

   SDIF/sdif/project_preinclude.h	28. Sep 1999	Diemo Schwarz

   This file "project_preinclude.h" is #included by sdif_portability.h into
   every source file of your project.  You should add here any
   project-specific information, macro definitions and conditionals.
	
   Generic stuff (valid for all projects and all architectures) should
   be added to sdif_portability.h.  Platform-specific stuff should be added
   to host_architecture.h.
  
   You will usually have one project_preinclude.h file per project,
   and you should therefore make sure that the access paths/include
   search paths are such that the project_preinclude.h file is unique.
  
   In order to write platform-independent code, you should insert any
   #defines in this file rather than adding them to the command line
   in the Makefile. This is because CodeWarrior for Mac OS does not
   use Makefiles and such declarations would therefore get lost.
  
   $Log: project_preinclude.h,v $
   Revision 1.3  2003/11/07 21:47:17  roebel
   removed XpGuiCalls.h and replaced preinclude.h  by local files

   Revision 1.2  2000/10/27 20:03:05  roebel
   autoconf merged back to main trunk

 * Revision 1.1.2.1  2000/08/21  17:48:36  tisseran
 * *** empty log message ***
 *
 * Revision 3.2  2000/05/12  14:41:50  schwarz
 * On behalf of Adrien, synchronisation with Mac sources, with some slight
 * changes because of cross-platform issues:
 * - Mac only stuff: XpSetFileAttribute XpFileSize
 * - Cross platform wrapper: XpGetenv XpExit
 * - Dangerous: strings.h (and thus bzero, bcopy) is not ANSI and thus doesn't
 *   exist on Mac.  Use string.h and memset, memcpy.
 *
 * Revision 3.1  1999/09/28  13:09:18  schwarz
 * Included #include <preincluded.h> for cross-platform uniformisation,
 * which in turn includes host_architecture.h and SDIF's project_preinclude.h.
 *
 * Revision 1.2  1999/02/19  15:36:32  schwarz
 * Fixed include of fp.h, preprocessor # in first column.
 *
 * Alberto Ricci, 19990212 <- I'm Y2K!
 */


/******** PROJECT PREINCLUDE FOR SDIF ********/


#ifndef __H_PROJECT_PREINCLUDE__
#define __H_PROJECT_PREINCLUDE__

/*
Sdif preinclude
*/

/*
#define _SdifMemoryReport
*/

#if HOST_OS_MAC

#define _SDIF_VERSION	"Macintosh Sdif 3.0"
#define _VERSION		"Macintosh Sdif 3.0"

#endif /* HOST_OS_MAC */


#endif /* __H_PROJECT_PREINCLUDE__ */

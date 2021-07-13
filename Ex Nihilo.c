/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code of Ex Nihilo!
 *
 * This is the main file for the project, and includes pretty much everything in the `include/` directory.  You are recommended to look at `ORGANIZATION.md` for a broad-level overview of this file. */

/* First, we need to include some things.  This includes some of the C Standard Library, SDL, and the files in the `include/` directory. */

#include "SDL.h"

#include "include/Global.h"
#include "include/Checks.h"
#include "include/Crash.h"

/* Now, we get to the main function. */

int main ( [[maybe_unused]] int argc , char * [[maybe_unused]] argv[] ) {

	/* First, we need to set the appropriate log priority based on whether the program is in Debug Mode or not.  The description on the SDL wiki for the `SDL_LogSetAllPriority ( )` function is wrong — what this does is set it so that all logs below this level aren't shown. */

#ifdef EX_NIHILO_DEBUG_MODE
	SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_VERBOSE ) ;
#else
	SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_INFO ) ;
#endif

	/* Now, we need to run the checks from the file `Checks.h`.  If we get an abnormal return value, the program is crashed depending on what the value was. */

	RunChecks ( ) ;
	
	return 0x00 ; }

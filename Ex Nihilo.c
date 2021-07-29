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
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "include/Crash.h"
#include "include/Global.h"
#include "include/Checks.h"
#include "include/Setup.h"
#include "include/Cleanup.h"

/* Now, we get to the main function. */

int main ( [[maybe_unused]] int argc , char * [[maybe_unused]] argv[] ) {

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Ex Nihilo has been started!" ) ;

	/* First, we need to set the appropriate log priority based on whether the program is in Debug Mode or not.  The description on the SDL wiki for the `SDL_LogSetAllPriority ( )` function is wrong — what this does is set it so that all logs below this level aren't shown. */

#ifdef EX_NIHILO_DEBUG_MODE
	SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_VERBOSE ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Game has been compiled in Debug Mode; all logs will be shown." ) ;
#else
	SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_INFO ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Game is in normal mode; verbose logs will be hidden." ) ;
#endif

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "BEGIN FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Program was compiled at %s on %s with standard C version %ld." , __TIME__ , __DATE__ , __STDC_VERSION__ ) ;

	/* Now, we need to set up the crash handler. */

	CrashHandlerSetup ( ) ;

	/* Now, we need to register our cleanup function in `atexit ( )`. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registering cleanup function in `atexit ( )`…" ) ;
	if ( atexit ( Cleanup ) ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "`atexit ( )` registration failed!  Crashing program…" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6601 : 0x4601 ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registration succeeded!" ) ;

	/* Now, we need to run the checks from the file `Checks.h`.  If we get an abnormal return value, the program is crashed depending on what the value was. */

	RunChecks ( ) ;

	/* Now, we need to setup SDL and its extensions. */

	Setup ( ) ;

	/* Now, we get to some random crap I wrote as a test.  This doesn't do anything of value. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Performing random crap…" ) ;
	SDL_Texture * ErrorTexture = SDL_CreateTextureFromSurface ( MainRenderer , ErrorSurface ) ;
	SDL_RenderCopy ( MainRenderer , ErrorTexture , NULL , NULL ) ;
	SDL_Color White = { 0xFF , 0xFF , 0xFF , 0xFF } ;
	SDL_Surface * HeeHoo = TTF_RenderUTF8_Solid ( BarlowCondensed , "heehoo peanut" , White ) ;
	SDL_Texture * HeeHooTexture = SDL_CreateTextureFromSurface ( MainRenderer , HeeHoo ) ;
	SDL_Rect HeeHooRectangle = { 0 , 0 , 320 * SizeMultiplier , 240 * SizeMultiplier } ;
	SDL_RenderCopy ( MainRenderer , HeeHooTexture , NULL , &HeeHooRectangle ) ;
	SDL_RenderPresent ( MainRenderer ) ;
	SDL_Delay ( 5000 ) ;
	SDL_DestroyTexture ( ErrorTexture ) ;
	SDL_DestroyTexture ( HeeHooTexture ) ;
	SDL_FreeSurface ( HeeHoo ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Random crap done!" ) ;

	/* Finally, we need to clean up. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "Cleaning up…" ) ;
	Cleanup ( ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "Cleaned up!" ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "END FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ;

	return 0x00 ; }

/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code of Ex Nihilo!
 *
 * This is the main file for the project, and includes pretty much everything in the `include/` directory. */

/* First, we need to include some things.  This includes some things from the C standard library, SDL, its extensions, and the files in the `include/` directory. */

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "include/Crash.h"
#include "include/Global.h"
#include "include/Checks.h"
#include "include/Setup.h"
#include "include/Cleanup.h"
#include "include/Loading.h"
#include "include/Input.h"
#include "include/Game.h"
#include "include/Menus.h"
#include "include/Docs.h"
#ifdef EX_NIHILO_DEBUG_MODE
#include "include/Debug.h"
#endif/*def EX_NIHILO_DEBUG_MODE*/

int main ( [[maybe_unused]] int argc , char * [[maybe_unused]] argv[] ) { /* `main ( )`'s arguments will probably get used eventually. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Ex Nihilo has been started!" ) ;

	/* First, we need to set the appropriate log priority based on whether the program is in Debug Mode or not.  The description on the SDL wiki for the `SDL_LogSetAllPriority ( )` function is wrong — what this does is set it so that all logs below this level aren't shown. */

#ifdef EX_NIHILO_DEBUG_MODE
	SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_VERBOSE ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Game has been compiled in Debug Mode; all logs will be shown." ) ;
#else
	SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_INFO ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Game is in normal mode; verbose logs will be hidden." ) ;
#endif

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Program was compiled at %s on %s with standard C version %ld." , __TIME__ , __DATE__ , __STDC_VERSION__ ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "BEGIN FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ;

	/* Now, we need to set up the crash handler.  This is from the file `Crash.h`. */

	CrashHandlerSetup ( ) ;

	/* Now, we need to register our cleanup function in `atexit ( )`.  The cleanup function is from `Cleanup.h`. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registering cleanup function in `atexit ( )`…" ) ;
	if ( atexit ( Cleanup ) ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "`atexit ( )` registration failed!  Crashing program…" ) ;
		Crash ( 0x6 , "The cleanup function could not be registered in `atexit ( )`." ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registration succeeded!" ) ;

	/* Now, we need to run the checks from the file `Checks.h`. */

	RunChecks ( ) ;

	/* Now, we need to setup SDL and its extensions.  This is from the file `Setup.h`. */

	Setup ( ) ;

	/* Now, we load some things.  This is from the file `Loading.h`. */

	LoadStuff ( ) ;

	/* And here, we get to the loop!  Every 36th of a second, one cycle of this loop is completed. */

	int FrameStartTick , TicksPassed ;
	int TimeToCrash ;

	State = MainMenu ;

	MouseX = 1 ;

	while ( 1 ) {

		/* First, we get the tick on which this cycle started for use at the end of the cycle.  We then clear the screen. */

		FrameStartTick = SDL_GetTicks ( ) ;

		SDL_SetRenderDrawColor ( MainRenderer , 0 , 0 , 0 , 0xFF ) ;
		SDL_RenderClear ( MainRenderer ) ;

		/* Now, we get the input for this tick and write it down.  This is from the file `include/Input.h`. */

		GetInput ( ) ;

		/* We now check the state of the game to determine what to do next. */

		switch ( State ) {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-folding-constant"
			case InGame:

				/* If we're in regular gameplay, then we need to update the game according to the input given, then tick the game, then render all the background elements of the world, then render all the moving bits onto the world, then render the UI.  This is from `Game.h`. */

				UpdateGame ( ) ;
				TickGame ( ) ;
				RenderWorld ( ) ;
				RenderSprites ( ) ;
				RenderUI ( ) ;
				break ;

			case MainMenu:
				
				/* If we're at the main menu, then all we need to do is deal with whatever input we got based on where we are in the menu, then render the menu.  This is from `Menus.h`. */

				UpdateMainMenu ( ) ;
				RenderMainMenu ( ) ;
				break ;

			case PauseMenu:

				/* If we're in the pause menu, then we need to update whatever settings the input tells us to update, then render the menu.  This is also from `Menus.h`. */

				UpdatePauseMenu ( ) ;
				RenderPauseMenu ( ) ;
				break ;

			case Documentation:

				/* If we're looking at the documentation, then we need to check the input to see what we need to do, which will usually be pretty simple, and then render the documentation.  This is from `Docs.h`. */

				LoadDocumentation ( ) ;
				RenderDocumentation ( ) ;
				break ;

#ifdef EX_NIHILO_DEBUG_MODE
			case DebugConsole:

				/* If we're in the debug console, we need to render whatever text has been typed so far, then deal with the command given.  This is from `Debug.h`. */

				UpdateConsole ( ) ;
				RenderConsole ( ) ;
				break ;
#endif/*def EX_NIHILO_DEBUG_MODE */
#pragma clang diagnostic pop

			default:

				/* If the state that the game is in is undefined, then the game is crashed. */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-value"
				argc ; //I genuinely have no idea why this is needed, but it's obviously awful. //
#pragma clang diagnostic pop
				SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "The game has reached an undefined state!  Crashing now…") ;
				SDL_Texture * ErrorTexture = SDL_CreateTextureFromSurface ( MainRenderer , ErrorSurface ) ;
				char CrashText[100] = "" ;
				SDL_Surface * CrashTextSurface ;
				SDL_Texture * CrashTextTexture ;
				int StringWidth = 0 , StringHeight = 0 ;
				TTF_SizeUTF8 ( BarlowCondensed , "The game has reached an unknown state and will crash in ## seconds." , &StringWidth , &StringHeight ) ;
				SDL_Rect CrashTextRectangle = { ( ( 640 - StringWidth ) / 2 ) * SizeMultiplier , ( ( 480 - StringHeight ) / 2 ) * SizeMultiplier , StringWidth * SizeMultiplier , StringHeight * SizeMultiplier } ;  // This is one of the worst things I've ever written. //
				SDL_Color White = { 0xFF , 0xFF , 0xFF , 0xFF } ;

				for ( int register i = 5 ; i > 0 ; i-- ) {
					SDL_RenderClear ( MainRenderer ) ;
					SDL_RenderCopy ( MainRenderer , ErrorTexture , NULL , NULL ) ;
					sprintf ( CrashText , "The game has reached an unknown state and will crash in %d seconds." , i ) ;
					CrashTextSurface = TTF_RenderUTF8_Blended ( BarlowCondensed , CrashText , White ) ;
					CrashTextTexture = SDL_CreateTextureFromSurface ( MainRenderer , CrashTextSurface ) ;
					SDL_RenderCopy ( MainRenderer , CrashTextTexture , NULL , &CrashTextRectangle ) ;
					SDL_RenderPresent ( MainRenderer ) ;
					SDL_Delay ( 1000 ) ; }
				Crash ( 0x9 ) ;
				break ; }

		/* Now that that's done, we just need to present to the renderer. */

		SDL_RenderPresent ( MainRenderer ) ;

		if ( Quit ) {
			break ; } 

		/* Finally, we check that we did everything in time.  If we did, then we wait until the end of the tick.  Otherwise, we mark down an error, and, given enough errors in a row, we then give the user 5 minutes to fix whatever's causing trouble, before crashing to prevent abuse. */

		TicksPassed = SDL_GetTicks ( ) - FrameStartTick ;
		if ( TicksPassed < 27 ) {
			if ( Errors > 0 ) {
				Errors--; }
			SDL_Delay ( 27 - TicksPassed ) ; }
		else {
			if ( Errors > 0xFF && !LagCrash ) {
				SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "Serious lag is occuring.  Beginning countdown to abuse-prevention crash." ) ;
				//LagPopup ( ) ; //I haven't actually created this yet.
				LagCrash = 1 ;
				TimeToCrash = 0 ; }
			else if ( LagCrash ) {
				if ( TimeToCrash == 36 * 300 ) {
					SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Lag has occured for too long and the game will now crash." ) ;
					Crash ( 0xA ) ; }
				else {
					TimeToCrash++ ; } }
			else {
				Errors++ ; 
				if ( !( Errors % 0xF ) ) {
					SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_WARN , "%d lag frames have occurred!" , Errors ) ; } } } } // It's the % command's time to shine. //
			

	/* Finally, we need to clean up.  This is the same cleanup function from `Cleanup.h`. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "Cleaning up…" ) ;
	Cleanup ( ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "Cleaned up!" ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "END FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_INFO , "Goodbye!" ) ;

	return 0x00 ; }

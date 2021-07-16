/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file, `Setup.h`, contains a single function, `Setup ( )`, that's run at the beginning of the program after the checks in `Checks.h` have been run.  This is used to setup Simple DirectMedia Layer and the official extensions to it that are being used in this program.  Most of the stuff from this is then written into the variables in `Global.h` for use in other parts of the program. */

/* First, some include guards. */

#pragma once
#ifndef SETUP_H
#define SETUP_H

/* Now, we include our libraries.  We obviously need all of the libraries for SDL and its extensions. */

#include "SDL.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

/* We also need other files from `include/`; currently, this is just `Global.h` and `Crash.h`. */

#include "Global.h"
#include "Crash.h"

/* We also need some things from the standard library; currently, this is just `<stdlib.h>` for `atexit ( )`. */

#include <stdlib.h>

/* Alright, here's the function. */

void Setup ( void ) {

	/* First, we need to initialize all of the libraries.  We're initializing the video and audio subsystems of SDL (and, implicitly, their prerequisites) and we're initializing support for PNG, FLAC, and TTF files.  Can't have lossy compression! */

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "Initializing SDL with video and audio subsystems…" ) ;
	if ( SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "SDL failed to initialize!  Error given:  \"%s\".  Crashing program…" , SDL_GetError ( ) ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6202 : 0x4202 , SDL_GetError ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "SDL has been initialized!" ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Setting up `atexit ( )` with `SDL_Quit ( )`…" ) ;
	if ( atexit ( SDL_Quit ) != 0 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "`atexit ( )` registration failed!" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6601 : 0x4601 , "CATASTROPHIC FAILURE" ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registered `SDL_Quit ( )` in `atexit ( )`!" ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "Initializing SDL_image with PNG support…" ) ;
	if ( ( ( IMG_Init ( IMG_INIT_PNG ) ) & IMG_INIT_PNG ) != IMG_INIT_PNG ) { // This is stupid.  There must be a better way to do this.
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "SDL_image failed to initialize!  Error give:  \"%s\".  Crashing program…" , SDL_GetError ( ) ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6203 : 0x4203 , SDL_GetError ( ) ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "SDL_image has been initialized!" ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Setting up `atexit ( )` with `IMG_Quit ( )`…" ) ;
	if ( atexit ( IMG_Quit ) != 0 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "`atexit ( )` registration failed!" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6601 : 0x4601 , "CATASTROPHIC FAILURE" ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registered `IMG_Quit ( )` in `atexit ( )`!" ) ;

	/* This is temporarily disabled, as I'm having trouble determining which FLAC library I need to have installed for this to work.

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "Initializing SDL_mixer with FLAC support…" ) ;
	if ( ( ( Mix_Init ( MIX_INIT_FLAC ) ) & MIX_INIT_FLAC ) != MIX_INIT_FLAC ) { // This is also stupid.
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "SDL_mixer failed to initialize!  Error given:  \"%s\".  Crashing program…" , SDL_GetError ( ) ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6204 : 0x4204 , SDL_GetError ( ) ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "SDL_mixer has been initialized!" ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Setting up `atexit ( )` with `Mix_Quit ( )`…" ) ;
	if ( atexit ( Mix_Quit ) != 0 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "`atexit ( )` registration failed!" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6601 : 0x4601 , "CATASTROPHIC FAILURE" ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registered `Mix_Quit ( )` in `atexit ( )`!" ) ;

	*/

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "Initializing SDL_ttf…" ) ;
	if ( TTF_Init ( ) < 0 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "SDL_ttf failed to initialize!  Error given:  \"%s\".  Crashing program…" , SDL_GetError ( ) ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6205 : 0x4205 , SDL_GetError ( ) ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "SDL_ttf has been initialized!" ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Setting up `atexit ( )` with `TTF_Quit ( )`…" ) ;
	if ( atexit ( TTF_Quit ) != 0 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_CRITICAL , "`atexit ( )` registration failed!" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6601 : 0x4601 , "CATASTROPHIC FAILURE" ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registered `TTF_Quit ( )` in `atexit ( )`!" ) ; }

	/* Now that we've done that, we can set up some more stuff. */

#endif/*ndef SETUP_H*/

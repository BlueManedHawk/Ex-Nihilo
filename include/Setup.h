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
#include <string.h>

/* Alright, here's the function. */

void Setup ( void ) {

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "BEGIN FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ;

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
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Registered `TTF_Quit ( )` in `atexit ( )`!" ) ;

	/* Now that we've done that, we can set up some more stuff.  We need to create our game window and renderer, load some particularly important textures, setup some stuff with the audio and load some particularly important sounds _(or we would, if I could figure out how to get FLAC support to work)_, and load the font. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_VIDEO , SDL_LOG_PRIORITY_VERBOSE , "Asking for window size…" ) ;
	SDL_MessageBoxButtonData FullscreenPromptButtons[] = {
		{ 0 , 0 , "Fullscreen" } ,
		{ 0 , 1 , "Monadic" } ,
		{ 0 , 2 , "Duplicant" } ,
		{ 0 , 3 , "Triplet" } ,
		{ 0 , 4 , "Quaternical" } } ;
	SDL_MessageBoxData FullscreenPromptData = {
		SDL_MESSAGEBOX_INFORMATION ,
		NULL ,
		"Size" ,
		"Please select the window size you want to play at." ,
		5 ,
		FullscreenPromptButtons ,
		NULL } ;
	int FullscreenButton = 0 ;
	SDL_ShowMessageBox ( &FullscreenPromptData , &FullscreenButton ) ;
	SDL_WindowFlags WindowFlags = 0 ;
	switch ( FullscreenButton ) {
		case 0:
			SizeMultiplier = 1 ;
			WindowFlags |= SDL_WINDOW_FULLSCREEN ;
			SDL_LogMessage ( SDL_LOG_CATEGORY_VIDEO , SDL_LOG_PRIORITY_VERBOSE , "User has asked for fullscreen." ) ;
			break ;
		case 1:
			SizeMultiplier = 1 ;
			SDL_LogMessage ( SDL_LOG_CATEGORY_VIDEO , SDL_LOG_PRIORITY_VERBOSE , "User has asked for monadic window size." ) ;
			break ;
		case 2:
			SizeMultiplier = 2 ;
			SDL_LogMessage ( SDL_LOG_CATEGORY_VIDEO , SDL_LOG_PRIORITY_VERBOSE , "User has asked for duplicant window size." ) ;
			break ;
		case 3:
			SizeMultiplier = 3 ;
			SDL_LogMessage ( SDL_LOG_CATEGORY_VIDEO , SDL_LOG_PRIORITY_VERBOSE , "User has asked for triplet window size." ) ;
			break ;
		case 4:
			SizeMultiplier = 4 ;
			SDL_LogMessage ( SDL_LOG_CATEGORY_VIDEO , SDL_LOG_PRIORITY_VERBOSE , "User has asked for quaternical window size." ) ;
			break ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_VIDEO , SDL_LOG_PRIORITY_VERBOSE , "Making window…" ) ;
	MainWindow = SDL_CreateWindow ( "Ex Nihilo" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 640 * SizeMultiplier , 480 * SizeMultiplier , WindowFlags ) ;
	if ( MainWindow == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Could not create the window!  Error from SDL:  \"%s\".  Crashing program…" , SDL_GetError ( ) ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6206 : 0x4206 ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_VIDEO , SDL_LOG_PRIORITY_VERBOSE , "Created window!" ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_RENDER , SDL_LOG_PRIORITY_VERBOSE , "Making renderer…" ) ;
	MainRenderer = SDL_CreateRenderer ( MainWindow , -1 , SDL_RENDERER_ACCELERATED ) ;
	if ( MainRenderer == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Could not create the renderer!  Error from SDL:  \"%s\".  Crashing program…" , SDL_GetError ( ) ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6207 : 0x4207 ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_RENDER , SDL_LOG_PRIORITY_VERBOSE , "Created renderer!" ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Loading important images…" ) ;
	char ErrorImagePath[0xFFF] ;
	strcpy ( ErrorImagePath , PrefPath ) ;
	strcat ( ErrorImagePath , "assets/Images/Special/UHOH.png" ) ;
	ErrorSurface = IMG_Load ( ErrorImagePath ) ;
	if ( ErrorSurface == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Could not load the error image!  Crashing program…" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6208 : 0x4208 , "The error image could not be loaded." ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Loaded error image." ) ;
	char TestImagePath[0xFFF] ;
	strcpy ( TestImagePath , PrefPath ) ;
	strcat ( TestImagePath , "assets/Images/Special/TestImage.png" ) ;
	TestSurface = IMG_Load ( TestImagePath ) ;
	if ( TestSurface == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Could not load the test image!  Crashing program…" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6208 : 0x4208 , "The test image could not be loaded." ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Loaded test image." ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Loaded important images!" ) ;

	/* This is where there should be some stuff with setting up audio and loading important sounds, but unfortunately, I haven't been able to get FLAC to work, so until I do, this is empty, and the program goes straight to getting the font. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Obtaining font…" ) ;
	char BarlowCondensedPath[0xFFF] ;
	strcpy ( BarlowCondensedPath , PrefPath ) ;
	strcat ( BarlowCondensedPath , "assets/Text/Font/BarlowCondensed-Thin.ttf" ) ;
	BarlowCondensed = TTF_OpenFont ( BarlowCondensedPath , 12 ) ;
	if ( BarlowCondensed == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_CRITICAL ,  "Could not obtain font!  Crashing program…" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6209 : 0x6209 ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Font obtained!" ) ; }

#endif/*ndef SETUP_H*/

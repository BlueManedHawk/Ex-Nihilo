/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code of Ex Nihilo!
 *
 * This file, `Loading.h`, contains a single function ran after the setup has been complete that loads some things, mostly assets, into the game. */

#pragma once
#ifndef LOADING_H
#define LOADING_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include <string.h>

 void LoadStuff ( void ) {

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "BEGIN FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Opening font…" ) ;
	char BarlowCondensedLocation[0xFFF] = "" ;
	strcpy ( BarlowCondensedLocation , PrefPath ) ;
	strcat ( BarlowCondensedLocation , "assets/Text/Font/BarlowCondensed-Regular.ttf" ) ;
	BarlowCondensed = TTF_OpenFont ( BarlowCondensedLocation , 16 ) ;
	if ( !BarlowCondensed ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Barlow Condensed could not be opened!  Crashing program…" ) ;
		char CrashMessage[0xFFF] = "" ;
		sprintf ( CrashMessage , "Barlow Condensed, which should be at\
				`%s`,\
				could not be opened." , BarlowCondensedLocation ) ;
		Crash ( 0x7 , CrashMessage ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Barlow Condensed has been opened!" ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Loading important images…" ) ;
	char ImagePath[0xFFF] ;
	strcpy ( ImagePath , PrefPath ) ;
	strcat ( ImagePath , "assets/Images/Special/UHOH.png" ) ;
	ErrorSurface = IMG_Load ( ImagePath ) ;
	if ( ErrorSurface == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Could not load the error image!  Crashing program…" ) ;
		Crash ( 0x7 , "The error image could not be loaded." ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Loaded error image." ) ;
	strcpy ( ImagePath , PrefPath ) ;
	strcat ( ImagePath , "assets/Images/Special/TestImage.png" ) ;
	TestSurface = IMG_Load ( ImagePath ) ;
	if ( TestSurface == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Could not load the test image!  Crashing program…" ) ;
		Crash ( 0x7 , "The test image could not be loaded." ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Loaded test image." ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Loaded important images!" ) ;

	char Path[0xFFF] ;
	strcpy ( Path , PrefPath ) ;
	strcat ( Path , "assets/Images/Special/Character Head.png" ) ;
	CharacterHeadSurface = IMG_Load ( Path ) ;
	CharacterHeadTexture = SDL_CreateTextureFromSurface ( MainRenderer , CharacterHeadSurface ) ;
	strcpy ( Path , PrefPath ) ;
	strcat ( Path , "assets/Images/Special/Character Body.png" ) ;
	CharacterBodySurface = IMG_Load ( Path ) ;
	CharacterBodyTexture = SDL_CreateTextureFromSurface ( MainRenderer , CharacterBodySurface ) ;
	SDL_FreeSurface ( CharacterHeadSurface ) ;
	SDL_FreeSurface ( CharacterBodySurface ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "END FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ; }

#endif/*ndef LOADING_H*/

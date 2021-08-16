/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file, `Cleanup.h`, contains a single function, `Cleanup`, that is run whenever the program needs to exit.  This function, of course, does the task of cleaning things up.
 *
 * There isn't currently very much in this file, but that's mostly because there isn't very much in the program.  This will probably expand with time. */

#pragma once
#ifndef CLEANUP_H
#define CLEANUP_H

#include "Global.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

void Cleanup ( void ) {

	/* For some reason, these cause problems (usually segfaults), even though I've specifically checked if they're null.  I have no idea why.
	if ( ErrorSurface != NULL ) {
		SDL_FreeSurface ( ErrorSurface ) ; }
	if ( TestSurface != NULL ) {
		SDL_FreeSurface ( TestSurface ) ; }

	if ( BarlowCondensed != NULL ) {
		TTF_CloseFont ( BarlowCondensed ) ; }
	*/

	if ( MainRenderer != NULL ) {
		SDL_DestroyRenderer ( MainRenderer ) ; }
	if ( MainWindow != NULL ) {
		SDL_DestroyWindow ( MainWindow ) ; }

	SDL_EnableScreenSaver ( ) ;

	if ( SDL_WasInit ( SDL_INIT_VIDEO ) ) {
		SDL_QuitSubSystem ( SDL_INIT_VIDEO ) ; }
	if ( SDL_WasInit ( SDL_INIT_AUDIO ) ) {
		SDL_QuitSubSystem ( SDL_INIT_AUDIO ) ; }

	IMG_Quit ( ) ;
	Mix_Quit ( ) ;
	TTF_Quit ( ) ;

	SDL_Quit ( ) ; }
#endif/*ndef CLEANUP_H*/

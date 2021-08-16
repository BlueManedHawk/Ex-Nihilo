/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file contains several functions that are used during the main loop during regular gameplay.  These update the game, then tick the game, then render the world, then render sprites onto the world, then render the UI.
 *
 * Uh, currently, most of this is just skeletal so that I can have a plan for things. */

#pragma once
#ifndef GAME_H
#define GAME_H

#include <math.h>

#include "Global.h"

#include "SDL.h" 

void UpdateGame ( void ) {

	if ( !( ( MouseX - 240 ) * SizeMultiplier ) ) {
		MouseX++ ; }
	CharacterHeadAngle = atan ( ( ( MouseY - 240 ) * SizeMultiplier ) / ( ( MouseX - 240 ) * SizeMultiplier ) ) ; // This should logically work.  I have genuinely no idea why it doesn't. //
	if ( MouseY > 240 * SizeMultiplier ) {
		CharacterHeadAngle += 180 ; }
	SDL_Log ( "%f" , CharacterHeadAngle ) ; }

 void TickGame ( void ) { }  // Just skeletal for now. //

 void RenderWorld ( void ) { } // Just skeletal for now. //

 void RenderSprites ( void ) {

	/* We can use the same rectangle for both of these because the images are the same size. */

	SDL_RenderCopyEx ( MainRenderer , CharacterBodyTexture , NULL , &CharacterRectangle , (double)CharacterBodyAngle , NULL , 0 ) ;
	SDL_RenderCopyEx ( MainRenderer , CharacterHeadTexture , NULL , &CharacterRectangle , CharacterHeadAngle , NULL , 0 ) ; }

 void RenderUI ( void ) { } // Just skeletal for now. //

#endif/*ndef GAME_H*/

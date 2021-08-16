/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file, `Input.h`, contains a single function used in the main loop to gather the input for this tick and write it down in several places.
 *
 * At the moment, this only gets mouse information and writes it down for use to determine the orientation of the character.  This will be expanded in the future. */

#pragma once
#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"

#include "Global.h"

 void GetInput ( void ) {

	SDL_Event e ;
	while ( SDL_PollEvent ( &e ) ) {
		if ( e.type == SDL_QUIT ) {
			Quit = 1 ; }
		if ( e.type == SDL_MOUSEMOTION ) {
			MouseX = e.motion.x ;
			MouseY = e.motion.y ;
			MouseButtons = e.motion.state ; } } }

#endif/*ndef INPUT_H*/

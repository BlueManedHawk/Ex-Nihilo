/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file currently just contains a bunch of skeletal functions for planning purposes.  These will be used for updating and rendering the menus. */

#pragma once
#ifndef MENUS_H
#define MENUS_H

#include "Global.h"

#include "SDL.h"

 void UpdateMainMenu ( void ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "The game has somehow entered into a state that isn't in-game." ) ;
	State = InGame ; }
 void RenderMainMenu ( void ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "The game has somehow entered a state that isn't in-game." ) ;
	State = InGame ; }
 void UpdatePauseMenu ( void ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "The game has somehow entered a state that isn't in-game." ) ;
	State = InGame ; }
 void RenderPauseMenu ( void ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "The game has somehow entered into a state that isn't in-game." ) ;
	State = InGame ; }

#endif/*ndef MENUS_H*/

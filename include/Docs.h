/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file currently just holds some skeletal stuff for planning purposes.  Eventually, it'll be used for loading and rendering the documentation. */

#pragma once
#ifndef DOCS_H
#define DOCS_H

#include "Global.h"

#include "SDL.h"

 void LoadDocumentation ( void ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "The game has somehow entered a state that isn't in-game." ) ;
	State = InGame ; }

 void RenderDocumentation ( void ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "The game has somehow entered a state that isn't in-game." ) ;
	State = InGame ; }

#endif/*ndef DOCS_h*/

/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file is currently just skeletal for planning purposes.  Eventually, it's going to be used for debug stuff. */

#ifndef DEBUG_H
#define DEBUG_H

 void UpdateConsole ( void ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "The game has exited the in-game state.  Returning now." ) ;
	State = InGame ; }

 void RenderConsole ( void ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_WARN , "The game has exited the in-game state.  Returning now." ) ;
	State = InGame ; }

#endif/*ndef DEBUG_H*/

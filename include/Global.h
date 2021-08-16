/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file, `Global.h`, is a header file for the project that's used pretty much everywhere in the source.  This contains several variables that are used mostly for interfunction communication, though there are also some constants that mostly exist for convenience. */

/* First, some include guards. */

#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H

#include "SDL.h"

/* This is just so that we can have debug-mode checks use the ternary operator instead preprocessing, which makes things _much_ nicer-looking.  This isn't done very much anymore, but it might be. */

#ifndef EX_NIHILO_DEBUG_MODE
const int EX_NIHILO_DEBUG_MODE = 0 ;
#endif/*ndef EX_NIHILO_DEBUg_MODE*/

/* This defines whether the battery will be rechecked every so often during the loop.  This is on by default. */

_Bool BatteryRechecks = 1 ;

/* This contains the "pref path", which the SDL wiki claims should be assumed to be the only safe place to write things. */

char * PrefPath = NULL ;

/* This size multiplier is used so that we can set the resolution to different things on different monitors. */

int SizeMultiplier = 1 ;

/* These are the window and the renderer, which are set in `Setup.h`. */

SDL_Window * MainWindow ;

SDL_Renderer * MainRenderer ;

/* There are multiple fonts for multiple sizes, because that's how SDL_ttf works, for some reason. */

TTF_Font * BarlowCondensed ;

/* These are a couple of surfaces for particularly important images. */

SDL_Surface * ErrorSurface , * TestSurface ;

/* These primes are used for checksumming. */

const short Primes[16] = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 57 , 53 } ;

/* IMPORTANT:  WHEN UPDATING THIS, ALWAYS ENSURE THAT THE FINAL `NULL` CONTINUES TO EXIST. 
 *
 * These arrays contain the locations of the assets and their expected checksums. */

char * AssetsLocationArray[] = {
	"/Images/Special/TestImage.png",
	"/Images/Special/UHOH.png" ,
	"/Images/Special/Character Body.png" ,
	"/Images/Special/Character Head.png" ,
	"/Images/Tiles/Void Stone.png" ,
	"/Text/Font/BarlowCondensed-Regular.ttf" ,
	NULL } ;

long long AssetsChecksumArray[] = {
	15385344 ,
	15106048 ,
	10654464 ,
	12864256 ,
	10108160 ,
	3199488 ,
	0 } ;

/* This is used to track how many frames the game has lagged for.  It goes up by one for every lag frame, and down by one for every non-lag*/

int Errors = 0 ;

/* This is used to see whether the game intends to crash due to lag. */

_Bool LagCrash = 0 ;

/* The state of the game is used to determine the state of the game.  The other things are just to reduce magic numbers. */

short State = 0 ;

const short InGame = 1 ;
const short MainMenu = 2 ;
const short PauseMenu = 3 ;
const short Documentation = 4 ;
#ifdef EX_NIHILO_DEBUG_MODE
const short DebugConsole = 5 ;
#endif/*def EX_NIHILO_DEBUG_MODE*/

/* These are used to track the state of the mouse.  These are filled each tick in `GetInput ( )`. */

uint32_t MouseButtons ;
int MouseX = 0 , MouseY = 0 ;

/* These are use to track the angle of the character's parts. */

double CharacterHeadAngle = 0 ;
int CharacterBodyAngle = 0 ;

/* These are pretty obvious. */

SDL_Surface * CharacterHeadSurface ; 
SDL_Texture * CharacterHeadTexture ;
SDL_Surface * CharacterBodySurface ;
SDL_Texture * CharacterBodyTexture ;

/* This is where the character is located.  It's defined after the resolution has been chosen. */

SDL_Rect CharacterRectangle ;

/* This is checked to see if the game should quit. */

_Bool Quit = 0 ;

#endif/*ndef GLOBAL_H*/

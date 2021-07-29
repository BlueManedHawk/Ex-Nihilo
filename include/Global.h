/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file, `Global.h`, is a header file for the project that's used pretty much EVERYWHERE in the source.  Currently, it doesn't define much, but I expect it to grow a lot, so I'm creating it now for future-proofing.*/

/* First, some include guards. */

#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H

#include "SDL.h"

/* This is just so that we can have debug-mode checks use the ternary operator instead preprocessing, which makes things _much_ nicer-looking. */

#ifndef EX_NIHILO_DEBUG_MODE
const int EX_NIHILO_DEBUG_MODE = 0 ;
#endif/*ndef EX_NIHILO_DEBUg_MODE*/

/* This defines whether the battery will be rechecked every so often during the loop.  This is on by default. */

_Bool BatteryRechecks = 1 ;

/* This contains the "pref path", which the SDL wiki claims should be assumed to be the only safe place to write things.  This is later set to the value returned by `SDL_GetPrefPath ( )` in `Checks.h`. */

char * PrefPath = NULL ;

/* This size multiplier is used so that we can set the resolution to different things on different monitors. */

int SizeMultiplier = 1 ;

/* These are the window and the renderer, which are set in `Setup.h`. */

SDL_Window * MainWindow ;

SDL_Renderer * MainRenderer ;

/* This is the only font that's currently being used in this. */

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
	"/Images/Special/TheCharacter.png" ,
	"/Images/Tiles/Void Stone.png" ,
	"/Text/Font/BarlowCondensed-Black.ttf" ,
	"/Text/Font/BarlowCondensed-BlackItalic.ttf" ,
	"/Text/Font/BarlowCondensed-Thin.ttf" ,
	"/Text/Font/BarlowCondensed-ThinItalic.ttf" ,
	NULL } ;

long long AssetsChecksumArray[] = {
	15385344 ,
	15106048 ,
	6961152 ,
	10108160 ,
	2565376 ,
	11518720 ,
	346112 ,
	11650048 ,
	0 } ;

#endif/*ndef GLOBAL_H*/

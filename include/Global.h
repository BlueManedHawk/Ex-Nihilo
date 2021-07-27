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

int SizeMultiplier = 1 ;

SDL_Window * MainWindow ;

SDL_Renderer * MainRenderer ;

SDL_Surface * ErrorSurface , * TestSurface ;

TTF_Font * BarlowCondensed ;

const short Primes[16] = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 57 , 53 } ;

/* IMPORTANT:  WHEN UPDATING THIS, ALWAYS ENSURE THAT THE FINAL `NULL` CONTINUES TO EXIST. */

char * AssetsLocationArray[] = {
	"/Images/Special/TestImage.png",
	NULL } ;

long long AssetsChecksumArray[] = {
	15385344 ,
	0 } ;

#endif/*ndef GLOBAL_H*/

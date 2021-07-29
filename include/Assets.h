/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file contains stuff for "checksumming" (HAH) the assets.  I put that in quotes because this is, frankly, a terrible checksum.  It doesn't comply with any formal specification like SHA-3 because I couldn't find a lick of useful information about such a system, since everything was completely impenetrable.  Therefore, this is just some random crap I threw together with the hope that something works right.
 *
 * It certainly doesn't help that a good chunk of the stuff used for the checksum (the table of primes, the array of expected checksums, and the type of the array) is stored in `Global.h`.*/

/* We first need include guards. */

#pragma once
#ifndef ASSETS_H
#define ASSETS_H

/* We now need to include `<stdio.h>` so that we can read bytes from the files, `<string.h>` for string manipulation, `<math.h>` to get the cube root of a prime, `Crash.h` to crash the program if we need to, and `Global.h` for some important bits for the checksum. */

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "Crash.h"
#include "Global.h"

/* Now comes the function.  What this does is it finds the asset, reads off bytes from it, concatenates eight of them into a long long, multiplies that long long by a specific prime, and stores it.  Once it's done that for each group of eight bytes in the asset, it takes each pair of long longs, multiplies the second by the cube root of a prime determined by the first, and XORs it on to the first.  It then XORs each long long onto the next, and then it compares the result it got to the one it was told it should have.  If they're equal, it does nothing; otherwise, it crashes the game.
 *
 * As stated before, this is a terrible checksum. */

void AssetsChecksum ( char * Asset , long long ExpectedChecksum ) {

	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "BEGIN FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Beginning checksum of %s." , Asset ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Opening asset…" ) ;
	char AssetLocation[0xFFF] = "" ;
	strcpy ( AssetLocation , PrefPath ) ;
	strcat ( AssetLocation , "assets" ) ;
	strcat ( AssetLocation , Asset ) ;
	FILE * AssetFILE = fopen ( AssetLocation , "r" ) ;
	if ( AssetFILE == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_CRITICAL , "Failed to open %s!  Crashing program…" , AssetLocation ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6301 : 0x4301 , AssetLocation ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Opened asset." ) ;

	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Creating actual sum…" ) ;
	long long Intermediate0 = 0x0 ;
	long long Intermediate1 = 0x0 ;
	long long Final = 0x0 ;
	int register Count = 0 ;
	_Bool Twice = 0 ;
	while ( !feof ( AssetFILE ) && !ferror ( AssetFILE ) ) {
		if ( Count % 8 && !( Count % 16 ) ) {
			Twice = 1 ;
			long long PrimeSelection = 0x001E0000 ;
			PrimeSelection &= Intermediate0 ;
			PrimeSelection >>= 17 ;
			Intermediate0 *= Primes[PrimeSelection] ;
			Intermediate1 = 0x0 ; }
		if ( Count % 8 && Count % 16 ) {
			Twice = 0 ;
			long long PrimeSelection = 0x001E0000 ;
			PrimeSelection &= Intermediate1 ;
			PrimeSelection >>= 17 ;
			Intermediate1 *= Primes[PrimeSelection] ;
			PrimeSelection = 0x000003A0 ;
			PrimeSelection &= Intermediate0 ;
			PrimeSelection >>= 6 ;
			Intermediate1 *= cbrt ( Primes[PrimeSelection] ) ;
			long long Inversion = 0x0 ;
			while ( Intermediate1 ) {
				Inversion <<= 1 ;
				Inversion |= ( Intermediate1 & 1 ) ? 1 : 0 ;
				Intermediate1 >>= 1 ; }
			Final ^= ( Intermediate0 ^ Inversion ) ;
			Intermediate0 = 0x0 ;
			Intermediate1 = 0x0 ; }

		int Byte = EOF ;
		Byte = fgetc ( AssetFILE ) ;
		if ( Twice ) {
			Intermediate1 |= Byte ;
			Intermediate1 <<= 8 ; }
		else {
			Intermediate0 |= Byte ;
			Intermediate0 <<= 8 ; }
		Byte = EOF ;
		Count++ ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Sum created." ) ;
	
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Comparing checksums…" ) ;
	if ( Final != ExpectedChecksum ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "%s checksummed to the wrong value!  Expected %lld, but got %lld!  Crashing program…" , Asset , ExpectedChecksum , Final ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6301 : 0x4301 , "Please look at the log for the fault." ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Checksum succeeded!" ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_APPLICATION , SDL_LOG_PRIORITY_VERBOSE , "END FUNCTION %s IN FILE %s AT LINE %d." , __func__ , __FILE__ , __LINE__ ) ; }

#endif/*ndef ASSETS_H*/

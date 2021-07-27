/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file, `Checks.h`, is a header file included in the main file, `Ex Nihilo.c`.  This header contains a single function, `RunChecks ( )`.  If you want to see where this function is used, see the main file.
 *
 * This function verifies a few things, such as the assets, the OS, and the battery. 
 *
 * The function returns an integer, which is 1 if the assets were bad, 2 if the OS was bad, and 3 if the battery was bad. 
 *
 * This function has a number of side effects.  A functional programmer, I am not. */

/* We first need an include guard. */

#pragma once
#ifndef CHECKS_H
#define CHECKS_H

/* We now need to include SDL because it has some functions that allow us to check the OS and the battery.  We also need to include the global header and the crash handler.  Oh, and there's also the standard input-output header to check for the existence of a file. */

#include <stdio.h>
#include "SDL.h"
#include "Global.h"
#include "Crash.h"
#include "Assets.h"

/* And now, we get to the meat of the file. */

void RunChecks ( void ) {

	/* We first verify the assets.  For now, all this does is ensure that a specific file exists, and if it doesn't, the user is told to put their assets in the appropriate place, and the game is crashed.
	 *
	 * Eventually, I want to make this properly checksum each of the assets, because currently this system doesn't do very much. */

	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Getting pref path…" ) ;
	PrefPath = SDL_GetPrefPath ( "BlueManedHawk" , "Ex Nihilo vN 2" ) ; // Currently, it's just me working on this, and I'm not part of any organization (that I know of).  That's why I chose this. //
	if ( PrefPath == NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_CRITICAL , "Pref path could not be obtained!  Crashing program…" ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x6201 : 0x4201 ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Pref path obtained!" ) ;
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Verifying assets…" ) ;
	for ( register int i = 0 ; AssetsLocationArray[i] != NULL ; i++ ) {
		AssetsChecksum ( AssetsLocationArray[i] , AssetsChecksumArray[i] ) ; }
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "All assets have been verified!" ) ;
	
	/* We now verify the OS.  `SDL_GetPlatform` is used to get this information.  If the OS is invalid, the program is crashed.  If the OS is questionable, the user is warned appropriately.  If the OS is fine, nothing happens. */
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Verifying OS…" ) ;
	const char * Platform = SDL_GetPlatform ( ) ;
	if ( strstr ( Platform , "Linux" ) != NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "OS verified!" ) ; }
	else if ( strstr ( Platform , "Unknown" ) != NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_WARN , "User's OS could not be verified; assuming good faith." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Could not verify OS!" ,\
				"Your operating system could not be verified.  Please\n\
				see the non-binding section of the License to see why\n\
				this might be a problem.  However, good faith will be\n\
				assumed, and you will be allowed to play.", NULL ) ; }
	else if ( strstr ( Platform , "Windows" ) != NULL || strstr ( Platform , "Mac OS X" ) || strstr ( Platform , "iOS" ) ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Invalid OS!  Crashing program…" ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Invalid OS!" ,\
				"You are attempting to run this software\n\
				under a bad ooperating system.  Please do\n\
				not do this.  For more information, please\n\
				see the non-binding section of the License.\n\
				\n\
				The program will now crash." , NULL ) ;
		Crash ( EX_NIHILO_DEBUG_MODE ? 0x2302 : 0x0302 ) ; }
	else if ( strstr ( Platform , "Android" ) != NULL ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_WARN , "User is on Android and may or may not have acquired program through illegitimate means; assuming good faith." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Acquiration concerns" ,\
				"You are playing this game on an Android device.  Where\n\
				you obtained this from cannot be checked, so good faith\n\
				will be assumed and you will be allowed to continue\n\
				playing.  (For more information about these concerns,\n\
				see the non-binding section of the License.)" , NULL ) ; }
	
	/* We now need to check the battery with `SDL_GetPowerInfo`.  This uses the following logic:
	 *
	 * - If the player is not on a battery, continue, and don't run rechecks.
	 * - If the player is on a battery, but it's plugged in, don't do anything at first, but run rechecks later.
	 * - If the player is on a battery that isn't plugged in, then:
	 *   	- If the battery is below 15% or has less than 15 minutes left, crash the game.
	 *   	- Otherwise, notify the user that they may want to plug in if they play for a while, but continue which running rechecks.
	 * - If the power state can't be determined, warn the user, but continue as normal.
	 *
	 * I have no idea why the output of `SDL_GetPowerInfo` is stored both in its arguments _and_ in it's return.  Ah well. */
	
	SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "Verifying battery…" ) ;
	int Seconds = -1 ;
	int Percent = -1 ;
	SDL_PowerState PowerState = SDL_GetPowerInfo ( &Seconds , &Percent ) ;
	if ( PowerState == SDL_POWERSTATE_UNKNOWN || ( Seconds == -1 && Percent == -1 ) ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_WARN , "Battery state unknown; warning user, rechecks will be run." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Battery state unknown" ,\
				"Your battery state could not be determined.  Please\n\
				check this before continuing." , NULL ) ; }
	else if ( PowerState == SDL_POWERSTATE_ON_BATTERY ) {
		if ( ( Seconds < 900 && Seconds != -1 ) || ( Percent < 15 && Percent != -1 ) ) {
			SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Battery too low!  Crashing program…" ) ;
			SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_ERROR , "Your battery is too low!" ,\
					"Your battery is very low, and Ex Nihilo has\n\
					been stopped to prevent loss of data.  Please\n\
					plug in your battery and relaunch the game if\n\
					you want to play." , NULL ) ;
			Crash ( EX_NIHILO_DEBUG_MODE ? 0x6302 : 0x4302 ) ; }
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "User is on battery; will run rechecks." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_INFORMATION , "You are on battery" ,\
				"If you are planning on playing for a long period\n\
				of time, you may want to plug in your battery." , NULL ) ; }
	else if ( PowerState == SDL_POWERSTATE_NO_BATTERY ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "User doesn't have battery; will not run rechecks." ) ;
		BatteryRechecks = 0 ; }
	else if ( PowerState == SDL_POWERSTATE_CHARGED || PowerState == SDL_POWERSTATE_CHARGING ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_ASSERT , SDL_LOG_PRIORITY_VERBOSE , "User battery is plugged in; will run rechecks." ) ; } }

#endif/*ndef CHECKS_H*/

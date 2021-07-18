/* LICENSE
 *
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.
 *
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file, `Crash.h`, is a header file that defines the crash system for the project.  It consists of several functions, only two of which matter:  `CrashHandlerSetup ( )`, which set up the crash handler, and `Crash ( )`, which causes a crash.
 *
 * More information on the crash protocol is available in `docs/Problems/CRASHES.md`.  Importantly, this details the difference between the application exit code and the system exit code, and describes what different codes mean. */

/* First, some include guards. */

#pragma once
#ifndef CRASH_H
#define CRASH_H

/* Now, some standard library stuff.  `<stdarg.h>` is for variable arguments, `<stdlib.h>` is for `exit ( )`, `<signal.h>` is to deal with signals, and `<time.h>` and `<stdio.h>` is used to put a time on and export the crash log. */

#include <stdarg.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>

/* This is probably the function that matters the most.  A good bit of this is just a big switch-case statement based on the first argument. */

_Noreturn void Crash ( int ApplicationExitCode , ... ) { // `ApplicationExitCode` _should_ be considered a short, and it's _treated_ as a short, but I can't _declare_ it as a short without Clang getting pissy. //

	/* We first need to set the button data and the color scheme for the message box.  This part is easy—I decided to go with a very red color scheme to hopefully get the attention of whoever experienced the crash. */

	SDL_MessageBoxButtonData MessageBoxButtonData[] = {
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT , 0 , "Dang it!" } ,
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT , 1 , "Export crash" } } ;

	SDL_MessageBoxColorScheme MessageBoxColorScheme = { {
		{ 0x7F , 0x0F , 0x0F } ,
		{ 0xFF , 0x1F , 0x1F } ,
		{ 0xFF , 0x1F , 0x1F } ,
		{ 0x7F , 0x0F , 0x0F } ,
		{ 0xFF , 0xFF , 0x1F } } } ;

	/* Now, we need to setup the text which will occur in the messagebox should the game crash.  This part is a pain in the hole, because strings aren't builtin to C, so we need to deal with this nightmare. */

	char CrashText[0xFFF] = "A problem has occurred with Ex Nihilo and the game has crashed.\n\
			    \n\
			    System Exit Code: " ;
	char ApplicationExitCodeString[16] = "" ;
	sprintf ( ApplicationExitCodeString , "%d" , ApplicationExitCode >> 8 ) ;
	strcat ( CrashText , ApplicationExitCodeString  ) ;
	strcat ( CrashText , "\nApplication Exit Code: " ) ;
	sprintf ( ApplicationExitCodeString , "%d" , ApplicationExitCode ) ; 
	strcat ( CrashText , ApplicationExitCodeString ) ;
	strcat ( CrashText , "\n\nSafe Exit: " ) ;
	strcat ( CrashText , ( ApplicationExitCode & 0x8000 ) ? "No.\n" : "Yes.\n" ) ;
	strcat ( CrashText , "Expected Exit: " ) ;
	strcat ( CrashText , ( ApplicationExitCode & 0x4000 ) ? "No.\n" : "Yes.\n" ) ;
	strcat ( CrashText , "Debug Mode On: " ) ;
	strcat ( CrashText , ( ApplicationExitCode & 0x2000 ) ? "Yes.\n" : "No.\n" ) ; // I'm fully aware this is weird.  See the protocol document for why this is.
	strcat ( CrashText , "[reserved]: " ) ;
	strcat ( CrashText , ( ApplicationExitCode & 0x1000 ) ? "No.\n\n" : "Yes.\n\n" ) ;

	/* Here's that big switch-case statment I mentioned.  I've tried to cover every possible case so that there isn't a loop of segfaults. */

	char * ErrorClassMessage = NULL ;
	char * ErrorTypeMessage = NULL ;
	switch ( ApplicationExitCode & 0x0F00 ) {
		case 0x0100:
			ErrorClassMessage = "Debug Mode\n" ;
			switch ( ApplicationExitCode & 0x00FF ) {
				case 0x0001:
					ErrorTypeMessage = "The game was crashed manually." ;
					break ;
				default:
					ErrorTypeMessage = "An unknown error type occured.  Please file an issue." ;
					break ; }
			break ;
		case 0x0200:
			ErrorClassMessage = "Problem with SDL (or extensions)\n" ;
			switch ( ApplicationExitCode & 0x00FF ) {
				case 0x0001:
					ErrorTypeMessage = "The pref path could not be obtained." ;
					break ;
				default:
					ErrorTypeMessage = "An unknown error type occured.   Please file an issue." ;
					break ; }
			break ;
		case 0x0300:
			ErrorClassMessage = "Attempt to play in invalid circumstances\n" ;
			switch ( ApplicationExitCode & 0x00FF ) {
				case 0x0001:
					ErrorTypeMessage = "Your game has invalid assets.  Please reinstall them." ;
					break ;
				case 0x0002:
					ErrorTypeMessage = "You have attempted to play on an invalid OS.  Please\n\
							    read the non-binding section of the license to see why\n\
							    this is a problem." ;
					break ;
				case 0x0003:
					ErrorTypeMessage = "Your battery is too low to play.  Please charge it." ;
					break ;
				default:
					ErrorTypeMessage = "An unknown error type occurred.  Please file an issue." ;
					break ; }
			break ;
		case 0x0400:
			ErrorClassMessage = "Game trying to prevent data loss\n" ;
			ErrorTypeMessage = "No type." ;
			break ;
		case 0x0500:
			ErrorClassMessage = "Crash-inducing signal recieved\n" ;
			switch ( ApplicationExitCode & 0x00FF ) {
				case 0x0001:
					ErrorTypeMessage = "Abnormal program exit occurred." ;
					break ;
				case 0x0002:
					ErrorTypeMessage = "A floating-point error occured." ;
					break ;
				case 0x0003:
					ErrorTypeMessage = "An illegal instruction was given." ;
					break ;
				case 0x0004:
					ErrorTypeMessage = "An interruption request was sent to the program." ;
					break ;
				case 0x0005:
					ErrorTypeMessage = "A segmentation fault occured." ;
					break ;
				case 0x0006:
					ErrorTypeMessage = "A termination request was sent to the program." ;
					break ;
				default:
					ErrorTypeMessage = "An unknown error type occurred.  Please file an issue." ;
					break ; }
			break ;
		default:
			ErrorClassMessage = "Unknown; please file an issue\n" ;
			ErrorTypeMessage = "An unknown error class was given, so no type can be determined." ;
			break ; }
	strcat ( CrashText , "Crash class: " ) ;
	strcat ( CrashText , ErrorClassMessage ) ;
	strcat ( CrashText , "Crash type: " ) ;
	strcat ( CrashText , ErrorTypeMessage ) ;
	va_list ap ;
	va_start ( ap , ApplicationExitCode ) ; 
	char * OtherInformation = va_arg ( ap , char * ) ;
	va_end ( ap ) ;
	strcat ( CrashText , "\nOther information:\n" ) ;
	if ( OtherInformation == NULL ) {
		strcat ( CrashText , "None given." ) ; }
	else {
		strcat ( CrashText , OtherInformation ) ; }
	strcat ( CrashText , "\n" ) ;
	strcat ( CrashText , "You may want to file an issue.\n\n" ) ;

	/* And after all that, we finally get to presenting the messagebox. */

	SDL_MessageBoxData MessageBoxData = {
		SDL_MESSAGEBOX_ERROR ,
		NULL ,
		"Ex Nihilo has crashed!" ,
		CrashText ,
		2 ,
		MessageBoxButtonData ,
		&MessageBoxColorScheme } ;

	int ButtonID = 0 ;

	SDL_ShowMessageBox ( &MessageBoxData , &ButtonID ) ;

	/* Exporting to a file isn't anything fancy.  We just put the crash text into a file. */

	if ( ButtonID ) {
		char * CrashLogFilename = SDL_GetPrefPath ( "BlueManedHawk" , "Ex Nihilo vN 2" ) ;
		strcat ( CrashLogFilename , "Crash Logs/Crash " ) ;
		time_t Time = time ( NULL ) ;
		char * TimeString = ctime ( &Time ) ;
		strcat ( CrashLogFilename , TimeString ) ;
		strcat ( CrashLogFilename , ".txt" ) ;
		FILE * CrashLogFile = fopen ( CrashLogFilename , "w" ) ; // Mmmph.
		if ( !CrashLogFile ) {
			SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Could not open crash log file for writing!" ) ; }
		else {
			fprintf ( CrashLogFile , "%s" , CrashText ) ; } }

	exit ( ApplicationExitCode >> 8 ) ; }

/* Now, we get to the crash handler setup functions.  Since `signal ( )` doesn't accept an argument for the arguments to the pointed function, I have to declare a bunch of other functions for it to point to that are really just the `Crash ( )` function with arguments. */

_Noreturn void CrashFromAbnormalExit ( [[maybe_unused]] int Required ) {
#ifdef EX_NIHILO_DEBUG_MODE
	Crash ( 0xE501 ) ; }
#else
	Crash ( 0xC501 ) ; }
#endif/*def EX_NIHILO_DEBUG_MODE*/

_Noreturn void CrashFromFloatingPointError ( [[maybe_unused]] int Required ) {
#ifdef EX_NIHILO_DEBUG_MODE
	Crash ( 0xE502 ) ; }
#else
	Crash ( 0xC502 ) ; }
#endif/*def EX_NIHILO_DEBUG_MODE*/

_Noreturn void CrashFromIllegalOperation ( [[maybe_unused]] int Required ) {
#ifdef EX_NIHILO_DEBUG_MODE
	Crash ( 0xE503 ) ; }
#else
	Crash ( 0xC503 ) ; }
#endif/*def EX_NIHILO_DEBUG_MODE*/

_Noreturn void CrashFromInterruption ( [[maybe_unused]] int Required ) {
#ifdef EX_NIHILO_DEBUG_MODE
	Crash ( 0xE504 ) ; }
#else
	Crash ( 0xC504 ) ; }
#endif/*def EX_NIHILO_DEBUG_MODE*/

_Noreturn void CrashFromSegfault ( [[maybe_unused]] int Required ) {
#ifdef EX_NIHILO_DEBUG_MODE
	Crash ( 0xE505 ) ; }
#else
	Crash ( 0xC505 ) ; }
#endif/*def EX_NIHILO_DEBUG_MODE*/

_Noreturn void CrashFromTermination ( [[maybe_unused]] int Required ) {
#ifdef EX_NIHILO_DEBUG_MODE
	Crash ( 0xE506 ) ; }
#else
	Crash ( 0xC506 ) ; }
#endif/*def EX_NIHILO_DEBUG_MODE*/

void CrashHandlerSetup ( void ) {
	signal ( SIGABRT , CrashFromAbnormalExit ) ;
	signal ( SIGFPE , CrashFromFloatingPointError ) ;
	signal ( SIGILL , CrashFromIllegalOperation ) ;
	signal ( SIGINT , CrashFromInterruption ) ;
	signal ( SIGSEGV , CrashFromSegfault ) ;
	signal ( SIGTERM , CrashFromTermination ) ; }

#endif/*ndef CRASH_H*/

/* LICENSE
 * You may freely distribute the original source code, binaries compiled from the original source code, modified binaries compiled from the original source code, modified source code, binaries compiled from modified source code, and modified binaries compiled from modified source code. However, you cannot charge for these, and you must distribute this license and give attribution when distributing.  
 * Modifications must be licensed in a way that preserves the rights that this license gives with the same conditions, and any modified files must state how they were modified and how to obtain the originals; additionally, any binaries must state how to obtain the sources that they were compiled from.
 * 
 * This software comes with no warranty, implied or explicit, and I am not liable for any problems caused by this software. Additonally, this license does not cover trademarks in any capacity. */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * This file, `Crash.h`, is a header file that defines the crash system for the project.  It consists of several functions, only two of which matter:  `CrashHandlerSetup ( )`, which set up the crash handler, and `Crash ( )`, which causes a crash.
 *
 * More information on the crash protocol is available in `docs/Problems/CRASHES.md`. */

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

_Noreturn void Crash ( int ExitCode , ... ) { // `ExitCode` _should_ be considered a short, and it's _treated_ as a short, but I can't _declare_ it as a short without Clang getting pissy. //

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

	/* Now, we need to setup the text which will occur in the messagebox should the game crash.  This part is a pain in the hole, because strings aren't a builtin part of C except where they are, so we need to deal with this nightmare from `<stdlib.h>`. */

	char CrashText[0xFFF] = "A problem has occurred with Ex Nihilo and the game has crashed.\n\
\n\
Exit Code: " ;
	char ExitCodeString[16] = "" ;
	sprintf ( ExitCodeString , "%#x\n" , ExitCode ) ;
	strcat ( CrashText , ExitCodeString  ) ;
	
	/* Here's that big switch-case statment I mentioned.  I've tried to cover every possible case so that there isn't a loop of segfaults. */

	char * ErrorTypeMessage = NULL ;
	switch ( ExitCode ) {
	case 0x0:
		ErrorTypeMessage = "Normal program termination.  If this happened, you shouldn't be seeing this dialog; please report an issue." ;
		break ;
	case 0x1:
		ErrorTypeMessage = "The player manually crashed the game." ;
		break ;
	case 0x2:
		ErrorTypeMessage = "The runtime checks failed." ;
		break ;
	case 0x3:
		ErrorTypeMessage = "A failure occured during the initialization of SDL." ;
		break ;
	case 0x4:
		ErrorTypeMessage = "Setting up SDL failed." ;
		break ;
	case 0x5:
		ErrorTypeMessage = "A signal was sent to the program." ;
		break ;
	case 0x6:
		ErrorTypeMessage = "A function could not be registered in `atexit ( )`." ;
		break ;
	case 0x7:
		ErrorTypeMessage = "Some assets could not be loaded." ;
		break ;
	case 0x8:
		ErrorTypeMessage = "The game was crashed to prevent a loss of data." ;
		break ;
	case 0x9:
		ErrorTypeMessage = "The game has reached an undefined state and you probably lost your progress (sorry!)." ;
		break ;
	case 0xA:
		ErrorTypeMessage = "The game was lagging too much and was crashed to prevent abuse." ;
		break ;
	default:
		ErrorTypeMessage = "An unknown error type occured; you should probably file an issue." ;
		break ; }
	

	strcat ( CrashText , "Crash type: " ) ;
	strcat ( CrashText , ErrorTypeMessage ) ;
	va_list ap ;
	va_start ( ap , ExitCode ) ; 
	char * OtherInformation = va_arg ( ap , char * ) ;
	va_end ( ap ) ;
	strcat ( CrashText , "\nOther information:\n" ) ;
	if ( OtherInformation == NULL ) {
		strcat ( CrashText , "No further information was given." ) ; }
	else {
		strcat ( CrashText , OtherInformation ) ; }
	strcat ( CrashText , "\n\nYou may want to file an issue.\n\n" ) ;

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

	/* Exporting to a file isn't anything fancy.  We just put the crash text into a file named based on the time and date. */

	if ( ButtonID ) {
		char * CrashLogFilename = SDL_GetPrefPath ( "BlueManedHawk" , "Ex Nihilo vN 2" ) ;
		strcat ( CrashLogFilename , "Crash Logs/Crash " ) ;
		time_t Time = time ( NULL ) ;
		char * TimeString = ctime ( &Time ) ;
		strcat ( CrashLogFilename , TimeString ) ;
		strcat ( CrashLogFilename , ".txt" ) ;
		FILE * CrashLogFile = fopen ( CrashLogFilename , "w" ) ; /* Mmpgh. */
		if ( !CrashLogFile ) {
			SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Could not open crash log file for writing!" ) ; }
		else {
			fprintf ( CrashLogFile , "%s" , CrashText ) ; } }

	exit ( ExitCode ) ; }

/* Now, we get to the crash handler setup functions.  Since `signal ( )` doesn't accept an argument for the arguments to the pointed function, I have to declare a bunch of other functions for it to point to that are really just the `Crash ( )` function with arguments. */

_Noreturn void CrashFromAbnormalExit ( [[maybe_unused]] int Required ) {
	Crash ( 0x5 , "Abnormal program termination occurred." ) ; }

_Noreturn void CrashFromFloatingPointError ( [[maybe_unused]] int Required ) {
	Crash ( 0x5 , "A floating point error occurred." ) ; }

_Noreturn void CrashFromIllegalOperation ( [[maybe_unused]] int Required ) {
	Crash ( 0x5 , "An illegal operation was performed." ) ; }

_Noreturn void CrashFromInterruption ( [[maybe_unused]] int Required ) {
	Crash ( 0x5 , "The program was interrupted." ) ; }

_Noreturn void CrashFromSegfault ( [[maybe_unused]] int Required ) {
	Crash ( 0x5 , "A segfault occurred." ) ; }

_Noreturn void CrashFromTermination ( [[maybe_unused]] int Required ) {
	Crash ( 0x5 , "The program was terminated." ) ; }

 void CrashHandlerSetup ( void ) {
	signal ( SIGABRT , CrashFromAbnormalExit ) ;
	signal ( SIGFPE , CrashFromFloatingPointError ) ;
	signal ( SIGILL , CrashFromIllegalOperation ) ;
	signal ( SIGINT , CrashFromInterruption ) ;
	signal ( SIGSEGV , CrashFromSegfault ) ;
	signal ( SIGTERM , CrashFromTermination ) ; }

#endif/*ndef CRASH_H*/

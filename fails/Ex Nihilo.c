/* Table of Contents
 * 5 — Introductory Paragraph
 * 22 — Preprocessing
 * 	22 — OS Check
 *	30 — Inclusions
 * 35 — `main ( )`
 * 	39 — Setup
 * 		41 — Platform Verification
 *		106 — Initial battery verification
 *		166 — Debug Mode Check
 * */

/* Hello, and welcome to the source code for Ex Nihilo!
 *
 * Ex Nihilo is written in C.  For information on the C Programming Language, please check out the latest publicly available draft at `http://www.open-std.org/JTC1/SC22/WG14/www/docs/n2596.pdf`.  This isn't really the best source to learn the language, however, as it's a reference manual.  Unfortunately, there is no official user manual, and a lot of user manuals I've found tend to teach things completely incorrectly.  For this reason, I'll explain throughout the code a lot of things which will seem really obvious to experienced C programmers.  I'll try not to be redundant, though, and you'll be expected to have this specification on hand.
 *
 * This project also uses Simple DirectMedia Layer, or SDL.  The wiki for this is available at `https://wiki.libsdl.org/`.  It's overall a pretty good wiki, but it is still a reference manual, so the same problems as above appply, with me using the same solutions.
 *
 * This project also uses some extensions to SDL.  These and their documentation are listed below:
 *
 * - SDL_image is used so that I don't have to deal with BMPs.  Its documentation is at `https://libsdl.org/projects/SDL_image/docs/index.html`.
 * - SDL_mixer is used so that I don't have to deal with WAVs and manually combining audio.  Its documentation is available at `https://libsdl.org/projects/SDL_mixer/docs/index.html`.
 * - SDL_ttf is used so that I don't need to create a manual text writing system, which I tried and failed to do once.  Its documentation is available at `https://libsdl.org/projects/SDL_ttf/docs/index.html`.
 *
 * Again, the same problems apply, and the same solutions are used.
 *
 * :-) */

/* First, we need to make sure that this isn't being compiled for a bad system.  As far as I know, the only one I can check for is Windows.  However, I can check for others outside of preprocessing. */

#if defined WIN32 || defined _WIN32 || defined WIN64 || defined _WIN64
# error "It looks like you are attempting to compile this for a Windows system.  Please do not do this.  For more information on why I don't want this, see the non-binding section of the License."
#endif

/* We now need to include the libraries we're going to use.  This includes stuff from the C Standard Library (see the specification for more information) as well as SDL and the extensions we're using. */

#include "SDL.h"

/* The main function is the heart of the program, and is the function called at startup.  Its arguments are used for the arguments given to the program when it's called from the command line.  Currently, I've set things up so that the program will crash if given any arguments, _unless_ it's a single argument that corresponds to a password for accessing the debug mode.  The names for these arguments can be anything, but I've decided to go with the names given in the specification. */

int main ( int argc , char * argv[] ) {

/* We first need to verify the system that this software is running on.  The `SDL_GetPlatform` function is used for this.  It's run once, the result is stored, and then some checks are run on that result.  This is done so that we don't need to call the function for each check.
 *
 * Something important to be said here is that the `SDL_LogSetAllPriority ( )` function doesn't say what it says in the documentation _at all_.  What it actually does is that it sets things up so that any message with a priority _below_ that of what's given to the function is hidden.  I have literally zero clue why, but it does can be have useful, as it means I can hide verbose and debug logs when the game is outside of debug mode.  So that's neat.
 *
 * I'm using `strstr ( )` here because I can't figure out what `strcmp ( )`, which seems like it would be the thing for this, actually does, or how its useful, and `strstr ( )` _seems_ like it would be useful enough.  Also, the SDL wiki makes it seem like maybe these won't be exact matches, particularly in the case of the unknown?  I honestly don't know.
*/

SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_VERBOSE ) ;
SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Verifying OS…" ) ;
const char * Platform = SDL_GetPlatform ( ) ;
if ( strstr ( Platform , "Linux" ) != NULL ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "OS verified!  Continuing as normal." ) ; }
else if ( strstr ( Platform , "Unknown" ) != NULL ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_WARN , "Could not determine OS.  Warning user…" ) ;

	// Complex message boxes are kinda weird, and you should probably just read the SDL Wiki pages on them, since I do not want to have to explain them here. //
	
	int OSWarningMessageBoxButton = 0 ;
	SDL_MessageBoxButtonData OSWarningMessageBoxButtonData[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT | SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT , 0 , "Nevermind." } ,
		{ 0 , 1 ,\
			"I know what\n\
			I'm doing!" } } ;
	SDL_MessageBoxData OSWarningMessageBoxData = {
		SDL_MESSAGEBOX_WARNING ,
		NULL ,
		"OS Unverifiable!" ,
		"Your operating system could not be verified.  Please\n\
		keep in mind that this software was designed for a\n\
		Linux desktop; it may or may not work correctly on\n\
		your system.\n\
		\n\
		Are you sure you want to continue?" ,
		2 ,
		OSWarningMessageBoxButtonData ,
		NULL } ;
	SDL_ShowMessageBox ( &OSWarningMessageBoxData , &OSWarningMessageBoxButton ) ;
	if ( OSWarningMessageBoxButton ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_INPUT , SDL_LOG_PRIORITY_INFO , "User has confirmed that they know what they're doing.  Continuing as normal." ) ; }
	else {
		SDL_LogMessage ( SDL_LOG_CATEGORY_INPUT , SDL_LOG_PRIORITY_CRITICAL , "User has quit; crashing program." ) ;
		return 0x05 ; } }
else if ( strstr ( Platform , "Android" ) != NULL ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_WARN , "User is on Android.  Hopefully, this was distributed through ethical means; assuming good faith." ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "You are on Android" ,\
			"You appear to be playing this game on Android.  This\n\
			is designed for desktop Linux, and it may not work\n\
			correctly on Android.\n\
			\n\
			Additionally, please make sure you didn't use Google\n\
			Play to obtain this software, and instead used something\n\
			more ethical, like F-Droid.  This can't be checked for,\n\
			so good faith will be assumed.", NULL ) ; }
else if ( strstr ( Platform , "Windows" ) != NULL || strstr ( Platform , "Mac OS X" ) != NULL || strstr ( Platform , "iOS" ) != NULL ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_CRITICAL , "Invalid OS detected!  Crashing software." ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_ERROR , "Invalid OS!" ,\
			"You appear to be playing on a bad operating\n\
			system.  Please do not do this!  For more\n\
			information on why I don't want this, see the\n\
			non-binding section of the license.\n\
			\n\
			The program will now crash." , NULL ) ;
	return 0x45 ; }

/* We now need to look at the battery level to make sure that it's worth it to run the program.  I've decided to do things as such:
 *
 * - If the battery is nonexistent, don't do anything, and don't run any rechecks (whether or not to do this is indicated by the `BatteryChecks` bool).
 * - If the battery is plugged in, don't do anything, but run rechecks.
 * - If the battery is not plugged in, check the battery percentage and time remaining, then…
 * 	- If the battery has less than 15 minutes left, crash the program.
 * 	- If the battery has less than 15% left, crash the program.
 * 	- If one of these can't be determined, warn the user accordingly, but continue while running rechecks.
 * 	- Otherwise, warn the user that they may want to plug in if they intend to play for a while, but continue while rechecks.
 * - If the battery state can't be determined, warn the user, but continue while running rechecks.
 *
 * One thing that I find somewhat weird is that the `SDL_GetPowerInfo ( )` function puts values both in its arguments _and_ in its return value.  This seems strange to me; after all, wouldn't it have been simpler to just return a struct with all of this information?  It just seems bizzare to me.  Oh well. */

SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Checking battery…" ) ;
SDL_PowerState PowerState = SDL_POWERSTATE_UNKNOWN ;
int BatterySeconds = -1 ;
int BatteryPercentage = -1 ;
_Bool BatteryRechecks = 1 ;
PowerState = SDL_GetPowerInfo ( &BatterySeconds , &BatteryPercentage ) ;
if ( PowerState == SDL_POWERSTATE_NO_BATTERY ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_INFO , "No battery in system; will not run rechecks." ) ;
	BatteryRechecks = 0 ; }
else if ( PowerState == SDL_POWERSTATE_CHARGING || PowerState == SDL_POWERSTATE_CHARGED ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_INFO , "Battery is plugged in; rechecks will be run." ) ; }
else if ( PowerState == SDL_POWERSTATE_ON_BATTERY ) {
	if ( BatterySeconds == -1 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_WARN , "Could not determine time left on battery; warning user." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Could not determine time left on battery" , "The time left on your battery could not be determined.  Please determine this and ensure it's okay before continuing." , NULL ) ; }
	else if ( BatteryPercentage == -1 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_WARN , "Could not determine battery percentage left; warning user." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Could not determine percentage left on battery" , "The percentage left on your battery could not be determined.  Please determine this and ensure it's okay before continuing." , NULL ) ; }
	else if ( BatterySeconds < 900 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_CRITICAL , "Too little time left on battery; crashing program." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_ERROR , "Battery life too short" ,\
				"You appear to have less than 15\n\
				minutes of battery life remaining.\n\
				Since this probably isn't enough\n\
				time to do anything useful, the program\n\
				will crash now." , NULL ) ;
		return 0x43 ; }
	else if ( BatteryPercentage < 15 ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_CRITICAL , "Too little percentage left on battery; crashing program." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_ERROR , "Battery percentage too little" ,\
				"You appear to have less than 15\n\
				percent of your battery remainging.\n\
				Since this probably isn't enough\n\
				to do anything useful in the time\n\
				this gives you, the program will\n\
				will crash now." , NULL ) ;
		return 0x43 ; }
	else {
		SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_INFO , "Battery seems okay; will do rechecks." ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "You are on battery" , "If you intend to play for a while, you may want to plug in your battery." , NULL ) ; } }
else {
	SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_WARN , "Battery state could not be determined; warning user." ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Battery state indeterminable" , "Your battery state could not be determined.  Pease make sure everything's okay before continuing." , NULL ) ; }



/* We now need to look at the arguments given to the program.  If there's a singular argument that matches a password, debug mode will be turned on (indicated by setting the variable `Debug` to 1).  If there's too many arguments or the password is wrong, it will crash.  Otherwise, it'll start normally.
 *
 * My intent is to figure out how to implement a checksum here and store that checksome instead…y'know, like a normal password system.  However, every checksum specification I've found has failed to actually explain how the checksum actually works. */

_Bool Debug = 0 ;
SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_VERBOSE ) ;
SDL_LogVerbose ( SDL_LOG_CATEGORY_INPUT , "Checking program arguments…" ) ;
if ( argc > 2 ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_ERROR , SDL_LOG_PRIORITY_CRITICAL , "Too many arguments; crashing program." ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_ERROR , "Too many arguments" , "You have given too many arguments to the program.  Please start the program again without arguments." , NULL ) ;
	return 0x46 ; }
else if ( argc < 2 ) {
	SDL_LogMessage ( SDL_LOG_CATEGORY_INPUT , SDL_LOG_PRIORITY_VERBOSE , "Debug mode not enabled; hiding verbose logs and continuing game as normal." ) ;
	SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_INFO ) ; }
else {
	SDL_LogMessage ( SDL_LOG_CATEGORY_TEST , SDL_LOG_PRIORITY_DEBUG , "Argument given: %s.  Sending confirmation to user…" , argv[1] ) ;
	int DebugModeMessageBoxButton = 0 ;
	SDL_MessageBoxButtonData DebugModeMessageBoxButtonData[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT | SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT , 0 , "Hell nah!" } ,
		{ 0 , 1 , "Hell yeah!" } } ;
	SDL_MessageBoxData DebugModeMessageBoxData = {
		SDL_MESSAGEBOX_WARNING ,
		NULL ,
		"Debug Mode AAA—" ,
		"You have entered the password\n\
		for Debug Mode.  Are you sure \n\
		you want to do this?" ,
		2 ,
		DebugModeMessageBoxButtonData ,
		NULL } ;
	SDL_ShowMessageBox ( &DebugModeMessageBoxData , &DebugModeMessageBoxButton ) ;
	if ( DebugModeMessageBoxButton ) {
		SDL_LogMessage ( SDL_LOG_CATEGORY_INPUT , SDL_LOG_PRIORITY_DEBUG , "Debug mode confirmed.  Keeping verbose logs unless stated otherwise." ) ; 
		Debug = 1 ; }
	else {
		SDL_LogMessage ( SDL_LOG_CATEGORY_INPUT , SDL_LOG_PRIORITY_DEBUG , "Debug mode not confirmed; hiding verbose logs and continuing game as normal." ) ;
		SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_INFO ) ; } }

/* We now need to get the "pref path" (which is the place where we'll write files) and some other common paths, then store them so that we don't need to get them every time.  The paths we're getting include:
 *
 * - The pref path
 * - The assets location
 * - The saves location
 * - The preferences location */

SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Getting paths…" ) ;
char * PrefPath = SDL_GetPrefPath ( "BlueManedHawk" , "Ex Nihilo Development Stages 2" ) ;
SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Got Pref Path." ) ;
char AssetsLocation[256] ; /* That should be enough, right? */ strcpy ( AssetsLocation , PrefPath ) ; strcat ( AssetsLocation , "Assets/" ) ;
SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Got assets location." ) ;
char SavesLocation[256] ; strcpy ( SavesLocation , PrefPath ) ; strcat ( SavesLocation , "Saves/" ) ;
SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Got saves location." ) ;
char PreferencesLocation[256] ; strcpy ( PreferencesLocation , PrefPath ) ; strcat ( PreferencesLocation , "Preferences/" ) ;
SDL_LogMessage ( SDL_LOG_CATEGORY_SYSTEM , SDL_LOG_PRIORITY_VERBOSE , "Got preferences location." ) ;



return 0x00 ; }

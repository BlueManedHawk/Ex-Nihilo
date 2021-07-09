/* Table of Contents
 * --- --- --- --- --- ---
 * Line Number:  Item
 * === === === === === ===
 * */

/* Hello, and welcome to the source code of Ex Nihilo!
 *
 * This project uses C2X.  The latest public draft of this can be found at:
 * http://www.open-std.org/JTC1/SC22/WG14/www/docs/n2596.pdf
 *
 * This project uses SDL2.  The wiki for this can be found at:
 * https://wiki.libsdl.org
 *
 * This source code assumes that you have access to these places. */

/* The first thing we need to do is include our libraries.  The order of inclusion is mostly historical happenstance.  `SDL.h` is for SDL2 (although it doesn't do anything on its own, which is why the bit with `sdl2-config` is necessary in the compilation command), `stdlib.h` is for a lot of things, `stdbool.h` is to make the code look nicer, and `string.h` is to manage strings.  Most of these are explained exactly in ß7 of the C specification. */
#include "SDL.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* We now need to check the compilation environment to ensure that this isn't being compiled for a bad system. */

#if defined WIN32 || _WIN32 || WIN64 || _WIN64
#	error "It looks like you're trying to compile this for a Windows system.  Please do not do this.  For more information, see the non-binding section of `docs/LICENSE.md`.\n"
#endif // defined WIN32 || _WIN32 || WIN64 || _WIN64

/* Now comes the main function. */

int main ( ) {

/* We need to set the log priority.  I have no idea why I need to do this, but if I don't, logs don't show up. */

SDL_LogSetAllPriority ( SDL_LOG_PRIORITY_INFO ) ;

/* We need to get the platform this is being played on, halt program execution if it's a bad one, and warn the user if it's a potentially concerning one.  This is mostly just a series of checks using the `strcmp` function.  The `strcmp` function from `string.h` is used to compare the string gotten from `SDL_GetPlatform`, because strings are actually arrays of characters, and arrays are actually combinations of pointers, so they can't be compared directly…it's a whole ordeal, but in any case, we only need to know how it works, not necessarily why, to make good use of it, a bit like gravity, slipperiness, and the electrostatic force.
 *
 * A separate variable is used to store the plaform so that we don't need to ask for it for every comparison.  Also, I'm not quite sure what the `flags` of `SDL_ShowSimpleMessageBox` actually <F31><F31><F31> do.*/

SDL_LogInfo ( SDL_LOG_CATEGORY_ASSERT , "Verifying OS…" ) ;
char Platform[] = SDL_GetPlatform ( ) ;
if ( strcmp ( Platform , "Windows" )  == 0 || strcmp ( Platform , "Mac OS X" ) == 0 || strcmp ( Platform , "iOS" ) == 0 ) {
	SDL_LogError ( SDL_LOG_CATEGORY_ERROR , "Invalid OS; program execution stoped for safety reasons.\n" ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_ERROR , "Invalid OS" ,\
	"For safety reasons, program execution has\n\
	been stopped, as it looks like you're trying\n\
	to play on an invalid OS.  Please do not do\n\
	this.  For more information, see the non-binding\n\
	section of `docs/LICENSE.md`.\n\nExit Code: 0x05." , NULL ) ;
	return 0x05 ; }
else if ( strcmp ( Platform , "Linux" ) == 0 ) {
	SDL_LogInfo ( SDL_LOG_CATEGORY_ASSERT , "OS verified!\n" ) ; }
else if ( strcmp ( Platform , "Android" ) ) {
	SDL_LogWarn ( SDL_LOG_CATEGORY_ASSERT , "Software may have been distributed through bad channels; good faith will be assumed.\n" ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Potential Distribution Concern" ,\
	"This software may have been distributed through\n\
	concerning channels, such as Google Play.  Please\n\
	see the non-binding section of `docs/LICENSE.md`\n\
	for details.  However, good faith will be assumed,\n\
	and program execution will continue." , NULL ) ; }
else {
	SDL_LogWarn ( SDL_LOG_CATEGORY_ASSERT , "OS could not be verified; good faith will be assumed." ) ; 
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "OS Inverifiable" ,\
	"Your OS could not be verified.  Please\n\
	see the non-binding section of `docs/LICENSE.md`\n\
	for details.  However, good faith will be assumed,\n\
	and program execution will continue." , NULL ) ; }

/* We now need to check the state of the battery.  This block of code works as such:
 *
 * - If the system doesn't use a battery, don't do anything.
 * - If the system uses a battery, but it's plugged in, don't do anything at first, but check on the battery state every so often (done in the main loop).
 * - If the system uses a battery and it isn't plugged in:
 * 	- If the percentage couldn't be determined, show the user a warning, but assume the battery is fine.
 * 	- If the percentage is below fifteen, show the user a warning, then exit the game.
 * 	- Otherwise, do nothing at first, but check on the battery every so often (done in the main loop).
 * - If the battery state couldn't be determined, show the user a warning, but assume the battery is fine.
 *
 * `Battery` states whether the battery should be checked every so often in the main loop.  `BatteryPercent` stores the percentage of battery remaining.  `PowerState` stores the state of the battery (see the SDL2 wiki's article on the `SDL_PowerState` type. */

SDL_LogInfo ( SDL_LOG_CATEGORY_ASSERT , "Checking for battery…" ) ;
bool Battery = NULL ;
int BatteryPercent = 0 ;
SDL_PowerState PowerState = SDL_GetPowerInfo ( NULL , &BatteryPercent ) ;
if ( PowerState == SDL_POWERSTATE_NO_BATTERY ) {
	SDL_LogInfo ( SDL_LOG_CATEGORY_ASSERT , "System does not use a battery.\n" ) ;
	Battery = 0 ; }
else if ( PowerState == SDL_POWERSTATE_CHARGING ||PowerState == SDL_POWERSTATE_CHARGED ) {
	SDL_LogInfo ( SDL_LOG_CATEGORY_ASSERT , "Battery exists, but is plugged in; initial check not necessary.\n" ) ;
	Battery = 1 ; }
else if ( PowerState == SDL_POWERSTATE_ON_BATTERY ) {
	SDL_LogInfo ( SDL_LOG_CATEGORY_ASSERT , "Battery exists and is not plugged in; initial check will be performed.\n" ) ;
	Battery = 1 ;
	SDL_LogInfo ( SDL_LOG_CATEGORY_ASSERT , "Checking battery percentage…" ) ;
	if ( BatteryPercent == -1 ) {
		SDL_LogWarn ( SDL_LOG_CATEGORY_ASSERT , "Battery percentage could not be determined; assuming good battery.\n" ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Battery Percentage Indeterminable" ,\
		"If you are low on battery, you\n\
		are encouraged to plug it in\n\
		before playing to prevent data loss." , NULL ) ;
		Battery = 0 ; }
	else if ( BatteryPercent <= 15 ) {
		SDL_LogError ( SDL_LOG_CATEGORY_ASSERT , "Battery too low; program execution stopped to prevent data loss.\n" ) ;
		SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_ERROR , "Battery Too Low" ,\
		"Your battery is low.  To prevent\n\
		loss of data, program execution has\n\
		been suspended.  Please plug in your\n\
		battery.\n\nExit Code: 0x05" , NULL ) ;
		return 0x05 ; }
	else {
		SDL_LogInfo ( SDL_LOG_CATEGORY_ASSERT , "Battery is fine.\n" ) ; } }
else {
	SDL_LogWarn ( SDL_LOG_CATEGORY_ASSERT , "Battery state could not be determined; assuming good battery.\n" ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Battery State Indeterminable" ,\
	"If you are low on battery,\n\
	you are encouraged to plug\n\
	it in before playing to prevent\n\
	data loss." , NULL ) ;
	Battery = 0 ; }

/* We now need to ask the user whether they want fullscreen.  Most of this is just declaring a bunch of variables for the messagebox.  This is very weird and complicated, and it has to be done in a bunch of separate variables instead of being fed as constants to the function.  Please look at the SDL2 wiki.
 *
 * I do plan to eventually implement double and quadruple windowed resolutions, so that people on unusually large monitors can play in windowed mode without having a minuscule window. */

SDL_LogInfo ( SDL_LOG_CATEGORY_INPUT , "Requesting whether to use fullscreen…" ) ;
int FullscreenChoice = 0 ;
SDL_MessageBoxButtonData MessageBoxButtonData[] = { {
	SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT ,
	0 ,
	"No." } , {
	SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT ,
	1 ,
	"Yes." } } ;
SDL_MessageBoxColorScheme MessageBoxColorScheme = { {
	{ 0x70 , 0x70 , 0x70 } ,
	{ 0x10 , 0x10 , 0x20 } ,
	{ 0x10 , 0x10 , 0x20 } ,
	{ 0x90 , 0x90 , 0x90 } ,
	{ 0xB0 , 0xB0 , 0xB0 } } } ;
SDL_MessageBoxData MessageBoxData = {
		SDL_MESSAGEBOX_INFORMATION ,
		NULL ,
		"Would you like fullscreen?" ,
		"Do you want to play in fullscreen?  This is highly recommended\n\
		if you play on a weirdly high resolution, such as one above 1080p.\n\
		(In any case, the window can be minimized during normal gameplay\n\
		with the eleventh Function key.)" ,
		2 ,
		MessageBoxButtonData ,
		&MessageBoxColorScheme } ;
if ( SDL_ShowMessageBox ( &MessageBoxData , &FullscreenChoice ) < 0 ) {
	SDL_LogError ( SDL_LOG_CATEGORY_ERROR , "SDL could not create the fullscreen request message box!  Here's what it says:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
Uint32 WindowFlags = FullscreenChoice ? SDL_WINDOW_FULLSCREEN : 0 ;
FullscreenChoice = 0 ;
SDL_LogInfo ( SDL_LOG_CATEGORY_INPUT , "Fullscreen information recieved and applied.\n" ) ;

/* We now need to check for the assets archive.  Since I want this game to be as plug-and-play as possible, I'm relying on the user putting the assets archive in the correct place.  After the assets archive is in the correct place, it's decompressed and untarred, and the assets are then moved to /tmp/ for faster access (since /tmp/ is usually stored in RAM).
 *
 * At a certain point, this block of code uses the `system` function to decompress and untar the Assets file.  Out of all of the things in this program, this is the thing I regret the most.  However, I feel that any better solution would require either overcomplicating the program with multiple files, or using a decompression library with completely impenetrable documentation.  Therefore, I have chosen to use this solution.  In any case, this is fairly constant, so I don't think there's too much room for security problems; however, I feel that this is the most likely area for a security issue to occur. */

SDL_LogInfo ( SDL_LOG_CATEGORY_SYSTEM , "Checking for assets…" ) ;
char UserDirectory[] = SDL_GetPrefPath ( "BlueManedHawk" , "Ex Nihilo" ) ;
char UserAssets[] = NULL ;
strcpy ( UserAssets , UserDirectory ) ;
strcat ( UserAssets , "Assets/Assets_N.1-pre+1.txz" ) ;
FILE * UserAssetsFile = fopen ( UserAssets , "r" ) ;
while ( UserAssetsFile == NULL ) {
	SDL_LogWarn ( SDL_LOG_CATEGORY_SYSTEM , "Could not find assets; requesting user move them to the appropriate place.\n" ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_WARNING , "Assets not available" ,\
	"Please move the Assets archive for\n\
	this version of the game to\n\
	`%s`." , UserAssets ) ;
	UserAssetsFile = fopen ( UserAssets , "r" ) ; }
SDL_LogInfo ( SDL_LOG_CATEGORY_SYSTEM , "Assets are in the appropriate place.\n" ) ;
char TmpAssets[] = NULL ;
strcpy ( TmpAssets , "/tmp/Ex Nihilo/Assets/" ) ;
FILE * TmpAssetsFile = fopen ( TmpAssets , "w" ) ;
system ( "tar xJf %s %s" , UserAssets , TmpAssets ) ; // Here's that "thing I regret the most" I was talking about.
fclose ( UserAssetsFile ) ;
remove ( UserAssetsFile ) ;
SDL_Free ( UserAssets ) ;

/* Finally, after all that, we can now get around to initializing SDL.  This program uses the video, audio, and timer subsystems for…video, audio, and timers, so it initializes those.  Once those are initialized, the function `SDL_Quit` is registered to occur if the game is terminated.  If it can't register that (which REALLY shouldn't happen!), then the game is terminated immediatlely with a warning to the user to report a security issue if it occurs repeatedly. */

SDL_LogInfo ( SDL_LOG_CATEGORY_APPLICATION , "Initializing SDL…" ) ;
if ( SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) != 0 ) {
	SDL_LogError ( SDL_LOG_CATEGORY_ERROR , "SDL failed to initialize!  Here's what it says:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
SDL_LogInfo ( SDL_LOG_CATEGORY_APPLICATION , "SDL has been initialized.\n" ) ;
SDL_LogInfo ( SDL_LOG_CATEGORY_SYSTEM , "Registering quit in exit function…" ) ;
if ( atexit ( SDL_Quit ) != 0 ) {
	SDL_LogError ( SDL_LOG_CATEGORY_ERROR , "Could not register quit function, terminating program." ) ;
	SDL_ShowSimpleMessageBox ( SDL_MESSAGEBOX_ERROR , "Unable to register quit function" ,\
	"SDL's quit function could not be registered.\n\
	This is REALLY BAD.  Please report a security\n\
	problem to me directly (SEE `docs/SECURITY.md`)\n\
	if this occurs repeatedly.  The game has been\n\
	exited for safety purposes.\n\nExit Code: 0x41" , NULL ) ;
	SDL_QuitSubSystem ( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) ;
	SDL_Quit ( ) ;
	return 0x41 ; }
SDL_LogInfo ( SDL_LOG_CATEGORY_SYSTEM , "Quit function registered.\n" ) ;

/* We now need to create the window and renderer.  For some reason, doing this creates two bonus messages in the log.  I have no idea where those come from. 
 *
 * This block references the `WindowFlags` variable from earlier. */

SDL_LogInfo ( SDL_LOG_CATEGORY_RENDER , "Creating window and renderer…" ) ;
SDL_Window * Window = NULL ;
SDL_Renderer * Renderer = NULL ;
if ( SDL_CreateWindowAndRenderer ( 640 , 480 , WindowFlags, &Window, &Renderer ) < 0 ) {
	SDL_LogError ( SDL_LOG_CATEGORY_ERROR , "SDL could not create the window and renderer!  Here's what it says:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
SDL_LogInfo ( SDL_LOG_CATEGORY_CUSTOM , "Note from the author:  I have literally no idea what those two messages above this one are, or where they came from.  They certainly aren't mine.  Anyway…" ) ;
SDL_LogInfo ( SDL_LOG_CATEGORY_RENDER , "Window and renderer created.\n" ) ;

/* Now, we need to clean everything up.*/

SDL_DestroyRenderer ( Renderer ) ;
SDL_DestroyWindow ( Window ) ;
SDL_QuitSubSystem ( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) ;
SDL_Quit ( ) ;
return 0x00 ; }

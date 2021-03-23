/* Table of Contents:
 *
 * - Line 15: Introduction
 * - Line 37: Setup
 * - Line 39: Libraries 
 * - Line 53: DrawText function
 * - Line 81: DrawText's MASSIVE SWITCH STATEMENT
 * - Line 370: The rest of DrawText
 * - Line 384: The main function
 * - Line 388: Debugging things
 * - Line 394: SDL setup
 * - Line 431: Testing things
 * - Line 460: Primary game loop */

/* Hello, and welcome to the source code of Ex Nihilo!
 *
 * The environment I use to modify this file is Neovim in the Kitty terminal emulator with the font Fira Code.  I suggest that you do the same for viewing this file.
 *
 * While reading this file, you may notice certain questionable things.  You may want to look at STYLE.md to understand these things and the reason they exist.
 *
 * It is also important to note that this file is normally compiled with clang for C2x.  This file is based off of the latest publically available draft for C2x, which is N2596.  You can get is here:
 *
 * http://www.open-std.org/JTC1/SC22/WG14/www/docs/n2596.pdf 
 *
 * You can tell Clang to compile with C2x with the argument -std=c2x.  You'll need Clang 11 to do this.
 *
 * On the topic of arguments, I use the arguments -Wall -Wextra -pendantic -Werror for compiling this (in addition to -std=c2x).  Depending on who you ask, this may be considered overkill.  In any case, these only affect what messages the compiler gernerates, and theoretically shouldn't change the outputted ELF file.
 *
 * At certain points in the code, a `return` statement will be used to terminate the process with a specific code.  Information on these codescan be found in TROUBLESHOOTING.md.
 *
 * Licensing details on this code can be found in LICENSE.md.
 *
 * This game uses SDL and its libraries.  While I do my best to explain what these things does, it would still do you some good to look at the SDL wiki, available at https://wiki.libsdl.org.
 *
 * To link to SDL2, you need to append `sdl2-config --cflags --libs`, **with the graves**, to your compiling command. */

/* We begin with the setup. */

/* I need to add some of the C Standard Library for this to work.  The specific libraries I use from the CSL are used for the following purposes:
 *
 * - `<stdio.h>` is used for basic input-output systems, such as `printf`.
 * - `<stdlib.h>` is mostly used for the `atexit` function. 
 * - `<string.h>` is used to faff about with strings. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Now, I need to add the SDL library. */

#include "SDL.h"

/* Drawing text to the screen is a pretty common thing to need to do, so I've created this function for it.  It takes two points for the location of the top-left corner of the text, a string to use for the text, where to find the text images, and where to place the text.  To prevent overflow, the function will automatically newline at the boundary of the window. */

void DrawText ( int LocationX , int LocationY , int MaximumLocationX , const char *Text , char *AssetsLocation , SDL_Renderer *Renderer ) {

/* We first need to setup all of the variables used in this function.  This includes storing the original LocationX for later, creating some strings for storage of characters and the locations thereof, defining the height and width of the rectangle where the characters will be placed, and creating a surface and texture for the characters. */

int OriginalLocationX = LocationX ;
char CurrentCharacter[1] = " " ;
char CharacterImageLocation[255] = " " ;
SDL_Rect CharacterDestination ;
CharacterDestination.w = 8 ;
CharacterDestination.h = 8 ;
SDL_Surface *CharacterSurface ;
SDL_Texture *CharacterTexture ;

/* We then need to cycle through the characters in the string given, then output each of them in the appropriate place. */

for ( int i = 0 ; Text[i] != '\0' ; i++ ) {
	CurrentCharacter[0] = Text[i] ;
	if ( ( LocationX + 16 ) > MaximumLocationX ) {
		LocationY += 8 ;
		LocationX = OriginalLocationX ; }
	else if ( i != 0 ) {
		LocationX += 8 ; } 
	CharacterDestination.x = LocationX ;
	CharacterDestination.y = LocationY ;
	strcpy ( CharacterImageLocation , AssetsLocation ) ;
	
	/* And now it's time for this massive switch statement!  Yes, I *did* try that thing that seems like such an obvious way to do this!  It didn't do jack-sh*t!  Why‽  I haven't a clue!  (If you want to skip this, jump to Line 370. */

	switch ( CurrentCharacter[0] ) {
	case 0x20 :
		strcat ( CharacterImageLocation , "space.bmp" ) ;
		break ;
	case 0x21 :
		strcat ( CharacterImageLocation , "exclamation.bmp" ) ;
		break ;
	case 0x22 :
		strcat ( CharacterImageLocation , "doublequote.bmp" ) ;
		break ;
	case 0x23 :
		strcat ( CharacterImageLocation , "hash.bmp" ) ;
		break ;
	case 0x24 :
		strcat ( CharacterImageLocation , "dollar.bmp" ) ;
		break ;
	case 0x25 :
		strcat ( CharacterImageLocation , "pernif.bmp" ) ;
		break ;
	case 0x26 :
		strcat ( CharacterImageLocation , "ampersand.bmp" ) ;
		break ;
	case 0x27 :
		strcat ( CharacterImageLocation , "singlequote.bmp" ) ;
		break ;
	case 0x28 :
		strcat ( CharacterImageLocation , "openparen.bmp" ) ;
		break ;
	case 0x29 :
		strcat ( CharacterImageLocation , "closeparen.bmp" ) ;
		break ;
	case 0x2A :
		strcat ( CharacterImageLocation , "asterisk.bmp" ) ;
		break ;
	case 0x2B :
		strcat ( CharacterImageLocation , "plus.bmp" ) ;
		break ;
	case 0x2C :
		strcat ( CharacterImageLocation , "comma.bmp" ) ;
		break ;
	case 0x2D :
		strcat ( CharacterImageLocation , "hyphen.bmp" ) ;
		break ;
	case 0x2E :
		strcat ( CharacterImageLocation , "period.bmp" ) ;
		break ;
	case 0x2F :
		strcat ( CharacterImageLocation , "foreslash.bmp" ) ;
		break ;
	case 0x30 :
		strcat ( CharacterImageLocation , "0.bmp" ) ;
		break ;
	case 0x31 :
		strcat ( CharacterImageLocation , "1.bmp" ) ;
		break ;
	case 0x32 :
		strcat ( CharacterImageLocation , "2.bmp" ) ;
		break ;
	case 0x33 :
		strcat ( CharacterImageLocation , "3.bmp" ) ;
		break ;
	case 0x34 :
		strcat ( CharacterImageLocation , "4.bmp" ) ;
		break ;
	case 0x35 :
		strcat ( CharacterImageLocation , "5.bmp" ) ;
		break ;
	case 0x36 :
		strcat ( CharacterImageLocation , "6.bmp" ) ;
		break ;
	case 0x37 :
		strcat ( CharacterImageLocation , "7.bmp" ) ;
		break ;
	case 0x38 :
		strcat ( CharacterImageLocation , "8.bmp" ) ;
		break ;
	case 0x39 :
		strcat ( CharacterImageLocation , "9.bmp" ) ;
		break ;
	case 0x3A :
		strcat ( CharacterImageLocation , "colon.bmp" ) ;
		break ;
	case 0x3B :
		strcat ( CharacterImageLocation , "semicolon.bmp" ) ;
		break ;
	case 0x3C :
		strcat ( CharacterImageLocation , "less.bmp" ) ;
		break ;
	case 0x3D :
		strcat ( CharacterImageLocation , "equals.bmp" ) ;
		break ;
	case 0x3E :
		strcat ( CharacterImageLocation , "more.bmp" ) ;
		break ;
	case 0x3F :
		strcat ( CharacterImageLocation , "question.bmp" ) ;
		break ;
	case 0x40 :
		strcat ( CharacterImageLocation , "at.bmp" ) ;
		break ;
	case 0x41 :
		strcat ( CharacterImageLocation , "A.bmp" ) ;
		break ;
	case 0x42 :
		strcat ( CharacterImageLocation , "B.bmp" ) ;
		break ;
	case 0x43 :
		strcat ( CharacterImageLocation , "C.bmp" ) ;
		break ; 
	case 0x44 :
		strcat ( CharacterImageLocation , "D.bmp" ) ;
		break ;
	case 0x45 :
		strcat ( CharacterImageLocation , "E.bmp" ) ;
		break ;
	case 0x46 :
		strcat ( CharacterImageLocation , "F.bmp" ) ;
		break ;
	case 0x47 :
		strcat ( CharacterImageLocation , "G.bmp" ) ;
		break ;
	case 0x48 :
		strcat ( CharacterImageLocation , "H.bmp" ) ;
		break ;
	case 0x49 :
		strcat ( CharacterImageLocation , "I.bmp" ) ;
		break ;
	case 0x4A :
		strcat ( CharacterImageLocation , "J.bmp" ) ;
		break ;
	case 0x4B :
		strcat ( CharacterImageLocation , "K.bmp" ) ;
		break ;
	case 0x4C :
		strcat ( CharacterImageLocation , "L.bmp" ) ;
		break ;
	case 0x4D :
		strcat ( CharacterImageLocation , "M.bmp" ) ;
		break ;
	case 0x4E :
		strcat ( CharacterImageLocation , "N.bmp" ) ;
		break ;
	case 0x4F :
		strcat ( CharacterImageLocation , "O.bmp" ) ;
		break ;
	case 0x50 :
		strcat ( CharacterImageLocation , "P.bmp" ) ;
		break ;
	case 0x51 :
		strcat ( CharacterImageLocation , "Q.bmp" ) ;
		break ;
	case 0x52 :
		strcat ( CharacterImageLocation , "R.bmp" ) ;
		break ;
	case 0x53 :
		strcat ( CharacterImageLocation , "S.bmp" ) ;
		break ;
	case 0x54 :
		strcat ( CharacterImageLocation , "T.bmp" ) ;
		break ;
	case 0x55 :
		strcat ( CharacterImageLocation , "U.bmp" ) ;
		break ;
	case 0x56 :
		strcat ( CharacterImageLocation , "V.bmp" ) ;
		break ;
	case 0x57 :
		strcat ( CharacterImageLocation , "W.bmp" ) ;
		break ;
	case 0x58 :
		strcat ( CharacterImageLocation , "X.bmp" ) ;
		break ;
	case 0x59 :
		strcat ( CharacterImageLocation , "Y.bmp" ) ;
		break ;
	case 0x5A :
		strcat ( CharacterImageLocation , "Z.bmp" ) ;
		break ;
	case 0x5B :
		strcat ( CharacterImageLocation , "openbracket.bmp" ) ;
		break ;
	case 0x5C :
		strcat ( CharacterImageLocation , "backslash.bmp" ) ;
		break ;
	case 0x5D :
		strcat ( CharacterImageLocation , "closebracket.bmp" ) ;
		break ;
	case 0x5E :
		strcat ( CharacterImageLocation , "caret.bmp" ) ;
		break ;
	case 0x5F :
		strcat ( CharacterImageLocation , "underscore.bmp" ) ;
		break ;
	case 0x60 :
		strcat ( CharacterImageLocation , "grave.bmp" ) ;
		break ;
	case 0x61 :
		strcat ( CharacterImageLocation , "a.bmp" ) ;
		break ;
	case 0x62 :
		strcat ( CharacterImageLocation , "b.bmp" ) ;
		break ;
	case 0x63 :
		strcat ( CharacterImageLocation , "c.bmp" ) ;
		break ;
	case 0x64 :
		strcat ( CharacterImageLocation , "d.bmp" ) ;
		break ;
	case 0x65 :
		strcat ( CharacterImageLocation , "e.bmp" ) ;
		break ;
	case 0x66 :
		strcat ( CharacterImageLocation , "f.bmp" ) ;
		break ;
	case 0x67 :
		strcat ( CharacterImageLocation , "g.bmp" ) ;
		break ;
	case 0x68 :
		strcat ( CharacterImageLocation , "h.bmp" ) ;
		break ;
	case 0x69 :
		strcat ( CharacterImageLocation , "i.bmp" ) ;
		break ;
	case 0x6A :
		strcat ( CharacterImageLocation , "j.bmp" ) ;
		break ;
	case 0x6B :
		strcat ( CharacterImageLocation , "k.bmp" ) ;
		break ;
	case 0x6C :
		strcat ( CharacterImageLocation , "l.bmp" ) ;
		break ;
	case 0x6D :
		strcat ( CharacterImageLocation , "m.bmp" ) ;
		break ;
	case 0x6E :
		strcat ( CharacterImageLocation , "n.bmp" ) ;
		break ;
	case 0x6F :
		strcat ( CharacterImageLocation , "o.bmp" ) ;
		break ;
	case 0x70 :
		strcat ( CharacterImageLocation , "p.bmp" ) ;
		break ;
	case 0x71 :
		strcat ( CharacterImageLocation , "q.bmp" ) ;
		break ;
	case 0x72 :
		strcat ( CharacterImageLocation , "r.bmp" ) ;
		break ;
	case 0x73 :
		strcat ( CharacterImageLocation , "s.bmp" ) ;
		break ;
	case 0x74 :
		strcat ( CharacterImageLocation , "t.bmp" ) ;
		break ;
	case 0x75 :
		strcat ( CharacterImageLocation , "u.bmp" ) ;
		break ;
	case 0x76 :
		strcat ( CharacterImageLocation , "v.bmp" ) ;
		break ;
	case 0x77 :
		strcat ( CharacterImageLocation , "w.bmp" ) ;
		break ;
	case 0x78 :
		strcat ( CharacterImageLocation , "x.bmp" ) ;
		break ;
	case 0x79 :
		strcat ( CharacterImageLocation , "y.bmp" ) ;
		break ;
	case 0x7A :
		strcat ( CharacterImageLocation , "z.bmp" ) ;
		break ;
	case 0x7B :
		strcat ( CharacterImageLocation , "openbrace.bmp" ) ;
		break ;
	case 0x7C :
		strcat ( CharacterImageLocation , "polebar.bmp" ) ;
		break ;
	case 0x7D :
		strcat ( CharacterImageLocation , "closebrace.bmp" ) ;
		break ;
	case 0x7E :
		strcat ( CharacterImageLocation , "tilde.bmp" ) ;
		break ; }

	/* Once we've gotten the character image we need, we then need to load the image onto a surface, then load the surface onto the texture, then copy the texture to the screen.  After the loop is finished, the characters will then be presented to the screen. */

	CharacterSurface = SDL_LoadBMP ( CharacterImageLocation ) ;
	if ( CharacterSurface == NULL ) {
		printf ( "SDL failed to load %s!  Thankfully, it was nice enough to give this error:\n%s\n" , CharacterImageLocation , SDL_GetError ( ) ) ; }
	CharacterTexture = SDL_CreateTextureFromSurface ( Renderer , CharacterSurface ) ;
	SDL_FreeSurface ( CharacterSurface ) ;
	if ( CharacterTexture == NULL ) {
		printf ( "SDL failed to apply the character surface to the character texture!  Thankfully, it was kind enough to give this error:\n%s\n" , SDL_GetError ( ) ) ; }
	SDL_RenderCopy ( Renderer , CharacterTexture , NULL , &CharacterDestination ) ; }

SDL_DestroyTexture ( CharacterTexture ) ; }

/* The main function contains the code, except for functions.  Why?  I don't know.  In any case, it takes a couple of arguments, these being an integer `argc` and a character pointer array `argv`.  These contain the count of arguments to the program and the arguments to the program, respecively.  Currently, I'm using this as debug functionality to tell the user that the program doesn't take any arguments.  Additionally, `argc` has the `maybe_unused` atribute, because I haven't thought of a reason to use it. */

int main ( [[maybe_unused]] int argc , char *argv[] ) {

/* We now need to determine whether there were any arguments, and to immediatly exit if there were, with a message telling people to try again without supplying arguments.  Thankfully, there's a pretty simple way to do this:  the C standard (see line 7) specifies that `argv[argc]` needs to be null; therefore, if there are any arguments, `argc` will be set to something other than 0, and `argv[1]` will not be null.  If that's true, then the program will terminate with an exit code of 0x60;  otherwise, it will terminate with an exit code of zero. */

if ( argv[1] != NULL ) {
	printf ( "Hey, this program isn't meant to take any arguments.  Try running it again without them.\n" ) ;
	return 0x60 ; }

/* Now, we need to declare some variables. */

char AssetsLocation[255] = "/home/";
const char *CurrentUser = getenv ( "USER" ) ;
strcat ( AssetsLocation , CurrentUser ) ;
strcat ( AssetsLocation , "/.ExNihilo/Assets/" ) ;
char ImageLocationLocation[255] = " " ;
_Bool Quit = 0 ;
SDL_Event CurrentEvent ;
double PreviousNifth [[maybe_unused]] = 0.0 ;
int WindowFlags = 0 ;
SDL_Rect PlayerCharacterDestinationRectangle ;
PlayerCharacterDestinationRectangle.x = 128 ;
PlayerCharacterDestinationRectangle.y = 128 ;
PlayerCharacterDestinationRectangle.w = 16 ;
PlayerCharacterDestinationRectangle.h = 16 ;
SDL_Surface* Surface ;
SDL_Texture* PlayerCharacterTexture ;
SDL_Texture* [[maybe_unused]] Texture ;

/* Once we've done that, we need to setup SDL, or at least the parts we care about.  This part checks to see if fullscreen is wanted, sets up the video subsystem, creates the game window, then creates the renderer for that window.  These have checks to make sure that everything goes right that crash the program if things go wrong.  This is _incredibly dull_, and I really don't want to bother explaining it.  All that's relevant is that the window is called `Window`, and the renderer is called `Renderer`.  If you really care about exactly what's going on here, please just read the SDL wiki.  It explains what each of these things does. */

if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
	printf ( "SDL failed to initialize the video subsystem!  Thankfully, it was kind enough to give this error:\n%s\n", SDL_GetError( ) ) ;
	return 0x41 ; }
atexit ( SDL_Quit ) ;
SDL_Window *FullscreenPopup = SDL_CreateWindow ( "Would you like fullscreen?" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 640 , 480 , 0 ) ;
if ( FullscreenPopup == NULL ) {
	printf ( "SDL failed to create the fullscreen popup!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
SDL_Renderer *FullscreenPopupRenderer = SDL_CreateRenderer ( FullscreenPopup , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;
if ( FullscreenPopupRenderer == NULL ) {
	printf ( "SDL failed to initialize the renderer for the fullscreen popup!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
while ( 1 ) {
	DrawText ( 0 , 0 , 640 , "Do you want to play in fullscreen?  Press [y] for yes or [n] for no.  (Note:  Not being in fullscreen will result in the window being the same size as this window.)" , AssetsLocation , FullscreenPopupRenderer ) ;
	SDL_RenderPresent ( FullscreenPopupRenderer ) ;
	while ( SDL_PollEvent ( &CurrentEvent ) ) {
		if ( CurrentEvent.key.type == SDL_KEYDOWN && CurrentEvent.key.keysym.sym == SDLK_n ) {
			WindowFlags = SDL_WINDOW_ALLOW_HIGHDPI ;
			break ; }
	if ( CurrentEvent.key.type == SDL_KEYDOWN && CurrentEvent.key.keysym.sym == SDLK_y ) {
			WindowFlags = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI ;
			break ; } }
	if ( WindowFlags != 0 ) {
		break ; } }
SDL_DestroyRenderer ( FullscreenPopupRenderer ) ;
SDL_DestroyWindow ( FullscreenPopup ) ;
SDL_Window *Window = SDL_CreateWindow ( "Ex Nihilo" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 640 , 480 , WindowFlags ) ;
if ( Window == NULL ) {
	printf ( "SDL failed to create the window!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
SDL_Renderer *Renderer = SDL_CreateRenderer ( Window , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;
if ( Renderer == NULL ) {
	printf ( "SDL failed to initialize the renderer!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }

char PlayerCharacterImageLocation[256] = " " ;
strcpy ( PlayerCharacterImageLocation , AssetsLocation ) ;
strcat ( PlayerCharacterImageLocation , "TheCharacter.bmp" ) ;
Surface = SDL_LoadBMP ( PlayerCharacterImageLocation ) ;
PlayerCharacterTexture = SDL_CreateTextureFromSurface ( Renderer , Surface ) ;
SDL_FreeSurface ( Surface ) ;

/* Let's now clear the window.  This is done with the `SDL_RenderClear` function.  Since this is a drawing function, we need to set the color first, using `SDL_SetRenderDrawColor`; in this case, I'm setting it to black.  The `SDL_RenderPresent` function just flushes the buffer to the renderer.  While this is done every tick, making this not strictly necessary, I've chosen to do it anyway. */

SDL_SetRenderDrawColor ( Renderer , 0 , 0 , 0 , 0xFF ) ;
SDL_RenderClear ( Renderer ) ;
SDL_RenderPresent ( Renderer ) ;

/* We now need to test…something.  I'm not actually sure what this was supposed to be for.  In any case, it loads an image from the assets to the screen. */

strcpy ( ImageLocationLocation , AssetsLocation ) ;
strcat ( ImageLocationLocation , "TestImage.bmp" ) ;
SDL_Surface *TestSurface = SDL_LoadBMP ( ImageLocationLocation ) ;
if ( TestSurface == NULL ) {
	printf ( "SDL failed to create the test surface!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
SDL_Texture *TestTexture = SDL_CreateTextureFromSurface ( Renderer , TestSurface ) ;
if ( TestTexture == NULL ) {
	printf ( "SDL failed to create the test texture!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
SDL_FreeSurface ( TestSurface ) ;
SDL_RenderCopy ( Renderer , TestTexture , NULL , NULL ) ;
SDL_RenderPresent ( Renderer ) ;
SDL_DestroyTexture ( TestTexture ) ;

/* Now let's test text drawing. */

DrawText ( 128 , 128 , 256 , "Surprise!" , AssetsLocation , Renderer ) ;
SDL_RenderPresent ( Renderer ) ;

/* Now begins the main game loop. */

while ( 1 ) {

/*Uh, okay, this is interesting.  For some reason, the game runs better overall when this bit is commented out.  I have no idea why this is.  I've decided to leave this, and the original comment associated with it (listed under "<=>" below), since this is supposed to improve performance, not hurt it.
 *
 * <=>
 *
 * We first need to deal with the time.  The game only does things one nif times per second, so if it's before the next nifth of a second, we shouldn't bother doing anything. (This is, by the way, one of the only reasons <time.h> is needed.) */
/*
if ( time ( NULL ) == -1 ) {
	break ; }
if ( difftime ( time ( NULL ) , PreviousNifth )  > 0.0278 ) {
	PreviousNifth = time ( NULL ) ; }
else {
	continue ; }
*/
/* The next thing we need to do is clear the screen.  This is done as before. */

SDL_SetRenderDrawColor ( Renderer , 0 , 0 , 0 , 0xFF ) ;
SDL_RenderClear ( Renderer ) ;

/* We now need to handle events.  Currently, all that we're doing is checking for whether "q" is held down, and quitting if it is. */

while ( SDL_PollEvent ( &CurrentEvent ) ) {
	if ( CurrentEvent.key.type == SDL_KEYDOWN && CurrentEvent.key.keysym.sym == SDLK_q ) {
		Quit = 1 ;
		continue ; }
	if ( CurrentEvent.key.type == SDL_KEYDOWN && CurrentEvent.key.keysym.sym == SDLK_f ) {
		PlayerCharacterDestinationRectangle.x++ ;
		continue ; }
	if ( CurrentEvent.key.type == SDL_KEYDOWN && CurrentEvent.key.keysym.sym == SDLK_s ) {
		PlayerCharacterDestinationRectangle.x-- ;
		continue ; }
	if ( CurrentEvent.key.type == SDL_KEYDOWN && CurrentEvent.key.keysym.sym == SDLK_e ) {
		PlayerCharacterDestinationRectangle.y-- ;
		continue ; }
	if ( CurrentEvent.key.type == SDL_KEYDOWN && CurrentEvent.key.keysym.sym == SDLK_c ) {
		PlayerCharacterDestinationRectangle.y++ ;
		continue ; } }


/* Now it's time to actually do things.  Currently, all that we're doing is quitting if the `Quit` variable is set to 1. */

if ( Quit == 1 ) {
	break ; }

SDL_RenderCopy ( Renderer , PlayerCharacterTexture , NULL , &PlayerCharacterDestinationRectangle ) ;

/* Finally, we need to write to the screen. */

SDL_RenderPresent ( Renderer ) ; }
 
/* Now, it's time to clean up everything.  We need to kill the renderer, kill the window, kill the video subsytem, kill SDL, and then kill the program. */

SDL_DestroyTexture ( TestTexture ) ;
SDL_DestroyRenderer ( Renderer ) ;
SDL_DestroyWindow ( Window ) ;
SDL_QuitSubSystem ( SDL_INIT_VIDEO ) ;
SDL_Quit ( ) ;
return 0x00 ; }

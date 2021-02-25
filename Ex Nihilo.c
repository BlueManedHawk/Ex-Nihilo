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

/* Now, I need to add the SDL library. */

#include "SDL.h"

/* The main function contains the code, except for functions.  Why?  I don't know.  In any case, it takes a couple of arguments, these being an integer `argc` and a character pointer array `argv`.  These contain the count of arguments to the program and the arguments to the program, respecively.  Currently, I'm using this as debug functionality to tell the user that the program doesn't take any arguments. */

int main ( int argc , char *argv[] ) {

/* This bit of code serves only to use `argc`, as otherwise an error is generated. */

if ( argc ) { }

/* We now need to determine whether there were any arguments, and to immediatly exit if there were, with a message telling people to try again without supplying arguments.  Thankfully, there's a pretty simple way to do this:  the C standard (see line 7) specifies that `argv[argc]` needs to be null; therefore, if there are any arguments, `argc` will be set to something other than 0, and `argv[1]` will not be null.  If that's true, then the program will terminate with an exit code of 0x60;  otherwise, it will terminate with an exit code of zero. */

if ( argv[1] != NULL ) {
	printf ( "Hey, this program isn't meant to take any arguments.  Try running it again without them.\n" ) ;
	return 0x60 ; }

/* Now that we're sure that the game was executed properly, we can initialize SDL.  This is done by using the `SDL_Init` function, with specific arguments for the separate subsystems.  Since I'm only using the video subsystem and not the audio subsystem (for now ¯‿°), the only argument I need to supply to the function is `SDL_INIT_VIDEO`.
 *
 * However, there is the possibility that this can fail.  If it does, then the function will return a number other than 0.  We can check for this, and immediately exit the program if such a fault occurs.  Additionally, SDL has a fancy function called `SDL_GetError`, which…gets the error.  (Of course, a normal error code will also be `return`ed.) */

if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
	printf ( "SDL failed to initialize the video subsystem!  Thankfully, it was kind enough to give this error:\n%s\n", SDL_GetError( ) ) ;
	return 0x41 ; }

/* Of course, if the game quits unexpectedly, we'll want to ensure that SDL closes safely.  We can do this with the `atexit` function from `<stdlib.h>`.  Ideally, we'd want this to exit each subsystem individually, but `atexit` calls the functions with no arguments, so we can only use `SDL_Quit`, which closes all subsystems at once without any arguments.*/

atexit ( SDL_Quit ) ;

/* We now need to setup the main game window.  Of course, if the game window fails to initialize, we don't want to keep doing things, so we need to put the window creation in a check to make sure it doesn't fail.  The function returns NULL on failure, so we'll check for that.
 *
 * The arguments to the function `SDL_CreateWindow` are the name of the window, the X and Y position and size of the window, respectively, respectively, and the flags to the function ORed together, respectively. */

SDL_Window *PrimaryGameWindow = SDL_CreateWindow ( "Ex Nihilo" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 640 , 480 , SDL_WINDOW_SHOWN ) ;
if ( PrimaryGameWindow == NULL ) {
	printf ( "SDL failed to create the window!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }

/* We now need to create a renderer for the primary game window.  What does this do?  I'm not quite sure.  In any case, we still need to check if there's a problem, which is done in the same way as before. 
 *
 * The function `SDL_CreateRenderer` takes arguments for the window to setup, the driver to use, and the flags to set.  It takes -1 for the second argument to just use whatever driver it can find. */

SDL_Renderer *GameRenderer = SDL_CreateRenderer ( PrimaryGameWindow , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) ;
if ( GameRenderer == NULL ) {
	printf ( "SDL failed to initialize the renderer!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }

/* Let's now clear the window.  This is done with the `SDL_RenderClear` function.  Since this is a drawing function, we need to set the color first, using `SDL_SetRenderDrawColor`; in this case, I'm setting it to black.  The `SDL_RenderPresent` function just flushes the buffer to the renderer. */

SDL_SetRenderDrawColor ( GameRenderer , 0 , 0 , 0 , 0xFF ) ;
SDL_RenderClear ( GameRenderer ) ;
SDL_RenderPresent ( GameRenderer ) ;

/* This part was originally going to be much better, using a specialized format for storing images.  Unfortunately, the SDL documentation is currently in a sorry state, and I couldn't figure out how the hell I was supposed to create a surface, and frankly, I don't want to spend any longer on this, so I'm going to use the temporary solution of loading BMPs.  It's ugly, it's lazy, and it's oversized, but it's what I have to do.
 *
 * What this does is it uses an unnecessarily complicated series of string-modification commands (because apparently the ISO can't be bothered to make this understandable) to determine the location of a specific test image, then takes that image and loads it to a surface, then takes that surface and loads it to a texture, then takes that texture and loads it to the renderer, then takes that renderer and loads it to the window.  There's probably some reason why this is so ridiculously complicated, but I hacen't been able to find an answer. */

char TestImageLocation[255] = "/home/";
const char *CurrentUser = getenv ( "USER" ) ;
strcat ( TestImageLocation , CurrentUser ) ;
strcat ( TestImageLocation , "/.ExNihilo/Assets/TestImage.bmp" ) ;
SDL_Surface *TestSurface = SDL_LoadBMP ( TestImageLocation ) ;
if ( TestSurface == NULL ) {
	printf ( "SDL failed to create the test surface!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
SDL_Texture *TestTexture = SDL_CreateTextureFromSurface ( GameRenderer , TestSurface ) ;
if ( TestTexture == NULL ) {
	printf ( "SDL failed to create the test texture!  Thankfully, it was nice enough to explain why:\n%s\n" , SDL_GetError ( ) ) ;
	return 0x41 ; }
SDL_FreeSurface ( TestSurface ) ;
SDL_RenderCopy ( GameRenderer , TestTexture , NULL , NULL ) ;
SDL_RenderPresent ( GameRenderer ) ;

/* Now begins the main game loop. */

while ( 1 ) {

/* Currently, the only thing that the main game loop does is check if the Q key is down, and if it is, it breaks from the game loop. */

int Quit = 0 ;
SDL_Event CurrentEvent ;
while ( SDL_PollEvent ( &CurrentEvent ) ) {
	if ( CurrentEvent.key.type == SDL_KEYDOWN && CurrentEvent.key.keysym.sym == SDLK_q ) {
		Quit = 1 ;
		break ; } }
if ( Quit == 1 ) {
	break ; } }
 
/* Now, it's time to clean up everything.  We need to kill the renderer, kill the window, kill the video subsytem, kill SDL, and then kill the program. */

SDL_DestroyTexture ( TestTexture ) ;
SDL_DestroyRenderer ( GameRenderer ) ;
SDL_DestroyWindow ( PrimaryGameWindow ) ;
SDL_QuitSubSystem ( SDL_INIT_VIDEO ) ;
SDL_Quit ( ) ;
return 0x00 ; }

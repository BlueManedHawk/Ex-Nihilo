/* Table of Contents
 *
 * Line Number | Contents
 * ----------------------
 * */

/* Hello, and welcome to the source code of Ex Nihilo! */

/* We begin with the setup.  The first thing we need to do is state which libraries we're using.  This includes the SDL library (obviously) and several things from the standard library, including `<stdio.h>` for input-output outside of SDL, `<stdlib.h>` for a lot of things (seriously, this needs to be split up), `<string.h>` to deal with strings (in an ISO-mandatedly overcomplicated manner), `<ctype.h>` to run tests on characters, `<time.h>` to interact with time, `<math.h>` to deal with math, `<signal.h>` so that people don't lose progress when they need to kill the process due to lag or something, etc. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* #include <time.h>
 * #include <math.h>
 * #include <signal.h> */
#include "SDL.h"

/* We now need to make sure that people aren't compiling this for a bad operating system. */

#ifdef _WIN32 || WIN32 || _WIN64 || WIN64
#	error "It looks like you're trying to compile this for a Windows system.  Please don't do this.  For more information, please look at `docs/PORTING.md`."
#endif

/* We now need to declare some global variables.  Global variables are sometimes considered a bad practice, but here I feel they're fine, since it may take up a bit of permanent space, but it will be _far_ more convenient in functions, so that they don't need to be explicitly sent to the function every time. 
 *
 * These variables include:
 * `Folder` — this states where `~/.ExNihilo/` is.
 * `Assets` — this states where `~/.ExNihilo/Assets/` is.  (Strictly speaking, this is redundant, since this could be derived from `RootFolder` every time it's necessary, but having this already ready means that we don't need to waste time locating it every time we need it.) */

char * Folder = NULL ;
strcpy ( Folder , "/home/\0" ) ;
strcat ( Folder , getenv ( "USER" ) ) ;
strcat ( Folder , "/.ExNihilo/" ) ;
char * Assets = NULL ;
strcpy ( Assets , Folder ) ;
strcat ( Assets , "Assets/" ) ;

/* We now need to declare our functions.  Currently, this is only the `DrawText` function, but I'll probably need to add more as time goes on. */

/* This is the `DrawText` function.  It takes in some text, a location, a background color, a width, and a renderer to write to.  It then writes to the renderer.  (The location and background color are arrays because it looks cooler. */

void DrawText ( const char * Text , int Location[2] , int Color[3] , int Newline , SDL_Renderer * Renderer ) {

/* We first need to declare our variables. */

char * File = NULL ;
SDL_Rect Container = {
	x = Location[0] ;
	y = Location[1] ;
	h = ( strlen ( Text ) / ( Newline * 8 ) ) + 8;
	w = Newline * 8 ; }
SDL_Surface * Surface = NULL ;
SDL_Texture * Texture = NULL ;
SDL_Rect Destination = {
	x = Location[0] ;
	y = 1[Location] - 8 ;
	h = 8 ;
	w = 8 ; }
int OriginalX = Location[0] ;

/* We need to use the information in `Container` and the information in `Background` to create a background for out text.  Since text can only be black because I have no clue how surfaces work to any degree, this background color needs to be fairly bright. */

SDL_SetRenderDrawColor ( Renderer , Background[0] , Background[1] , Background[2] , SDL_ALPHA_OPAQUE ) ;
SDL_RenderFillRect ( Renderer , &Container ) ;

/* Now we enter the loop of the function.  What this essentially does is it goes through each of the characters, finds the appropriate file, loads it, and writes it to the screen.  More detail is available in the comments in the loop itself. */

for ( int i = 0 ; Text[i] != '\0' ; i++ ; ) {

	strcpy ( File , Assets ) ;
	strcat ( File , "Images/Writing/" ) ;
	if ( iscntrl ( Text[i] ) ) {
		strcat ( File , "unknown.bmp" ) ; }
	else if ( Text[i] == '/' ) {
		strcat ( File , "slash.bmp" ) ; }
	else if ( Text[i] == '%' ) {
		strcat ( File , "pernif.bmp" ) ; }
	else {
		strcat ( File , "Images/Writing/" ) ;
		strcat ( File , Text[i] ) ;
		strcat ( File , ".bmp" ) ;
		printf ( File ) ; }

	Surface = SDL_LoadBMP ( File ) ;
	Texture = SDL_CreateTextureFromSurface ( Renderer , Surface ) ;
	SDL_RenderCopy ( Renderer , Texture , NULL , Destination ) ;
	SDL_FreeSurface ( Surface ) ;

	Destination.x = ( Destination.x >= ( Newline * 8 ) + Container.x ) ? OriginalX : Destination.x + 8 ;
	Destination.y =+ ( Destination.x == OriginalX ) ? 8 : 0 ; }

SDL_DestroySurface ( Surface ) ;
SDL_DestroyTexture ( Texture ) ;
free ( File ) ; }



int main ( 

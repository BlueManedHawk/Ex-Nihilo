/* Hello, and welcome to the source code of Ex Nihilo! */

/* While reading this file, you may notice certain questionable things.  You may want to look at STYLE.md to understand these things and the reason they exist. */

/* It is also important to note that this file is normally compiled with clang for C2x.  This file is based off of the latest publically available draft for C2x, which is N2596.  You can get is here:
 *
 * http://www.open-std.org/JTC1/SC22/WG14/www/docs/n2596.pdf 
 *
 * You can tell Clang to compile with C2x with the argument -std=c2x.  You'll need Clang 11 to do this.
 *
 * On the topic of arguments, I use the arguments -Wall -Wextra -pendantic -Werror for compiling this (in addition to -std=c2x).  Depending on who you ask, this may be considered overkill. */

/* At certain points in the code, a `return` statement will be used to terminate the process with a specific code.  Information on these codescan be found in TROUBLESHOOTING.md. */

/* Licensing details on this code can be found in LICENSE.md. */

/* The environment I use to modify this file is Neovim in the Kitty terminal emulator with the font Fira Code.  I suggest that you do the same for viewing this file. */

/* Unfortunately, I need to rely on the standard library to output to the terminal.  I haven't found any way to do this that doesn't use `<stdio.h>`. */

#include <stdio.h>

/* The main function contains the code, except for functions.  Why?  I don't know.  In any case, it takes a couple of arguments, these being an integer `argc` and a character pointer array `argv`.  These contain the count of arguments to the program and the arguments to the program, respecively.  Currently, I'm using this as debug functionality to tell the user that the program doesn't take any arguments. */

int main ( int argc , char *argv[] ) {

/* We now need to determine whether there were any arguments, and to immediatly exit if there were, with a message telling people to try again without supplying arguments.  Thankfully, there's a pretty simple way to do this:  the C standard (see line 7) specifies that `argv[argc]` needs to be null; therefore, if there are any arguments, `argc` will be set to something other than 0, and `argv[1]` will not be null.  If that's true, then the program will terminate with an exit code of one;  otherwise, it will terminate with an exit code of zero. */

if ( argv[1] != NULL ) {
	printf ( "Hey, this program isn't meant to take any arguments.  Try running it again without them.\n" ) ;
	return 1 ; } 
printf ( "Wahoo!\n" ) ;
return 0 ; }

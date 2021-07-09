# Organization of the Source

This file is intended as a very very _very_ broad overview of the code.  If you want exact details, you should look at the source itself and all of its comments.


The main file is `Ex Nihilo.c` in the root directory of the repository.  This file includes everything else in the `include` directory.  I've tried my best to divide the code up between the files reasonably, making sure that each file is for a specific thing and that there aren't too many or too few files, but I recognize that I may very well have failed.

The program begins with some licensing information and an introductory paragraph.  It then includes relevant files from the C Standard Library, SDL and the extensions we're using, and the files from the `include` directory.  It also sets some pragmas, defines some macros, and runs some compile-time checks.  Throughout the code, the macro EX\_NIHILO\_DEBUG\_MODE is checked to see if the program is being compiled for Debug Mode.

After that, some variable are declared.  These are mostly used for communications between functions.

From here, some runtime checks are done, such as verifying the operating system, checksumming the assets, and checking the battery.  The user is then asked if they want to play in fullscreen.  This is from the file `Checks.h`.

From here, SDL and its extensions are prepared for use in this program.  This is from the file `Setup.h`.

From here, some things are loaded.  This is from the file `Loading.h`.

And now, we reach the loop.  This is the brains of the operation.  The loop goes through one cycle every 36th of a second.  If a series of cycles take more than this time, the program will crash to prevent abuse.  However, a warning will be given before then so that the user can fix things.

The first step in the loop is to gather input.  What keys have been pressed?  Where has the mouse been clicked?  What text has been inputted?  This information is then written down for later use.  This is from the file `Input.h`.  (And yes, text input is different from keypresses.  It's a bit strange.)

From here, we need to consider what state the program is in.  Are we in the main menu?  Are we in normal gameplay?  Are we looking at our inventory?  Are we in the pause menu?  This is from the file `State.h`

From here, what to do depends on the state of the program.  This can get very complicated, too much so to explain here.  Some of these steps are shared between the different states, and some of the states have multiple files dedicated to them.  However, in general, the steps generally involve considering the input given and using that to change some part of the program…which I have just realized is probably the least helpful I could possibly be.

Following this, we analyse the state of the program, and based on that, create something to draw to the screen.  Frequently, we can cache the previous state of the screen and just modify that instead of doing everything over.  We then present it to the screen.  This is from the file `Present.h`.

And then, we wait until the end of the we go back to the start of the loop and do it all over again.

At some point, we will want to quit.  This will break us from the loop, where we then perform some cleanup, such as saving things, properly closing SDL, and other stuff.  This is from the file `Cleanup.h`.

At some point, the game might crash.  The file `Crash.h`contains the crash handler for the game.

…

I'm not quite sure why I made this document.  What was the point of this again?  I think it may just have been to get my thoughts straight.  I'm honestly not sure.  Eh, whatever.  It might be useful.

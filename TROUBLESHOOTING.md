# Troubleshooting

This document lists some information on how to troubleshoot problems with Ex Nihilo.

## It won't compile!

Are you compiling it correct?  Remember, the code is based on C2x according to Clang, so you'll need Clang 11 (which uses the command `clang-11`—_that_ tripped me up a few times) and you'll need to include the `-std=c2x` option when compiling.

If that doesn't work, please file an issue (see `CONTRIBUTING.md`).

## It won't run!

Are you on Linux?  This software is only being developed for Linux-based systems.  Trying to run it on BSD may not work, trying to run it on MacOS X probably won't work, and trying to run it on Windows _definitely_ won't work.  (For more information as to why this is, see `PORTING.md`.)  It's also important to note that I'm doing this on an extremely broken Chromebook running an extremely broken install of GalliumOS, so some subtle differences may break everything.  You may want to just compile it yourself (see COMPILING.md, and if compiling fails, see the above section).

Do you have permission to execute the file?  Seriously, check this.  It's tripped me up many times before.

If this doesn't work, try running it from a CLI, then getting the exit code.  (On Bash, you can do this with `echo $?`.)  It may be crashing so unnoticably quickly that it's interpretted as not running at all.  From there, proceed to section "It's crashing!".

If it still won't run, please file an issue (see `CONTRIBUTING.md`).

## I don't understand this thing!

Please, read the in-game documentation thoroughly.  It will almost certainly contain your answer.  If it somehow doesn't, please file an issue (see `CONTRIBUTING.md`).

## It's crashing!

Oh…_oh no._  Something has truly gone wrong.

Firstly, run the game from a CLI, reproduce the crash, and then get the exit code.  (On bash, you can do this with `echo $?`.)  Convert it to binary.  This error code determines what caused the crash:

- The first nybble of the byte describes a few characteristics (in all cases, 0 is yes, and 1 is no):
	- The first bit states whether the game exited safely.
	- The second bit states whether the game exited expectedly.
	- The third bit states whether the game was outside debug mode.
	- The fourth bit is reserved because it makes things easier.
- The second nybble of the byte is used to state the source of the crash, and is _not_ treated bitwise.
	- 0 indicates the it what it what was it not what have it.
	- 1 indicates some error in SDL.
	- 2 indicates that the error was from an inability to write.
	- 3 indicates illegal positioning.
	- 4 indicates that the game was crashed manually.
	- 5 indicates that the game was running too slowly.
	- 6 indicates a prevention of system breakage.
	- 7 indicates an abnormal infinite loop was detected.
	- 8 indicates that the error was from an inability to read.
	- 9 indicates that a server sent bad information.
	- Other values are currently unused.

Please be sure to file an issue (see `CONTRIBUTING.md`).

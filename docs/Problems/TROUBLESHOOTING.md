# Troubleshooting

This document lists some information on how to troubleshoot problems with Ex Nihilo.

## It won't compile!

Are you compiling it correct?  Please make sure to thoroughly read `COMPILING.md`.

Otherwise, please file an issue (see `CONTRIBUTING.md` and `ISSUES.md`).

## It won't run!

Do you have permission to execute the file?  If you do, proceed.

Are you on Linux?  This software is only being developed for Linux-based systems.  Trying to run it on BSD may not work, trying to run it on MacOS X probably won't work, and trying to run it on Windows _definitely_ won't work.  (For more information as to why this is, see the non-binding section of `docs/LICENSE.md`.)  It's also important to note that I'm doing this on an extremely broken Chromebook running an extremely broken install of GalliumOS, so some subtle differences may break everything.  You may want to just compile it yourself (see `docs/COMPILING.md`, and if compiling fails, see the above section).

If this doesn't work, try running it from a CLI, then getting the exit code.  (On Bash, you can do this with `echo $?`.)  It may be crashing so unnoticably quickly that it's interpretted as not running at all.  From there, proceed to section "It's crashing!".

If it still won't run, please file an issue (see `CONTRIBUTING.md`).

## A segfault occured when I was fullscreened, and now everything's wonky!

The exact details of what to do vary for each desktop environment.  However, in general, you can go to your monitor preferences and select the correct resolution.

Once you've fixed that, _please report an issue!_  See `CONTRIBUTING.md` and `ISSUES.md` for details.

## My battery is broken and my system (which uses LXDE) needs to be constantly plugged in, but it constantly alternates between thinking the battery is discharging and thinking it's charging, thereby creating particularly annoying notifications in fullscreen mode!  What do I do?

Kill the process `xfce4-power-manager`.  You don't need it.

## It's crashing!

Aw, crap.

First, _file an issue!_  See `CONTRIBUTING.md` and `ISSUES.md` for details.

**I will never ask you for a save file, and neither should anybody else.**

I may ask you for an exit code.  To get this, run the game from a Bash CLI and reproduce the crash, then do `echo $?`.  Convert it to binary.  This error code determines what caused the crash:

- The first nybble of the byte describes a few characteristics (in all cases, 0 is yes, and 1 is no):
	- The first bit states whether the game exited safely.
	- The second bit states whether the game exited expectedly.
	- The third bit states whether the game was outside debug mode.
	- The fourth bit is reserved because it makes things easier.
- The second nybble of the byte is used to state the source of the crash, and is _not_ treated bitwise.
	- 0 indicates normal exit conditions.
	- 1 indicates an error with SDL.
	- 2 indicates a manual crash.
	- 3 indicates a closure to prevent loss of data.
	- 4 indicates that the assets were invalid, and you should probably reinstall them.
	- 5 indicates an attempt to play under invalid circumstances.
	- 6 indicates that the game was given invalid input.
	- Other values are not currently used.

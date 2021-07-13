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

## It's crashing!

See `CRASHES.md`.  In general, you should report an issue.  Please see `CONTRIBUTING.md` and `ISSUES.md`.

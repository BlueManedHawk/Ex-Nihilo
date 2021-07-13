# Explanations of Some Questionable Decisions

This document contains several questions about the game.

## How do I find help?

Try the built-in User Manual and the built-in Reference Manual.  If neither of those contain your answer, then clearly something's wrong with them, and you should probably file an issue (see `CONTRIBUTING.md` and `ISSUES.md`).

## Why does this game use a mouse?

This is a regretable decision.  Unfortunately, there exist more computers that have a mouse, but not great antighosting, than computers that have good antighosting.  This is, obviously, stupid, but it's something I need to deal with.  I am very sorry about this.

## Why isn't debug mode included by default, just turned off?

Here's another regretable decision, albeit less so, and mostly because it forced me to use a Makefile.  The reason I've done this is because including Debug Mode by default would put in what would be to many users simply bloat.  Therefore, I made the decision to have debug mode only be included if somebody specifically compiles for it.  Sorry!

## Why C?

I have chosen to use C instead of C++ (which seems to be the industry standard for games) for a few reasons:

- C is not a bloated language like C++ is.  There are a few niceties missing, but they can be done without.
- C is not an object-oriented language like C++ is.  Object-oriented programming is a broken, messy, confusing paradigm that is too separated from what a computer actually does to be useful.
- C is understandable.  Everything is nicely organized and put where it needs to be, and there isn't an overwhelming amount of stuff.

As an analogy:  C++ is if somebody noticed the box of C — a box that, while not quite full, was very nicely organized, and had everything nicely integrated cleanly together, as if done by a professional Tetris player — and decided that the best way to fill the box up was not by carefully designing new pieces to put into it carefully and cleanly, but by dumping the contents carelessly into a new box, spilling a couple things outside on the way, and then tossing in whatever felt "right" until they ended up with an overflowing box of crap.

## Why aren't you using a game engine?

Using a game engine would provide too much overhead, and there don't seem to be any that are compatible with C.

## Why is everything spread out accross multiple files?

This is definitely one of the decisions that I most regret.  I did this because it helps prevent the text editor from being overloaded, and to a _very_ questionable degree prevents one's brain from being overloaded.  I don't like the fact that I did this, but I've done the best I can to explain the structure of things in `ORGANIZATION.md`.

I am so, so sorry.

## What even is a makefile?

A full explanation of how a makefile works is too long to be included here, but a short explanation is available in the text of the makefile itself.

## Why isn't anything compressed?

I haven't been able to find a good compression library.  `zlib`'s documentation is completely impenetrable, and I don't know of anything else. I could theoretically use the `system ( )` function in `stdlib.h`, but that's _**very**_ questionable and would probably lead to some security issues.

Don't fret too much, though:  I do use SDL\_Image and SDL\_sound to use compressed images and sounds, which is…I dunno.  It's something, I guess.

## What IDE do you use to make this?

I don't use an IDE.  I use Neovim for text editing and LLDB for debugging.

## Why do the directories in the root of the repo all have decapitalized names, but the files in all of those directories all have front-capitalized names, except in `docs/`, where the files have screaming-case names, but the directories don't?

Unfortunately, I have no idea.  This seems to be common practice in a lot of repositories, so I decided to went with go to have it.  At the very least, I can say that the reason the `docs/` directory is decapitalized is because otherwise GitHub wouldn't recognize the files in it for their special purposes.

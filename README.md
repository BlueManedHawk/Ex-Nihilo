# Ex Nihilo

## Preface

This repository is for the video game Ex Nihilo.  It is still in very very _**very**_ early developement, and may cause many problems.  The license is at `docs/LICENSE.md`, and installation instructions are available at `docs/INSTALLING.md`.  If you have a security issue to report, _**please**_ look at the security policy in `docs/SECURITY.md`.

## Introduction

The overarching goal of the project is to create a game in which the player starts with nothing and works their way up.  The game will be a sandbox game featuring extensive magic and technology systems.  The game will contain a comprehensive reference manual built-in to the game, and an interactive user manual will exist to help guide the player.

## Problems

_More information:  `docs/PROBLEMS.md`_

There are a number of reasons you may be having a problem.  The files that you should look at when you have a problem are _generally_ all in the `docs/Problems/` directory.  See the Index section below.

## Contributing

_More information:  `docs/CONTRIBUTING.md`_

There are multiple ways to contribute.  The files containing information on how to contribute are _generally_ all in the `docs/Problems/` directory.  See the Index section below.

## Index

These are all located in the `docs` directory in this repository.

- LICENSE.md contains licensing information.
- SECURITY.md contains the protocol for reporting security problems with the game.
- CREDITS.md contains my thanks to various people.
- INSTALLING.md contains instructions on how to install the game.
- CHANGELOG.md is a changelog of all the versions released.
- REQUIREMENTS.md explains what you need to play the game.
- fdjdalgsnjcixslfo9cin2odoks==s;dqvicopzjhddaal
- PROBLEMS.md explains where you can figure out how to fix some problems.
	- CRASHES.md explains the crash protocol for the game.
	- LINGERERS.md lists several lingering problems with the game.
	- FAIRNESS.md lists several problems regarding fairness in playing the game.
	- QUESTIONS.md mostly explains questionable decisions.
- CONTRIBUTING.md explains where you figure out how to contribute.
	- DESIGN.md explains some design principles for the game.
	- ISSUES.md explains how to file an issue.
	- PULLS.md explains how to make code contributions.
	- LOGS.md explains the game's logging protocol.

## Further Reading

This program is written in C.  The latest public draft of C2x is available at http://www.open-std.org/JTC1/SC22/WG14/www/docs/n2596.pdf.

This game uses SDL 2 and the extensions SDL\_image, SDL\_mixer, and SDL\_ttf.  The wiki for SDL is available at https://wiki.libsdl.org/, and information on its extensions are available at https://libsdl.org/projects/SDL_image/docs/index.html, https://libsdl.org/projects/SDL_mixer/docs/index.html, and https://libsdl.org/projects/SDL_ttf/docs/index.html

This project uses Clang 11 to compile, because Clang 13 (the latest version) would take up too much space and Clang 12 seems to not actually exist.  The user manual for Clang is available at https://clang.llvm.org/docs/UsersManual.html.  Clang also implements several extensions to C, which can be read about at https://clang.llvm.org/docs/LanguageExtensions.html.  It also implements extensions from GCC for compatibility, which are available at https://gcc.gnu.org/onlinedocs/gcc/C-Extensions.html.

This program uses a makefile.  GNU Make is used to execute the makefile, because I can't find any information on any other Make programs.  The documentation for Make is available at https://www.gnu.org/software/make/manual/make.pdf

It's recommended that you use LLDB to debug the program, especially since the default makefile tunes the debug output for LLDB.  Information on this is available at https://lldb.llvm.org/.

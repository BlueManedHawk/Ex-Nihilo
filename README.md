**This project has been archived.** For more information, see [here](https://bluemanedhawk.tumblr.com/post/662076954824114176/im-shelving-the-project-again).

# Ex Nihilo

## Preface

This repository is for the video game Ex Nihilo.  It is still in very very _**very**_ early developement, and may cause many problems.  The license is at `docs/LICENSE.md`, and installation instructions are available at `docs/INSTALLING.md`.  If you have a security issue to report, _**please**_ look at the security policy in `docs/SECURITY.md`.

## Introduction

The overarching goal of the project is to create a game in which the player starts with nothing and works their way up.  The game will be a sandbox game featuring extensive magic and technology systems.  The game will contain a comprehensive reference manual built-in to the game, and an interactive user manual will exist to help guide the player.

## Problems

_More information:  `docs/PROBLEMS.md`_

There are a number of reasons you may be having a problem.  The files that you should look at when you have a problem are _generally_ all in the `docs/Problems/` directory.  These include `docs/Problems/LINGERERS.md`, which lists lingering well-known bugs in the game, `docs/Problems/QUESTIONS.md`, which lists several questions about the game and explains the many, _**many**_ questionable decisions, `docs/Problems/REQUIREMENTS.md`, which lists what you need to play the game, and `docs/Problems/TROUBLESHOOTING.md`, which lists common issues you might run into.

## Contributing

_More information:  `docs/CONTRIBUTING.md`_

The easiest way to contribute is to find a problem and file an issue.  You can find more information on this in `docs/Contributing/ISSUES.md`.  When filing a problem, please consider the game design principles, available in `docs/Contributing/DESIGN.md`.

I'm currently not accepting pull requests until I'm more educated about how copyright works.  Until then, you can look at `docs/Contributing/COMPILING.md` to understand how the game is compiled.  The source code is pretty well commented (or at least I'd like to think so) but `docs/Contributing/ORGANIZATION.md` gives a broad overview of how the source code is organized.  You'll also want to look at `docs/Contributing/STYLE.md` so you can understand why the source code looks like that.

## Index

These are all located in the `docs` directory in this repository.

- LICENSE.md contains licensing information.
- SECURITY.md contains the protocol for reporting security problems with the game.
- CREDITS.md contains my thanks to various people.
- ETHICS.md
- INSTALLING.md contains instructions on how to install the game.
- CHANGELOG.md is a…changelog.
- fdjdalgsnjcixslfo9cin2odoks==s;dqvicopzjhddaal
- PROBLEMS.md explains where you can figure out how to fix some problems.
	- LINGERERS.md lists several lingering bugs.
	- REQUIREMENTS.md explains what you need to play the game.
	- QUESTIONS.md mostly explains questionable decisions.
	- TROUBLESHOOTING.md explains how to fix some common problems.
- CONTRIBUTING.md explains where you figure out how to contribute.
	- DESIGN.md explains some design principles for the game.
	- ISSUES.md explains how to file an issue.
	- COMPILING.md explains how the makefile works.
	- ORGANIZATION.md explains how the source is organized.
	- STYLE.md explains how the source is formatted.

## Further Reading

This program is written in C.  The latest public draft of C2x is available at http://www.open-std.org/JTC1/SC22/WG14/www/docs/n2596.pdf.

This game uses SDL 2 and the extensions SDL\_image, SDL\_mixer, and SDL\_ttf.  The wiki for SDL is available at https://wiki.libsdl.org/, and information on its extensions are available at https://libsdl.org/projects/SDL\_image/docs/index.html, https://libsdl.org/projects/SDL\_mixer/docs/index.html, and https://libsdl.org/projects/SDL\_ttf/docs/index.html

This project uses Clang 11 to compile, because Clang 13 (the latest version) would take up too much space and Clang 12 seems to not actually exist.  The user manual for Clang is available at https://clang.llvm.org/docs/UsersManual.html.  Clang also implements several extensions to C, which can be read about at https://clang.llvm.org/docs/LanguageExtensions.html.  It also implements extensions from GCC for compatibility, which are available at https://gcc.gnu.org/onlinedocs/gcc/C-Extensions.html.

This program uses a makefile.  GNU Make is used to execute the makefile, because I can't find any information on any other Make programs.  The documentation for Make is available at https://www.gnu.org/software/make/manual/make.pdf

It's recommended that you use LLDB to debug the program, especially since the default makefile tunes the debug output for LLDB.  Information on this is available at https://lldb.llvm.org/.

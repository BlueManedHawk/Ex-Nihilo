# LICENSE
#
# You can freely distribute this file and modifications of this file, but you cannot charge for them, and you must distribute this license and give attribution when distributing.
#
# Modifications must be licensed such that they preserve the rights this license gives with the same restrictions; furthermore, you must state what modifications were made and how to obtain the original.
#
# This comes with no warranty, implied or explicity, and I am not liable for any problems caused by this.  This license does not cover trademarks.


# If you're using Neovim, this may be painfully cyan.  Sorry!


# Hello, and welcome to the makefile for Ex Nihilo!
#
# If you don't know, a makefile is a compiling automation tool.  It consists of a number of _targets_ (the unindented bits that end with a colon) that can be selected as arguments to the process from the command line (e.g. you select the `help` target with `make help`).  If you don't specify any particular target, the first target in a makefile will be used.  These targets are then followed on the same line by prerequisites, which can be files or other targets.
#
# From there, a target consists of a series of single-tab-indented commands to be executed on a shell, separated by semicolons.  Each line is executed on a different shell (so, for example, `cd` won't be remembered between lines) but two lines can be treated as one by escaping the former's newline with a backslash.
#
# Additionally, there exist macros for makefiles.  These are defined similarly to how variables are in most programming languages.  They are used such that `$(EXAMPLE)` means "Expand the macro 'EXAMPLE' here.".
#
# There exist other things, like suffix rules and pattern rules.  If you want more information, I suggest you look at the Wikipedia page for Make, then look at the manual for GNU Make, which this program uses, which is available here:  https://www.gnu.org/software/make/manual/make.pdf.


# This particular makefile uses the `clang-11` command a lot.  You may want to look at the documentation, which is available here:  https://clang.llvm.org/docs/.  (I use Clang 11 because any future revision would take up too much space on my Chromebook.)


# The first target, and the default, chastises you for not specifying an argument, then redirects you to `COMPILING.md`

default:
	$(warning "Hey!  You need to specify something to make!  See `COMPILING.md` for details.")

# I'm now going to declare some macros, because while these make it very slightly slower, they're going to overall make this much easier to maintain, and will reduce the repetitiveness of the makefile.


# First, we need to declare the compilation stuff.  This includes the compilation command, the most common filenames, the formatting options, the diagnostic options, the it to it can't be what have, and some other options.  This means that in the event this needs to be expanded, faffing about with changing everything everywhere can be avoided.


COMMON_BINARY_OUTPUT = Ex\ Nihilo.elf
COMMON_ASSETS_OUTPUT = Assets.txz
COMMON_SOURCE_INPUT = Ex\ Nihilo.c
COMMON_ASSETS_INPUT = Assets/

COMPILE_COMMAND = clang-11 $(FORMATTING_OPTIONS) $(DIAGNOSTIC_OPTIONS) $(OTHER_OPTIONS) `sdl2-config --cflags --libs`
TAR_COMMAND = tar -cJf $(COMMON_ASSETS_OUTPUT) $(COMMON_ASSETS_INPUT)

FORMATTING_OPTIONS = -fdiagnostics-show-category=name
DIAGNOSTIC_OPTIONS = -Wall -Werror -Wextra -pedantic 
DEBUGGING_OPTIONS = -g -fdebug-macro -glldb
OTHER_OPTIONS = -std=c2x

release:
	$(COMPILE_COMMAND) $(COMMON_SOURCE_INPUT) -o $(COMMON_BINARY_OUTPUT)
	$(TAR_COMMAND)

lldb:
	$(COMPILE_COMMAND) $(DEBUGGING_OPTIONS) $(COMMON_SOURCE_INPUT) -o $(COMMON_BINARY_OUTPUT)

debug:
	$(COMPILE_COMMAND) $(DEBUGGING_OPTIONS) -DEX_NIHILO_DEBUG_MODE $(COMMON_SOURCE_INPUT) -o Ex\ Nihilo\ DEBUG.elf

binary:
	$(COMPILE_COMMAND) $(COMMON_SOURCE_INPUT) -o $(COMMON_BINARY_OUTPUT)

assets:
	$(TAR_COMMAND)

# There is no `make clean` command because I don't trust myself to not screw it up massively.

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
# This document will assume that you're familiar with makefiles, and more particularly, GNU make, the manual for which is available here:  https://www.gnu.org/software/make/manual/make.pdf.


default:
	$(warning "Hey!  You need to specify something to make!  See `COMPILING.md` for details.")

COMMON_BINARY_OUTPUT = Ex\ Nihilo.elf
COMMON_ASSETS_OUTPUT = Assets.txz
COMMON_SOURCE_INPUT = Ex\ Nihilo.c
COMMON_ASSETS_INPUT = assets/

COMPILE_COMMAND = clang-11 $(FORMATTING_OPTIONS) $(DIAGNOSTIC_OPTIONS) $(OTHER_OPTIONS) `sdl2-config --cflags --libs`
TAR_COMMAND = tar -cJf $(COMMON_ASSETS_OUTPUT) $(COMMON_ASSETS_INPUT)

FORMATTING_OPTIONS = -fdiagnostics-show-category=name
DIAGNOSTIC_OPTIONS = -Wall -Werror -Wextra -pedantic 
DEBUGGING_OPTIONS = -g -fdebug-macro -glldb
OTHER_OPTIONS = -std=c2x -v -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

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

# There is no `make clean` or `make install` command because I don't trust myself to not screw it up massively.

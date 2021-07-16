# Crashes

## Introduction

Crashes are generally handled by the crash handler, located in `Crash.h`.  This consists of several functions, but there are only two we care about:  a crash handler setup function, called at the beginning of the program, and a crash function, which is called whenever a crash needs to occur.

The crash handler setup function really just sets some stuff with `<signal.h>`.  It uses most of the other functions in the header for this.

The crash function must be called with one short argument, and optionally a second string argument corresponding to a message to be displayed.  When the crash function is called, a window is displayed showing someinformation about the crash, mostly based on the arguments given.  If the SDL video subsystem and the SDL\_ttf library are initialized, those will be used for this; otherwise, an SDL messagebox will be used.

## Exit codes

There are two types of exit code:  the _application_ exit code, and the _system_ exit code.  The system exit code is the upper byte of the application exit code, which is a short.  The first nybble of the application exit code indicates some flags, the second nybble indicates the crash class, and the lower byte indicates the crash type, which shows more specific information about the crash based on the class.  The system exit code is what's returned by the program (and therefore what's available with `echo $?`), and the application exit code is what's used in the `Crash ( )` function.

The flags in the first nybble are as follows (with 0 meaning yes and 1 meaning no):

- Did the game exit safely?
- Did the game exit expectedly?
- Was the game outside debug mode?
- [reserved because it makes things easier]

## Crash classes

### Crash Class 1:  Debug Mode

This is used to indicate that the crash was _caused_ because of debug mode.  The types are:

- 1: Indicates that the crash was caused manually.
- Other values aren't used.

### Crash Class 2:  SDL error

This indicates that the problem occured with SDL.

- 1: Unobtainable pref path
- 2: Failed to initialize SDL
- 3: Failed to initialize SDL\_image
- 4: Failed to initialize SDL\_mixer
- 5: Failed to initialize SDL\_ttf
- Other values aren't used.

### Crash Class 3:  Invalid Circumstances

This indicates that the user attempted to play under invalid circumstances.

- 1:  Invalid assets
- 2:  Invalid OS
- 3:  Invalid battery
- Other values aren't used.

### Crash Class 4:  Data loss prevention

This indicates that the program was crashed to prevent data loss.

### Crash Class 5:  Signal

This indicates that the program was crashed because it recieved a signal.

- 1: Abnormal program termination
- 2: Floating point error
- 3: Illegal instruction
- 4: Interruption
- 5: Segmentation fault
- 6: Termination request
- Other values aren't used.

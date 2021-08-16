# Crashes

## Introduction

Crashes are generally handled by the crash handler, located in `Crash.h`.  This consists of several functions, but there are only two we care about:  a crash handler setup function, called at the beginning of the program, and a crash function, which is called whenever a crash needs to occur.

The crash handler setup function really just sets some stuff with `<signal.h>`.  It uses most of the other functions in the header for this.

The crash function must be called with one byte argument, and optionally a second string argument corresponding to an additional message to be displayed.  This string isn't formatted; if you need that, use `sprintf ( )` or something.  When the crash function is called, a window is displayed showing some information about the crash based on the arguments given.  ~~If the SDL video subsystem and the SDL\_ttf library are initialized, those will be used for this; otherwise, an SDL messagebox will be used.~~ (this is, temporarily, a lie.)

The game currently uses a very simple system where a single byte is used for a basic exit code, and further information is stored in the message.  This may eventually prove inadequate; if such occurs, a more complex system will be designed.

## Crash Codes

- 0:  Normal program termination.
- 1:  Manually-initiated crash.
- 2:  Runtime checks failure.
- 3:  SDL initialization failure.
- 4:  SDL setup failure.
- 5:  Signal recieved.
- 6:  `atexit ( )` registration failure.
- 7:  Loading failure.
- 8:  Data loss prevention.
- 9:  An undefined game state was reached.
- A:  Lag abuse prevention.

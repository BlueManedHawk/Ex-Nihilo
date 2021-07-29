# Logging Protocol

The function `SDL_LogMessage ( )` is generally used for logging.  In general, you probably shouldn't log things in infinite loops unless you know what you're doing.

## Log Categories

In general, you can just select whatever category "feels right".  The category isn't displayed anyway.  There are, however, a few exceptions:

- The error category is exclusively used for when a message has the error or critical priorities.
- The custom category isn't currently used for anything, so don't use that.
- Don't confuse assertions and tests.

## Log Priorities

Log priorities are as follows:

- Verbose is for information that a player outside of Debug Mode probably won't need to see.
- Debug is exclusively for use with logs that are directly relevant to debug mode.
- Info is used for information that the general player may benefit from seeing.
- Warnings are used when something goes wrong, but the game doesn't need to stop.
- Errors aren't currently used for anything.
- Critical errors are shown just before the game crashes.

## Logging Style

This is the main way to avoid confusion with SDL's own (seemingly random) logging.

- Use full sentences.
- End sentences with periods by default, elipses when logging the beginning of something, and exclamation points when logging the end of something.

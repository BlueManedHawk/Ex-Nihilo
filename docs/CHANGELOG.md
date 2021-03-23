# Changelog

This document lists all the changes in each version of Ex Nihilo.  These versions are listed with the earliest versions at the top, and the latest versions at the bottom.  This is because going from bottom to top would mean overoscillation of the path of the eyes.

A level-2 heading lists the version.  Level-3 headings are used to separate the changes in each version by the type of change.  If there are no changes in a particular section, that section will be elided.  The sections are as follows:

- The **IMPORTANT!** section lists changes of any type that are important, which typically means removal of something which was heavily used, information on a security fix, a notice of backwards incompatibility, or something else I haven't thought of.  These are preceeded with a !.
- The **Additions** section lists changes that add new features to the game.  These are preceeded with a +, which inexplicably renders as a °.
- The **Modifications** section lists changes that don't add anything new, but modify existing things.  These are preceeded by a ~.
- The **Removals** section lists changes that take away some element of the game.  These are preceeded with a $.
- The **Deprecations** section lists changes that add some new element for the purpose of replacing a different element.  These are preceeded by a @.
- The **Fixes** sections lists changes that resolve issues.  (The term _Fixes_ is used instead of _Resolutions_ to make at-a-glance distinguishing from _Removals_ easier.)  These are preceeded by a %.
- The **Behind-the-scenes** section lists changes that don't change the play of the game, but which still happened within the code.  (The term _Behind-the-scenes_ is used instead of _Refactors_ to make at-a-glance distinguishing from _Removals_ easier.)  These are preceeded by a =.

A version is formatted as in the regular expression `/\R\.\d+\a*(-(beta|pre|rc)+\d)?/`, where `\R` is a roman numeral or the letter "N", which I'm using for 0 and also for "**N**ot Finished".  `beta`s are for adding new features, `pre`releases are for fixing issues, and `rc`s are release candidates.

There may be a time where a version will need to be made innacessible, due to something such as legal reasons, serious security issues, or something else.  While the entry for these versions will stay, the heading for the version will have `[REMOVED ON <date>: <reason>]` appended to it.  The date will be YYYY-MM-DD.

For plans for future versions, see `PLANS.md`.

## Version N.0, released on 2021-02-16.

### IMPORTANT!

- ! This is the first version.
- ! This version doesn't contain any code.

### Additions

- + Created the file `Ex Nihilo.c`.
- + Created the file `README.md`.
- + Created the file `CHANGELOG.md`.
- + Created the file `COMPILING.md`.
- + Created the file `CONTRIBUTING.md`.
- + Created the file `CREDITS.md`.
- + Created the file `INSTALLING.md`.
- + Created the file `LICENSING.md`.
- + Created the file `PLANS.md`.
- + Created the file `PORTING.md`.
- + Created the file `REQUIREMENTS.md`.
- + Created the file `STYLE.md`.

## Version N.1 beta 0, released on 2021-03-23.

### IMPORTANT!
- ! The goal of Release N.1 is to get all of the basic game things listed in `docs/PLANS.md` into the game.
- ! This particular beta includes the ability to move a player character around.

### Additions
- + Put code in the code file.
- + Made the file `docs/TROUBLESHOOTING.md`
- + Made assets a thing.
- + Certain parts of the game will now draw text to the screen.
- + Expandions to `PLANS.md`.
- + The game now creates windows.
- + You can now press Q to quit.
- + Fullscreen is available, but optional.
- + You can move a player character with [e], [s]. [c], and [f].
- + Made the file `docs/SECURITY.md`

### Modifications
- ~ Moved all markdown files (exempting `README.md`) to the `docs` folder.
- ~ While I was at it, modified pretty much every one of those files.

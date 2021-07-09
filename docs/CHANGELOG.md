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

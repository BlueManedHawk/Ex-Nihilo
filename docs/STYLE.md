# Programming Style Guide for Ex Nihilo

## Introduction

There are many reasons why a programming style guide is necessarry, such as organization, consistency, and æsthetics.  A programming style guide typically encompasses many things, such as whitespace usage, naming of things, comment usage, etc.  This document serves to lay out the style for Ex Nihilo.

## Game Design

Ə is a bad way to design a capital schwa.

### Balance of strategy and skill

If a game focuses too much on skill, then certain people will always be better than others, and to get to their level would require more dedication to than would be fun.

If a game focuses too much on strategy, then a perfect strategy will inevitably arrive, and everybody will use such a strategy, and the game will become very, very boring.

A good balance of strategy and skill will lead to a fun experience.

### Balance of luck

If a game doesn't focus enough on luck, the player will never need to adapt their gameplay, and the game will always follow the same path.

If a game focuses too much on luck, then it will feel unfair to everybody involved.

A good balance of luck keeps players in suspense, while not being super game-changing.

### Balance of patterns and diversity

If a game has too many patterns, the player will always know what's coming, and the player will be bored.

If a game has too much diversity, the player will need to memorize too much, and will be overwhelmed.

A good balance of patterns and diversity will lead to a series of matrices with appropriately spaced holes.

### Balance of help

If the player recieves too much help, the player will get angry at the game for not letting the player do anything.

If the player doesn't recieve enough help, the player will get angry at the game for expecting them to know everything.

A good balance of help will leave the player feeling thankful.

## Why C?

I have chosen to use C instead of C++ (which seems to be the industry standard for games) for a few reasons:

- C is not a bloated language like C++ is.  There are a few niceties missing, but they can be done without.
- C is not an object-oriented language like C++ is.  Object-oriented programming is a broken, messy, confusing paradigm that is only useful in a select few circumstances, none of which are this.
- C is understandable.  Everything is nicely organized and put where it needs to be.  The concepts are proper.

As an analogy:  C++ is if somebody noticed the box of C — a box that, while not quite full, was very nicely organized, and had everything nicely integrated cleanly together, as if done by a professional Tetris player — and decided that the best way to fill the box up was not by carefully designing new pieces to put into it carefully and cleanly, but by dumping the contents carelessly into a new box, spilling a couple things outside on the way, and then tossing in whatever felt "right" until they ended up with an overflowing box of crap.

## The program itself

### Comments

#### Comments are to be used

There is a certain group of people who claim that there exists a thing known as "self-documenting code", this being code which requires no comments to explain what it does.

Self-documenting code does not exist.  Comments are a necessary part of source code, and are crucial to understanding it.

#### Comment types

In general, only the block comment (`/* ... */`) is to be used.  Inline comments look really out-of-place in C.  There are of course certain situations where an inline comment is useful, but they're rare.

The delimiters of a block comment are to be placed at the beginning and end of a comment, _on the same line as the text_.

#### Level of detail

A particular comment should explain what a particular _block_ of code does, not a single statement or a massive chunk.  In general, comments should be placed where there would be a blank line for readability anyway.

### Whitespace

#### Tabs

Tabs are to be used to indent blocks of code, _not to align pieces of code._  Usage of tabs for the purpose of alignment means that more needs to be changed at the same time, leading to commits that bury the important changes under a bunch of noise.  (Of course, reasonable commit messages will mean that the important information won't be lost, but those typically shouldn't be relied upon.)

There are exactly two situations where blocks of code should _not_ be indented:

- Functions
- The main loop

Outside of these situations, all blocks of code should have appropriate indentation.

#### Newlines

Newlines are to be used after every ; and every }, except in `char`s.  Empty lines are to be used to separate distinct bits of code.

#### Spaces

Spaces are to be put around the assignment operator, the five basic math operators, the comparison operators, the logical operators (except `!`), the bitwise operators (except `~`), the compound assignment operators, the comma operator, the ternary operator, function calls, parentheses (except in strings), and the structure dereference operator.

Spaces are to be used before the characters {, }, \*, and ;, except in strings.

### Braces

The opening brace is to be put at the end of the first line before the contained code, and the closing brace is to be put on the last line of the contained code.

### Names

All names are in `PascalCase`.  The exception is `#define`d macros, which are written capitalizedly.  **Constants are not to be capitalised.**

Names should not be too long, and should not be too short.  The first is prevented by restricting names to use only nouns, verbs, and adwords, while the second is prevented by prohibition of shortenings.

# Programming Style Guide for Ex Nihilo

## Introduction

There are many reasons why a programming style guide is necessarry, such as organization, consistency, and æsthetics.  A programming style guide typically encompasses many things, such as whitespace usage, naming of things, comment usage, etc.  This document serves to lay out the style for Ex Nihilo.

Please note that for everything in this document, there _will_ be exceptions that aren't noted explicitly.

## Comments

### Comments are to be used

There is a certain group of people who claim that there exists a thing known as "self-documenting code", this being code which requires no comments to explain what it does.

Self-documenting code does not exist.  Comments are a necessary part of source code, and are crucial to understanding it.

### Comment types

In general, only the block comment (`/* ... */`) is to be used.  Inline comments look really out-of-place in C.  There are of course certain situations where an inline comment is useful, but they're rare.

The delimiters of a block comment are to be placed at the beginning and end of a comment, _on the same line as the text_.

### Level of detail

A particular comment should explain what a particular _block_ of code does, not a single statement or a massive chunk.  In general, comments should be placed where there would be a blank line for readability anyway.

## Whitespace

### Tabs

Tabs are to be used to indent blocks of code, _not to align pieces of code._  Usage of tabs for the purpose of alignment means that more needs to be changed at the same time, leading to commits that bury the important changes under a bunch of noise.  (Of course, reasonable commit messages will mean that the important information won't be lost, but those typically shouldn't be relied upon.)

### Newlines

Newlines are to be used after most every ; and every }.  Empty lines are to be used to separate distinct bits of code.

### Spaces

Spaces are to be put around the assignment operator, the five basic math operators, the comparison operators, the logical operators (except `!`), the bitwise operators (except `~`), the compound assignment operators, the comma operator, the ternary operator, function calls, parentheses, the dereference operator, and the structure dereference operator.

Spaces are to be used before the characters {, }, &, and ;, except in strings.

## Braces

The opening brace is to be put at the end of the first line before the contained code, and the closing brace is to be put on the last line of the contained code.

## Names

All names are in `PascalCase`.  The exception is `#define`d macros, which are written capitalizedly.  **Constants are not to be capitalised.  Constants are _safer_ than variables, not dangerouser.**

Names should not be too long, and should not be too short.  The first is prevented by restricting names to use only nouns, verbs, and adwords, while the second is prevented by prohibition of shortenings.

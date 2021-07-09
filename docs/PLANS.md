# Plans

## General Long-Term Goals

The overarching goal of the project is to create a game in which the player starts with nothing and works their way up.  The game will be a sandbox game featuring extensive magic and technology systems.  The game will contain a comprehensive reference manual built-in to the game, and an interactive user manual will exist to help guide the player.

The game will be 2-dimensional, as I want this game to be playable by anybody, regardless of computing power, and because 3D graphics tend to be incredibly difficult to get to work, but would be required for a 3D implementation of this game to be playable.  However, I do recognize that this may cause problems, especially with 2D graphics failing to  give the game the correct atmosphere, so it's entirely possible that a 3D implementation would occur.  While this would obviously be a tremendous overhaul, I'm not sure whether it would be an entirely separate game or just a major release.

There will be multiple different disciplines of magic and technology.  Certain disciplines would be derived from others, but I'd ideally like to avoid a formalized "research tree".

The game will use keyboard and mouse.  I regret this, since it makes the game tremendously more complicated, but unfortunately it seems to be the only way to get the game to conceptually work.

Most of the sounds will probably be recorded, including the music, which will probably use the only two instruments that I may or may not have access to.  I might do some editing with Audacity or something, but the source will always be recorded.

The intended endgame is a final boss called the Magical Circuit.  There are no plans for a postgame.

Multiplayer support is not planned, as starting with nothing includes starting without friends.  However, networking still may be implemented for other things.

## Specific short-term goals

### Basic software things

- [ ] Checks
	- [X] Verification of OS
	- [ ] Verification of assets
	- [X] Verification of battery
- [ ] Setting up SDL
- [ ] Cleanup
- [ ] Crash handler

### Basic game things

- [ ] Movable character — done with WASD, orientation controlled with (ugh) the mouse
- [ ] Placing and destruction of flooring and not-flooring
- [ ] Interactions with tiles — just something basic to start with
- [ ] Basic **placeholder** inventory system
- [ ] Crafting system, ideally a good one
- [ ] Beasts — basic logic implementation, details later
- [ ] Basic **placeholder** combat
- [ ] Built-in reference manual
- [ ] Interactive user manual — working like a tree of tasks, except more flexible

### Void Magic

Void magic will be the most basic form of magic, necessary to synthesize things from the surrounding nothingness.  This will be used to gain the first materials, and will form the basis of other magic systems.

- [ ] Synthesis of void particulate, an item used to form the most basic of matter.
- [ ] Construction of void particulate into void stone, used as flooring and walls.
- [ ] Throwing void stone (item) onto void stone (floor) to get void rocks.
- [ ] Usage of void rocks on void stone (wall) to subtractively create a crushing table to refine void rocks into void sand, then void silt.
- [ ] Usage of void rocks on void stone (wall) to subtractively create a barrel for synthesis of water from void particulate.
- [ ] Combining of void silt and water to get void dirt, to be imbued with void particulate to grow Rabmab (see below).
- [ ] Some use for void sand as something other than just an intermediate product.

### Background Music

The music of a game is extremely important to give the game an atmosphere, to immerse the player in the world, and to truly make the game feel alive.  Seeing as there exists no good way to create digital music, I've decided that most of the music will be recordings of the only two instruments I may or may not have access to.

- [ ] _The Key_, a multi-movement song played while the game is loading that uses single notes to establish the melodies for the rest of the soundtrack.  The melodies are played in a random order.  It won't mean anything.
- [ ] Fours single-movement songs played on the title screen that _The Key_ transitions to:
	- [ ] _The Lock_, a song which continues _The Key_, but with harmony.  Like _The Key_, it isn't meant to mean anything or invoke any particular feeling.
	- [ ] _The Door_, a song intended to be bright and cheerful, meant to invoke a feeling of happiness and hope, with the intent to focus on how there's nothing in your way.
	- [ ] _The Gate_, a song intended to be dark and forboding, meant to invoke a feeling of depression and fear, with the intent to focus on how there's nothing in your way.
	- [ ] _The Safe_, a mysterious and confusing song.
- [ ] A few multi-movement songs which's movements play during normal gameplay in no particular order:
	- [ ] _The Air of the Solstice_, a track intended to evoke feelings of adventure.  Will be somewhat similar to _The Key_, except not.
	- [ ] _The Peaceable Day_, a track intended to evoke that feeling you get when you're in a hard rain with no thunder on a very toned day.
	- [ ] _The Island of Rocks_, a track intended to invoke a feeling of depression, sadness, and remorse.
- [ ] A few songs which specifically play during combat, each named after a tool of combat.  Deterimining what "during combat" means will be _extremely_ difficult, especially without angering everybody.
- [ ] Songs for bossfights, each one building on the last, and with each one named after the according boss.
- [ ] A credits song, consisting of a medley of everything, and including most of the rest of the soundtrack.

### Sounds

Sounds for the game will probably be harvested from the real world.  Sounds are intended for the following things:

- [ ] Ambience — what exactly this will mean in this context is not yet certain.
- [ ] Beast noises — probably including ambient sounds, attack sounds, being-attacked sounds, walking around, and specific sounds.  (Note:  The player won't emit any sounds.)
- [ ] Interface sounds
- [ ] Other stuff too

### ROMMMMs

ROMMMM stand for Read-Only Memory Metallic Music Medium.  These will be on-demand songs obtained through special circumstances.  These will be arranged in five "books" (since I feel "album" isn't quite the right term):

- [ ] _Genres_ will contain songs in various genres.  I'm not sure how big this'll grow, but I plan for the following:
	- [ ] Classical (is that the right term?)
	- [ ] Fake Jazz (since real jazz is fundamentally bad)
	- [ ] Electronica (I'm thinking something like Animusic, y'know?)
- [ ] _Instruments_ will contain songs focused on a single instrument.  I have no idea how I'll do this.
- [ ] _Misinterpretations_ will be a series of other files disguised as Ogg Vorbis files, or maybe other file formats if Ogg Vorbis is too restrictive.
- [ ] _Numbers_ will be a series of experimental tracks, many of which won't be "music".  The numbers will range from 0 to 13, with the exception of Number 8.  Some of the tracks will have variants.  Not all the numbers have been decided.  Some that have are:
	- [ ] Number 9 will be many people screaming.  This will all be individually gathered, so it won't contain iconic screams like the Wilhelm Scream and the one from Big Enough.  This will have a large variant in which the screams will be separate instead of all together.
	- [ ] Number 6 will be the audio of some bodies of water.  This will have a variant from inside the bodies of water instead.
	- [ ] Number 7 will be a recording of crying.
	- [ ] Number 4 and Number 5 will be on the same ROMMMM.  Number 4 will be a series of short jokes, and Number 5 will be a single long joke.  This ROMMMM will have a variant in which the jokes are cheesier.
	- [ ] _Number Eleven:  The End of It All_ will be a very long, single-movement piece of actual music detailing the fall of something incredible.
	- [ ] Number 13 will be a piece of music made up of the game's sound files.
- [ ] _Çoʔsap_ will be a series of remixes of certain movements of the background music.

### Basic technology

The technology system will be at such a level as to allow the player a high amount of control over the circuits they build, while not being cumbersome and unmanagable.  As the player progresses, they will gain access to smaller and smaller circuits, allowing more things to be done in a single tile.

- [ ] Wires
- [ ] Power sources and sinks
- [ ] Switches
- [ ] Delays
- [ ] Checks
- [ ] Disincentivizers
- [ ] Lamp

### Blood magic

Blood magic will be a system of magic building upon void magic which uses the blood of creatures.  The exact details have not yet been worked out.

### Necromancy

Necromancy will be a late-game magic system building upon blood magic.  It will obviously be very powerful, as striking down one's enemies to have them fight against the rest of the enemies is a pretty clear reincforcing feedback-loop.  As with blood magic, the exact details have not yet been worked out.

### Self-maintainence

- [ ] Class A nutrients, used for healing
- [ ] Class B nutrients, used for energy
- [ ] Mood:  the happier you are, the faster you work
- [ ] Food to get nutrients
- [ ] Some way to modify mood

### Effects

- [ ] Circumstantial effects, permanent and applied to items
- [ ] Permeating effects, temporary and applied to the player
- [ ] Each general effect having an associated situational effect
- [ ] Stacking of effects
- [ ] Some way to obtain these effects
- [ ] Other special effects that do more than simply change an attribute

### Complex combat

A sensible, balanced, and enjoyable combat system is incredibly important for a game to succeed.  A combat system needs the right balance of strategy, requiring the player to determine creative solutions to problems, while also having some skill, with a bit of luck to balance things out.

- [ ] the the the the the the the the the the the the ththe thet the the tht eht the theht eht ehtht ehthe tthe the the theh the theht ehtheht the thteh t'
- [ ] At least the following combat items:
	- [ ] Sword for slashing
	- [ ] Shield for blocking
	- [ ] Spear for piercing
	- [ ] Scythe for reaching
	- [ ] Mace for knocking
	- [ ] Bow (long and compound forms)
- [ ] Knockback
- [ ] Maybe using the weapons for other purposes too?

### Automation

Automation will be a category of technology used to automate menial tasks.  Because the entire world will be loaded at once, this automation will mostly occur in the background while the player does other things, removing the need for the player to sit in one place waiting for something to get done.  As with basic automation, the system will be extremely modular.  The exact details have not yet been fleshed out.

### Beasts

Beasts will be autonomous entities.  Friendly beasts will be called Creatures, whereas unfriendly beasts will be called Monsters.  I don't have too many ideas for beasts yet, but I have a couple.

- [ ] Puffballs — adorable little balls of fluff, which can be created by leaving fluff (probably synthesized by imbuing some plant fiber with void particulate) in adequate quantities on the ground and waiting a bit.  They naturally grow and shed fluff, which can be harvested for…something, I dunno, or can be left there to get more puffballs.  They will come in small variations.
- [ ] Glork-pe — simple monsters from the shadows.  Slompling around, they have a simple melee attack.  If a player creates a large platform in the shadows with a single way to them, they can be like that one berserker sometime before of the Normal Invasion that got stabbed in the balls by people in a barrel.

### Plants

- [ ] Rabmab — a simple plant with a single green stalk that grows fast until it fruits with a large, bulbous, orange ball that gives a bit of Class A nutrients and some Class B nutrients.  Can be manufactured into Plant Fiber, which can imbued with Void Particulate to get Fluff.
- [ ] Qlurectrio — a fast-growing plant that gives a very nice building material that is much easier to obtain than void stone, especially with automation.  (The Q is pronouced as a velar plosive — a Q is used here because it looks correcter.)

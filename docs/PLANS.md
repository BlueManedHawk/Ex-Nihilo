# Plans

## The Long-Term Goal

The long-term goal of the project is to create a game in which the player starts with nothing and works their way up.  The game will feature extensive magic and technology systems, along with built-in documentation of many parts of the game.  While the game will be a sandbox game, a tree of advancements will exist to help guide the player.

## Short-term goals

### Basic game things

- [ ] Movable character
- [ ] Placing and destruction of flooring
- [ ] Placing and destruction of not-flooring
- [ ] Interactions with tiles
- [ ] Inventory
- [ ] Items
- [ ] Crafting
- [ ] Beasts
- [ ] Basic placeholder combat
- [ ] Built-in documentation

### Void Magic

Void magic will be the most basic form of magic, necessary to synthesize things from the surrounding nothingness.  This will be used to gain the first materials, and will form the basis of other magic systems.

- [ ] Integer counter which increases by one each second, initially capped at 5, storing void particulate
- [ ] Void stone, synthesized from 5 void particulate, used as flooring
- [ ] Throwing void stone to break into void rocks
- [ ] Crushing table, made by using void rocks to refine void stone, used to refine void rocks into void gravel, then void sand
- [ ] Altar, made like crushing table, consumes certain materials and void particulate to expand void particulate capacity
- [ ] Fluid barrel, made like crushing table, can consume 10 void particulate to synthesize water
- [ ] Void silt, made from saturating void sand
- [ ] Void dirt, made from void silt and void gravel, forms the basis of plants, can be imbued with 15 void particulate to grow…something.

### Music and Sound

The music and sound of a game is extremely important to give the game an atmosphere, to immerse the player in the world, and to truly make the game feel alive.  ~~The game will use simple sounds to go with its simple graphics, using triangle, square, sawtooth, and noise waves.~~  (After some experimentation, it appears that this can no longer be gaurenteed; thereby, no gaurentee is made about what the music will sound like.)

- [ ] _The Key_, a song played while the game is loading that uses simple single tones, going over each of the melodies used throughout the soundtrack, which overall doesn't mean anything and isn't intended to evoke any particular feeling.  Each melody is assigned a movement, and the movements play in a random order.
- [ ] Fours single-movement songs played on the title screen that _The Key_ transitions to:
	- [ ] _The Lock_, a song which continues _The Key_, but with harmony.  Like _The Key_, it isn't meant to mean anything or invoke any particular feeling.
	- [ ] _The Door_, a song intended to be bright and cheerful, meant to invoke a feeling of happiness and hope, with the intent to focus on how there's nothing in your way.
	- [ ] _The Gate_, a song intended to be dark and forboding, meant to invoke a feeling of depression and fear, with the intent to focus on how there's nothing in your way.
	- [ ] _The Safe_, a mysterious and confusing song.
- [ ] Several multi-movement songs which play during normal gameplay in no particular order, intended to invoke the following feelings:
	- [ ] Calmness
	- [ ] Excitement
	- [ ] Sadness
	- [ ] Confusion
	- [ ] Happiness
	- [ ] Fear
	- [ ] Satisfaction
- [ ] A few songs which specifically play during combat.
- [ ] Songs for bossfights, each one building on the last.
- [ ] A credits song, consisting of a medley of everything, and including most of the rest of the soundtrack.

### Basic technology

The technology system will be at such a level as to allow the player a high amount of control over the circuits they build, while not being cumbersome and unmanagable.  As the player progresses, they will gain access to smaller and smaller circuits, allowing more things to be done in a single tile.

- [ ] Wires
- [ ] Power flows and sinks
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

- [ ] Situational effects, permanent and applied to items
- [ ] General effects, temporary and applied to the player
- [ ] Each general effect having an associated situational effect
- [ ] Stacking of effects
- [ ] Some way to obtain these effects

### Complex combat

A sensible, balanced, and enjoyable combat system is incredibly important for a game to succeed.  A combat system needs the right balance of strategy, requiring the player to determine creative solutions to problems, while also having some skill, with a bit of luck to balance things out.  However, it won't do to just have a simple combat system…

- [ ] Each weapon will have several forms of attack:
	- [ ] Swing
	- [ ] Thrust
	- [ ] Block
	- [ ] Combo
	- [ ] Special
- [ ] the the the the the the the the the the the the ththe thet the the tht eht the theht eht ehtht ehthe tthe the the theh the theht ehtheht the thteh t'
- [ ] At least the following combat items:
	- [ ] Sword
	- [ ] Shield
	- [ ] Axe
	- [ ] Scythe
	- [ ] Bow (long and compound forms)
- [ ] Knockback

## Finished Short-term Goals

### Basic things

- [ ] ~~Draw to the screen~~
- [ ] ~~Draw specific things to the screen~~
- [ ] ~~Have the screen react to keypresses~~
- [ ] ~~Setup drawing text to the screen~~
- [ ] ~~Allow "the screen" to be a window in X11~~

After looking around for a bit, I couldn't find a single damn solution that didn't use X11 and some nonstandard graphics library; therefore, I am unfortunately going to need to use X11 and SDL (which seems like the best choice) in order to do this.  For this reason, I have chosen to reforment this section as follows:

- [X] Create a window
- [X] Draw to the window
- [X] Draw something specific to the window
- [X] Allow the window to react to keypresses
- [X] ~~Setup SDL (whatever that means)~~
- [X] Make the window fullscreen
- [X] Setup drawing text to the screen ~~(somewhat complete — basic logic implemented, but not yet the assets)~~


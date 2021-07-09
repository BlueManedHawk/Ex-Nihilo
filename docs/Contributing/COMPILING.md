# Compiling Ex Nihilo

Clone the repository; then, in the root directory, you can run one of the following commands:

- `make` — Chastises you for not giving any arguments, then redirects you here.
- `make release` — Compiles a non-debug build of the game as `Ex Nihilo.elf` and compresses the assets as `Assets.txz`.
- `make lldb` — Compile a release build for use with LLDB.  Debug builds are always prepared for this.  Does not create assets archive.
- `make debug` — Compiles a debug build of the game as `Ex Nihilo DEBUG.elf`.  Does not create assets archive.
- `make binary` — Compiles a non-debug build of the game as `Ex Nihilo.elf`.  Does not create assets archive.
- `make assets` — Creates just an assets archive as `Assets.txz`.

There is no `make clean` command because I don't trust myself to not screw it up.  Besides, the only files this can create are `Ex Nihilo.elf`, `Ex Nihilo DEBUG.elf`, and `Assets.txz`, which the user can remove manually.

I do intend to expand this to be better in the future, primarily by allowing it to create prepared packages for package managers (e.g. `.deb` and `.rpm` files).  However, this hasn't yet been implemented.

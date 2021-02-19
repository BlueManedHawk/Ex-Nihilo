# Compiling Ex Nihilo

Run the command

```bash
clang-11 -Wall -Werror -Wextra -pedantic "Ex Nihilo.c" `sdl2-config --cflags --libs` -o "Whatever you want the executable to be called.elf"
```

in the directory containing the file `Ex Nihilo.c`.  Do not that the `-Wall -Wextra -Werror -pedantic` part isn't strictly necessary; I just use it to help catch problems, and it doesn't affect the final executable in any way other that determining if it exists.

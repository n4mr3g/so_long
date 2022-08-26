# so_long

![image](https://user-images.githubusercontent.com/26860329/186975678-41fd5f18-ddf4-40fe-a708-8d5b1238203a.png)


Simple game project written completely in C.

I've written this game as part of the core curriculum of the coding school [42 Wolfsburg](https://42wolfsburg.de/).

As per the subject required, I used the [minilibx library](https://github.com/42Paris/minilibx-linux) and my own versions of some other previous projects from the 42 core curriculum:

### -libft:
Library with rewritten functions from the C standard library + some extras.
### -get_next_line:
Read line by line from a file descriptor.
### -ft_printf:
Rewritten version of the _printf_ function.

## Objective:

The objective of the game is to, in the minimum amount of moves possible, collect all the gold and exit through the door afterwards.

The optional enemies always chase the player, and running onto one of them will finish the game.

### Keys:
**WASD** to move, **ESC** to exit.

## Usage:

After compiling with _make_, run the program like this:

```./so_long [path to map].ber```

The executable takes a .ber file as an argument, which should contain a valid map for the game that should look something like this:
```
11111111
1P0C0001
100000C1
10000001
10101011
10101011
10101011
10111011
10101011
10101011
10XXX0E1
11111111
```
Where each character means the following:
```
1: Walls
P: Player
E: Exit
0: Floor
C: Collectibles (gold)
X: Enemies.
```
Additionally, the map must comply with the following requirementes:
```
-It must be rectangular
-It must have exactly one exit
-It must have exactly one player
-It must have at least one collectible
-It must be surrounded by walls
-File extension should be ".ber" (".BER" or ".Ber" won't work)
```

And of course, as with every other project: no memory leaks, "forbidden functions and control structures", segmentation faults or a relinking Makefile are tolerated.

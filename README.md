# so_long

![image](https://user-images.githubusercCancel changesontent.com/26860329/186975678-41fd5f18-ddf4-40fe-a708-8d5b1238203a.png)


Simple game project written completely in C .

This project part of the core curriculum of the coding school 42 Wolfsburg.

As per the subject required, I used the minilibx library (https://github.com/42Paris/minilibx-linux) and some other previous projects from the 42 core curriculum:

-libft (rewritten functions from the C standard library + some extras)
-get_next_line (read line by line from a file descriptor)
-ft_printf (rewritten version of printf)

The objective of the game is to collect all the gold, avoid the (optional) enemies, and exit through the door.

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

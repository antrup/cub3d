# cub3d
3D dynamic view inside a maze (Wolfenstein like) using ray-casting

### Dependencies
X11 include files (package xorg)
XShm extension (package libxext-dev)
Utility functions from BSD systems - development files (package libbsd-dev)

sudo apt-get install xorg libxext-dev libbsd-dev (Ubuntu)

Minilibx: https://github.com/42Paris/minilibx-linux

cd mlx-linux && ./configure

### Build
make

### Run
./cub3D path_to_map

## Map

The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.

See map/test.cub for example.

- The map must be closed/surrounded by walls, if not the program returns
an error.
- Except for the map content, each type of element can be separated by one or
more empty line(s).
- Except for the map content which always has to be the last, each type of
element can be set in any order in the file.
- Except for the map, each type of information from an element can be separated
by one or more space(s).
- Spaces are a valid part of the map.

Each element (except the map) firsts information is the type identifier (com-
posed by one or two character(s)), followed by all specific informations for each
object in a strict order such as :

∗ North texture:
NO ./path_to_the_north_texture
- identifier: NO
- path to the north texure

∗ South texture:
SO ./path_to_the_south_texture
- identifier: SO
- path to the south texure

∗ West texture:
WE ./path_to_the_west_texture
- identifier: WE
- path to the west texure

∗ East texture:
EA ./path_to_the_east_texture
- identifier: EA
- path to the east texure

∗ Floor color:
F 220,100,0
- identifier: F
- R,G,B colors in range [0,255]: 0, 255, 255

∗ Ceilling color:
C 225,30,0
- identifier: C
- R,G,B colors in range [0,255]: 0, 255, 255

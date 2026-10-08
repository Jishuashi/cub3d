*This project has been created as part of the 42 curriculum by hchartie, ldeplace.*

<h1 align="center">CUB3D</h1>

<p align="center">
	<em>A small 3D maze renderer using raycasting, inspired by Wolfenstein 3D.</em>
</p>

<p align="center">
	<img src="https://img.shields.io/badge/%20-LANGUAGE-6C757D?style=for-the-badge&labelColor=00599C&logo=c&logoColor=white" alt="LANGUAGE C badge" />
	&nbsp;&nbsp;
	<img src="https://img.shields.io/badge/%20-Cub3D-6C757D?style=for-the-badge&labelColor=000000&logo=42&logoColor=white" alt="42 Cub3D" />
</p>

<p align="center">
	<sub>
		<code>make</code> &nbsp;•&nbsp; <code>./cub3D maps/valid/valid_normal.cub</code>
	</sub>
</p>

---

## Description

Cub3D is a first-person "3D" maze viewer written in C with the MiniLibX graphics library. Starting from a simple 2D map described in a `.cub` file, the program renders what a player sees inside the maze using the **raycasting** technique popularized by Wolfenstein 3D.

The goal of the project is to learn the basics of real-time graphics and of parsing user input safely:

- Parsing and validating a `.cub` configuration file (textures, colors, map).
- Checking that the map is closed by walls, using a flood fill.
- Casting one ray per screen column with the DDA algorithm to find the wall hit.
- Drawing textured walls, with a different texture per compass direction (North, South, East, West), plus flat floor and ceiling colors.
- Handling keyboard and window events (movement, rotation, clean exit).
- Managing memory carefully: every allocation is freed, including on error paths.

### Features

- Textured walls, one texture per cardinal direction.
- Configurable floor and ceiling colors.
- Player spawn orientation taken from the map (`N`, `S`, `E`, `W`).
- Forward/backward movement, strafing, and rotation, with wall collisions and sliding along walls.
- Strict error handling with explicit messages (bad extension, unknown or duplicate key, missing texture, invalid color, open map, wrong number of players, ...).

### Project structure

```
src/
├── cube3d.c            main, window and hooks
├── init.c              initialization of map, textures and MLX
├── parsing/            .cub parsing, color/texture parsing, map checks, flood fill
├── gameplay/           player, movement, key handling
├── raycasting/         ray setup and DDA
├── rendering/          texture loading and drawing
├── utils/              file reading, errors, memory, helpers
└── libft/              personal C library
maps/valid/             maps that must be accepted
maps/err/               maps that must be rejected
textures/               XPM textures
mlx/                    MiniLibX
```

## Instructions

### Requirements

- Linux or macOS
- `cc`, `make`
- X11 development libraries (`libx11-dev`, `libxext-dev` on Debian/Ubuntu) for MiniLibX on Linux

### Compilation

```bash
make
```

Make targets:

- `make` — build MiniLibX, libft and the `cub3D` executable
- `make clean` — remove object files
- `make fclean` — remove object files and the executable
- `make re` — `fclean` then `make`
- `make norm` — run norminette on `src/`

### Execution

```bash
./cub3D <map.cub>
```

Examples:

```bash
./cub3D maps/valid/valid_normal.cub
./cub3D maps/valid/valid_spawn_n.cub    # spawns facing North
./cub3D maps/err/err_open_top.cub       # prints an error and exits
```

Run it from the root of the repository: the texture paths of the provided maps are relative (`./textures/...`).

### Controls

| Key | Action |
|---|---|
| `W` / `Up` | Move forward |
| `S` / `Down` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `Left` / `Right` | Rotate the view |
| `ESC` / `Q` | Quit |
| Window close button | Quit |

### Configuration file (`.cub`)

The file name must end with `.cub`. It contains six identifiers, in any order, followed by the map, which must be the last element of the file:

```
NO ./textures/no_holder.xpm
SO ./textures/so_holder.xpm
WE ./textures/we_holder.xpm
EA ./textures/ea_holder.xpm

F 220,100,0
C 28,157,186

111111
100101
101001
1100N1
111111
```

| Identifier | Meaning |
|---|---|
| `NO`, `SO`, `WE`, `EA` | Path of the north, south, west and east wall textures (XPM) |
| `F` | Floor color, `R,G,B` with each value in `0..255` |
| `C` | Ceiling color, `R,G,B` with each value in `0..255` |

Map characters:

- `1` wall, `0` empty space
- `N`, `S`, `E`, `W` player start position and orientation (exactly one)
- ` ` (space) is allowed, but a walkable cell must never touch a space or the border of the map: the playable area must be closed by walls

On any error, the program prints `Error` followed by an explanation and exits with status `1`.

### Test maps

- `maps/valid/` contains maps that must load, including one per spawn orientation (`valid_spawn_n/s/e/w`), unusual layouts and formatting variants.
- `maps/err/` contains maps that must be rejected (unknown or duplicate keys, bad colors, missing textures, open maps, wrong player count, ...).

To check every map quickly:

```bash
for f in maps/err/*.cub; do ./cub3D "$f" > /dev/null 2>&1; echo "$? $f"; done   # all must print 1
```

The `*_holder.xpm` textures each show a colored letter (N, S, E, W) so that the orientation of every wall can be checked at a glance.

## Resources

References used for the project:

- Lode Vandevenne, *Raycasting* tutorial: https://lodev.org/cgtutor/raycasting.html
- Wikipedia, *Ray casting*: https://en.wikipedia.org/wiki/Ray_casting
- Wikipedia, *Digital differential analyzer* (DDA): https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)
- MiniLibX documentation and manual pages (`mlx/man`): https://harm-smits.github.io/42docs/libs/minilibx
- Wikipedia, *Flood fill*: https://en.wikipedia.org/wiki/Flood_fill
- XPM format description: https://en.wikipedia.org/wiki/X_PixMap
- Xlib documentation (events and masks): https://tronche.com/gui/x/xlib/

### AI usage

An AI assistant (Claude Code) was used as a helper, never as a replacement for understanding the code:

- **Testing:** running the project against the evaluation checklist (compilation, parsing errors, memory leaks with valgrind, movement and spawn orientation, texture orientation) and writing a test report.
- **Test data:** generating the maps in `maps/valid/` and `maps/err/`, and the colored letter textures (`*_holder.xpm`).


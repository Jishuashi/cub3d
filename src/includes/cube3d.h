/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:18 by hchartie          #+#    #+#             */
/*   Updated: 2026/09/17 10:30:25 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/libft.h"
# include "./parse_map.h"
# include "./cub_format_checker.h"
# include "./parse_textures.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_SPEED 0.09
# define ROT_SPEED 0.1
# define PLAYER_RADIUS 0.2

typedef struct s_image
{
	void			*image;
	char			*data;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_image;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}	t_player;

typedef struct s_ray
{
	double			dir_x;
	double			dir_y;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	double			perp_dist;
	double			wall_x;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}	t_ray;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_assets		*assets;
	t_image			screen;
	t_player		player;
	t_ray			ray;
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_left;
	int				key_right;
}	t_game;

int					check_map(t_map *map);
void				init(t_game *data, t_file *file, int map_line);
void				start(t_game *data);
int					flood_fill(char **map, t_point *pos);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:18 by hchartie          #+#    #+#             */
/*   Updated: 2026/09/15 13:25:48 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/libft.h"
# include "./parse_map.h"
# include "./cub_format_checker.h"
# include "./parse_textures.h"
# include "./mlx_linux.h"
# include <fcntl.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

typedef struct s_image
{
	void	*image;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_assets	*assets;
	t_image		screen;
}	t_game;

int		check_map(t_map *map);
void	init(t_game *data, t_file *file, int map_line);
void	start(t_game *data);
int		flood_fill(char **map, t_point *pos);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:18 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/23 17:23:44 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/libft.h"
# include "./parse_map.h"
# include "./cub_format_checker.h"
# include "./parse_textures.h"
# include <fcntl.h>

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_assets	*assets;
}	t_game;

int		check_map(t_map *map);
void	init(t_game *data, t_file *file, int map_line);
void	start(t_game *data);
int		flood_fill(char **map, t_point *pos);

#endif

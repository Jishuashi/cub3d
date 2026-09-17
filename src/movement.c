/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:18:12 by louka2b           #+#    #+#             */
/*   Updated: 2026/09/17 10:27:32 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"
#include "includes/movement.h"
#include "includes/render.h"
#include <math.h>

static int	cell_walkable(t_game *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= (int)data->map->heigh || map_x < 0
		|| !data->map->grid[map_y]
		|| map_x >= (int)ft_strlen(data->map->grid[map_y]))
		return (0);
	return (data->map->grid[map_y][map_x] != '1'
		&& data->map->grid[map_y][map_x] != ' ');
}

static int	is_walkable(t_game *data, double x, double y)
{
	return (cell_walkable(data, x - PLAYER_RADIUS, y - PLAYER_RADIUS)
		&& cell_walkable(data, x + PLAYER_RADIUS, y - PLAYER_RADIUS)
		&& cell_walkable(data, x - PLAYER_RADIUS, y + PLAYER_RADIUS)
		&& cell_walkable(data, x + PLAYER_RADIUS, y + PLAYER_RADIUS));
}

void	move_player(t_game *data, double move_x, double move_y)
{
	if (is_walkable(data, data->player.x + move_x, data->player.y))
		data->player.x += move_x;
	if (is_walkable(data, data->player.x, data->player.y + move_y))
		data->player.y += move_y;
}

void	rotate_player(t_game *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(angle)
		- data->player.dir_y * sin(angle);
	data->player.dir_y = old_dir_x * sin(angle)
		+ data->player.dir_y * cos(angle);
	data->player.plane_x = data->player.plane_x * cos(angle)
		- data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle)
		+ data->player.plane_y * cos(angle);
}

void	redraw(t_game *data)
{
	draw_background(data);
	draw_walls(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen.image, 0, 0);
}

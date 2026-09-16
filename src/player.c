/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:50:21 by louka             #+#    #+#             */
/*   Updated: 2026/09/16 23:12:47 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"
#include <math.h>

#define MOVE_SPEED 0.1
#define ROT_SPEED 0.1

static int	is_walkable(t_game *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= (int)data->map->heigh || map_x < 0
		|| !data->map->grid[map_y] || map_x >= (int)ft_strlen(data->map->grid[map_y]))
		return (0);
	return (data->map->grid[map_y][map_x] != '1'
		&& data->map->grid[map_y][map_x] != ' ');
}

static void	move_player(t_game *data, double move_x, double move_y)
{
	if (is_walkable(data, data->player.x + move_x, data->player.y))
		data->player.x += move_x;
	if (is_walkable(data, data->player.x, data->player.y + move_y))
		data->player.y += move_y;
}

static void	rotate_player(t_game *data, double angle)
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

int	key_press(int keycode, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keycode == 113 || keycode == 65307)
		return (mlx_loop_end(data->mlx), 0);
	if (keycode == 119 || keycode == 65362)
		data->key_w = 1;
	else if (keycode == 115 || keycode == 65364)
		data->key_s = 1;
	else if (keycode == 97)
		data->key_left = 1;
	else if (keycode == 100)
		data->key_right = 1;
	else if (keycode == 65361)
		data->key_left = 1;
	else if (keycode == 65363)
		data->key_right = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keycode == 119 || keycode == 65362)
		data->key_w = 0;
	else if (keycode == 115 || keycode == 65364)
		data->key_s = 0;
	else if (keycode == 97)
		data->key_left = 0;
	else if (keycode == 100)
		data->key_right = 0;
	else if (keycode == 65361)
		data->key_left = 0;
	else if (keycode == 65363)
		data->key_right = 0;
	return (0);
}

int	game_loop(void *param)
{
	t_game	*data;
	int		updated;

	data = (t_game *)param;
	updated = 0;
	if (data->key_w)
		move_player(data, data->player.dir_x * MOVE_SPEED,
			data->player.dir_y * MOVE_SPEED), updated = 1;
	if (data->key_s)
		move_player(data, -data->player.dir_x * MOVE_SPEED,
			-data->player.dir_y * MOVE_SPEED), updated = 1;
	if (data->key_left)
		rotate_player(data, -ROT_SPEED), updated = 1;
	if (data->key_right)
		rotate_player(data, ROT_SPEED), updated = 1;
	if (updated)
	{
		draw_background(data);
		draw_walls(data);
		mlx_put_image_to_window(data->mlx, data->win, data->screen.image, 0, 0);
	}
	return (0);
}

void	init_player(t_game *data)
{
	int	x;
	int	y;
	char	orientation;

	y = 0;
	while (y < (int)data->map->heigh)
	{
		x = 0;
		while (data->map->grid[y][x++])
		{
			orientation = data->map->grid[y][x];
			if (orientation == 'N' || orientation == 'S'
				|| orientation == 'E' || orientation == 'W')
			{
				data->player.x = x + 0.5;
				data->player.y = y + 0.5;
				data->player.dir_x = (orientation == 'E') - (orientation == 'W');
				data->player.dir_y = (orientation == 'S') - (orientation == 'N');
				data->player.plane_x = -data->player.dir_y * 0.66;
				data->player.plane_y = data->player.dir_x * 0.66;
				return ;
			}
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:50:21 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/29 15:23:01 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/movement.h"
#include "../includes/player.h"
#include "../includes/render.h"

/**
 * Key press hook.
 *
 * Quits on ESC or Q, otherwise raises the flag of the pressed movement key.
 *
 * @param keycode Key symbol.
 * @param param Pointer to the game structure.
 * @return Always 0.
 */
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
		data->key_a = 1;
	else if (keycode == 100)
		data->key_d = 1;
	else if (keycode == 65361)
		data->key_left = 1;
	else if (keycode == 65363)
		data->key_right = 1;
	return (0);
}

/**
 * Key release hook: clears the flag of the released key.
 *
 * @param keycode Key symbol.
 * @param param Pointer to the game structure.
 * @return Always 0.
 */
int	key_release(int keycode, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keycode == 119 || keycode == 65362)
		data->key_w = 0;
	else if (keycode == 115 || keycode == 65364)
		data->key_s = 0;
	else if (keycode == 97)
		data->key_a = 0;
	else if (keycode == 100)
		data->key_d = 0;
	else if (keycode == 65361)
		data->key_left = 0;
	else if (keycode == 65363)
		data->key_right = 0;
	return (0);
}

/**
 * Per-frame hook: updates the player and redraws if a key is held.
 *
 * @param param Pointer to the game structure.
 * @return Always 0.
 */
int	game_loop(void *param)
{
	t_game	*data;
	int		updated;

	data = (t_game *)param;
	updated = 0;
	if (data->key_w || data->key_s || data->key_a || data->key_d
		|| data->key_left || data->key_right)
	{
		update_player(data);
		updated = 1;
	}
	if (updated)
		redraw(data);
	return (0);
}

/**
 * Sets the player's position and view from its spawn cell.
 *
 * The position is the cell center; direction and camera plane follow the
 * orientation.
 *
 * @param data Game structure.
 * @param x Column of the spawn cell.
 * @param y Row of the spawn cell.
 * @param orientation 'N', 'S', 'E' or 'W'.
 */
static void	set_player(t_game *data, int x, int y, char orientation)
{
	data->player.x = x + 0.5;
	data->player.y = y + 0.5;
	data->player.dir_x = (orientation == 'E') - (orientation == 'W');
	data->player.dir_y = (orientation == 'S') - (orientation == 'N');
	data->player.plane_x = -data->player.dir_y * 0.66;
	data->player.plane_y = data->player.dir_x * 0.66;
}

/**
 * Finds the spawn character in the map and initializes the player.
 *
 * @param data Game structure.
 */
void	init_player(t_game *data)
{
	int		x;
	int		y;
	char	orientation;

	y = 0;
	while (y < (int)data->map->heigh)
	{
		x = 0;
		while (data->map->grid[y][x])
		{
			orientation = data->map->grid[y][x];
			if (orientation == 'N' || orientation == 'S'
				|| orientation == 'E' || orientation == 'W')
			{
				set_player(data, x, y, orientation);
				return ;
			}
			x++;
		}
		y++;
	}
}

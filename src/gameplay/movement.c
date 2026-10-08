/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:18:12 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/29 15:22:45 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/movement.h"
#include "../includes/render.h"
#include <math.h>

/**
 * Tells whether the map cell containing a point is walkable.
 *
 * @param data Game structure.
 * @param x X coordinate in map units.
 * @param y Y coordinate in map units.
 * @return 1 if the cell is inside the map and not a wall or space, 0
 * otherwise.
 */
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

/**
 * Tells whether the player can stand at a position.
 *
 * Checks the four corners of the player's collision box.
 *
 * @param data Game structure.
 * @param x Target X coordinate.
 * @param y Target Y coordinate.
 * @return 1 if all four corners are walkable, 0 otherwise.
 */
static int	is_walkable(t_game *data, double x, double y)
{
	return (cell_walkable(data, x - PLAYER_RADIUS, y - PLAYER_RADIUS)
		&& cell_walkable(data, x + PLAYER_RADIUS, y - PLAYER_RADIUS)
		&& cell_walkable(data, x - PLAYER_RADIUS, y + PLAYER_RADIUS)
		&& cell_walkable(data, x + PLAYER_RADIUS, y + PLAYER_RADIUS));
}

/**
 * Moves the player, sliding along walls.
 *
 * The X and Y axes are tested separately so the player slides instead of
 * stopping on contact.
 *
 * @param data Game structure.
 * @param move_x Displacement along X.
 * @param move_y Displacement along Y.
 */
void	move_player(t_game *data, double move_x, double move_y)
{
	if (is_walkable(data, data->player.x + move_x, data->player.y))
		data->player.x += move_x;
	if (is_walkable(data, data->player.x, data->player.y + move_y))
		data->player.y += move_y;
}

/**
 * Rotates the view direction and the camera plane.
 *
 * @param data Game structure.
 * @param angle Angle in radians (positive turns right).
 */
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

/**
 * Renders a full frame and displays it in the window.
 *
 * @param data Game structure.
 */
void	redraw(t_game *data)
{
	draw_background(data);
	draw_walls(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen.image, 0, 0);
}

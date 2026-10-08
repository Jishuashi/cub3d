/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:17:51 by louka2b           #+#    #+#             */
/*   Updated: 2026/09/29 15:23:04 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/movement.h"

/**
 * Applies the movements and rotations of the currently held keys.
 *
 * @param data Game structure.
 */
void	update_player(t_game *data)
{
	if (data->key_w)
		move_player(data, data->player.dir_x * MOVE_SPEED,
			data->player.dir_y * MOVE_SPEED);
	if (data->key_s)
		move_player(data, -data->player.dir_x * MOVE_SPEED,
			-data->player.dir_y * MOVE_SPEED);
	if (data->key_a)
		move_player(data, data->player.dir_y * MOVE_SPEED,
			-data->player.dir_x * MOVE_SPEED);
	if (data->key_d)
		move_player(data, -data->player.dir_y * MOVE_SPEED,
			data->player.dir_x * MOVE_SPEED);
	if (data->key_left)
		rotate_player(data, -ROT_SPEED);
	if (data->key_right)
		rotate_player(data, ROT_SPEED);
}

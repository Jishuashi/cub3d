/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:50:21 by louka             #+#    #+#             */
/*   Updated: 2026/09/15 13:50:24 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	init_player(t_game *data)
{
	int	x;
	int	y;
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
				data->player.x = x + 0.5;
				data->player.y = y + 0.5;
				data->player.dir_x = (orientation == 'E') - (orientation == 'W');
				data->player.dir_y = (orientation == 'S') - (orientation == 'N');
				data->player.plane_x = -data->player.dir_y * 0.66;
				data->player.plane_y = data->player.dir_x * 0.66;
				return ;
			}
			x++;
		}
		y++;
	}
}

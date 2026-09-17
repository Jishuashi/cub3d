/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:18:04 by louka2b           #+#    #+#             */
/*   Updated: 2026/09/17 10:18:06 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static void	init_ray_y(t_game *data, t_ray *ray)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (data->player.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - data->player.y) * ray->delta_y;
	}
}

void	init_ray(t_game *data, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dir_x = data->player.dir_x + data->player.plane_x * camera_x;
	ray->dir_y = data->player.dir_y + data->player.plane_y * camera_x;
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (data->player.x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - data->player.x) * ray->delta_x;
	}
	init_ray_y(data, ray);
}

int	ray_hits_wall(t_game *data, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= (int)data->map->heigh
		|| ray->map_x < 0 || !data->map->grid[ray->map_y]
		|| ray->map_x >= (int)ft_strlen(data->map->grid[ray->map_y])
		|| data->map->grid[ray->map_y][ray->map_x] == '\0')
		return (1);
	return (data->map->grid[ray->map_y][ray->map_x] == '1'
		|| data->map->grid[ray->map_y][ray->map_x] == ' ');
}

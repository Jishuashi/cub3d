/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:50:28 by louka             #+#    #+#             */
/*   Updated: 2026/09/17 10:11:34 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"
#include "includes/raycast.h"
#include "includes/render.h"
#include "includes/raycast.h"

static void	cast_ray(t_game *data, t_ray *ray)
{
	while (!ray_hits_wall(data, ray))
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}

static void	prepare_wall(t_game *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist = ray->side_x - ray->delta_x;
	else
		ray->perp_dist = ray->side_y - ray->delta_y;
	if (ray->perp_dist < 0.001)
		ray->perp_dist = 0.001;
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_dist);
	if (ray->line_height > SCREEN_HEIGHT * 2)
		ray->line_height = SCREEN_HEIGHT * 2;
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = data->player.y + ray->perp_dist * ray->dir_y;
	else
		ray->wall_x = data->player.x + ray->perp_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	render_column(t_game *data, int screen_x)
{
	t_ray		ray;

	init_ray(data, &ray, screen_x);
	cast_ray(data, &ray);
	prepare_wall(data, &ray);
	draw_wall_column(data, &ray, screen_x);
}

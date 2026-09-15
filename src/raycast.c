/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:50:28 by louka             #+#    #+#             */
/*   Updated: 2026/09/15 13:50:30 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"
#include <math.h>

static void	init_ray(t_game *data, t_ray *ray, int x)
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
}

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

static void	cast_ray(t_game *data, t_ray *ray)
{
	init_ray_y(data, ray);
	while (data->map->grid[ray->map_y][ray->map_x] != '1')
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
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_dist);
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

static t_texture	*get_texture(t_game *data, t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
		return (&data->assets->ea_img);
	if (ray->side == 0)
		return (&data->assets->we_img);
	if (ray->dir_y > 0)
		return (&data->assets->so_img);
	return (&data->assets->no_img);
}

void	render_column(t_game *data, int screen_x)
{
	t_ray		ray;
	t_texture	*texture;
	int		x;
	int		y;
	int		d;
	int		tex_y;

	init_ray(data, &ray, screen_x);
	cast_ray(data, &ray);
	prepare_wall(data, &ray);
	texture = get_texture(data, &ray);
	x = (int)(ray.wall_x * texture->width);
	if ((ray.side == 0 && ray.dir_x > 0)
		|| (ray.side == 1 && ray.dir_y < 0))
		x = texture->width - x - 1;
	y = ray.draw_start;
	while (y <= ray.draw_end)
	{
		d = y * 256 - SCREEN_HEIGHT * 128 + ray.line_height * 128;
		tex_y = ((d * texture->height) / ray.line_height) / 256;
		put_pixel(&data->screen, screen_x, y, *(unsigned int *)(texture->data
			+ tex_y * texture->line_length + x * (texture->bits_per_pixel / 8)));
		y++;
	}
}

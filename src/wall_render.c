/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:17:58 by louka2b           #+#    #+#             */
/*   Updated: 2026/09/17 10:22:14 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"
#include "includes/render.h"

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

static int	get_texture_x(t_ray *ray, t_texture *texture)
{
	int	x;

	x = (int)(ray->wall_x * texture->width);
	if (x < 0)
		x = 0;
	if (x >= texture->width)
		x = texture->width - 1;
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		x = texture->width - x - 1;
	return (x);
}

static int	get_texture_y(t_ray *ray, t_texture *texture, int y)
{
	int	d;
	int	tex_y;

	d = y * 256 - SCREEN_HEIGHT * 128 + ray->line_height * 128;
	tex_y = ((d * texture->height) / ray->line_height) / 256;
	if (tex_y < 0)
		return (0);
	if (tex_y >= texture->height)
		return (texture->height - 1);
	return (tex_y);
}

void	draw_wall_column(t_game *data, t_ray *ray, int screen_x)
{
	t_texture	*texture;
	int			x;
	int			y;
	int			tex_y;

	texture = get_texture(data, ray);
	x = get_texture_x(ray, texture);
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = get_texture_y(ray, texture, y);
		put_pixel(&data->screen, screen_x, y, *(unsigned int *)(texture->data
				+ tex_y * texture->line_length
				+ x * (texture->bits_per_pixel / 8)));
		y++;
	}
}

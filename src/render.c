/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:50:34 by louka             #+#    #+#             */
/*   Updated: 2026/09/16 21:55:49 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int	color_value(t_colors *color)
{
	return ((color->red << 16) | (color->green << 8) | color->blue);
}

void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->data + y * image->line_length
		+ x * (image->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

void	draw_background(t_game *data)
{
	int	x;
	int	y;
	int	ceiling;
	int	floor;

	ceiling = color_value(data->assets->ceiling);
	floor = color_value(data->assets->floor);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT / 2)
			put_pixel(&data->screen, x, y++, ceiling);
		while (y < SCREEN_HEIGHT)
			put_pixel(&data->screen, x, y++, floor);
		x++;
	}
}

void	draw_walls(t_game *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		render_column(data, x);
		x++;
	}
}

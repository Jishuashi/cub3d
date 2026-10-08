/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:50:34 by louka             #+#    #+#             */
/*   Updated: 2026/09/29 15:21:44 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../includes/render.h"

/**
 * Packs a color into a 0xRRGGBB integer.
 *
 * @param color Color to convert.
 * @return The packed color.
 */
static int	color_value(t_colors *color)
{
	return ((color->red << 16) | (color->green << 8) | color->blue);
}

/**
 * Writes one pixel into an image buffer.
 *
 * @param image Target image.
 * @param x Pixel column.
 * @param y Pixel row.
 * @param color Color as 0xRRGGBB.
 */
void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->data + y * image->line_length
		+ x * (image->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

/**
 * Fills the screen with the ceiling (top half) and floor (bottom half) colors.
 *
 * @param data Game structure.
 */
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

/**
 * Draws every wall column of the frame.
 *
 * @param data Game structure.
 */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_compat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 16:10:00 by louka             #+#    #+#             */
/*   Updated: 2026/08/07 15:50:59 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/cube3d.h"

void	*mlx_init(void)
{
	return (malloc(1));
}

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	(void)mlx_ptr;
	(void)size_x;
	(void)size_y;
	(void)title;
	return (malloc(1));
}

int	mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	(void)mlx_ptr;
	free(win_ptr);
	return (0);
}

int	mlx_destroy_display(void *mlx_ptr)
{
	free(mlx_ptr);
	return (0);
}

void	*mlx_new_image(void *mlx_ptr, int width, int height)
{
	(void)mlx_ptr;
	(void)width;
	(void)height;
	return (malloc(1));
}

char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
		int *line_length, int *endian)
{
	if (bits_per_pixel)
		*bits_per_pixel = 32;
	if (line_length)
		*line_length = 0;
	if (endian)
		*endian = 0;
	return ((char *)img_ptr);
}

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr)
{
	(void)mlx_ptr;
	free(img_ptr);
	return (0);
}

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width,
		int *height)
{
	(void)mlx_ptr;
	(void)filename;
	if (width)
		*width = 0;
	if (height)
		*height = 0;
	return (malloc(1));
}

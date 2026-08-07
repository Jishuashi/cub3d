/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:31:06 by louka             #+#    #+#             */
/*   Updated: 2026/08/07 15:32:21 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	init_img_null(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

static void	free_single_texture(void *mlx, t_img *tex)
{
	if (tex && tex->img)
	{
		mlx_destroy_image(mlx, tex->img);
		tex->img = NULL;
		tex->addr = NULL;
	}
}

void	free_textures_struct(void *mlx, t_texture **textures)
{
	if (!textures || !*textures)
		return ;
	if (mlx)
	{
		free_single_texture(mlx, &(*textures)->nord);
		free_single_texture(mlx, &(*textures)->sud);
		free_single_texture(mlx, &(*textures)->ouest);
		free_single_texture(mlx, &(*textures)->est);
	}
	free(*textures);
	*textures = NULL;
}

t_texture	*alloc_textures(void)
{
	t_texture	*textures;

	textures = (t_texture *)malloc(sizeof(t_texture));
	if (!textures)
	{
		write(2, "Error\nMalloc failed for textures\n", 33);
		return (NULL);
	}
	init_img_null(&textures->nord);
	init_img_null(&textures->sud);
	init_img_null(&textures->ouest);
	init_img_null(&textures->est);
	return (textures);
}
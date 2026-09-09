/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:53:41 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/09 12:53:57 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static int	load_texture(void *mlx, char *path, t_texture *texture)
{
	texture->image = mlx_xpm_file_to_image(mlx, path, &texture->width,
			&texture->height);
	if (!texture->image)
		return (0);
	texture->data = mlx_get_data_addr(texture->image, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	if (!texture->data)
	{
		mlx_destroy_image(mlx, texture->image);
		texture->image = NULL;
		return (0);
	}
	return (1);
}

int	load_textures(void *mlx, t_assets *assets)
{
	if (!mlx || !assets)
		return (0);
	if (!load_texture(mlx, assets->no, &assets->no_img)
		|| !load_texture(mlx, assets->so, &assets->so_img)
		|| !load_texture(mlx, assets->ea, &assets->ea_img)
		|| !load_texture(mlx, assets->we, &assets->we_img))
		return (free_texture_images(mlx, assets), 0);
	return (1);
}

void	free_texture_images(void *mlx, t_assets *assets)
{
	if (!mlx || !assets)
		return ;
	if (assets->no_img.image)
		mlx_destroy_image(mlx, assets->no_img.image);
	if (assets->so_img.image)
		mlx_destroy_image(mlx, assets->so_img.image);
	if (assets->ea_img.image)
		mlx_destroy_image(mlx, assets->ea_img.image);
	if (assets->we_img.image)
		mlx_destroy_image(mlx, assets->we_img.image);
	assets->no_img = (t_texture){0};
	assets->so_img = (t_texture){0};
	assets->ea_img = (t_texture){0};
	assets->we_img = (t_texture){0};
}

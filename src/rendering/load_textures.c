/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:53:41 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/29 15:21:04 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * Loads one XPM file into a texture.
 *
 * @param mlx MLX connection.
 * @param path Path of the XPM file.
 * @param texture Texture to fill.
 * @return 1 on success, 0 on failure.
 */
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

/**
 * Loads the four wall textures (NO, SO, EA, WE).
 *
 * Releases any loaded image if one fails.
 *
 * @param mlx MLX connection.
 * @param assets Assets holding the paths and receiving the images.
 * @return 1 on success, 0 on failure.
 */
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

/**
 * Destroys the loaded texture images and resets them.
 *
 * @param mlx MLX connection.
 * @param assets Assets holding the images.
 */
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

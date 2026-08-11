/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:41:05 by louka             #+#    #+#             */
/*   Updated: 2026/08/11 12:42:12 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static void	free_single_texture(void *mlx, t_img *tex)
{
	if (tex && tex->img)
	{
		mlx_destroy_image(mlx, tex->img);
		tex->img = NULL;
		tex->addr = NULL;
	}
}

void	free_textures(void *mlx, t_texture *textures, char **paths)
{
	if (!textures)
		return ;
	free_single_texture(mlx, &textures->nord);
	free_single_texture(mlx, &textures->sud);
	free_single_texture(mlx, &textures->ouest);
	free_single_texture(mlx, &textures->est);
	free(paths);
}

static int	load_single_texture(void *mlx, t_img *tex, char *path)
{
	if (!path || ft_strlen(path) < 4 || ft_strncmp(path + ft_strlen(path) - 4,
			".xpm", 4) != 0)
		return (ft_print_err(path ? path : "texture", " texture must be .xpm"), 0);
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	if (!tex->addr)
	{
		mlx_destroy_image(mlx, tex->img);
		tex->img = NULL;
		return (0);
	}
	return (1);
}

int	init_textures(void *mlx, t_texture *textures, char *path)
{
	char	**paths;

	paths = ft_split(path, ';');
	if (!paths)
		return (0);
	textures->nord.img = NULL;
	textures->sud.img = NULL;
	textures->ouest.img = NULL;
	textures->est.img = NULL;
	if (!load_single_texture(mlx, &textures->nord, paths[0]))
		return (free_textures(mlx, textures, paths), 0);
	if (!load_single_texture(mlx, &textures->sud, paths[1]))
		return (free_textures(mlx, textures, paths), 0);
	if (!load_single_texture(mlx, &textures->ouest, paths[2]))
		return (free_textures(mlx, textures, paths), 0);
	if (!load_single_texture(mlx, &textures->est, paths[3]))
		return (free_textures(mlx, textures, paths), 0);
	free(paths);
	return (1);
}

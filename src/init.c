/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:18:23 by louka2b           #+#    #+#             */
/*   Updated: 2026/09/17 10:20:05 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static void	init_error(t_game *data, t_file *file, char *message)
{
	free_file(file);
	free_map(data->map);
	free_texture_images(data->mlx, data->assets);
	free_textures(data->assets);
	mlx_destroy_display(data->mlx);
	ft_print_err("", message, NULL);
	exit(1);
}

static void	init_map(t_game *data, t_file *file, int map_line)
{
	int	is_valid;

	data->map = parse_map(file, map_line);
	if (!data->map)
		return (free_file(file), ft_print_err("", "Memory allocation failed\n",
				NULL), exit(1));
	is_valid = check_map(data->map);
	if (!is_valid)
		return (free_file(file), free_map(data->map), ft_print_err("",
				"Map not surrounded by Wall or invalid map char\n",
				NULL), exit(1));
	if (is_valid < 0)
		return (free_file(file), free_map(data->map), ft_print_err("",
				"Memory allocation failed\n", NULL), exit(1));
	ft_putstr_fd("Map loaded successfully\n", 1);
}

void	init(t_game *data, t_file *file, int map_line)
{
	init_map(data, file, map_line);
	data->assets = parse_textures(file, map_line);
	if (!data->assets)
		return (free_file(file), free_map(data->map), ft_print_err("",
				"Memory allocation failed\n", NULL), exit(1));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_file(file), free_map(data->map),
			free_textures(data->assets), ft_print_err("",
				"MLX initialization failed\n", NULL), exit(1));
	if (!load_textures(data->mlx, data->assets))
		return (init_error(data, file, "Unable to load MLX textures\n"));
	if (!check_colors_value(data->assets))
		return (init_error(data, file,
				"Colors value must be between 0 and 255"));
}

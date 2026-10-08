/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:18:23 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/17 12:48:54 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

/**
 * Frees every allocated resource, prints an error and exits.
 *
 * @param data Game structure.
 * @param file Raw file content.
 * @param message Error message to print.
 */
static void	init_error(t_game *data, t_file *file, char *message)
{
	free_file(file);
	free_map(data->map);
	free_texture_images(data->mlx, data->assets);
	free_textures(data->assets);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_print_err("", message, NULL);
	exit(1);
}

/**
 * Parses and validates the map section of the file.
 *
 * Exits with an error if the map cannot be built, has not exactly one player
 * or is not closed by walls.
 *
 * @param data Game structure receiving the map.
 * @param file Raw file content.
 * @param map_line Index of the first map line.
 */
static void	init_map(t_game *data, t_file *file, int map_line)
{
	int	is_valid;

	data->map = parse_map(file, map_line);
	if (!data->map)
		return (free_file(file), ft_print_err("", "Memory allocation failed\n",
				NULL), exit(1));
	if (count_players(data->map->grid) != 1)
		return (free_file(file), free_map(data->map), ft_print_err("",
				"Map must contain exactly one player (N, S, E or W)\n",
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

/**
 * Initializes the map, textures, MLX and colors.
 *
 * Exits with an error message if any step fails.
 *
 * @param data Game structure to fill.
 * @param file Raw file content.
 * @param map_line Index of the first map line.
 */
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

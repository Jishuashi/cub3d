/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/09/09 12:55:44 by ldeplace         ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	t_game	data;
	t_file	*file;
	int		map_line;

	if (ac != 2)
		return (ft_putstr_fd("Error\nArg must be only a map in format .cub\n",
				2), 1);
	map_line = 0;
	check_path(av[1]);
	if (!check_file(av[1]))
		return (ft_print_err(av[1], " map path invalid\n", NULL), 1);
	file = read_file(av[1]);
	if (!file)
		return (ft_print_err("", "Memory allocation failed\n", NULL), 1);
	if (!check_map_format(file, &map_line))
		return (free_file(file)
			, ft_print_err("", "Memory allocation failed\n", NULL), 1);
	init(&data, file, map_line);
	start(&data);
	free_texture_images(data.mlx, data.assets);
	mlx_destroy_display(data.mlx);
	return (free_file(file), free_textures(data.assets), free_map(data.map), 0);
}

void	init(t_game *data, t_file *file, int map_line)
{
	int	is_valid;

	data->map = parse_map(file, map_line);
	if (!data->map)
		return (free_file(file)
			, ft_print_err("", "Memory allocation failed\n", NULL), exit(1));
	is_valid = check_map(data->map);
	if (!is_valid)
		return (free_file(file), free_map(data->map), ft_print_err(""
				, "Map not surrounded by Wall or invalid map char\n", NULL)
			, exit(1));
	if (is_valid < 0)
		return (free_file(file), free_map(data->map)
			, ft_print_err("", "Memory allocation failed\n", NULL)
			, exit(1));
	data->assets = parse_textures(file, map_line);
	if (!data->assets)
		return (free_file(file), free_map(data->map)
			, ft_print_err("", "Memory allocation failed\n", NULL), exit(1));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_file(file), free_map(data->map)
			, free_textures(data->assets), ft_print_err(""
				, "MLX initialization failed\n", NULL), exit(1));
	if (!load_textures(data->mlx, data->assets))
		return (init_error(data, file, "Unable to load MLX textures\n"));
	if (!check_colors_value(data->assets))
		return (init_error(data, file,
				"Colors value must be between 0 and 255"));
}

void	start(t_game *data)
{
	size_t		i;
	size_t		j;

	i = 0;
	printf("Map:\n");
	while (i < data->map->heigh)
	{
		j = 0;
		while (data->map->grid[i][j])
		{
			printf("%c", data->map->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	printf("NO : %s\nSO : %s\n", data->assets->no, data->assets->so);
	printf("EA : %s\nWE : %s\n", data->assets->ea, data->assets->we);
	printf("\n");
	printf("F Colors | R : %d G: %d B:%d\n", data->assets->floor->red,
		data->assets->floor->green, data->assets->floor->blue);
	printf("C Colors | R : %d G: %d B:%d\n", data->assets->ceiling->red,
		data->assets->ceiling->green, data->assets->ceiling->blue);
}

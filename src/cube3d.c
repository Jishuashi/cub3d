/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/09/15 13:50:10 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"
static int	close_window(t_game *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

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
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	data->screen.image = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!data->win || !data->screen.image)
		return ;
	data->screen.data = mlx_get_data_addr(data->screen.image,
			&data->screen.bits_per_pixel, &data->screen.line_length,
			&data->screen.endian);
	init_player(data);
	draw_background(data);
	draw_walls(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen.image, 0, 0);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->screen.image);
	mlx_destroy_window(data->mlx, data->win);
}

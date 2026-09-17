/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/09/17 10:14:24 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"
#include "includes/movement.h"
#include "includes/player.h"
#include "includes/render.h"

static int	close_window(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	mlx_loop_end(data->mlx);
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	data;
	t_file	*file;
	int		map_line;

	if (ac != 2)
		return (ft_putstr_fd("Error\nArg must be only a map in format .cub\n",
				2), 1);
	ft_bzero(&data, sizeof(data));
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
	ft_putstr_fd("Controls: W/S move, A/D turn, Q or ESC quits\n", 1);
	mlx_hook(data->win, 2, 1L << 0, (int (*)())key_press, data);
	mlx_key_hook(data->win, key_release, data);
	mlx_hook(data->win, 17, 0, (int (*)())close_window, data);
	mlx_loop_hook(data->mlx, (int (*)())game_loop, data);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->screen.image);
	mlx_destroy_window(data->mlx, data->win);
}

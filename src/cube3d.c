/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/11 12:39:40 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

static void	print_map(t_map *map)
{
	size_t	i;

	i = 0;
	ft_printf("Map : \n");
	while (i < map->heigh)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
	ft_printf("\n");
}

static int	run_program(char *path)
{
	t_game	game;
	t_map	*map;

	game = (t_game){0};
	check_path(path);
	check_map_file(ft_open(path));
	map = parse_map(path);
	if (!map)
		return (1);
	if (!init_game(&game, path))
		return (printf("error empty .xpm or mlx init failed\n"),
			free_map(map), 1);
	printf("mlx and texture loaded\n");
	print_map(map);
	cleanup_mlx(&game);
	free_map(map);
	return (0);
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (ft_putstr_fd("Error\nArg must be only a map in format .cub\n",
				2), 1);
	return (run_program(av[1]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 00:53:22 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

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
	data.map = parse_map(file, map_line);
	if (!data.map)
		return (free_file(file)
			, ft_print_err("", "Memory allocation failed\n", NULL), 1);
	init(&data);
	return (free_file(file), free_map(data.map), 0);
}

void	init(t_game *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	printf("Map:\n");
	while (i < data->map->heigh)
	{
		j = 0;
		while (j < data->map->width)
		{
			printf("%c", data->map->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

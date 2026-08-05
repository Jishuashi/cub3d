/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/05 01:04:32 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(int ac, char *av[])
{
	size_t	i;
	t_map	*map;

	if (ac != 2)
		return (ft_putstr_fd("Error\nArg must be only a map in format .cub",
				2), 1);
	check_path(av[1]);
	check_map_file(ft_open(av[1]));
	map = parse_map(av[1]);
	if (!map)
		return (1);
	i = 0;
	ft_printf("Map : \n");
	while (i < map->heigh)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
	ft_printf("\n");
	free_map(map);
	return (0);
}

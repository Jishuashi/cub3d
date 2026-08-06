/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 18:05:28 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(int ac, char *av[])
{
	t_map	*map;

	if (ac != 2)
		return (ft_putstr_fd("Error\nArg must be only a map in format .cub\n",
				2), 1);
	check_path(av[1]);
	check_map_file(ft_open(av[1]));
	map = parse_map(av[1]);
	if (!map)
		return (1);
	printf("Map is valid : %d\n", check_map(map));
	free_map(map);
	return (0);
}

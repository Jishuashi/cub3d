/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/07 19:00:21 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(int ac, char *av[])
{
	t_map	*map;
	t_file	*file;

	if (ac != 2)
		return (ft_putstr_fd("Error\nArg must be only a map in format .cub\n",
				2), 1);
	check_path(av[1]);
	file = read_file(av[1]);
	/*map = parse_map(av[1]);
	if (!map)
		return (1);
	printf("Map is valid : %d\n", check_map(map));
	free_map(map); */
	(void) map;
	free_file(file);
	return (0);
}

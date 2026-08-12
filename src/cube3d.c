/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/12 16:57:37 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(int ac, char *av[])
{
	t_map	*map;
	t_file	*file;
	int		map_line;

	if (ac != 2)
		return (ft_putstr_fd("Error\nArg must be only a map in format .cub\n",
				2), 1);
	check_path(av[1]);
	if (!check_file(av[1]))
		return (ft_print_err(av[1], " map path invalid\n"), 1);
	file = read_file(av[1]);
	if (!file)
		return (ft_print_err("", "Memory allocation failed\n"), 1);
	if (!check_map_format(file, &map_line))
		return (ft_print_err("", "Memory allocation failed\n"), 1);
	(void) map;
	printf("Map Good\n");
	free_file(file);
	return (0);
}

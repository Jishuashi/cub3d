/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:58:21 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/04 19:19:57 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(void)
{
	size_t	i;
	t_map	*map;

	map = parse_map("./maps/testmap.cub");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:10:51 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 18:04:19 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube3d.h"

int	check_map(t_map *map)
{
	static const int	char_val[] = {'1', '0', ' ', 'N', '\n', 0};
	size_t				e;
	size_t				i;
	size_t				j;

	i = 0;
	while (i < map->heigh)
	{
		j = 0;
		while (map->grid[i][j])
		{
			e = 0;
			while (char_val[e])
			{
				if (char_val[e] != map->grid[i][j])
					return (0);
				e++;
			}
			j++;
		}
		if (j != map->width)
			return (0);
		i++;
	}
	return (1);
}

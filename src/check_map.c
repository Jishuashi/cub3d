/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:10:51 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 01:25:52 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube3d.h"

/**
 * Validates the content of a parsed map grid.
 *
 * Each character in the map must belong to the allowed set:
 * wall, floor, space, player spawn, and line break terminator.
 * The function also verifies that each row matches the map width.
 *
 * @param map Pointer to the parsed map structure.
 * @return 1 if the map is valid, 0 otherwise.
 */
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

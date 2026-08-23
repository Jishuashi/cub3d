/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:34:56 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/23 17:19:04 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	flood_fill(char **map, t_point *pos)
{
	int	r1;
	int	r2;
	int	r3;
	int	r4;

	if (!pos)
		return (-1);
	if (pos->x < 0 || pos->y < 0 || !map[pos->x]
		|| (size_t)pos->y >= ft_strlen(map[pos->x])
		|| map[pos->x][pos->y] == ' ' || !map[pos->x][pos->y])
		return (free(pos), 0);
	if (map[pos->x][pos->y] == '1' || map[pos->x][pos->y] == 'V')
		return (free(pos), 1);
	map[pos->x][pos->y] = 'V';
	r1 = flood_fill(map, get_point((pos->x + 1), pos->y));
	r2 = flood_fill(map, get_point((pos->x - 1), pos->y));
	r3 = flood_fill(map, get_point(pos->x, (pos->y + 1)));
	r4 = flood_fill(map, get_point(pos->x, (pos->y - 1)));
	if (r1 < 0 || r2 < 0 || r3 < 0 || r4 < 0)
		return (free(pos), -1);
	if (!r1 || !r2 || !r3 || !r4)
		return (free(pos), 0);
	return (free(pos), 1);
}

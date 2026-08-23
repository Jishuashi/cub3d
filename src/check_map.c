/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:10:51 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/23 17:29:47 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube3d.h"

static int	is_valid(char **copy, char curr, t_point *pos);

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
	size_t	i;
	size_t	j;
	char	**grid;
	char	**copy;
	int		valid;

	i = 0;
	grid = map->grid;
	copy = copy_map(map->grid, map->heigh);
	if (!copy)
		return (-1);
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			valid = is_valid(copy, grid[i][j], get_point(i, j));
			if (valid <= 0)
				return (free_double(copy), valid);
			j++;
		}
		i++;
	}
	return (free_double(copy), 1);
}

static int	is_valid(char **copy, char curr, t_point *pos)
{
	int	res;

	res = 1;
	if (!ft_strchr("NSWE10 ", curr))
		return (free(pos), 0);
	if (curr == 'N' || curr == 'W' || curr == 'E' || curr == 'S' || curr == '0')
		return (flood_fill(copy, pos));
	return (free(pos), res);
}

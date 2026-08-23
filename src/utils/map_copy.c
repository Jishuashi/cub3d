/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:52:15 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/23 16:58:53 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	**copy_map(char **map, size_t row)
{
	char	**copy;
	size_t	i;

	copy = (char **)malloc(sizeof(char *) * (row + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < row)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (free_double(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

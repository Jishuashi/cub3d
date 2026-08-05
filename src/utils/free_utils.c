/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:26:57 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 01:12:14 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->heigh)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void	free_grid_map(char **map, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(map[j++]);
	free(map);
}

void	free_parsed(char *line, int fd, char **split)
{
	size_t	i;

	while (line)
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
	close(fd);
}

void	free_double(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

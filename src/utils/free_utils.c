/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:26:57 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 17:30:42 by hchartie         ###   ########.fr       */
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

void	free_parsed(t_parsed *parsed)
{
	size_t	i;

	while (parsed->line)
	{
		free(parsed->line);
		parsed->line = ft_get_next_line(parsed->fd);
	}
	i = 0;
	while (parsed->split_line && parsed->split_line[i])
		free(parsed->split_line[i++]);
	free(parsed->split_line);
	close(parsed->fd);
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

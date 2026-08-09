/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:26:57 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/10 00:56:21 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->heigh)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
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
	if (!parsed)
		return ;
	if (parsed->sp_l)
	{
		free(parsed->sp_l[0]);
		free(parsed->sp_l[1]);
		free(parsed->sp_l);
		parsed->sp_l = NULL;
	}
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

void	free_file(t_file *file)
{
	size_t	i;

	i = 0;
	while (i < file->len)
	{
		free(file->lines[i]);
		i++;
	}
	free(file->lines);
	free(file);
}

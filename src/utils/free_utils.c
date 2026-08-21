/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:26:57 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/20 13:50:02 by hchartie         ###   ########.fr       */
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
	int		i;

	if (!parsed)
		return ;
	if (parsed->sp_l)
	{
		i = 0;
		while (parsed->sp_l[i])
		{
			free(parsed->sp_l[i]);
			i++;
		}
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
	if (!file)
		return ;
	if (file->lines)
	{
		while (i < file->len)
		{
			if (file->lines[i])
				free(file->lines[i]);
			i++;
		}
		free(file->lines);
	}
	free(file);
}

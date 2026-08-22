/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:26:57 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 02:38:13 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

/**
 * Frees all memory allocated for a parsed map.
 *
 * @param map Pointer to the map structure to free.
 */
void	free_map(t_map *map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map->grid && i < map->heigh)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

/**
 * Frees a grid of strings up to the given index.
 *
 * @param map Pointer to the string array to free.
 * @param i Number of elements to free.
 */
void	free_grid_map(char **map, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(map[j++]);
	free(map);
}

/**
 * Frees the tokenized parsed line and its associated split array.
 *
 * @param parsed Pointer to the parsing state to clean.
 */
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

/**
 * Frees a NULL-terminated array of strings.
 *
 * @param tab Pointer to the string array.
 */
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

/**
 * Frees the file structure and all strings it contains.
 *
 * @param file Pointer to the parsed file structure.
 */
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

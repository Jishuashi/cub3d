/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:08:53 by louka             #+#    #+#             */
/*   Updated: 2026/08/22 01:25:52 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parse_map.h"

/**
 * Builds a map structure starting from the map section of a parsed file.
 *
 * The function calculates the number of lines in the map, copies the map rows,
 * and stores the resulting width and grid into a newly allocated structure.
 *
 * @param file Parsed file structure containing all loaded lines.
 * @param i_line Index of the first row of the map section.
 * @return A newly allocated map on success, or NULL on allocation failure.
 */
t_map	*parse_map(t_file *file, int i_line)
{
	t_map	*res;

	res = (t_map *)malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	res->heigh = get_heigh_map(file, i_line);
	res->grid = get_map(file, i_line, res->heigh);
	if (!res->grid)
		return (free(res), NULL);
	res->width = get_width_map(file, i_line);
	return (res);
}

/**
 * Copies the map section into a dedicated grid of rows.
 *
 * Each map line is duplicated and trimmed from a trailing newline before being
 * stored into the returned array. The last entry is set to NULL as a terminator.
 *
 * @param file Parsed file structure.
 * @param i_line Index of the first map line.
 * @param heigh Number of rows to be copied.
 * @return A NULL-terminated grid of strings representing the map.
 */
char	**get_map(t_file *file, int i_line, size_t heigh)
{
	char	**res;
	char	*line;
	size_t	i;
	size_t	e;

	res = (char **)malloc(sizeof(char *) * (heigh + 1));
	if (!res)
		return (NULL);
	i = (size_t)i_line;
	while (file->lines[i])
	{
		line = ft_strdup(file->lines[i]);
		if (!line)
			return (free_grid_map(res, i - i_line), NULL);
		e = 0;
		while (line[e++])
		{
			if (line[e] == '\n')
				line[e] = '\0';
		}
		res[i - i_line] = line;
		i++;
	}
	res[i - i_line] = NULL;
	return (res);
}

/**
 * Counts the number of rows remaining in the map section.
 *
 * @param file Parsed file structure.
 * @param i_line Index of the first map row.
 * @return The number of lines in the map.
 */
size_t	get_heigh_map(t_file *file, int i_line)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = (size_t)i_line;
	while (file->lines[i])
	{
		res++;
		i++;
	}
	return (res);
}

/**
 * Returns the width of the first row of the map.
 *
 * @param file Parsed file structure.
 * @param i_line Index of the first map row.
 * @return The width of the map row as a string length.
 */
size_t	get_width_map(t_file *file, int i_line)
{
	return (ft_strlen(file->lines[i_line]));
}

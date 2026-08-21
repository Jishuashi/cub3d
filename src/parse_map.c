/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:08:53 by louka             #+#    #+#             */
/*   Updated: 2026/08/22 01:19:23 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parse_map.h"

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

size_t	get_width_map(t_file *file, int i_line)
{
	return (ft_strlen(file->lines[i_line]));
}

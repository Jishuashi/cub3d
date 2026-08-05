/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:08:53 by louka             #+#    #+#             */
/*   Updated: 2026/08/04 23:52:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parse_map.h"

t_map	*parse_map(char *file)
{
	t_map	*res;

	res = (t_map *)malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	res->heigh = get_heigh_map(ft_open(file));
	res->map = get_map(ft_open(file), res->heigh);
	if (!res->map)
		return (free(res), NULL);
	res->width = get_width_map(ft_open(file));
	return (res);
}

char	**get_map(int fd, size_t heigh)
{
	char	**res;
	char	*line;
	size_t	i;
	int		nb_line;

	res = (char **)malloc(sizeof(char *) * (heigh + 1));
	if (!res)
		return (close(fd), NULL);
	i = 0;
	nb_line = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (nb_line >= 9)
			res[i++] = line;
		else
			free(line);
		line = ft_get_next_line(fd);
		nb_line++;
	}
	if (nb_line < 9)
		return (close(fd), free_grid_map(res, i), NULL);
	res[i] = NULL;
	close(fd);
	return (res);
}

size_t	get_heigh_map(int fd)
{
	size_t	res;
	int		nb_line;
	char	*line;

	line = ft_get_next_line(fd);
	res = 0;
	nb_line = 0;
	while (line)
	{
		if (nb_line >= 9)
			res++;
		free(line);
		line = ft_get_next_line(fd);
		nb_line++;
	}
	if (fd >= 0)
		close(fd);
	return (res);
}

size_t	get_width_map(int fd)
{
	size_t	res;
	char	*line;
	size_t	nb_line;

	line = ft_get_next_line(fd);
	nb_line = 0;
	while (line)
	{
		nb_line++;
		if (nb_line == 9)
			res = ft_strlen(line);
		free(line);
		line = ft_get_next_line(fd);
	}
	free(line);
	close(fd);
	return (res);
}

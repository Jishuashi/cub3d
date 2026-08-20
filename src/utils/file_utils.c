/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:18:41 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/20 13:48:05 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	ft_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(" : file not found\n", 2);
		exit(1);
	}
	return (fd);
}

void	check_path(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid map extension (must be .cub)\n", 2);
		exit(1);
	}
	if (len == 4 || path[len - 5] == '/')
	{
		ft_putstr_fd("Error\nThe map .cub has no name\n", 2);
		exit(1);
	}
}

size_t	get_len_file(int fd)
{
	char	*line;
	size_t	res;

	if (fd < 0)
		return (0);
	line = gnl_cub(fd);
	res = 0;
	while (line)
	{
		res++;
		free(line);
		line = gnl_cub(fd);
	}
	if (errno != 0)
		return (close(fd), free(line), 0);
	return (close(fd), free(line), res);
}

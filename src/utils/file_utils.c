/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:18:41 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/10 00:53:18 by hchartie         ###   ########.fr       */
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

t_file	*read_file(char	*path)
{
	int		fd;
	char	*line;
	t_file	*file;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->len = get_len_file(open(path, O_RDONLY));
	file->lines = (char **)malloc(sizeof(char *) * (file->len + 1));
	if (!file->lines)
		return (free(file), NULL);
	line = ft_get_next_line(fd);
	while (line)
	{
		file->lines[i] = line;
		line = ft_get_next_line(fd);
		i++;
	}
	file->lines[i] = NULL;
	return (close(fd), file);
}

size_t	get_len_file(int fd)
{
	char	*line;
	size_t	res;

	if (fd < 0)
		return (0);
	line = ft_get_next_line(fd);
	res = 0;
	while (line)
	{
		res++;
		free(line);
		line = ft_get_next_line(fd);
	}
	free(line);
	close(fd);
	return (res);
}

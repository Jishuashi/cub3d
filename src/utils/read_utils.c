/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:51:20 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/20 13:48:16 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static int	fill_file(t_file *file, int fd)
{
	char	*line;
	size_t	i;

	i = 0;
	line = gnl_cub(fd);
	while (line)
	{
		file->lines[i++] = line;
		line = gnl_cub(fd);
	}
	file->lines[i] = NULL;
	file->len = i;
	if (errno != 0)
		return (0);
	return (1);
}

t_file	*read_file(char *path)
{
	int		fd;
	int		fd_len;
	t_file	*file;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = malloc(sizeof(t_file));
	if (!file)
		return (close(fd), NULL);
	fd_len = open(path, O_RDONLY);
	if (fd_len < 0)
		return (close(fd), free(file), NULL);
	file->len = get_len_file(fd_len);
	file->lines = malloc(sizeof(char *) * (file->len + 1));
	if (!file->lines || file->len == 0)
		return (close(fd), free_file(file), NULL);
	if (!fill_file(file, fd))
		return (close(fd), free_file(file), NULL);
	close(fd);
	return (file);
}

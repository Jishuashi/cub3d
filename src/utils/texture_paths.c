/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:40:00 by ldeplace          #+#    #+#             */
/*   Updated: 2026/08/11 12:22:15 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	free_split_line(char **split_line)
{
	int	i;

	if (!split_line)
		return ;
	i = 0;
	while (split_line[i])
		free(split_line[i++]);
	free(split_line);
}

static char	*append_texture_path(char *paths, char *path)
{
	char	*tmp;

	if (!path)
		return (free(paths), NULL);
	if (!paths)
		return (path);
	tmp = ft_strjoin(paths, ";");
	free(paths);
	if (!tmp)
		return (free(path), NULL);
	paths = ft_strjoin(tmp, path);
	free(tmp);
	free(path);
	return (paths);
}

static char	*read_texture_path(int fd, char *paths)
{
	char	*line;
	char	**split_line;
	char	*trimmed;

	line = ft_get_next_line(fd);
	if (!line)
		return (free(paths), NULL);
	split_line = ft_split(line, ' ');
	if (!split_line || !split_line[0] || !split_line[1])
		return (free(line), free_split_line(split_line), free(paths), NULL);
	trimmed = ft_strtrim(split_line[1], "\n");
	free(line);
	free_split_line(split_line);
	return (append_texture_path(paths, trimmed));
}

char	*get_texture_paths(char *file)
{
	char	*paths;
	int		fd;
	int		i;

	paths = NULL;
	i = 0;
	fd = ft_open(file);
	while (i < 4)
	{
		paths = read_texture_path(fd, paths);
		if (!paths)
			return (close(fd), NULL);
		i++;
	}
	close(fd);
	return (paths);
}

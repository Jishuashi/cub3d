/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:18:41 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 01:20:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (close(fd), 0);
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

void	check_map_file(int fd)
{
	char				*line;
	char				**split_line;
	static const char	*id[] = {"NO", "SO", "WE", "EA", "\n", "F", "C", NULL};
	size_t				nb_line;
	size_t				i;

	line = ft_get_next_line(fd);
	nb_line = 0;
	while (line)
	{
		split_line = ft_split(line, ' ');
		if (!split_line)
			return (free_parsed(line, fd, split_line), ft_print_err(""
					, "Memory alloc failed"));
		if (nb_line < 8)
		{
			printf("%zu\n", nb_line);
			check_map_line(fd, split_line, line, id[nb_line]);
		}
		free(line);
		i = 0;
		while (split_line && split_line[i])
			free(split_line[i++]);
		free(split_line);
		line = ft_get_next_line(fd);
		nb_line++;
	}
	close(fd);
}

void	check_map_line(int fd, char **split_line, char *line, const char *id)
{
	int		l_fd;
	char	*texture_path;

	if (!id || ft_strncmp((char *)id, "\n", 1) == 0)
		return ;
	if (ft_strncmp(split_line[0], (char *)id, ft_strlen(id)) != 0)
	{
		ft_print_err(split_line[0], " the key valid/correct order");
		free_parsed(line, fd, split_line);
		exit(1);
	}
	if (ft_strlen(split_line[0]) == 2)
	{
		texture_path = ft_strtrim(split_line[1], "\n");
		if (!texture_path)
			return (free_parsed(line, fd, split_line), exit(1));
		l_fd = open(texture_path, O_RDONLY);
		if (l_fd < 0)
			return (free_parsed(line, fd, split_line),
				ft_print_err(texture_path, " texture not found"),
				free(texture_path), exit(1));
		free(texture_path);
		close(l_fd);
	}
	check_color(fd, line, split_line);
}

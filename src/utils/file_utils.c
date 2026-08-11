/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:18:41 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/11 12:42:12 by ldeplace         ###   ########.fr       */
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
	t_parsed			parsed;
	static const char	*id[] = {"NO", "SO", "WE", "EA", "\n", "F", "C", NULL};
	size_t				nb_line;
	size_t				i;

	parsed.line = ft_get_next_line(fd);
	parsed.fd = fd;
	nb_line = 0;
	while (parsed.line)
	{
		parsed.split_line = ft_split(parsed.line, ' ');
		if (!parsed.split_line)
			return (free_parsed(&parsed), ft_print_err(""
					, "Memory alloc failed"));
		if (nb_line < 8)
			check_map_line(&parsed, id[nb_line]);
		free(parsed.line);
		i = 0;
		while (parsed.split_line && parsed.split_line[i])
			free(parsed.split_line[i++]);
		free(parsed.split_line);
		parsed.line = ft_get_next_line(fd);
		nb_line++;
	}
	close(fd);
}

void	check_map_line(t_parsed *parsed, const char *id)
{
	int			l_fd;
	char		*texture_path;
	char		**split_line;

	split_line = parsed->split_line;
	if (!id || ft_strncmp((char *)id, "\n", 1) == 0)
		return ;
	if (ft_strncmp(split_line[0], (char *)id, ft_strlen(id)) != 0)
		return (ft_print_err(split_line[0], " the key valid/correct order")
			, free_parsed(parsed), exit(1));
	if (ft_strlen(split_line[0]) == 2)
	{
		texture_path = ft_strtrim(split_line[1], "\n");
		if (!texture_path)
			return (free_parsed(parsed), exit(1));
		if (ft_strlen(texture_path) < 4 || ft_strncmp(texture_path
			+ ft_strlen(texture_path) - 4, ".xpm", 4) != 0)
			return (ft_print_err(texture_path, " texture must be .xpm"),
				free(texture_path), free_parsed(parsed), exit(1));
		l_fd = open(texture_path, O_RDONLY);
		if (l_fd < 0)
			return (free_parsed(parsed),
				ft_print_err(texture_path, " texture not found"),
				free(texture_path), exit(1));
		free(texture_path);
		close(l_fd);
	}
	check_color(parsed);
}

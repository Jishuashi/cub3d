/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:18:41 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 01:26:12 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

/**
 * Checks whether a file can be opened for reading.
 *
 * @param path Path to the file to inspect.
 * @return 1 if the file exists and is accessible, 0 otherwise.
 */
int	check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

/**
 * Opens a file for reading and exits on failure.
 *
 * This helper is used for required map assets. If the file cannot be opened,
 * it prints an error message and terminates the program.
 *
 * @param path Path to the file to open.
 * @return The file descriptor associated with the opened file.
 */
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

/**
 * Validates the file extension and the presence of a name for a .cub map.
 *
 * The function ensures the path ends with the expected extension and rejects
 * empty or invalid map names.
 *
 * @param path Path to validate.
 */
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

/**
 * Counts the number of lines stored in a file descriptor.
 *
 * The function reads every remaining line using the custom GNL and returns the
 * number of lines found before EOF. If an error occurs, it returns 0.
 *
 * @param fd File descriptor to inspect.
 * @return Number of lines found in the file.
 */
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

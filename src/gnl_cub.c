/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:38:05 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 01:25:52 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*ft_put_in_acc(int fd, char *acc);
static char	*ft_get_line(char *acc);
static char	*ft_clean_acc(char *acc);

/**
 * Reads one line from the given file descriptor.
 *
 * The function accumulates data until a newline is found, extracts the current
 * line, and keeps the remainder in a static accumulator for the next call.
 *
 * @param fd File descriptor to read from.
 * @return The next line as a newly allocated string, or NULL on EOF or failure.
 */
char	*gnl_cub(int fd)
{
	static char	*acc;
	char		*line;
	char		*new_acc;

	errno = 0;
	acc = ft_put_in_acc(fd, acc);
	if (!acc)
		return (NULL);
	line = ft_get_line(acc);
	if (!line)
		return (free(acc), acc = NULL, NULL);
	new_acc = ft_clean_acc(acc);
	if (!new_acc && errno != 0)
		return (free(line), acc = NULL, NULL);
	acc = new_acc;
	return (line);
}

/**
 * @brief Put in an accumulator all line in the buffer_size
 * 
 * @param fd The file descriptor
 * @param acc The accumulator
 * @return char* The accumulator filled with the read buffer
 */
static char	*ft_put_in_acc(int fd, char *acc)
{
	char	*buff;
	char	*temp;
	int		read_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		errno = ENOMEM;
		return (free(acc), NULL);
	}
	read_bytes = 1;
	while (!ft_gnl_strchr(acc, '\n') && read_bytes > 0)
	{
		read_bytes = read (fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (errno = EIO, free(acc), free(buff), NULL);
		buff[read_bytes] = '\0';
		temp = ft_strjoin(acc, buff);
		if (!temp)
			return (errno = ENOMEM, free(acc), free(buff), NULL);
		free(acc);
		acc = temp;
	}
	free(buff);
	return (acc);
}

/**
 * @brief Get the next line in the accumulator
 * 
 * @param acc The accumulator with line readed
 * @return char* The next_line
 */
static char	*ft_get_line(char *acc)
{
	int		i;
	char	*line;

	i = 0;
	if (!acc || !acc[0])
		return (NULL);
	while (acc[i] && acc[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (errno = ENOMEM, NULL);
	i = 0;
	while (acc[i] && acc[i] != '\n')
	{
		line[i] = acc[i];
		i++;
	}
	if (acc[i] == '\n')
	{
		line[i] = acc[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/**
 * @brief Remove the previous line in the accumulator
 * 
 * @param acc The accumulator with line readed
 * @return char* The cleaned accumulator
 */
static char	*ft_clean_acc(char *acc)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (acc[i] && acc[i] != '\n')
		i++;
	if (!acc[i])
		return (free(acc), NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(acc) - i + 1));
	if (!res)
	{
		errno = ENOMEM;
		return (free(acc), NULL);
	}
	i++;
	while (acc[i])
		res[j++] = acc[i++];
	res[j] = '\0';
	return (free(acc), res);
}

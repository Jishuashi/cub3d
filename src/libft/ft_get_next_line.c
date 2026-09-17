/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:38:05 by hchartie          #+#    #+#             */
/*   Updated: 2026/01/08 13:03:49 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*ft_put_in_acc(int fd, char *acc);
static char	*ft_get_line(char *acc);
static char	*ft_clean_acc(char *acc);

/**
 * @brief Get the next line of the  file descriptor by 
 * a unique call
 * 
 * @param fd The file descriptor
 * @return char* The next line in the file
 */
char	*ft_get_next_line(int fd)
{
	static char	*acc;
	char		*line;

	acc = ft_put_in_acc(fd, acc);
	if (!acc)
		return (NULL);
	line = ft_get_line(acc);
	acc = ft_clean_acc(acc);
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
		return (NULL);
	read_bytes = 1;
	while (!ft_gnl_strchr(acc, '\n') && read_bytes > 0)
	{
		read_bytes = read (fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(acc);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		temp = acc;
		acc = ft_strjoin(temp, buff);
		free(temp);
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
		return (NULL);
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
	{
		free(acc);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(acc) - i + 1));
	if (!res)
		return (NULL);
	i++;
	while (acc[i])
		res[j++] = acc[i++];
	res[j] = '\0';
	free(acc);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:48:06 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/04 18:11:58 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H
# include "../libft/libft.h"
# include "./utils.h"
# include <fcntl.h>

typedef struct s_map
{
	size_t	width;
	size_t	heigh;
	char	**map;
}	t_map;

t_map	*parse_map(char *file);
char	**get_map(int fd, size_t heigh);
size_t	get_heigh_map(int fd);
size_t	get_width_map(int fd);

#endif
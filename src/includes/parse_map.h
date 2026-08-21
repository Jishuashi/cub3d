/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:48:06 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/21 20:37:21 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H
# include "../libft/libft.h"
# include "utils.h"
# include <fcntl.h>

typedef struct s_map
{
	size_t	width;
	size_t	heigh;
	char	**grid;
}	t_map;

typedef struct s_file	t_file;

t_map	*parse_map(t_file *file, int line);
char	**get_map(t_file *file, int line, size_t heigh);
size_t	get_heigh_map(t_file *file, int line);
size_t	get_width_map(t_file *file, int line);

#endif
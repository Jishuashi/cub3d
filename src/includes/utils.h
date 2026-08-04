/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:08:48 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/04 19:07:26 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../libft/libft.h" 
# include "./parse_map.h"
# include <fcntl.h>

typedef struct s_map	t_map;

int		check_file(char *path);
void	free_map(t_map *map);
void	free_grid_map(char **map, int i);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:08:48 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 01:12:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../libft/libft.h" 
# include "./parse_map.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map	t_map;

int		check_file(char *path);
void	free_map(t_map *map);
void	free_grid_map(char **map, int i);
int		ft_open(char *path);
void	check_path(char *path);
void	check_map_file(int fd);
void	check_map_line(int fd, char **split_line, char *line, const char *id);
void	free_parsed(char *line, int fd, char **split);
void	ft_print_err(char *var, char *msg);
void	check_color(int fd, char *line, char **split_line);
char	*trim_nl(char *str);
int		check_int_str(char *str);
void	free_double(char **tab);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:08:48 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/06 17:36:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../libft/libft.h" 
# include "./parse_map.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map	t_map;

typedef struct s_parsed
{
	char	*line;
	int		fd;
	char	**split_line;
}	t_parsed;

int		check_file(char *path);
void	free_map(t_map *map);
void	free_grid_map(char **map, int i);
int		ft_open(char *path);
void	check_path(char *path);
void	check_map_file(int fd);
void	check_map_line(t_parsed *parsed, const char *id);
void	free_parsed(t_parsed *parsed);
void	ft_print_err(char *var, char *msg);
void	check_color(t_parsed *parsed);
char	*trim_nl(char *str);
int		check_int_str(char *str);
void	free_double(char **tab);
void	validate_color_components(t_parsed *parsed, char **sp_val, char *var);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:08:48 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/23 17:04:38 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../libft/libft.h" 
# include "./parse_map.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_map	t_map;
typedef struct s_assets	t_assets;

typedef struct s_file
{
	size_t	len;
	char	**lines;
}	t_file;

typedef struct s_parsed
{
	t_file	*file;
	char	**sp_l;
	char	**used_key;
}	t_parsed;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int		check_file(char *path);
void	free_map(t_map *map);
void	free_grid_map(char **map, int i);
int		ft_open(char *path);
void	check_path(char *path);
void	free_parsed(t_parsed *parsed);
void	ft_print_err(char *var, char *msg, t_parsed	*par);
void	check_color(t_parsed *parsed);
char	*trim_nl(char *str);
int		check_int_str(char *str);
void	free_double(char **tab);
void	validate_color_components(t_parsed *parsed, char **sp_val, char *var);
size_t	get_len_file(int fd);
t_file	*read_file(char	*path);
void	free_file(t_file *file);
char	*reduce_space_val(char **src);
void	err_map_pos(t_parsed *par);
char	*gnl_cub(int fd);
int		check_colors_value(t_assets *assets);
char	**copy_map(char **map, size_t row);
t_point	*get_point(int x, int y);
t_point	*set_point(t_point *point, int x, int y);

#endif
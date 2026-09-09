/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_format_checker.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:10:37 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/23 16:49:19 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FORMAT_CHECKER_H
# define CUB_FORMAT_CHECKER_H
# include "./utils.h"

int		check_map_format(t_file *file, int *map_line);
void	check_key(t_parsed	*parsed, int *nb_key, char **used_keys);
int		check_if_map(t_parsed *parsed, int nb_keys);
void	check_no_map(int nb_keys, int current, t_file *file, char **used);
int		flood_fill(char **map, t_point *pos);

#endif
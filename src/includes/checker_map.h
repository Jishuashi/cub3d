/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:10:37 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/10 01:02:30 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_MAP_H
# define CHECKER_MAP_H
# include "./utils.h"

int	check_map_format(t_file *file, int *map_line);
void	check_key(t_parsed	*parsed, int *nb_key, char **used_keys);

#endif
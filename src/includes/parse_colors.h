/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 02:53:03 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 14:33:59 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_COLORS_H
# define PARSE_COLORS_H
# include "utils.h"

typedef struct s_colors
{
	int	red;
	int	green;
	int	blue;
}	t_colors;

t_colors	*parse_color(t_file *file, int i_line, char *key);
t_colors	*get_colors(t_colors *colors, t_file *file, int i_line, char *key);
t_colors	*set_colors(t_colors *colors, char *val);

#endif
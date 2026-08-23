/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 01:30:42 by hchartie          #+#    #+#             */
/*   Updated: 2026/08/22 03:04:50 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TEXTURES_H
# define PARSE_TEXTURES_H
# include "utils.h"
# include "./parse_colors.h"

typedef struct s_assets
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	t_colors	*floor;
	t_colors	*ceiling;
}	t_assets;

t_assets	*parse_textures(t_file *file, int i_line);
void		free_textures(t_assets *assets);

#endif
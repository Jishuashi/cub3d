/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 01:30:42 by hchartie          #+#    #+#             */
/*   Updated: 2026/09/09 12:53:57 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TEXTURES_H
# define PARSE_TEXTURES_H
# include "utils.h"
# include "./parse_colors.h"

typedef struct s_texture
{
	void	*image;
	char	*data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_assets
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	t_texture	no_img;
	t_texture	so_img;
	t_texture	ea_img;
	t_texture	we_img;
	t_colors	*floor;
	t_colors	*ceiling;
}	t_assets;

t_assets	*parse_textures(t_file *file, int i_line);
int			load_textures(void *mlx, t_assets *assets);
void		free_texture_images(void *mlx, t_assets *assets);
void		free_textures(t_assets *assets);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:41:28 by louka             #+#    #+#             */
/*   Updated: 2026/08/07 15:38:39 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XPM_H
# define XPM_H

# include "../minilibx-linux/mlx.h"
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	t_img	nord;
	t_img	sud;
	t_img	ouest;
	t_img	est;
}	t_texture;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	frame;
}	t_game;

int	        init_textures(void *mlx, t_texture *textures, char *path);
void	    free_textures_struct(void *mlx, t_texture **textures);
t_texture	*alloc_textures(void);
#endif
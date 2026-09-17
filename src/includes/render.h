/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka2b <louka2b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 09:58:07 by louka2b           #+#    #+#             */
/*   Updated: 2026/09/17 09:58:09 by louka2b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "cube3d.h"

void	draw_background(t_game *data);
void	draw_walls(t_game *data);
void	put_pixel(t_image *image, int x, int y, int color);
void	render_column(t_game *data, int screen_x);
void	draw_wall_column(t_game *data, t_ray *ray, int screen_x);
void	redraw(t_game *data);

#endif

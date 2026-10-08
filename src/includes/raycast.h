/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 10:18:41 by ldeplace          #+#    #+#             */
/*   Updated: 2026/09/17 10:18:43 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cube3d.h"

void	init_ray(t_game *data, t_ray *ray, int x);
int		ray_hits_wall(t_game *data, t_ray *ray);

#endif